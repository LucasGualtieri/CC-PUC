#include <iostream>
#include <cassert>
#include <unordered_map>
#include "../include/Graph/Graph.hpp"
#include "../utils/timer.hpp"
#include "../include/Graph/GraphBuilder.hpp"

// clear && g++ tests/fastAdjacencyListTest.cc -std=c++20 -o bin/fastAdjacencyListTest && bin/fastAdjacencyListTest

using namespace std;

// Union-Find com união por rank e compressão de caminho
template <typename T>
class UnionFind {

	std::unordered_map<T, T> parent;
	// Se os vertices fossem int eu poderia usar o rank como um valor negativo no proprio parent
	std::unordered_map<T, int> rank;

	size_t sets = 0;

public:

	size_t numberOfSets() { return sets; }

	void insert(T vertex) {
		parent[vertex] = vertex;
		rank[vertex] = 0;
		sets++;
	}

	bool connected(T u, T v) { return find(u) == find(v); }

	T find(T vertex) { // Como fazer iterativamente?

		if (parent[vertex] != vertex) {
			// return find(parent[vertex]) // Sem path compression
			parent[vertex] = find(parent[vertex]); // Path compression
		}

		return parent[vertex];
	}

	void join(T u, T v) {

		// parent[find(v)] = find(u); // Sem join por rank

		T rootU = find(u), rootV = find(v);

		if (rootU == rootV) return;

		sets--;

		if (rank[rootU] > rank[rootV]) {
			parent[rootV] = rootU;
		}

		else if (rank[rootU] < rank[rootV]) {
			parent[rootU] = rootV;
		}

		else {
			parent[rootV] = rootU;
			rank[rootU]++;
		}
	}
};
//
// Graph kruskal(const Graph& G) {
//
// 	/*G.CloneEmpty()*/
// 	/*G.CloneStructure()*/
// 	/*G.CloneDT()*/
// 	/*G.CloneDataStructure()*/
//
// 	Graph mst = GraphBuilder()
// 	.dataStructure(Graph::FastAdjacencyList)
// 	.weighted()
// 	.build();
//
// 	LinearList<Edge> sortedEdges = G.edges();
// 	sortedEdges.sort();
//
// 	UnionFind<Vertex> unionFind;
//
// 	for (const Vertex& v : G.vertices()) {
// 		unionFind.insert(v);
// 	}
//
// 	int i = 0;
//
// 	while (unionFind.numberOfSets() > 1) {
//
// 		const Edge& e = sortedEdges[i++];
//
// 		if (!unionFind.connected(e.u, e.v)) {
// 			unionFind.join(e.u, e.v);
// 			mst.addEdge(e);
// 		}
// 	}
//
// 	return mst;
// }
//
void testFastAdjacencyList() {

	Graph g = GraphBuilder()
		.weighted()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	// Test graph initialization
	assert(g.n == 0); // Ensure the graph has the correct number of vertices
	assert(g.edges().size() == 0); // Graph should have no edges initially

	// Test adding edges
	g.addEdge(0, 1, 10.5);
	g.addEdge(1, 2, 20.5);

	// cout << g.edges() << endl;

	assert(g.edges().size() == 2); // Two edges should exist
	assert(g.hasEdge(0, 1));
	assert(g.hasEdge(1, 2));
	assert(!g.hasEdge(0, 2)); // Edge does not exist

	// Test edge weights
	assert(g.getEdge(0, 1).weight == 10.5f);
	assert(g.getEdge(1, 2).weight == 20.5f);

	// // Test exporting graph (requires Graphviz installed)
	// try {
	//     g.export_to("test_graph");
	//     cout << "Graph exported successfully." << endl;
	// } catch (const runtime_error& e) {
	//     cout << "Failed to export graph: " << e.what() << endl;
	// }

	// Test cloning
	Graph gClone = g;
	assert(gClone.n == g.n); // Ensure cloned graph has the same number of vertices
	assert(gClone.edges().size() == g.edges().size()); // Ensure edges are cloned

	// Test modifying cloned graph
	gClone.addEdge(2, 3, 15.0);
	assert(gClone.edges().size() == 3); // Additional edge should exist in cloned graph
	assert(g.edges().size() == 2); // Original graph should remain unchanged

	cout << g << endl;

	// Test unweighted graph
	Graph gUnweighted = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	gUnweighted.addEdge(0, 1);

	assert(gUnweighted.hasEdge(0, 1));
	assert(gUnweighted.hasEdge(1, 0)); // Undirected graph

	try {
		gUnweighted.addEdge(2, 3, 5.0); // Should throw an error
		assert(false); // Should not reach this point
	} catch (const runtime_error& e) {
		assert(string(e.what()) == "You should not pass the weight of the edge");
	}

    cout << "All Graph tests passed!" << endl;
}

void speedTest() {

	{
		Graph G = GraphBuilder()
			.dataStructure(Graph::FastAdjacencyList)
		.build();

		const size_t NUM_VERTICES = 10000; // Number of vertices

		Timer timer;

		std::cout << "Testing the speed...\n";
		timer.start();

		G.addVertex(0);

		for (size_t i = 1; i < NUM_VERTICES; ++i) {

			G.addVertex(i);

			// size_t NUM_EDGES = ((i * i - i) / (( i + 1 ) / 2));
			size_t NUM_EDGES = i;
			// cout << "NUM_EDGES: " << NUM_EDGES << endl;

			// Add edges
			for (size_t j = 0; j < NUM_EDGES; ++j) {
				size_t u = rand() % i;
				size_t v = rand() % i;
				G.addEdge(u, v);
			}
		}

		timer.stop();
		std::cout << "Time elapsed: " << timer << " ms\n";
	}

	{
		Graph G = GraphBuilder()
			.dataStructure(Graph::AdjacencyList)
		.build();

		const size_t NUM_VERTICES = 10000; // Number of vertices

		Timer timer;

		std::cout << "Testing the speed on the fast version...\n";
		timer.start();

		G.addVertex(0);

		for (size_t i = 1; i < NUM_VERTICES; ++i) {

			G.addVertex(i);

			// size_t NUM_EDGES = ((i * i - i) / (( i + 1 ) / 2));
			size_t NUM_EDGES = i;
			// cout << "NUM_EDGES: " << NUM_EDGES << endl;
			// cout << "Density: " << G.density() << endl;

			// Add edges
			for (size_t j = 0; j < NUM_EDGES; ++j) {
				size_t u = rand() % i;
				size_t v = rand() % i;
				G.addEdge(u, v);
			}
		}

		timer.stop();
		std::cout << "Time elapsed: " << timer << " ms\n";
	}
}

int main() {

	testFastAdjacencyList();

	// speedTest();

	// cout << kruskal(G) << endl;

    return 0;
}

#include <iostream>
#include <unordered_map>

using namespace std;

#include "Graph.hpp"
#include "GraphBuilder.hpp"
#include "Edge.hpp"

#include "../DataStructures/include/list/linearList.hpp"

// clear && g++ main.cc -std=c++20 && ./a.out

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

Graph kruskal(const Graph& G) {

	/*G.CloneEmpty()*/
	/*G.CloneStructure()*/
	/*G.CloneDT()*/
	/*G.CloneDataStructure()*/

	Graph mst = GraphBuilder()
	.dataStructure(Graph::AdjacencyMatrix)
	.weighted()
	.build();

	LinearList<Edge> sortedEdges = G.edges();
	sortedEdges.sort();

	UnionFind<Vertex> unionFind;

	for (const Vertex& v : G.vertices()) {
		unionFind.insert(v);
	}

	int i = 0;

	while (unionFind.numberOfSets() > 1) {

		const Edge& e = sortedEdges[i++];

		if (!unionFind.connected(e.u, e.v)) {
			unionFind.join(e.u, e.v);
			mst.addEdge(e);
		}
	}

	return mst;
}

int main() {

	// TODO: Fazer a class Graph de tal forma que não seja necessário definir o N, toda estrutura deve ser capaz de crescer

	Graph G = GraphBuilder()
	// .directed()
	.weighted()
	.dataStructure(Graph::AdjacencyMatrix)
	.build();

	G.addEdge(0, 1, 1);
	G.addEdge(0, 2, 2);
	G.addEdge(0, 3, 3);
	G.addEdge(0, 4, 4);
	G.addEdge(3, 4, 1);

	cout << G << endl;

	cout << "---------------------" << endl;

	// cout << kruskal(G) << endl;

}

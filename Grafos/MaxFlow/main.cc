#include <iostream>
#include <algorithm>

#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"
#include "../DataStructures/utils/Pair.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"

using namespace std;

using Path = LinearList<Edge>;

// clear && g++ main.cc -std=c++20 && ./a.out

Path buildPath(const Vertex& s, const Vertex& t, LinearList<Pair<Vertex, float>>& predecessor) {

	Path path;

	Vertex v = t;

	if (predecessor[t].first == -1) return {};

	while (v != s) {

		auto [u, w] = predecessor[v];

		path.push_front({ u, v, w });
		v = predecessor[v].first;
	}

	return path;
}

Path DFS(const Vertex& s, const Vertex& t, const Graph& G) {

	LinkedStack<Vertex> stack(s);
	LinearList<Pair<Vertex, float>> predecessor(G.n, {-1, 0});
	predecessor[s] = { s, 0 };

	while (!stack.empty()) {
		
		const Vertex& u = stack.pop();
		if (u == t) break;
		
		for (auto [v, w] : G.neighbors(u)) {
			if (predecessor[v].first == -1) {
				stack.push(v);
				predecessor[v] = { u, w };
			}
		}
	}

	return buildPath(s, t, predecessor);
}

Path BFS(const Vertex& s, const Vertex& t, const Graph& G) {

	LinkedQueue<Vertex> queue(s);
	LinearList<Pair<Vertex, float>> predecessor(G.n, {-1, 0});
	predecessor[s] = { s, 0 };

	while (!queue.empty()) {
		
		const Vertex& u = queue.pop();
		if (u == t) break;
		
		for (auto [v, w] : G.neighbors(u)) {
			if (predecessor[v].first == -1) {
				queue.push(v);
				predecessor[v] = { u, w };
			}
		}
	}

	return buildPath(s, t, predecessor);
}

float Bottleneck(Path& P) {

	float bottleneck = P[0].weight;

	for (const Edge& e : P) {
		bottleneck = std::min(bottleneck, e.weight);
	}

	return bottleneck;
}

Graph CreateResidualGraph(Matrix<int>& flow, const Graph& G) {

	Graph gf = G.cloneDataStructure(G.n);
	float newCapacity;

	for (const Edge& e : G.edges()) {

		newCapacity = e.weight - flow[e.u][e.v];

		if (newCapacity > 0) {
			gf.addEdge({ e.u, e.v, newCapacity });
		}

		newCapacity = flow[e.u][e.v];

		if (newCapacity > 0) {
			gf.addEdge({ e.v, e.u, newCapacity });
		}
	}

	return gf;
}

float FordFulkerson(const Vertex& s, const Vertex& t, auto FindPath, const Graph& G) {

	Matrix<int> flow(G.n, G.n);

	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			flow[i][j] = 0;
		}
	}

	int i = 0;

	Graph gf = CreateResidualGraph(flow, G);
	gf.export_to(format("images/teste{}", i++), "circo");

	float b, maxFlow = 0;

	Path P;

	while (!(P = FindPath(s, t, gf)).empty()) {

		maxFlow += b = Bottleneck(P); 

		for (Edge& e : P) {

			if (G.hasEdge(e)) {
				flow[e.u][e.v] += b;
			}

			else flow[e.v][e.u] -= b;
		}

		gf = CreateResidualGraph(flow, G);
		gf.export_to(format("images/teste{}", i++), "circo");
	}

	return maxFlow;
}

int main() {

	// Preciso pensar na estrutura de dados, lista com vertices de entrada?
	Graph G = GraphBuilder()
		.directed()
		.weighted()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	G.addEdge(0, 1, 4);
	G.addEdge(0, 2, 4);
	G.addEdge(0, 3, 7);
	G.addEdge(1, 2, 7);
	G.addEdge(1, 5, 9);
	G.addEdge(2, 4, 7);
	G.addEdge(3, 4, 7);
	G.addEdge(4, 5, 12);

	// G.addEdge(0, 1, 20);
	// G.addEdge(0, 2, 10);
	// G.addEdge(1, 2, 30);
	// G.addEdge(1, 3, 10);
	// G.addEdge(2, 3, 20);

	// G.addEdge(0, 1, 100);
	// G.addEdge(0, 2, 100);
	// G.addEdge(1, 2, 1);
	// G.addEdge(1, 3, 100);
	// G.addEdge(2, 3, 100);

	float flow = FordFulkerson(0, 5, DFS, G);

	cout << "Flow: " << flow << endl;

	cout << "Density: " << G.density() << endl;

	return 0;
}

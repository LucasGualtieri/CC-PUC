// #include <iostream>

#include "../../../PAA-TP01/DataStructures/include/graph/Graph.hpp"
#include "../../../PAA-TP01/DataStructures/include/graph/GraphBuilder.hpp"
#include <limits>
// #include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"

// clear && g++ -std=c++23 dijkstra.cpp && ./a.out

using namespace std;

const float infinity = numeric_limits<float>::infinity();

Vertex argmin(LinearList<float> D, LinearList<Vertex> S) {

	Vertex arg;
	float min = infinity;

	for (Vertex v : S) {
		if (D[v] < min) {
			min = D[v];
			arg = v;
		}
	}

	return arg;
}

LinearList<float> dijkstra(Vertex x, Graph G) {

	LinearList<float> D(G.n, 0);

	for (Vertex v : G.vertices()) {
		D[v] = infinity;
	}

	D[x] = 0;

	LinearList<Vertex> S = G.vertices();

	while (!S.empty()) {

		Vertex u = argmin(D, S);
		S.remove(u);

		for (auto [v, peso] : G.edgesOf(u)) {

			if (/* S.contains(v) &&*/ D[v] > D[u] + peso) {
				D[v] = D[u] + peso;
				S += v;
			}
		}
	}

	return D;
}

int main() {

	Graph G = GraphBuilder()
		.weighted()
		.directed()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	for (Vertex v = 0; v < 7; v++) {
		G.addVertex(v);
	}

	G.addEdge({0, 1, 1.0f});
	G.addEdge({1, 2, 2.0f});
	G.addEdge({1, 4, 1.0f});
	G.addEdge({2, 3, 2.0f});
	G.addEdge({3, 5, 2.0f});
	G.addEdge({5, 4, -10.0f});
	G.addEdge({4, 6, 1.0f});

	// G.export_to("graph");

	LinearList<float> distancias = dijkstra(0, G);

	cout << "  ";
	for (char a = 'a'; a <= 'g'; a++) {
		cout << a << ", ";
	}

	cout << endl << distancias << endl;

	return 0;
}

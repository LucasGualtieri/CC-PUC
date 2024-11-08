#include <iostream>

#include "Graph.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/Pair.hpp"

using namespace std;

using Edge = Pair<int, int>;
using Path = LinearList<Edge>;
#define edge auto

void UpdateResidualGraph(const Graph& gf, const Graph& G, Matrix<int>& flow) {

	/*edge [u, v] = e;*/
	/**/
	/*if (G.hasEdge(e)) {*/
	/*	return G.capacity(e) - flow[u][v];*/
	/*}*/
	/**/
	/*else return flow[u][v];*/
}

int Bottleneck(Path& P, const Graph& gf, Matrix<int>& flow) {

	int bottleneck = 0;

	for (edge [u, v] : P) {
		bottleneck = std::min(bottleneck, gf.capacity({u, v}));
	}

	return bottleneck;
}

int FordFulkerson(int s, int t, auto FindPath, Graph G) {

	Matrix<int> flow(G.n, G.n);

	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			flow[i][j] = 0;
		}
	}

	Graph gf(G); // Preciso pensar na estrutura de dados, lista com vertices de entrada?

	int b, maxFlow = 0;

	Path P;

	while (!(P = FindPath(s, t, gf)).empty()) {
		
		maxFlow += b = Bottleneck(P, G, flow); 

		for (edge [u, v] : P) {

			if (G.hasEdge({u, v})) {
				flow[u][v] += b;
			}

			else flow[v][u] -= b;
		}

		UpdateResidualGraph(gf, G, flow);
	}

	return maxFlow;
}

Path DFS(int s, int t, Graph gf) {

	return {};
}

int main() {

	Graph G = {
		{0, {{1, 0}}},
	};

	cout << G << endl;

	int flow = FordFulkerson(0, 1, DFS, G);

	cout << "Flow: " << flow << endl;

	return 0;
}

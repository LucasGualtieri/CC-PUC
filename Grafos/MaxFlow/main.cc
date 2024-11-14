#include <iostream>
#include <algorithm>
#include <limits>

#include "../Teste/Graph.hpp"
#include "../Teste/GraphBuilder.hpp"
#include "../DataStructures/include/Pair.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"

using namespace std;

using Path = LinearList<Edge>;

Path DFS(const Vertex& s, const Vertex& t, const Graph& G) {

	LinkedStack<Vertex> stack(s);
	LinearList<Pair<Vertex, float>> predecessor(G.n, {-1, 0});
	predecessor[s] = { s, 0 };

	while (!stack.empty()) {
		
		const Vertex& u = stack.pop();
		if (u == t) break;
		
		for (auto [v, w] : G.kneighbors(u)) {
			if (predecessor[v].first == -1) {
				stack.push(v);
				predecessor[v] = { u, w };
			}
		}
	}

	Path path;

	Vertex v = t;

	while (v != s) {

		auto [u, w] = predecessor[v];

		path.push_front({ u, v, w });
		v = predecessor[v].first;
	}

	return path;
}

Path BFS(const Vertex& s, const Vertex& t, const Graph& G) {

	LinkedQueue<Vertex> queue(s);
	LinearList<Pair<Vertex, float>> predecessor(G.n, {-1, 0});
	predecessor[s] = { s, 0 };

	while (!queue.empty()) {
		
		const Vertex& u = queue.pop();
		if (u == t) break;
		
		for (auto [v, w] : G.kneighbors(u)) {
			if (predecessor[v].first == -1) {
				queue.push(v);
				predecessor[v] = { u, w };
			}
		}
	}

	Path path;

	Vertex v = t;

	while (v != s) {

		auto [u, w] = predecessor[v];

		path.push_front({ u, v, w });
		v = predecessor[v].first;
	}

	return path;
}

void UpdateResidualGraph(const Graph& gf, const Graph& G, Matrix<int>& flow) {

	// edge [u, v] = e;
	//
	// if (G.hasEdge(e)) {
	// 	return G.capacity(e) - flow[u][v];
	// }
	//
	// else return flow[u][v];
}

float Bottleneck(Path& P, Matrix<int>& flow, const Graph& gf) {

	float bottleneck = std::numeric_limits<float>::infinity();

	for (const Edge& e : P) {
		bottleneck = std::min(bottleneck, e.weight);
	}

	return bottleneck;
}

int FordFulkerson(const Vertex& s, const Vertex& t, auto FindPath, const Graph& G) {

	Matrix<int> flow(G.n, G.n);

	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			flow[i][j] = 0;
		}
	}

	Graph gf(G); // Preciso pensar na estrutura de dados, lista com vertices de entrada?

	float b, maxFlow = 0;

	Path P;

	while (!(P = FindPath(s, t, gf)).empty()) {

		maxFlow += b = Bottleneck(P, flow, gf); 

		for (Edge& e : P) {

			if (G.hasEdge(e)) {
				flow[e.u][e.v] += b;
			}

			else flow[e.v][e.u] -= b;
		}

		UpdateResidualGraph(gf, G, flow);
	}

	return maxFlow;
}

int main() {

	Graph G = GraphBuilder()
	.directed()
	.weighted()
	.dataStructure(Graph::AdjacencyMatrix)
	.build();

	G.addEdge(0, 1, 2);
	G.addEdge(1, 2, 3);
	G.addEdge(2, 3, 4);
	G.addEdge(3, 4, 5);

	cout << G << endl;

	cout << DFS(0, 4, G) << endl;

	// float flow = FordFulkerson(0, 4, DFS, G);
	
	// cout << "Flow: " << flow << endl;

	return 0;
}

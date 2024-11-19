#include <iostream>
#include <algorithm>
#include <ostream>
#include <sstream>

#include "timer.hpp"
#include "../Teste/Graph.hpp"
#include "../Teste/GraphBuilder.hpp"
#include "../DataStructures/include/Pair.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"

using namespace std;

using Path = LinearList<Edge>;

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
		
		for (auto [v, w] : G.kneighbors(u)) {
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
		
		for (auto [v, w] : G.kneighbors(u)) {
			if (predecessor[v].first == -1) {
				queue.push(v);
				predecessor[v] = { u, w };
			}
		}
	}

	return buildPath(s, t, predecessor);
}

Path MaxMin(const Vertex& s, const Vertex& t, const Graph& G) { return {}; }

float Bottleneck(Path& P, const Graph& gf) {

	float bottleneck = P[0].weight;

	for (const Edge& e : P) {
		bottleneck = std::min(bottleneck, e.weight);
	}

	return bottleneck;
}

Graph CreateResidualGraph(Matrix<int>& flow, const Graph& G) {

	Graph gf = G.cloneDataStructure(G.n);
	float newWeight;

	for (const Edge& e : G.edges()) {

		newWeight = e.weight - flow[e.u][e.v];

		if (newWeight > 0) {
			gf.addEdge({ e.u, e.v, newWeight });
		}

		newWeight = flow[e.u][e.v];

		if (newWeight > 0) {
			gf.addEdge({ e.v, e.u, newWeight });
		}
	}

	return gf;
}

string FordFulkerson(const Vertex& s, const Vertex& t, auto FindPath, const Graph& G) {

	Timer totalTime;
	totalTime.start();

	Matrix<int> flow(G.n, G.n);

	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			flow[i][j] = 0;
		}
	}

	int i = 0, pathsFound = 0;

	Graph gf = CreateResidualGraph(flow, G);

	float avgTimePerPathFind = 0, b, maxFlow = 0;

	Path P;

	do {

		Timer timer;
		timer.start();
		P = FindPath(s, t, gf);
		timer.stop();

		// cout << "P: " << P << endl;

		avgTimePerPathFind += timer.result();

		if (P.empty()) break;

		pathsFound++;

		maxFlow += b = Bottleneck(P, gf); 

		for (Edge& e : P) {

			if (G.hasEdge(e)) {
				flow[e.u][e.v] += b;
			}

			else flow[e.v][e.u] -= b;
		}

		gf = CreateResidualGraph(flow, G);

	} while (!P.empty());

	totalTime.stop();

	ostringstream os;

	os << "{" << endl;
	os << "    " << format("Flow: {}", maxFlow) << endl;
	os << "    " << format("Time Elapsed: {:.4f}ms", totalTime.result()) << endl;
	os << "    " << format("Number of paths found: {}", pathsFound) << endl;
	os << "    " << format("Average time per PathFind(): {:.4f}ms", (avgTimePerPathFind / pathsFound)) << endl;
	os << "}" << endl;

	return os.str();
}

int main() {

	Graph G = GraphBuilder()
		.directed()
		.weighted()
		.dataStructure(Graph::AdjacencyMatrix)
	.build();

	G.addEdge(0, 1, 100);
	G.addEdge(0, 2, 100);
	G.addEdge(1, 2, 1);
	G.addEdge(1, 3, 100);
	G.addEdge(2, 3, 100);

	string stats;

	for (;;) {

	  stats = FordFulkerson(0, 3, DFS, G);
	  cout << "Stats " << stats << endl;

	  stats = FordFulkerson(0, 3, BFS, G);
	  cout << "Stats " << stats << endl;

	  stats = FordFulkerson(0, 3, MaxMin, G);
	  cout << "Stats " << stats << endl;

	}


	return 0;
}

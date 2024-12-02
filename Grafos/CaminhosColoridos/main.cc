#include <ctime>
#include <iostream>
#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

LinearList<Vertex> BFS(const Vertex& s, const Vertex& t, const Graph& G) {

	LinkedQueue<Vertex> q = {s};

	LinearList<Vertex> predecessors(G.n, -1);

	while(!q.empty()) {

		Vertex u = q.pop();

		if (u == t) break;

		for (Vertex& v : G.neighbors(u, 0)) {
			if (predecessors[v] == -1) {
				q.push(v);
				predecessors[v] = u;
			}
		}
	}

	LinearList<Vertex> path;

	Vertex aux = t;

	if (predecessors[aux] != -1) {

		while (aux != s) {
			path.push_front(aux);
			aux = predecessors[aux];
		}

		path.push_front(aux);
	}

	return path;
}

void colorPath(const LinearList<Vertex>& path, Graph& G) {

	if (path.empty()) return;

	Pair<string, string> prop = {"green", ""};

	for (Vertex i = 0; i < path.size() - 1; i++) {
		G.changeVertexProps(path[i], prop);
		G.changeEdgeProps(path[i], path[i + 1], {"green", "dashed"});
	}

	G.changeVertexProps(path[path.size() - 1], prop);
}

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)
		.directed()
	.build();
	
	{
		srand(time(0));

		const int numVertices = 30;
		const int numEdges = 50;

		for (Vertex i = 0; i < numVertices; i++) G.addVertex(i);

		// Generate random edges
		for (int i = 0; i < numEdges; i++) {

			Vertex u = rand() % numVertices;
			Vertex v = rand() % numVertices;

			if (u != v && !G.hasEdge(u, v)) {
				G.addEdge(u, v);
			}
		}
	}

	LinearList<Vertex> path = BFS(0, 29, G);

	cout << path << endl;

	colorPath(path, G);

	G.export_to("path");

	return 0;
}

// #include <iostream>

#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"
#include <unordered_set>

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

void colorMap(Graph& G) {

	LinearList<int> degree(G.n); 

	for (Vertex& v : G.vertices()) {
		degree += G.degree(v);
	}

	LinearList<Vertex> sortedVertices = G.vertices();

	sortedVertices.sort([&degree](Vertex& u, Vertex& v) {
		return degree[u] > degree[v];
	});
	
	LinearList<int> color(G.n, 0);

	for (Vertex& u : sortedVertices) {

		unordered_set<int> coresVizinhos;

		for (Vertex& v : G.neighbors(u, 0)) {
			coresVizinhos.insert(color[v]);
		}

		while (coresVizinhos.count(color[u])) color[u]++;
	}

	for (Vertex& v : G.vertices()) {
		cout << format("color[{}] = {}", v, color[v]) << endl;
	}
}

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)
	.build();

	for (int i = 0; i <= 12; i++) G.addVertex(i);

	// G.addEdge(0, 1);
	// G.addEdge(0, 2);
	// G.addEdge(0, 3);
	// G.addEdge(1, 2);

	// Funciona para o novo algoritmo
	// G.addEdge(0, 1);
	// G.addEdge(1, 2);
	// G.addEdge(1, 3);
	// G.addEdge(2, 4);

	G.addEdge(0, 12);
	G.addEdge(0, 11);
	G.addEdge(0, 10);
	G.addEdge(0, 9);
	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(2, 4);
	G.addEdge(3, 5);
	G.addEdge(4, 5);
	G.addEdge(4, 6);
	G.addEdge(4, 7);

	G.export_to("teste");

	colorMap(G);

	return 0;
}

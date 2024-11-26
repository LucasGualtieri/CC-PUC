#include <iostream>

#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

bool Clique(const Vertex& x, const LinearList<Vertex>& neighbors, const Graph& G) {

	for (const Vertex& u : neighbors) { 
		for (const Vertex& v : neighbors) { 
			if (v != u && !G.hasEdge(u, v)) { 
				return false; 
			} 
		} 
	} 

	return true;
}

LinearList<Vertex> Clique(const Graph& G) { 

	LinearList<int> degree(G.n); 

	for (Vertex& v : G.vertices()) {
		degree.push_back(G.degree(v));
	}

	LinearList<Vertex> sortedVertices = G.vertices();

	sortedVertices.sort([&degree](Vertex& u, Vertex& v) {
		return degree[u] > degree[v];
	});

	for (Vertex& u : sortedVertices) {

		LinearList<Vertex> neighbors = G.neighbors(u, true);
		bool isClique = Clique(u, neighbors, G);

		if (isClique) return u + neighbors;
	}

	// This return should never be reached
	return {};
}

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)
	.build();

	// for (int i = 0; i <= 5; i++) G.addVertex(i);

	// G.addEdge(0, 1); // Condição pro K4 aparecer
	// G.addEdge(0, 2);
	// G.addEdge(0, 3);
	// G.addEdge(0, 4);
	// G.addEdge(0, 5);
	// G.addEdge(1, 2);
	// G.addEdge(1, 3);
	// G.addEdge(2, 3);

	for (int i = 0; i <= 11; i++) G.addVertex(i);

	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(11, 1); // FIX: APAGAR
	G.addEdge(0, 4);
	G.addEdge(2, 3);
	G.addEdge(2, 4);
	G.addEdge(2, 5);
	G.addEdge(3, 5);
	G.addEdge(10, 3); // FIX: APAGAR
	G.addEdge(4, 5);
	G.addEdge(4, 6);
	G.addEdge(5, 6);
	G.addEdge(5, 7);
	G.addEdge(6, 7);
	G.addEdge(7, 8);
	G.addEdge(7, 9);
	
	cout << G << endl;

	LinearList<Vertex> clique = Clique(G);
	cout << "Clique: " << clique << endl;

	return 0;
}

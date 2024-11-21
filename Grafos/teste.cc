#include <iostream>

#include "DataStructures/include/Graph/Graph.hpp"
#include "DataStructures/include/Graph/GraphBuilder.hpp"
#include "DataStructures/include/list/linearList.hpp"
#include "DataStructures/include/stack/linkedStack.hpp"

// clear && g++ teste.cc -std=c++20 && ./a.out

using namespace std;

LinearList<Vertex> DFS(const Vertex& x, const Graph& G, LinearList<bool>& descobertos) {

	LinearList<Vertex> FTD; // Fecho Transitivo Direto

	LinkedStack<Vertex> stack;
	stack.push(x);
	descobertos[x] = true;

	while (!stack.empty()) {

		Vertex u = stack.pop();
		FTD += u;

		for (auto [v, w] : G.kneighbors(u)) {
			if (!descobertos[v]) {
				stack.push(v);
				descobertos[v] = true;
			}
		}
	}

	return FTD;
}

LinearList<LinearList<Vertex>> Componentes(const Graph& G) {

	LinearList<LinearList<Vertex>> componentes;

	LinearList<bool> descobertos(G.n, false);

	for (Vertex& v : G.vertices()) {

		if (!descobertos[v]) {
			componentes += DFS(v, G, descobertos);
		}
	}

	return componentes;
}

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)
	.build();

	G.addEdge(0, 1);
	G.addVertex(2); // NOTE: Isso so e necessario por uma limitacao atual da matriz de adjancia
	G.addEdge(3, 4);
	G.addEdge(3, 5);

	// cout << G << endl;

	cout << Componentes(G) << endl;
}

#include <iostream>

using namespace std;

#include "Graph.hpp"
#include "GraphBuilder.hpp"
#include "AdjacencyMatrix.hpp"

// #include "../DataStructures/include/list/linearList.hpp"

// class Edge {
// 	int u, v, w;
// };

// clear && g++ main.cc && ./a.out

Graph kruskal(Graph& g) {

	// Graph mst;

	// for (Vertex e : g) {

	// }

	// for (Edge e : g.edges()) {

	// }
	
	return g;
}

int main() {

	// Graph g = GraphBuilder()
	// .vertices()
	// .edges()
	// .build();

	Graph g = GraphBuilder()
	.dataStructure(new AdjacencyMatrix)
	.build();

	g.foo();
}

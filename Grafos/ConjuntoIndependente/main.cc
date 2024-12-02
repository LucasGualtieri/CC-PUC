#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"

// FIX: 'using' should be pink
using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

// NOTE: the only thing difference is the saturation, might be the terminal
int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)
	.build();

	for (int i = 0; i <= 6; i++) G.addVertex(i);

	// Criando um grafo completo.
	for (int i = 0; i <= 5; i++) {
		for (int j = i + 1; j <= 6; j++) {
			G.addEdge(i, j);
		}
	}

	G.changeEdgeProps(4, 1, {"red", "dashed"});
	G.changeEdgeProps(4, 5, {"red", "dashed"});
	G.changeEdgeProps(5, 1, {"red", "dashed"});
	G.changeEdgeProps(3, 2, {"blue", "dashed"});

	G.changeVertexProps(1, {"red", ""});
	G.changeVertexProps(4, {"red", ""});
	G.changeVertexProps(5, {"red", ""});
	G.changeVertexProps(2, {"blue", ""});
	G.changeVertexProps(3, {"blue", ""});

	G.export_to("conjuntoIndependente", "circo", 1200);

	return 0;
}

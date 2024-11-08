#include <iostream>

using namespace std;

#include "Graph.hpp"
#include "GraphBuilder.hpp"
#include "AdjacencyMatrix.hpp"
#include "Edge.hpp"

// #include "../DataStructures/include/list/linearList.hpp"

// clear && g++ main.cc && ./a.out

void teste(Graph<int>& G) {

	// for (Vertex e : g) {

	// }

	for (auto e : G.edges()) {

		/*cout << e << endl;*/
	}
}

int main() {

	Graph<int> G = GraphBuilder<int>()
	.weighted().directed()
	.dataStructure(new AdjacencyMatrix<int>())
	.build();

	G.foo();

}

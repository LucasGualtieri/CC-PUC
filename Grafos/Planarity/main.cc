#include <iostream>

#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"
// #include "../DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

// if ((m > 2 * n - 4) && (m > 3 * n - 6)) return false;

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	int n = 4;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			G.addEdge(i, j);
		}
	}

	// for (int i = 5; i < n + 5; i++) {
	// 	G.addEdge(0, i);
	// }

	cout << G << endl;

	// cout << (isPlanar(G) ? "Graph is planar" : "Graph is not planar") << endl;

	// G.export_to("graph");

	return 0;
}

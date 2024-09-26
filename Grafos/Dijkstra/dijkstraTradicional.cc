#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ dijkstraTradicional.cc && ./a.out

int main() {

	Graph g = {
		{ 0, { {1, 1}, {2, 1}, {4, 4} } },
		{ 1, { {3, 3}, {4, 1} } },
		{ 2, { {4, 2}, {5, 3} } },
		{ 4, { {3, 1}, {5, 2} } },
		{ 5, { } },
	};

	cout << g << endl;

	// cout << g.DFS(0) << endl;

	cout << "Distances: " << g.dijkstra(0, 4) << endl;
}
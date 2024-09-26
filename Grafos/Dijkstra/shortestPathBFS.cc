#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ shortestPathBFS.cc && ./a.out

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

	// g.BFS(0, 3);

	cout << "ShortestPath(0, 3): " << g.BFS(0, 3) << endl;
}
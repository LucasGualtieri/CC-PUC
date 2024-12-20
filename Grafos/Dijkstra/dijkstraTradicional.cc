#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ dijkstraTradicional.cc -std=c++20 && ./a.out

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

	// cout << "BFS: " << g.BFS(0, 3) << endl;

	// cout << "Distances: " << g.dijkstra(0, 4) << endl;

	cout << "Distances: " << g.dijkstra1(0) << endl;

	cout << "Distances: " << g.dijkstra2(0) << endl;
}
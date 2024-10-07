#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ dijkstra.cc -std=c++20 && ./a.out

int main() {

	Graph g = {
		{ 0, { {1, 1}, {2, 1}, {4, 4} } },
		{ 1, { {3, 3}, {4, 1} } },
		{ 2, { {4, 2}, {5, 3} } },
		{ 4, { {3, 1}, {5, 2} } },
		{ 5, { } },
	};

	cout << g << endl;

	cout << "Distances: " << g.dijkstra(0) << endl;
}
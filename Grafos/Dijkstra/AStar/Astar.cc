#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ Astar.cc -std=c++20 && ./a.out

int main() {

	Graph g = {
		{ { 0, 0 }, { } },
		{ { 1, 3 }, { {2, 2}, {3, 2}, {4, 2} } },
		{ { 2, 2 }, { {5, 2} } },
		{ { 3, 1 }, { {5, 2} } },
		{ { 4, 2 }, { {5, 2} } },
		{ { 5, 0 }, { } },
	};


	cout << g.Astar(1, 5) << endl;

	// cout << g << endl;

}
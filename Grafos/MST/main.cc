#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

int main() {

	Graph<char> g = {
		{'A', {{'B', 1}, {'E', 1}, {'F', 2}}},
		{'B', {{'C', 3}, {'F', 7}}},
		{'C', {{'F', 4}, {'D', 8}}},
		{'D', {{'F', 2}, {'E', 1}}},
		{'E', {{'F', 3}}},
	};

	// cout << g << endl;

	// cout << "----------------------------------------------" << endl;

	g.exportGraph("normal");

	Graph<char> mst = g.generateMST('A');
	// cout << mst << endl;
	mst.exportGraph("MST");

	return 0;
}

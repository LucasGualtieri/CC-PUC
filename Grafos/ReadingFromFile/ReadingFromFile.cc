#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ ReadingFromFile.cc && ./a.out

int main() {

	Graph g("graph-test-50000.txt");

	// cout << g << endl;

	cout << g.kosaraju("dot") << endl;

	// g.export_to_graphviz("dot");
}
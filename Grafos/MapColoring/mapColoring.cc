#include <iostream>

#include "../DataStructures/include/list/linearList.hpp"
#include "GraphOtimizado.hpp"
// #include "Graph.hpp"

using namespace std;

// clear && g++ mapColoring.cc && ./a.out

int main() {

	system("python3 ScriptsPython/GenerateAdjacency.py");

	Graph g("adjacencyList.txt");

	// cout << g << endl;

	g.colorVertices();

	return 0;
}
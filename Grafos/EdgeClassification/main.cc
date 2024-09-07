#include <iostream>
#include "Graph.hpp"

using namespace std;

// clear && g++ main.cc && ./a.out

int main() {

	Graph g = {
		{ 0, { 1, 2, 3 }},
		{ 1, { 0 }}, // Loop / Aresta de retorno
		{ 2, { 1, 3 }},
		{ 4, { 3 }}
	};

	cout << g << endl;

	cout << g.BFS(0) << endl;
	cout << g.DFS(0) << endl;

	g.ClassificacaoRec();
}
#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ maiorCaminho.cc -std=c++20 && ./a.out

int main() {

	Graph g = {
		{ 0, { 1, 2 } },
		{ 1, { 3, 4 } },
		{ 2, { 5, 6 } },
		{ 3, { 9 } },
		{ 4, { 5 } },
		{ 5, {} },
		{ 6, { 7 } },
		{ 7, {} },
		{ 8, { 7 } },
		{ 9, { 4 } },
		{ 10, { 3 } }
	};

	cout << g << endl;

	cout << "Maior caminho: " << g.maiorCaminho(0) << endl;
}
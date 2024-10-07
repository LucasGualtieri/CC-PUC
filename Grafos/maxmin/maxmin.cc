#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ maxmin.cc -std=c++20 && ./a.out

int main() {

	// Lista de adjacencia de cada vértice, com os vizinhos: {vertice, capacidade}
	// Graph g = {
	// 	{0, {{3,5}, {2,4}, {1,1}}},
	// 	{1, {{4,3}}},
	// 	{2, {{5,5}}},
	// 	{3, {{2,5}, {5,3}}},
	// 	{4, {{5,4}}},
	// 	{5, {}},
	// };

	Graph g = {
		{0, {{1,5}, {2,1}}},
		{1, {{3,3}, {4,6}}},
		{4, {{2,4}}},
	};

	// Graph g = {
	// 	{0, {{1,1}, {2,3}, {3,4}}},
	// 	{1, {{4,3}}},
	// 	{2, {{5,2}}},
	// 	{3, {{5,8}}},
	// 	{4, {{5,4}}},
	// 	{5, {}},
	// };

	cout << g << endl;

	// cout << g.maxminMultiple(0, 5) << endl;
	cout << g.maxmin(0, 2) << endl;
	cout << g.minmax(0, 2) << endl;
}
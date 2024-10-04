#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ maxmin.cc -std=c++20 && ./a.out

int main() {

	Graph g = {
		{0, {{3,5}, {2,4}, {1,1}}},
		{1, {{4,3}}},
		{2, {{5,5}}},
		{3, {{2,5}, {5,3}}},
		{4, {{5,4}}},
		{5, {}},
	};

	// Graph g = {
	// 	{0, {{1,1}, {2,3}, {3,4}}},
	// 	{1, {{4,3}}},
	// 	{2, {{5,2}}},
	// 	{3, {{5,8}}},
	// 	{4, {{5,4}}},
	// 	{5, {}},
	// };

	// cout << g << endl;

	// cout << g.maxminMultiple(0, 5) << endl;
	cout << g.maxmin(0, 5) << endl;
	cout << g.minmax(0, 5) << endl;
}
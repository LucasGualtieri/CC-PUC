#include <iostream>

#include "Graph.hpp"

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

int main() {

	Graph<char> g = {
		{'A', {{'B', 1}, {'E', 2}, {'F', 3}}},
		{'B', {{'C', 4}, {'F', 5}}},
		{'C', {{'F', 6}, {'D', 7}}},
		{'D', {{'F', 8}, {'E', 9}, {'G', 13}}},
		{'E', {{'F', 10}}},
		{'F', {{'I', 11}}},
		{'G', {{'C', 0}}},
		{'I', {{'D', 12}}},
	};

	// Graph<char> g = {
	// 	{'A', {{'B', 1}, {'E', 1}, {'F', 2}}},
	// 	{'B', {{'C', 3}, {'F', 7}}},
	// 	{'C', {{'F', 4}, {'D', 8}}},
	// 	{'D', {{'F', 2}, {'E', 1}}},
	// 	{'E', {{'F', 3}}},
	// };

	cout << g << endl;

	cout << "----------------------------------------------" << endl;

	g.exportGraph("normal");

	Graph<char> mst = g.prim('A');
	cout << mst << endl;
	mst.exportGraph("prim");

	cout << "----------------------------------------------" << endl;

	mst = g.kruskal();
	cout << mst << endl;
	mst.exportGraph("kruskal");

	return 0;
}

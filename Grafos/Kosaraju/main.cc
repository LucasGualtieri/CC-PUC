#include <iostream>
#include "Graph.hpp"

using namespace std;

// clear && g++ main.cc && ./a.out

int main() {

	// Graph g = {
	// 	{ 0, { 1 }},
	// 	{ 1, { 2, 4 }},
	// 	{ 2, { 3 }},
	// 	{ 3, { 0 }},
	// 	{ 4, { 5 }},
	// 	{ 5, { 6 }},
	// 	{ 6, { 4 }},
	// 	// { 7, {}},
	// };

	Graph g = {
		{ 0, { 1 }},
		{ 1, { 3 }},
		{ 2, { 1, 3, 4 }},
		{ 3, { 0, 4, 5 }},
		{ 4, { 5, 6, 7 }},
		{ 5, { 4 }},
		{ 6, { 7 }},
		{ 7, {}},
		{ 8, { 5, 9, }},
		{ 9, { 5, 7, 10, 11, }},
		{ 10, { 6, 8, 11, 13 }},
		{ 11, { 8, 9 }},
		{ 12, { 10 }},
		{ 13, { 12 }},
		// { 14, { }}
	};

	cout << g << endl;

	Graph t = g.transpose();
	cout << t << endl;

	cout << "Componentes: " << g.kosaraju("dot") << endl;
}
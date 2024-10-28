#include <iostream>

#include "GraphProof.hpp"
#include "timer.hpp"
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ Porcentagens.cc -std=c++20 && ./a.out

float log(float n, float base) { return log(n) / log(base); }

int main() {

	Graph g = {
		{0, {{1, 1}, {2, 0.5}}},
		{1, {{2, 1}}},
		{2, {{1, 0.25}}},
	};

	int a = 2;

	for (int i = 0; i < g.m; i++) {
		g.W[i] = log(g.W[i], a);
	}

	// cout << g << endl;

	LinearList<float> probabilidades = g.dijkstra(0);
	// LinearList<float> probabilidades = g.dijkstraMax(0);

	cout << probabilidades << endl;

	for (int i = 0; i < g.n; i++) {
		probabilidades[i] = pow(a, probabilidades[i]);
	}

	cout << probabilidades << endl;

	for (int i = 0; i < g.m; i++) {
		g.W[i] = pow(a, g.W[i]);
	}

	// cout << g << endl;
}
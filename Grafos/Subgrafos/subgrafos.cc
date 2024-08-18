#include <cmath>
#include <iostream>
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ subgrafos.cc && ./a.out

typedef LinearList<int> Vertices;
typedef LinearList<LinearList<int>> Arestas;

size_t factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

size_t subsetCombinations(int i, int n) {
	return factorial(n) / (factorial(i) * factorial(n - i));
}

template <typename T>
LinearList<LinearList<T>> PowerSet(LinearList<T> set, size_t min = 0, size_t max = 0x7fffffff) {

	if (max == 0x7fffffff) max = set.size();

	int N = set.size();

	LinearList<LinearList<T>> powerSet(pow(2, N));

	for (int i = min; i <= max; i++) {

		LinearList<T> subset(i);

		int currentIndex = 0;

		size_t combinations = subsetCombinations(i, N);

		for (int j = 0; j < combinations; j++) {

			while (subset.size() < i) {

				if (currentIndex >= N) {
					if (subset.back() == set.back()) subset.pop_back();
					currentIndex = set.indexOf(subset.pop_back()) + 1;
				}

				subset.push_back(set[currentIndex++]);
			}

			powerSet.push_back(subset);

			if (!subset.empty()) subset.pop_back();
		}
	}

	return powerSet;
}

size_t subgraphs(int N) {

	size_t number = 0;

	for (int i = 1; i <= N; i++) {
		number += pow(2, (i * i - i) / 2) * subsetCombinations(i, N);
	}

	return number;
}

int main() {

	int N;

	cout << "Digite o |V| do grafo completo: ";
	cin >> N;

	LinearList<int> set(1, N);

	int i = 1;

	cout << endl;

	for (Vertices V : PowerSet(set, 1)) {

		Arestas edgesSet = PowerSet(V, 2, 2);

		for (Arestas E : PowerSet(edgesSet)) {

			cout << "Subgrafo " << i++ << ": " << endl;
			cout << "V = " << V << endl;
			cout << "E = " << E << endl << endl;
		}
	}

	cout << "O número de subgrafos gerados foi: " << subgraphs(N) << endl;
}
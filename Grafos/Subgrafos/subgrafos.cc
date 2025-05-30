#include <cmath>
#include <iostream>
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ subgrafos.cc -std=c++20 && ./a.out

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
		number += subsetCombinations(i, N) * pow(2, (i * i - i) / 2);
	}

	return number;
}

int main() {

	int N;

	cout << "Digite o |V| do grafo completo: ";
	cin >> N;

	LinearList<int> set(N);
	for (int i = 1; i <= N; i++) set.push_back(i);

	int i = 1;

	cout << endl << subgraphs(N) << " subgrafos serão gerados." << endl;

	for (Vertices V : PowerSet(set, 1)) {

		Arestas edgesSet = PowerSet(V, 2, 2);

		for (Arestas E : PowerSet(edgesSet)) {

			cout << endl << "Subgrafo " << i++ << ": " << endl;
			cout << "V = " << V << endl;
			cout << "E = " << E << endl;
		}
	}
}

// Solução MUITO parecida com a nossa, porém mais eficiente por não precisar de fazer comparação entre conjuntos.
/* void powerSet(string str, int index = -1, string curr = "") {

	int n = str.length();

	// base case
	if (index == n) return;

	// First print current subset, or add it to a bigger set.
	cout << curr << "\n";

	// Try appending remaining characters to current subset
	for (int i = index + 1; i < n; i++) {

		curr += str[i];
		powerSet(str, i, curr);

		curr.erase(curr.size() - 1);
	}

	return;
} */

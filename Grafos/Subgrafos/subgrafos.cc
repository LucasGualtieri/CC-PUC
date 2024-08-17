#include <cmath>
#include <iostream>
#include "../DataStructures/include/list/linearList.hpp"
// #include <LinearList>

using namespace std;

// clear && g++ subgrafos.cc && ./a.out

int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

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

		int setinha = 0;

		size_t combinations = subsetCombinations(i, N);

		for (int j = 0; j < combinations; j++) {

			while (subset.size() < i) {

				if (setinha >= N) {
					// O acesso do .back() é O(1) mas a comparação entre sets pode ser custosa...
					if (subset.back() == set.back()) subset.pop_back();
					setinha = set.indexOf(subset.pop_back()) + 1;
				}

				subset.push_back(set[setinha++]);
			}

			powerSet.push_back(subset);

			// foi necessario essa condição, mas não lembro exatamente o pq
			if (!subset.empty()) subset.pop_back();
		}
	}

	return powerSet;
}

typedef LinearList<int> Vertices;
typedef LinearList<LinearList<int>> Arestas;

int main() {

	// Além disto, informe o número de subgrafos gerados.
	// fazer a função que calcula o somatório 2^(...) * np

	int N;

	cout << "Digite o tamanho do grafo completo: ";
	cin >> N;

	LinearList<int> set(1, N);

	int i = 1;

	for (Vertices V : PowerSet(set, 1)) {

		Arestas edgesSet = PowerSet(V, 2, 2);

		for (Arestas E : PowerSet(edgesSet)) {

			cout << "Subgrafo " << i++ << ": " << endl;
			cout << "V = " << V << endl;
			cout << "E = " << E << endl;
		}
	}
}
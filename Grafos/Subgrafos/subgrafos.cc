#include <cmath>
#include <iostream>
#include "../DataStructures/include/list/linearList.hpp"
// #include <LinearList>

using namespace std;

// clear && g++ subgrafos.cc && ./a.out

int fat(int n) { return n <= 1 ? 1 : n * fat(n - 1); }

int np(int i, int n) {
	return (fat(n)) / (fat(i) * (fat(n - i)));
}

template <typename T>
LinearList<LinearList<T>> gerarConjuntoPotencia(LinearList<T> conjunto, size_t min = 0, size_t max = 0x7fffffff) {

	if (max == 0x7fffffff) max = conjunto.size();

	int N = conjunto.size();

	LinearList<LinearList<T>> conjuntoPotencia(pow(2, N));

	for (int i = min; i <= max; i++) { // i determina o tamanho do agrupamento

		LinearList<T> subconjunto(i);

		int setinha = 0;

		int NP = np(i, N); // NP determina a quantidade de agrupamentos

		for (int j = 0; j < NP; j++) {

			while (subconjunto.size() < i) {

				if (setinha >= N) {
					if (subconjunto.back() == conjunto.back()) subconjunto.pop_back();
					setinha = conjunto.indexOf(subconjunto.pop_back()) + 1;
				}

				subconjunto.push_back(conjunto[setinha++]);
			}

			conjuntoPotencia.push_back(subconjunto);

			if (!subconjunto.empty()) subconjunto.pop_back();
		}
	}

	return conjuntoPotencia;
}

int main() {

	const int N = 3;

	LinearList<int> V(1, N);

	int i = 1;

	for (LinearList<int> v : gerarConjuntoPotencia(V, 1)) {


		LinearList<LinearList<int>> arestas = gerarConjuntoPotencia(v, 2, 2);

		LinearList<LinearList<LinearList<int>>> cpArestas = gerarConjuntoPotencia(arestas);

		for (LinearList<LinearList<int>> aresta : cpArestas) {

			cout << "Subgrafo " << i++ << ": " << endl;
			cout << "V = " << v << endl;
			cout << "E = " << aresta << endl;
		}
	}
}
#include <format>
#include <iostream>
#include <limits>
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ -std=c++23 LS.cpp && ./a.out

int foo(const LinearList<int>& seq) {

	size_t n = seq.size();
	LinearList<bool> visitados(n, false);

	int maiorSubseq = numeric_limits<int>::min();

	for (int i = 0; i < n - 1; i++) {

		if (visitados[i]) continue;

		int numeroDaVez = seq[i], contador = 1;
		cout << format("NumeroDaVez: {}", numeroDaVez) << endl;

		for (int j = i + 1; j < n; j++) {

			if (seq[j] >= numeroDaVez) {
				cout << format("seq[j]: {}", seq[j]) << endl;
				contador++;
				maiorSubseq = max(maiorSubseq, contador);
				visitados[j] = true;
				numeroDaVez = seq[j];
			}
		}
		cout << "----------------" << endl;
	}

	return maiorSubseq;
}

int main() {

	LinearList<int> seq = { 10, 100, 1, 2, 0, 150, 2, 3, 4 };

	int resp = foo(seq);
	cout << resp << endl;

	return 0;
}

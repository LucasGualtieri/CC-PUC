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

// LinearList<LinearList<int>> gerarCpVertices(LinearList<int> V) {

// 	int N = V.size();

// 	LinearList<LinearList<int>> cpVertices(pow(2, N));

// 	for (int i = 1; i <= N; i++) { // i determina o tamanho do agrupamento

// 		LinearList<int> conjunto(i);

// 		int setinha = 0;

// 		int NP = np(i, N); // NP determina a quantidade de agrupamentos
// 		for (int j = 0; j < NP; j++) {

// 			while (conjunto.size() < i) {

// 				if (setinha >= N) {
// 					// seila essa condicao
// 					if (conjunto.back() == V.back()) conjunto.pop_back();
// 					setinha = V.indexOf(conjunto.pop_back()) + 1;
// 				}

// 				conjunto.push_back(V[setinha++]);
// 			}

// 			cpVertices.push_back(conjunto);

// 			conjunto.pop_back();
// 		}
// 	}

// 	return cpVertices;
// }

// LinearList<LinearList<int>> gerarArestas(LinearList<int> V) {

// 	// vectorPrint(V);

// 	int N = V.size();

// 	// LinearList<LinearList<int>> cpVertices(pow(2, N)); // .reserver() é o jeito certo
// 	// LinearList<LinearList<int>> arestas(1); // Não sei se vai fazer sentido combinar todas as arestas com uma aresta vazia. Talvez deixar pra gerar essa vazia depois no gerarCpArestas
// 	LinearList<LinearList<int>> arestas; // Não sei se vai fazer sentido combinar todas as arestas com uma aresta vazia. Talvez deixar pra gerar essa vazia depois no gerarCpArestas

// 	LinearList<int> conjunto;

// 	arestas.push_back(conjunto);

// 	int setinha = 0;

// 	int i = 2;

// 	// cout << "np: " << np(i, N) << endl;
// 	// if (np(i, N) == 0) arestas.push_back(conjunto);

// 	int NP = np(i, N);
// 	for (int j = 0; j < NP; j++) { // j determina a quantidade de agrupamentos

// 		while (conjunto.size() < i) { // k determina o tamanho do conjunto que é = i

// 			if (setinha >= N) {
// 				if (conjunto[conjunto.size() - 1] == N) conjunto.pop_back();
// 				setinha = conjunto[conjunto.size() - 1];
// 				conjunto.pop_back();
// 			}

// 			conjunto.push_back(V[setinha++]);
// 		}

// 		arestas.push_back(conjunto);

// 		conjunto.pop_back();
// 	}

// 	return arestas;

// }

/* void gerarCpArestas(LinearList<LinearList<int>> E, LinearList<LinearList<LinearList<int>>>& cpArestas) {

	int N = E.size();

	for (int i = 1; i <= N; i++) { // i determina o tamanho do agrupamento

		LinearList<LinearList<int>> arestas;

		int setinha = 0;

		for (int j = 0; j < np(i, N); j++) {

			while (arestas.size() < i) {

				if (setinha >= N) {
					if (arestas[arestas.size() - 1] == N) arestas.pop_back();
					setinha = arestas[arestas.size() - 1];
					arestas.pop_back();
				}

				arestas.push_back(V[setinha++]);
			}

			cpVertices.push_back(arestas);

			arestas.pop_back();
		}
	}
} */

template <typename T>
LinearList<LinearList<T>> gerarConjuntoPotencia(LinearList<T> conjunto, size_t min = 0, size_t max = 0x7fffffff) {

	if (max == 0x7fffffff) max = conjunto.size();

	int N = conjunto.size();

	LinearList<LinearList<T>> conjuntoPotencia(pow(2, N));

	for (int i = min; i <= max; i++) { // i determina o tamanho do agrupamento

		LinearList<T> subconjunto(i);

		int setinha = 0;

		int NP = np(i, N); // NP determina a quantidade de agrupamentos
		// cout << "conjunto: " << conjunto << endl;
		// cout << "i: " << i << endl;
		// cout << "max: " << max << endl;
		// cout << "NP " << NP << endl;
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
	// cout << "V: " << V << endl;

	LinearList<LinearList<int>> cpVertices = gerarConjuntoPotencia(V, 1);
	// cout << "todos os vetices: " << cpVertices << endl;

	// cout << "cpVertices[6]: " << cpVertices[6] << endl;

	// LinearList<LinearList<int>> arestas = gerarConjuntoPotencia(cpVertices[6], 2, 2);
	// cout << "todas as arestas = " << arestas << endl;

	// LinearList<LinearList<LinearList<int>>> teste = gerarConjuntoPotencia(arestas);
	// cout << "todas as combinações de arestas: " << teste << endl;

	int i = 1;

	for (LinearList<int> v : cpVertices) {


		LinearList<LinearList<int>> arestas = gerarConjuntoPotencia(v, 2, 2);
		// cout << "todas as arestas = " << arestas << endl;

		LinearList<LinearList<LinearList<int>>> cpArestas = gerarConjuntoPotencia(arestas);

		for (LinearList<LinearList<int>> aresta : cpArestas) {

			cout << "Subgrafo " << i++ << ": " << endl;
			cout << "V = " << v << endl;
			cout << "E = " << aresta << endl;
		}

		// cout << "cpArestas: " << cpArestas << endl;

		// cout << "------------------------------" << endl;

		// if (v.size() <= 1) continue;

		// LinearList<LinearList<int>> E = gerarConjuntoPotencia(v, 2, 2);
		// cout << "E: " << E << endl;
		// LinearList<LinearList<LinearList<int>>> cpArestas = gerarConjuntoPotencia(E);
		// cout << "cpArestas: " << cpArestas << endl;

		// // cout << E << endl;
		// cout << cpArestas << endl;
		// cout << "---------------------" << endl;
		// break;

		// for (LinearList<LinearList<int>> arestas : cpArestas) {
		// 	for (LinearList<int> e : arestas) {
		// 		cout << "Subgrafo: " << i++ << endl;
		// 		cout << "V: " << v << endl;
		// 		cout << "E: " << e << endl;
		// 	}
		// }
	}
}
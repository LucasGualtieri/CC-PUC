#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ subgrafos.cc && ./a.out
void vectorPrint(vector<int> vector) {

	cout << "{ ";
	for (int i : vector) cout << i << " ";
	cout << "}" << endl;
}
void printarVertices(vector<vector<int>> cpVertices) { cout << "{ ";

	for (vector<int> conjunto : cpVertices) {

		cout << "{ ";

		for (int v : conjunto) {
			cout << v << " ";
		}

		cout << "}, ";
	}

	cout << "}";
}

int fat(int n) { return n <= 1 ? 1 : n * fat(n - 1); }

int np(int i, int n) {
	return (fat(n)) / (fat(i) * (fat(n - i)));
}

vector<vector<int>> gerarCpVertices(vector<int> V) {

	int N = V.size();

	// vector<vector<int>> cpVertices(pow(2, N));
	vector<vector<int>> cpVertices;

	for (int i = 1; i <= N; i++) { // i determina o tamanho do agrupamento

		vector<int> conjunto;

		int setinha = 0;

		for (int j = 0; j < np(i, N); j++) { // j determina a quantidade de agrupamentos

			while (conjunto.size() < i) { // k determina o tamanho do conjunto que é = i

				if (setinha >= N) {
					if (conjunto[conjunto.size() - 1] == N) conjunto.pop_back();
					setinha = conjunto[conjunto.size() - 1];
					conjunto.pop_back();
				}

				conjunto.push_back(V[setinha++]);
			}

			cpVertices.push_back(conjunto);

			conjunto.pop_back();
		}
	}

	return cpVertices;
}

vector<vector<int>> gerarArestas(vector<int> V) {

	// vectorPrint(V);

	int N = V.size();

	// vector<vector<int>> cpVertices(pow(2, N));
	vector<vector<int>> arestas(1);

	vector<int> conjunto;

	int setinha = 0;

	int i = 2;

	// cout << "np: " << np(i, N) << endl;
	// if (np(i, N) == 0) arestas.push_back(conjunto);

	for (int j = 0; j < np(i, N); j++) { // j determina a quantidade de agrupamentos

		while (conjunto.size() < i) { // k determina o tamanho do conjunto que é = i

			if (setinha >= N) {
				if (conjunto[conjunto.size() - 1] == N) conjunto.pop_back();
				setinha = conjunto[conjunto.size() - 1];
				conjunto.pop_back();
			}

			conjunto.push_back(V[setinha++]);
		}

		arestas.push_back(conjunto);

		conjunto.pop_back();
	}

	return arestas;

}

/* void gerarCpArestas(vector<vector<int>> E, vector<vector<vector<int>>>& cpArestas) {

	int N = E.size();

	for (int i = 1; i <= N; i++) { // i determina o tamanho do agrupamento

		vector<vector<int>> arestas;

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

int main() {

	const int N = 4;

	// cout << fat(13) << endl;

	vector<int> vertices(N);
	for (int i = 1; i <= N; i++) vertices[i - 1] = i;

	// for (int i : vertices) cout << i << " ";
	// cout << endl;

	vector<vector<int>> cpVertices = gerarCpVertices(vertices);
	// printarVertices(cpVertices);

	if (cpVertices.size() == pow(2, N) - 1) cout << "Deu bom a qtd" << endl;
	// cout << endl << cpVertices.size() << endl;

	int i = 1;

	for (vector<int> V : cpVertices) {

		vector<vector<int>> E = gerarArestas(V);

		for (vector<int> aresta : E) {

			cout << "Subgrafo: " << i++ << endl;
			cout << "V: ";
			vectorPrint(V);
			cout << "E: ";
			vectorPrint(aresta);
		}

		// vector<vector<vector<int>>> cpArestas;

		// cpArestas.push_back(E);

		// gerarCpArestas(E, cpArestas);

		// for () {

			// cout << "Subgrafo: " << i++ << endl;
			// cout << "V: ";
			// vectorPrint(V);
			// cout << "E: ";
			// vectorPrint(aresta);
		// }
	}
}


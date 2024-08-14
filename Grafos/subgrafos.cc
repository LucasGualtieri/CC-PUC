#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ subgrafos.cc && ./a.out

int fat(int n) { return n == 1 || n == 0 ? 1 : n * fat(n - 1); }

int np(int i, int n) {
	return (fat(n)) / (fat(i) * (fat(n - i)));
}

vector<vector<int>> gerarCpVertices(vector<int> V) {

	int N = V.size();

	// vector<vector<int>> cpVertices(pow(2, N));
	vector<vector<int>> cpVertices;

	for (int i = 1; i <= N; i++) { // i determina o tamanho do agrupamento

		for (int j = 0; j < np(i, N); j++) { // j determina a quantidade de agrupamentos

			vector<int> conjunto; //(/* pensar em algo */);

			for (int k = 0; k < i; k++) { // k determina o tamanho do conjunto que é = i
				// cout << "np: " << np(i, N) << endl;
				// cout << "i: " << i << endl;
				// cout << "j: " << j << endl;
				// cout << "k + j: " << (k + j) << endl;
				// cout << V[k + j] << endl;
				// cout << "-----------------------" << endl;
				conjunto.push_back(V[k + j]);
			}

			cpVertices.push_back(conjunto);
		}
	}

	return cpVertices;
}

// vector<vector<int>> gerarArestas(vector<int> V) {
// 	vector<vector<int>> a;
// 	return a;
// }
// vector<vector<vector<int>>> gerarCpArestas(vector<vector<int>> E) {
// 	vector<vector<vector<int>>> a;
// 	return a;
// }

void printarVertices(vector<vector<int>> cpVertices) {

	cout << "{ ";

	for (vector<int> conjunto : cpVertices) {

		cout << "{ ";

		for (int v : conjunto) {
			cout << v << " ";
		}

		cout << "}, ";
	}

	cout << "}";
}

int main() {

	const int N = 3;

	vector<int> vertices(N);
	for (int i = 1; i <= N; i++) vertices[i - 1] = i;

	// for (int i : vertices) cout << i << endl;

	vector<vector<int>> cpVertices = gerarCpVertices(vertices);

	printarVertices(cpVertices);

	cout << endl << cpVertices.size() << endl;

	// for (vector<int> V : cpVertices) {
	// 	vector<vector<int>> E = gerarArestas(V);
	// 	// printar V + E;

	// 	vector<vector<vector<int>>> cpArestas = gerarCpArestas(E);
	// 	// printar V + E vai ter que ter um for
	// }

	// cout << "lskdfj" << endl;

	// cout << np(3, 3) << endl;
}

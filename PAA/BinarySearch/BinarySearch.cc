#include <cmath>
#include <format>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ BinarySearch.cc -std=c++23 && ./a.out

int contador, custoTotal;

template <typename T, typename Container>
int BinarySearch(T x, int L, int R, Container V) {

	contador++;

	custoTotal++;
	if ((R - L) + 1 == 0) return -1;

	custoTotal++;
	int M = (L + R) / 2;

	custoTotal++;
	if (V[M] == x) return M;

	custoTotal += 2;
	if (x < V[M]) R = M - 1;

	else L = M + 1;

	custoTotal++;
	return BinarySearch(x, L, R, V);
}

template <typename T, typename Container>
int BinarySearch(T x, size_t n, Container V) {
	return BinarySearch(x, 0, n - 1, V);
}

int f(int n) {
	int k = 6;
	return k * log2(n) + k + 1;
}

int main() {

	vector<int> V, teste;

	int n = 2051;
	for (int i = 1; i <= n; i++) V.push_back(i);
	for (int i = -10; i <= n + 10; i++) teste.push_back(i);

	int piorCusto = 0;

	for (int i : teste) {

		contador = 0;
		custoTotal = 0;

		BinarySearch(i, n, V);

		piorCusto = max(piorCusto, custoTotal);
	}

	// cout << "contador: " << contador << endl;
	// cout << "custoTotal: " << custoTotal << endl;
	cout << "piorCusto: " << piorCusto << endl;
	cout << format("f({}): {}", n, f(n)) << endl;
	cout << "---------------------" << endl;

	int index = BinarySearch(0, n, V);

	cout << "index: " << index << endl;

	return 0;
}

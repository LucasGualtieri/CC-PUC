#include <format>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ BinaryLinearSearch.cc -std=c++23 && ./a.out

int contador = 0;

template <typename T, typename Container>
T BinaryLS(T x, int L, int R, Container array) {

	int M = (L + R) / 2;

	// contador++;
	// if (array[M] == x) return M;

	contador++;
	if ((R - L) + 1 <= 1) return -1;

	int LR = BinaryLS(x, L, M - 1, array);
	int RR = BinaryLS(x, M + 1, R, array);

	contador++;
	return max(LR, RR);
}

template <typename T, typename Container>
T BinaryLS(T x, size_t n, Container array) {
	return BinaryLS(x, 0, n - 1, array);
}

int custo(int n) {
	const int c = 2;
	return n + c * n - c;
}

int main() {

	int n = 64;

	vector<int> array(n, 0);

	int index = BinaryLS(1, n, array);

	cout << index << endl;
	cout << format("custo previsto: {}", custo(n)) << endl;
	cout << format("custo real: {}", contador) << endl;

	return 0;
}

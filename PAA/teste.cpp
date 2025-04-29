#include <iostream>
#include <cmath>

using namespace std;

// clear && g++ teste.cpp && ./a.out

long long count = 0;

long long foo(long long n) {
	count++;
	if (n <= 1) return 1;
	return foo(n / 4) + foo(n / 4);
}

long long bar(long long n) {

	long long soma = 0;

	long long LS = ceil(log(n) / log(4));

	for (long long i = 0; i <= LS; i++) {
		soma += pow(2, i);
	}

	return soma;
}

int main() {

	long long n = 1'000'000'000;

	for (int i = 0; i < n; i++) {

		count = 0;

		cout << "sqrt(n): " << 2.08 * sqrt(i) << endl;
		foo(i);
		cout << "count: " << count << endl;
		cout << "bar(n): " << bar(i) << endl;
		cout << "------------------------------------" << endl;

	}

	// cout << ceil(log2(sqrt(n))) << endl;

	cout << 2 * pow(2, ceil(log2(pow(n, .5)))) - 1 << endl;
	cout << 2 * pow(2, ceil(log2(sqrt(n)))) - 1 << endl;
	cout << 2 * pow(n, .5) - 1 << endl;
	cout << 2 * sqrt(n) - 1 << endl;
	// cout << pow(2, ceil(log2(sqrt(n))) - log2(sqrt(n))) * 2 * sqrt(n) - 1 << endl;

	return 0;
}

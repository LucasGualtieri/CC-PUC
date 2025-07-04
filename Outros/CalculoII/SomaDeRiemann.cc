#include <iostream>
#include <cmath>

using namespace std;

#define PI numbers::pi_v<float>

// clear && g++ SomaDeRiemann.cc -std=c++20 && ./a.out

double SomaDeRiemann(auto f, double a, double b, int n = 10000000) {

	double soma = 0, deltaX = (b - a) / n;

	for (int i = 1; i <= n; i++) {
		soma += deltaX * f(a + i * deltaX);
	}

	return soma;
}

int main() {

	cout << SomaDeRiemann([](double x) { return pow(x, 2); }, 0, 1) << endl;
	cout << 1.0/3.0 << endl;

	// cout << SomaDeRiemann([](double x) { return sin(x); }, 0, PI, 1000) << endl;
	// cout << 2 << endl;

	// cout << SomaDeRiemann([](double x) { return 4 * PI * x * sqrt(4 - pow(x - 4, 2)); }, 2, 6, 1000) << endl;

}
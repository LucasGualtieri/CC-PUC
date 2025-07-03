#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// clear && g++ -std=c++23 teste.cpp && ./a.out

using namespace std;

template<typename T>
class CustomVector {
private:
    vector<T> buffer;
    int maxSize;

public:

	int p = 0, u = 0, n = 0;

    CustomVector(int capacity, T value) : buffer(capacity + 1, value), maxSize(capacity + 1) {}
    CustomVector(int capacity) : buffer(capacity + 1), maxSize(capacity + 1) {}

    void print() {

        for (int i = 0; i < n; i++) {
            cout << (*this)[i] << " ";
        }

        cout << endl;
    }

    T& operator[](const int& i) {
        return buffer[(p + i) % maxSize];
    }

    T operator[](const int& i) const {
        return buffer[(p + i) % maxSize];
    }

    void put(T value) {

        buffer[u] = value;
        u = (u + 1) % maxSize;

		if (n < maxSize) n++;
		else p = (p + 1) % maxSize; // overwrite oldest element
    }
};

template<typename T>
void printVector(const vector<T>& vec) {

	for (T i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T>
void printCircularVector(const CustomVector<T>& vec) {

	for (int i = 0; i < vec.n; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

template<typename T>
void printArray(const T* array, const size_t& n) {

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int minimum_blocks(const int& n, const vector<int>& blocos, int sum = 0, int i = 0) {

	if (sum == n) return i;
	if (sum > n) return (int)INFINITY;

	int height = (int)INFINITY;

	for (int b : blocos) {
		height = min(minimum_blocks(n, blocos, sum + b, i + 1), height);
	}

	return height;
}

int minimum_blocks_memoized(const int& n, const vector<int>& blocos, vector<int>& dp, int height, int i) {

	if (height == n) return i;
	if (height > n) return (int)INFINITY;

	int aux = (int)INFINITY;

	for (int b : blocos) {
		if (dp[height + b] == (int)INFINITY) dp[height + b] = minimum_blocks_memoized(n, blocos, dp, height + b, i + 1);
		aux = min(dp[height + b], aux);
	}

	return aux;
}

int minimum_blocks_memoized(const int& n, const vector<int>& blocos) {
	
	vector<int> dp(n, (int)INFINITY);

	return minimum_blocks_memoized(n, blocos, dp, 0, 0);
}

int minimum_blocks_bottom_up(const int& height, const vector<int>& blocos) {

	vector<float> dp(height + 1, INFINITY);
	dp[height] = 0;

	for (int i = height - 1; i >= 0; i--) {

		for (int bloco : blocos) {
			if (i + bloco <= height) {
				dp[i] = min(dp[i], dp[i + bloco] + 1);
			}
		}

		// printVector(dp);
	}

	// printVector(dp);

	return dp[0];
}

int minimum_blocks_bottom_up2(const int& height, const vector<int>& blocos) {

	vector<float> dp(height + 1, INFINITY);
	dp[0] = 0;

	for (int i = 1; i <= height; i++) {

		for (int bloco : blocos) {
			if (i - bloco >= 0) {
				dp[i] = min(dp[i], dp[i - bloco] + 1);
			}
		}

		// printVector(dp);
	}

	// printVector(dp);

	return dp[height];
}

// FIX: Ta errado, bem errado...
int minimum_blocks_bottom_better_space(const int& height, const vector<int>& blocos) {

	int maxBloco = (int)-INFINITY;

	for (int b : blocos) maxBloco = max(maxBloco, b);

	CustomVector<float> dp(maxBloco, INFINITY);

	dp.put(0);

	for (int i = 2; i <= height; i++) {

		float minValue = INFINITY;

		for (int bloco : blocos) {
			if (i - bloco >= 0) {
				minValue = min(minValue, dp[i - bloco] + 1);
			}
		}

		dp.put(minValue);

	}

	dp.print();

	return dp[maxBloco];
}

int main() {

	//Caso 1: múltiplos exatos
	// int n = 10;
	// vector<int> blocos = {1, 2, 5}; // Esperado: 2 (5 + 5)

	// Caso 2: impossível atingir
	// int n = 7;
	// vector<int> blocos = {2, 4}; // Esperado: não existe solução (INFINITY ou equivalente)

	// Caso 3: apenas 1 bloco possível
	// int n = 9;
	// vector<int> blocos = {3}; // Esperado: 3 (3 + 3 + 3)

	// Caso 4: múltiplos não triviais
	// int n = 11;
	// vector<int> blocos = {1, 3, 5}; // Esperado: 3 (5 + 5 + 1)

	// Caso 5: várias combinações possíveis
	int n = 17;
	vector<int> blocos = {2, 6, 7}; // Esperado: 3 (7 + 6 + 2 + 2)

	// Caso 6: blocos grandes e pequenos
	// int n = 23;
	// vector<int> blocos = {1, 10, 12}; // Esperado: 3 (12 + 10 + 1)

	// Caso 7: altura alta com blocos pequenos
	// int n = 1000;
	// vector<int> blocos = {1, 3, 4}; // Esperado: deve funcionar rapidamente com espaço O(4)

	// Caso 8: altura alta com blocos grandes
	// int n = 1000;
	// vector<int> blocos = {50, 75, 120}; // Esperado: algumas combinações possíveis

	// Caso 9: muitos blocos
	// int n = 250;
	// vector<int> blocos = {1, 2, 5, 10, 20, 50, 100}; // Esperado: 3 (100 + 100 + 50)

	// Caso 10: altura 0
	// int n = 0;
	// vector<int> blocos = {1, 5, 10}; // Esperado: 0 blocos (já estamos na altura desejada)

	// cout << "Minimum way: " << minimum_blocks_memoized(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks_bottom_up(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks_bottom_up2(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks_bottom_better_space(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks(n, blocos) << endl;

	return 0;
}

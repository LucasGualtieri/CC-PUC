#include <cmath>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

#include "../../../PAA-TP01/DataStructures/include/matrix/matrix.hpp"
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/DataStructures/utils/Pair.hpp"

// clear && g++ -std=c++23 limited_coins.cpp && ./a.out

using namespace std;

template <typename T>
bool contains(const unordered_set<T>& set, T value) {
	return set.count(value);
}

template <typename T>
void printVector(const vector<T> vec) {

	for (T i : vec) {
		cout << i.first << " ";
	}
	cout << endl;
	
}

int blocks_bottom_up(const int& height, const vector<int>& blocos) {

	vector<Pair<int, unordered_set<int>>> dp(
		height + 1, { numeric_limits<int>::max(), unordered_set<int>() }
	);

	dp[0].first = 0;

	for (int i : blocos) dp[0].second.insert(i);

	for (int i = 1; i <= height; i++) {

		for (int bloco : blocos) {

			auto& [value, set] = dp[i - bloco];

			if (i - bloco >= 0 && contains(set, bloco)) {
				if (value + 1 < dp[i].first) {
					dp[i].first = value + 1;
					dp[i].second = set;
					dp[i].second.erase(bloco);
				}
			}
		}
	}

	printVector(dp);

	return dp[height].first;
}

void copiarColuna(int a, int b, int bloco, Matrix<bool>& matrix) {

	for (int i = 0; i < matrix.height; i++) {
		matrix[i][b] = matrix[i][a];
	}

	matrix[bloco][b] = false;
}

int blocks_bottom_up_matrix(const int& height, const vector<int>& blocos) {

	int n = blocos.size();

	LinearList<int> dp((size_t)(height + 1), numeric_limits<int>::max());
	dp[0] = 0;

	Matrix<bool> matrix(true, n, height + 1);
	for (int i = 0; i < n; i++) {
		matrix[i][0] = true;
	}

	for (int i = 1; i <= height; i++) {

		int bestBloco = -1;

		for (int j = 0; j < n; j++) { // O(|blocos|)

			int bloco = blocos[j];

			if (i - bloco >= 0 && matrix[j][i - bloco]) {

				if (dp[i - bloco] + 1 < dp[i]) {
					dp[i] = dp[i - bloco] + 1;
					bestBloco = j;
				}
			}
		}

		if (bestBloco > 0) { // O(|blocos|)
			copiarColuna(i - blocos[bestBloco], i, bestBloco, matrix);
		}
	}

	cout << dp << endl;

	return dp[height];
}

int main() {

	// Caso 0: múltiplos exatos
	// int n = 9;
	// vector<int> blocos = { 6, 5, 4, 2, 1 };

	int n = 16;
	vector<int> blocos = { 10, 8, 7, 3, 2, 1 };

	// cout << "Minimum way: " << minimum_blocks_memoized(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks_bottom_up(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks_bottom_up2(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks_bottom_better_space(n, blocos) << endl;
	// cout << "Minimum way: " << minimum_blocks(n, blocos) << endl;
	cout << "Minimum way: " << blocks_bottom_up(n, blocos) << endl;
	cout << "Minimum way: " << blocks_bottom_up_matrix(n, blocos) << endl;

	return 0;
}

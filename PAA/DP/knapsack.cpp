#include <iostream>
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/DataStructures/include/matrix/matrix.hpp"

using namespace std;

// clear && g++ -std=c++23 knapsack.cpp && ./a.out

int knapsack(const size_t& weight, const LinearList<int>& w, const LinearList<int>& v) {

	size_t n = w.size();

	Matrix<int> dp(n + 1, weight + 1);

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= weight; j++) {
			
			if (j - w[i - 1] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
			}

			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp << endl;

	return dp[n][weight];
}

int main() {

	LinearList<int> w = { 1, 3, 4, 5 };
	LinearList<int> v = { 1, 4, 5, 7 };

	cout << knapsack(7, w, v) << endl;

	return 0;
}

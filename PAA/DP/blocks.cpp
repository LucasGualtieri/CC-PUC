#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ blocks.cpp && ./a.out

int blocks_top_down(const size_t& h, const vector<int>& blocks) {

	if (h == 0) return 0;

	int bestAnswer = INT_MAX;

	for (int b : blocks) {

		if (b <= h) {
			bestAnswer = min(bestAnswer, 1 + blocks_top_down(h - b, blocks));
		}
	}

	return bestAnswer == INT_MAX ? INT_MAX - 1 : bestAnswer;
}

int blocks_top_down_memoized(const size_t& h, const vector<int>& blocks, vector<int>& dp) {

	for (int b : blocks) {

		if (b <= h) {

			if (dp[h - b] != INT_MAX) {
				dp[h] = min(dp[h], 1 + dp[h - b]);
			}

			else dp[h] = min(dp[h], 1 + blocks_top_down_memoized(h - b, blocks, dp));
		}
	}

	return dp[h] = dp[h] == INT_MAX ? INT_MAX - 1 : dp[h]; 
}

int blocks_top_down_memoized(const size_t& h, const vector<int>& blocks) {

	vector<int> dp(h + 1, INT_MAX);
	dp[0] = 0;

	return blocks_top_down_memoized(h, blocks, dp);
}

int blocks_bottom_up(const size_t& h, const vector<int>& blocks) {

	vector<int> dp(h + 1, INT_MAX);
	dp[0] = 0;

	for (int b : blocks) {
		for (int i = b; i <= h; i++) {
			dp[i] = min(dp[i], dp[i - b] + 1);
		}
	}

	return dp[h];
}

int main() {

	vector<int> blocks = { 2, 6, 8 };
	size_t h = 10;

	cout << blocks_bottom_up(h, blocks) << endl;
	cout << blocks_top_down_memoized(h, blocks) << endl;
	cout << blocks_top_down(h, blocks) << endl;

	return 0;
}

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ blocks_01.cpp && ./a.out

int blocks_top_down(const size_t& h, const vector<int>& blocks, int index = 0) {

	if (h == 0) return 0;

	int bestAnswer = INT_MAX;

	for (int i = index; i < blocks.size(); i++) {

		int b = blocks[i];

		if (b <= h) {
			bestAnswer = min(bestAnswer, 1 + blocks_top_down(h - b, blocks, i + 1));
		}
	}

	return bestAnswer == INT_MAX ? INT_MAX - 1 : bestAnswer;
}

int blocks_top_down_memoized(const size_t& h, const vector<int>& blocks, int index, vector<int>& dp) {

	for (int i = index; i < blocks.size(); i++) {

		int b = blocks[i];

		if (b <= h) {

			if (dp[h - b] != INT_MAX) {
				dp[h] = min(dp[h], 1 + dp[h - b]);
			}

			else dp[h] = min(dp[h], 1 + blocks_top_down_memoized(h - b, blocks, i + 1, dp));
		}
	}

	return dp[h] = dp[h] == INT_MAX ? INT_MAX - 1 : dp[h]; 
}

int blocks_top_down_memoized(const size_t& h, const vector<int>& blocks) {

	vector<int> dp(h + 1, INT_MAX);
	dp[0] = 0;

	return blocks_top_down_memoized(h, blocks, 0, dp);
}

int blocks_bottom_up(const size_t& h, const vector<int>& blocks) {

	vector<int> dp(h + 1, INT_MAX);
	dp[0] = 0;

	for (int b : blocks) {
		for (int i = b; i <= h; i++) {
			dp[b] = min(dp[b], dp[b - b] + 1);
		}
	}

	return dp[h];
}

int main() {

	vector<int> blocks;
	size_t h;

	// Test case 0: exact match with two blocks
	blocks = {1, 2, 3};
	h = 5;
	// Expected output: 2  (choose 2 + 3)

	// Test case 1: exact match with two blocks
	// blocks = {2, 6, 8};
	// h = 10;
	// Expected output: 2  (choose 2 + 8)

	// Test case 2: not possible to reach h
	// blocks = {1, 3, 4};
	// h = 10;
	// Expected output: -1 (no subset sums to 10)

	// Test case 3: multiple combinations, pick one with fewer blocks
	blocks = {1, 1, 2, 4, 8};
	h = 7;
	// Expected output: 2  (1 + 2 + 4)

	// Test case 4: only one combination possible
	// blocks = {7, 3, 5};
	// h = 8;
	// Expected output: 2 (3 + 5)

	// Test case 5: need all blocks
	// blocks = {2, 4, 5};
	// h = 12;
	// Expected output: 3 (3 + 4 + 5)

	// Test case 6: edge case — h = 0
	// blocks = {1, 2, 3};
	// h = 0;
	// Expected output: 0 (no block needed)

	// Test case 7: edge case — empty block list
	// blocks = {};
	// h = 5;
	// Expected output: -1 (no blocks available)

	// for (int i = 1; i <= 30; i++) blocks.push_back(i);  // blocks = {1, 2, ..., 30}
	// h = 465;  // 1 + 2 + ... + 30

	// cout << blocks_bottom_up(h, blocks) << endl;
	// cout << blocks_top_down_memoized(h, blocks) << endl;
	cout << blocks_top_down(h, blocks) << endl;

	return 0;
}

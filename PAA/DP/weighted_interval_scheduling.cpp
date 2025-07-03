#include <iostream>
#include <limits>

#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ -std=c++23 weighted_interval_scheduling.cpp && ./a.out

int max_sum_weighted_intervals(int index, int boundary, const LinearList<LinearList<int>>& intervals) {

	int n = intervals.size(), max_sum;

	if (index >= n || intervals[index][0] < boundary) return numeric_limits<int>::min();

	int weight = max_sum = intervals[index][2];

	for (int i = index + 1; i < n; i++) {
		max_sum = max(max_sum, weight + max_sum_weighted_intervals(i, intervals[index][1], intervals));
	}

	return max_sum;
}

int max_sum_weighted_intervals_top_down(const LinearList<LinearList<int>>& intervals) {

	int max_sum = numeric_limits<int>::min();

	for (int i = 0; i < intervals.size(); i++) {
		max_sum = max(max_sum, max_sum_weighted_intervals(i, 0, intervals));
	}

	return max_sum;
}

int max_sum_weighted_intervals_bottom_up(const LinearList<LinearList<int>>& intervals) { // O(n²) é mt pior que O(nlgn)

	size_t n = intervals.size();

	LinearList<int>dp(n, 0);

	for (int i = 0; i < n; i++) dp[i] = intervals[i][2];

	for (int i = 1; i < n; i++) {

		for (int j = i - 1; j >= 0; j--) {

			if (intervals[i][0] >= intervals[j][1]) {
				dp[i] = max(dp[i], intervals[i][2] + dp[j]);
				break;
			}
		}

		dp[i] = max(dp[i], dp[i - 1]);
	}

	// cout << dp << endl;

	return dp[n - 1];
}

int main() {

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 3, 5 }, { 2, 4, 4 }, { 0, 7, 1 }, { 6, 11, 4 }, { 5, 9, 3 }, { 8, 10, 7 },
	// };
	// Expected output: 12
	// Best intervals: {1,3,5} and {8,10,7}

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 2, 4 }, { 3, 4, 5 }, { 5, 6, 6 },
	// };
	// Expected output: 15
	// All intervals can be taken.

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 10, 5 }, { 1, 10, 15 }, { 1, 10, 10 },
	// };
	// Expected output: 15
	// Only one can be chosen, pick the one with max weight.

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 10, 10 }, { 2, 5, 6 }, { 6, 9, 7 },
	// };
	// Expected output: 13
	// Best: {2,5,6} and {6,9,7}

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 4, 5 }, { 2, 4, 6 }, { 3, 4, 7 }, { 5, 7, 3 },
	// };
	// Expected output: 10
	// Best: {3,4,7} and {5,7,3}

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 5, 3 }, { 2, 6, 8 }, { 3, 7, 2 },
	// };
	// Expected output: 8
	// Only one can be taken.

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 2, 10 }, { 3, 4, 9 }, { 5, 6, 8 }, { 7, 8, 7 },
	// };
	// Expected output: 34
	// Take all.

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 2, -1 }, { 3, 4, -2 }, { 5, 6, -3 },
	// };
	// Expected output: 0 or -1 (depends on interpretation)
	// You may treat empty selection as zero total weight.

	// LinearList<LinearList<int>> intervals = {
	// 	{ 1, 10, 10 }, { 11, 12, 1 }, { 13, 14, 2 },
	// };
	// Expected output: 13
	// All disjoint.

	LinearList<LinearList<int>> intervals = {
		{ 6 - 5, 6, 5 }, { 7 - 5, 7, 6 }, { 12 - 5, 12, 5 }, { 14 - 5, 14, 1 }, { 18 - 5, 18, 2 }, { 19 - 5, 19, 3 }
	};

	intervals.sort([](auto a, auto b) {
		return a[1] < b[1];
	});

	// cout << intervals << endl;

	// cout << max_sum_weighted_intervals_top_down(intervals) << endl;
	cout << max_sum_weighted_intervals_bottom_up(intervals) << endl;

	return 0;
}

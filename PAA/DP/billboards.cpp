#include <iostream>

#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ -std=c++23 weighted_interval_scheduling.cpp && ./a.out

void backtrack(const LinearList<int>& dp, const LinearList<LinearList<int>>& intervals) {

	size_t n = dp.size();
	LinearList<int> result;

	int i = n - 1;
	while (i >= 0) {

		// If we take interval[i]
		int weight = intervals[i][2];

		// Look for the latest compatible interval
		int j = i - 1;
		while (j >= 0 && intervals[i][0] <= intervals[j][1]) j--;

		int totalWithCurrent = weight + (j >= 0 ? dp[j] : 0);

		// Compare with dp[i-1] to know if we took it
		if (dp[i] == totalWithCurrent) {

			// We took interval i
			result.push_front(i);  // prepend to keep order
			i = j; // jump to the compatible interval
		}

		else i--;
	}

	cout << "Selected interval indices: " << result << endl;

	for (int idx : result) {
		cout << "Billboard: km " << intervals[idx][1] << " -> Weight: " << intervals[idx][2] << endl;
	}
}

int billboard_bottom_up(const LinearList<LinearList<int>>& intervals) { // O(n²) é mt pior que O(nlgn)

	size_t n = intervals.size();

	LinearList<int>dp(n, 0);

	for (int i = 0; i < n; i++) dp[i] = intervals[i][2];

	for (int i = 1; i < n; i++) {

		for (int j = i - 1; j >= 0; j--) {

			// NOTE: Could also be '>='
			if (intervals[i][0] > intervals[j][1]) {
				dp[i] = max(dp[i], intervals[i][2] + dp[j]);
				break;
			}
		}

		dp[i] = max(dp[i], dp[i - 1]);
	}

	backtrack(dp, intervals);

	return dp[n - 1];
}

int main() {

	LinearList<LinearList<int>> intervals = {
		{ 6 - 5, 6, 5 },
		{ 7 - 5, 7, 6 },
		{ 12 - 5, 12, 5 },
		{ 14 - 5, 14, 1 },
		{ 18 - 5, 18, 2 },
		{ 19 - 5, 19, 3 }
	};

	intervals.sort([](auto a, auto b) {
		return a[1] < b[1];
	});

	cout << billboard_bottom_up(intervals) << endl;

	return 0;
}

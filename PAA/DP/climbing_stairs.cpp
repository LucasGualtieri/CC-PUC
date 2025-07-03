#include <cmath>
#include <iostream>
#include <vector>

// clear && g++ climbing_stairs.cpp && ./a.out

using namespace std;

/*
	You are climbing a staircase. It takes n steps to reach the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

	Example 1:

	Input: n = 2
	Output: 2
	Explanation: There are two ways to climb to the top.
	1. 1 step + 1 step
	2. 2 steps
	Example 2:

	Input: n = 3
	Output: 3
	Explanation: There are three ways to climb to the top.
	1. 1 step + 1 step + 1 step
	2. 1 step + 2 steps
	3. 2 steps + 1 step

	Constraints:

	1 <= n <= 45
*/

int climbStairsR(const int& n, int i = 0) {

	if (i == n) return 1;
	if (i > n) return 0;

	return climbStairsR(n, i + 1) + climbStairsR(n, i + 2);
}

int climbStairs(int n) {
	return climbStairsR(n, 0);
}

long long climbing_stairs_top_down(const int& n, vector<long long>& dp, int i) {

	if (i == n) return 1;
	if (i > n) return 0;
	
	if (dp[i + 1] == -1) dp[i + 1] = climbing_stairs_top_down(n, dp, i + 1);
	if (dp[i + 2] == -1) dp[i + 2] = climbing_stairs_top_down(n, dp, i + 2);

	return dp[i + 1] + dp[i + 2];
}

long long climbing_stairs_top_down(const int& n) {

	vector<long long> dp(n + 2, -1);

	return climbing_stairs_top_down(n, dp, 0);
}

long long climbing_stairs_bottom_up(const int& n) {

	long long a = 1, b = 1;

	for (int i = 0; i < n - 1; i++) {
		long long c = a + b;
		a = b;
		b = c;
	}

	return b;
}

int main() {

	int n = 40;
	cout << "Number of possible ways: " << climbing_stairs_top_down(n) << endl;
	cout << "Number of possible ways: " << climbing_stairs_bottom_up(n) << endl;
	cout << "Number of possible ways: " << climbStairs(n) << endl;

	return 0;
}

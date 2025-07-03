#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

using namespace std;

// clear && g++ -std=c++23 LCS.cpp && ./a.out

string foo(const string& x, const string& y, const vector<vector<int>>& dp) {

	string result = "";
	size_t n = x.size(), m = y.size();

	for (int i = n; i > 0; i--) {
		if (dp[i - 1][m] < dp[i][m]) {
			result = x[i - 1] + result;
		}
	}

	return result;
}

pair<int, string> LCS(const string& x, const string& y) {

	size_t n = x.size(), m = y.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

    return { dp[n][m], foo(x, y, dp)};
}

int main() {

	{
		auto [len, str] = LCS("a", "aa");
		cout << format("{}: {}", str, len) << endl;
	}

	{
		auto [len, str] = LCS("123", "01023");
		cout << format("{}: {}", str, len) << endl;
	}

	{
		auto [len, str] = LCS("babad", "dabab");
		cout << format("{}: {}", str, len) << endl;
	}

	return 0;
}

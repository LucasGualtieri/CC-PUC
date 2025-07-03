#include <format>
#include <iostream>

#include "../../../PAA-TP01/DataStructures/utils/Pair.hpp"
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ -std=c++23 max_non_adjacent_sum.cpp && ./a.out

int array_sum(const LinearList<int>& array) {

	int sum = 0;

	for (int i : array) sum += i;

	return sum;
}

LinearList<int> argmin_array_sum(const LinearList<int>& array1, const LinearList<int>& array2) {

	if (array_sum(array1) > array_sum(array2)) {
		return array1;
	}

	else return array2;
}

LinearList<int> max_non_adjacent_sum(int i, LinearList<int> aux, const LinearList<int>& A) {

	if (i == A.size() - 1) return aux + A[i];

	LinearList<int> left = aux + A[i], right = aux + A[i + 1];

	if (i < A.size() - 2) {
		left = max_non_adjacent_sum(i + 2, left, A);
	}

	if (i < A.size() - 3) {
		right = max_non_adjacent_sum(i + 3, right, A);
	}

	return argmin_array_sum(left, right);
}

Pair<int, LinearList<int>> max_non_adjacent_sum(const LinearList<int>& A) {
	
	LinearList<int> resp = max_non_adjacent_sum(0, {}, A);

	return { array_sum(resp), resp };
}

int max_non_adjacent_sum_bottom_up(const LinearList<int>& A) {

	size_t n = A.size();

	// Casos base para quando o array for menor que 2
	if (n == 0) return 0;
	if (n == 1) return A[0];

	LinearList<int> dp(n, 0);

	dp[n - 1] = A[n - 1];
	dp[n - 2] = max(A[n - 1], A[n - 2]);
	
	for (int i = n - 3; i >= 0; i--) {
		dp[i] = max(A[i] + dp[i + 2], dp[i + 1]);
	}

	return dp[0];
}

int max_non_adjacent_sum_bottom_up_constant_space(const LinearList<int>& A) {

	size_t n = A.size();

	// Casos base para quando o array for menor que 2
	if (n == 0) return 0;
	if (n == 1) return A[0];

	int c, a = A[0], b = max(A[0], A[1]);
	
	for (int i = 2; i < n; i++) {
		c = max(a, A[i] + b);
		a = b;
		b = c;
	}

	return b;
}

int main() {

	LinearList<int> A = { 3, 2, 5, 10, 7, 6, 9 };
	// LinearList<int> A = { 4, 1, 1, 9 };

	auto [sum, subsequence] = max_non_adjacent_sum(A);

	cout << format("{}: {}", sum, subsequence.str()) << endl;

	cout << max_non_adjacent_sum_bottom_up(A) << endl;
	cout << max_non_adjacent_sum_bottom_up(A) << endl;

	return 0;
}

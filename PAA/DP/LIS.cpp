#include <iostream>
#include <stack>
#include <vector>

#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ -std=c++23 LIS.cpp && ./a.out

int LIS(LinearList<int>& sequence) {

	size_t n = sequence.size();

	LinearList<int> indices(n, 0);

	for (int i = 0; i < n; i++) indices[i] = i;
	
	stack<pair<int, int>> s;

	s.push({0, n - 1});

	cout << sequence << endl;

	while (!s.empty()) {

		auto [L, R] = s.top();
		s.pop();

		int i = L, j = R;
		int pivo = sequence[(L + R) / 2];
		int pivo_index = indices[(L + R) / 2];

		while (i <= j) {
			while (sequence[i] < pivo || (sequence[i] == pivo && indices[i] < pivo_index)) i++;
			while (sequence[j] > pivo || (sequence[j] == pivo && indices[j] > pivo_index)) j--;
			if (i <= j) {
				swap(sequence[i], sequence[j]);
				swap(indices[i++], indices[j--]);
			}
		}

		if (L < j) s.push({L, j});
		if (i < R) s.push({i, R});
	}

	cout << sequence << endl;
	cout << "indices: " << indices << endl;

	int lis = 1;
	int lastIndex = indices[0];
	int max = sequence[0];

	for (int i = 1; i < n; i++) {

		if (sequence[i] > max && indices[i] > lastIndex) {
			lis++;
			lastIndex = indices[i];
			max = sequence[i];
		}
	}

    return lis;
}

int main() {

	// LinearList<int> sequence = {10,9,2,5,3,7,101,18};

	// LinearList<int> sequence = {0,1,0,3,2,3};

	// LinearList<int> sequence = {0,1,0,3,2,3};

	LinearList<int> sequence = {1,3,6,7,9,4,10,5,6};

	cout << LIS(sequence) << endl;

	return 0;
}

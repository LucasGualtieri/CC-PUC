#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// clear && g++ QuadraticProbing.cc -std=c++23 && ./a.out

int main() {

	int n = 128;

	vector<int> table;

	unordered_set<int> set;

	int h = 0;

	for (int i = 0; i < n; i++) {
		set.insert((h + i * i) % n);
	}

	for (int i : set) table.push_back(i);

	sort(table.begin(), table.end());

	for (int i : table) cout << i << endl;

	return 0;
}

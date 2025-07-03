#include <iostream>
#include <vector>

// clear && 

using namespace std;

vector<int> multiplcation(const vector<int>& x, const vector<int>& y) {
	
	int n = x.size(), m = y.size();
	vector<vector<int>> aux(n);

	// NOTE: Placing the leading zeros
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// aux[i].insert(0, 123);
		}
	}


	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			aux[?].insert();
		}
	}

	vector<int> product;



	return product;
}

int main() {

	vector<int> x = { 100 };
	vector<int> y = { 1 };

	vector<int> product = multiplication(x, y);

	return 0;
}

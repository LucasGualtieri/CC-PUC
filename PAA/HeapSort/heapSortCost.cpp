#include <iostream>
#include <vector>

using namespace std;

// clear && g++ heapSortCost.cpp && ./a.out

void buildMaxHeap(const int& root, const int& N, vector<int>& array) {

	int largest = root, l = 2 * root + 1, r = 2 * root + 2;

	if (l < N && array[l] > array[largest]) largest = l;
	else if (r < N && array[r] > array[largest]) largest = r;

	if (largest != root) {
		swap(array[root], array[largest]);
		buildMaxHeap(largest, N, array);
	}
}

void HeapSort(vector<int>& array) {

	int N = array.size();

	for (int i = N / 2 - 1; i >= 0; i--) { // O(nlogn)
		buildMaxHeap(i, N, array);
	}

	for (int i = N - 1; i > 0; i--) {
		swap(array[0], array[i]);
		buildMaxHeap(0, i, array);
	}
}

int main() {

	vector<int> array = { 5, 3, 2, 1, 4 };

	HeapSort(array);

	for (int i : array) cout << i;
	cout << endl;

	return 0;
}

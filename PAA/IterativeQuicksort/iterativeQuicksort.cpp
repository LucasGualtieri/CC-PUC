#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <fstream>
#include <iomanip> // for setprecision

#include "../../../PAA-TP01/include/timer.hpp"
#include "../../../PAA-TP01/DataStructures/utils/Pair.hpp"
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/DataStructures/include/stack/linkedStack.hpp"

using namespace std;

// clear && g++ -++23 -O0 iterativeQuicksort.cpp && ./a.out

int Random(const int& inferiorLimit, const int& superiorLimit) {

	// NOTE: Setting the following variables to static led to significant improvements in performance
	static random_device rd;  // Obtain a random seed from hardware
	static mt19937 gen(rd()); // Initialize Mersenne Twister PRNG
	uniform_int_distribution<int> dist(inferiorLimit, superiorLimit); // Inclusive Range [a, b]

	return dist(gen);
}

template <typename T>
bool isSorted(LinearList<T> array) {

	for (int i = 1; i < array.size(); i++) {
		if (array[i] < array[i - 1]) return false;

	}

	return true;
}

template <typename T>
void quicksort(LinearList<T>& array) {

	int n = array.size();
	LinkedStack<Pair<int, int>> s = {{0, n - 1}};

	while (!s.empty()) {

		auto [L, R] = s.pop();

		int i = L, j = R;
		int pivo = array[(L + R) / 2];

		while (i <= j) {
			while (array[i] < pivo) i++;
			while (array[j] > pivo) j--;
			if (i <= j) swap(array[i++], array[j--]);
		}

		if (L < j) s.push({L, j});
		if (i < R) s.push({i, R});
	}
}

template <typename T>
void QuickSortRec(LinearList<T>& array, int left, int right) {

	int i = left, j = right;
	int pivo = array[(right + left) / 2];

	while (i <= j) {
		while (array[i] < pivo) i++;
		while (array[j] > pivo) j--;
		if (i <= j) swap(array[i++], array[j--]);
	}

	if (left < j) QuickSortRec(array, left, j);
	if (i < right) QuickSortRec(array, i, right);
}

template <typename T>
void recursiveQuicksort(LinearList<T>& array) {
    QuickSortRec(array, 0, array.size() - 1);
}

int main() {

	Timer timer1, timer2;

	ofstream file("quicksort_results.csv");
	file << "n,iterative_time,recursive_time\n"; // CSV header

	for (const int n : { 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000}) {

		LinearList<int> base(n), array1, array2;

		for (int i = 0; i < n; i++) base += Random(-n, n);

		array1 = array2 = base;

		{
			timer1.start();
			quicksort(array1);
			timer1.stop();

			if (!isSorted(array1)) {
				cout << "Array1 is not sorted, aborting!" << endl;
				break;
			}
		}

		{
			timer2.start();
			recursiveQuicksort(array2);
			timer2.stop();

			if (!isSorted(array2)) {
				cout << "Array2 is not sorted, aborting!" << endl;
				break;
			}
		}

		double time1 = timer1.result();
		double time2 = timer2.result();

		cout << format("With {} numbers: ", n) << endl;
		cout << format("Iterative took {}", time1) << endl;
		cout << format("Recursive took {}", time2) << endl;
		cout << "----------------------" << endl;

		file << n << "," << setprecision(10) << time1 << "," << time2 << "\n";
	}

	file.close();

	return 0;
}

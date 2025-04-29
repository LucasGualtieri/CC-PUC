#include <fstream>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <unordered_set>

#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/DataStructures/include/list/linkedList.hpp"
#include "../../../PAA-TP01/include/timer.hpp"
#include "processTimer.hpp"

// clear && g++ -std=c++20 ListPushBack.cpp && ./a.out

using namespace std;

int main() {

	size_t n = 10'000;

	Timer timer, totalTime;
	ProcessTimer pTimer, pTotalTime;
	LinearList<int> linearList;
	LinkedList<int> linkedList;
	LinearList<double> times(n, 0);

	totalTime.start();
	// pTotalTime.start();

	for (int i = 0; i < n; i++) {
		timer.start();
		// pTimer.start();
			// linearList += 0;
			linkedList.push_back(0);
		timer.stop();
		times[i] = timer.result();
		// times[i] = pTimer.result();
	}

	cout << format("Total Process Time: {:.{}f}", pTotalTime.result(), 10) << endl;

	double avgTime = 0;

	for (const auto& time : times) {
		avgTime += time;
	}

	avgTime /= n;

	cout << format("Avg Time: {:.{}f}", avgTime, 10) << endl;
	cout << format("Total Time: {:.{}f}", totalTime.result(), 10) << endl;

	int k = n / 100;

	std::ofstream file("output.csv");

    if (!file) throw runtime_error("Error opening file!\n");

	unordered_set<int> set;

	// NOTE: i < n is overkill, maybe sqrt(n)?
	for (int i = 0; i < n; i++) {
		set.insert(5 * pow(2, i));
	}

	file << format("i, time") << endl;

	for (int i = 0; i < n; i++) {
		if (i % k == 0 || set.count(i)) {
			file << format("{}, {:.10f}", i, times[i]) << endl;
		}
	}

	return 0;
}

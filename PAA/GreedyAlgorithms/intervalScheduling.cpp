#include <iostream>

#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/DataStructures/utils/Pair.hpp"

// clear && g++ -std=c++20 intervalScheduling.cpp && ./a.out

using namespace std;

LinearList<Pair<int, int>> MaxDisjointIntervalSet(LinearList<Pair<int, int>> set) {

	LinearList<Pair<int, int>> subset;

	set.sort([](auto a, auto b) {
		return a.second < b.second;
	});

	Pair<int, int> last = set[0];
	subset += last;

	for (int i = 1; i < set.size(); i++) {

		if (set[i].first > last.second) {
			last = set[i];
			subset += last;
		}
	}

	return subset;
}

LinearList<Pair<int, int>> MinNecessaryIntervalSet(LinearList<Pair<int, int>> set) {

	LinearList<Pair<int, int>> subset;

	set.sort([](auto& a, auto& b) {

		// if (a.first == b.first) {
		// 	return (a.second - a.first + 1) > (b.second - b.first + 1);
		// }

		return a.first < b.first;
	});

	cout << "set: " << set << endl;

	Pair<int, int> last = set[0];

	for (int i = 1; i < set.size(); i++) {

		if (set[i].first <= last.second && set[i].second > last.second) {
			last = set[i];
		}

		if (set[i].first > last.second) {
			subset += last;
			subset += set[i];
			last = set[i];
		}

		if (set[i].first < last.second && i == set.size() - 1) {
			subset += last;
		}
	}

	return subset;
}

int main() {

	// const LinearList<Pair<int, int>> set = {{-5, -3}, {-1, 5}, {4, 7}, {6, 9}, {8, 11}, {10, 12}, {0, 12}};
	const LinearList<Pair<int, int>> set = {{-1, 5}, {4, 7}, {6, 9}, {8, 11}, {10, 12}, {0, 12}};

	LinearList<Pair<int, int>> subset;

	// subset = MaxDisjointIntervalSet(set);
	// cout << subset << endl;

	subset = MinNecessaryIntervalSet(set);
	cout << subset << endl;

	return 0;
}

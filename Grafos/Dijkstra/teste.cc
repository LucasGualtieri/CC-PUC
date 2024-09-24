#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <thread>   // for this_thread::sleep_for
#include <chrono>   // for chrono::milliseconds

#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/list/linearList.hpp"

using namespace std;

// clear && g++ dijkstra.cc && ./a.out

// https://chatgpt.com/share/66f2ffed-43d8-8003-8ccd-ca32edc445f9

struct CompareBySecond {

	bool operator()(const pair<int, float>& p1, const pair<int, float>& p2) {
		return p1.second < p2.second;
	}
};

LinearList<int> dijkstra(int u, int v, Matrix<float> m) {

	LinearList<int> path;

	// priority_queue<pair<int, float>, vector<pair<int, float>>, CompareBySecond> pq(CompareBySecond(v));
	priority_queue<pair<int, float>, vector<pair<int, float>>, CompareBySecond> pq;

	int antecessores[m.width];
	for (int i = 0; i < m.width; i++) antecessores[i] = -1;

	int visitados[m.width];
	for (int i = 0; i < m.width; i++) visitados[i] = 0;

	visitados[u] = 1;

	pq.push({u, 0});

	int last;

	while (true) {

		auto [w, distance] = pq.top();
		pq.pop();

		visitados[w] = 1;

		// cout << "w: " << w << endl;
		// cout << "distance: " << distance << endl;

		last = w;

		if (w == v) {
			// break;
			for (int i = 0; i < m.width; i++) visitados[i] = 0;
			if (pq.empty()) break;
		}

		for (int i = 0; i < m.width; i++) {
			if (m[w][i] && !visitados[i]) {
				// cout << "i: " << i << endl;
				pq.push({i, distance + m[w][i]});
				antecessores[i] = w;
			}
		}

		// cout << "------------" << endl;

		// this_thread::sleep_for(chrono::milliseconds(500));
	}

	while (last != u) {
		path.push_front(last);
		last = antecessores[last];
	}

	path.push_front(u);

	return path;
}

int main() {

	Matrix<float> m = {
		{ 0, 1, 2, 3, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 5, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 3, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 3, 0 },
		{ 0, 0, 0, 0, 0, 0, 2, 2 }, // botar 2.1 resolve, pq ele fica empatado { (6, 7), (7, 7) } e o 6 é poppado primeiro
		{ 0, 0, 0, 0, 0, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	LinearList path = dijkstra(0, 7, m);

	cout << path << endl;

}
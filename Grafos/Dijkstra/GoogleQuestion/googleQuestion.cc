#include <iostream>
#include <queue>
#include <unordered_set>
#include "../../DataStructures/include/matrix/matrix.hpp"
#include "../../DataStructures/include/Pair.hpp"
#include "../../DataStructures/include/list/linearList.hpp"

#include "Graph.hpp"

using namespace std;

using Point = Pair<int, int>;

// Custom hash function for unordered_set
struct PointHash {
    size_t operator()(const Point& p) const {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
};

using Set = unordered_set<Point, PointHash>;

using PrirityQueue = std::priority_queue<
    std::pair<int, Point>,
    std::vector<std::pair<int, Point>>,
    std::greater<>
>;

// clear && g++ googleQuestion.cc -std=c++20 && ./a.out

LinearList<Point> adj(Point p, Matrix<float> m) {

	LinearList<Point> adjacentes;

	int i = p.first, j = p.second;

	LinearList<Point> deltas = { {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}, };

	for (auto [y, x] : deltas) {
		if (m.inBounds(y, x)) {
			adjacentes.push_back({y, x});
		}
	}

	return adjacentes;
}

void foo(Matrix<float>& m) {

	Point x = {0, 0};

	PrirityQueue Q;
	Q.push({m[0][0], x});

	Set visited;

	while (!Q.empty()) {

		auto [val, u] = Q.top();
		Q.pop();

		if (visited.count(u) > 0) continue;

		visited.insert(u);

		m[u.first][u.second] = val;

		for (auto [i, j] : adj(u, m)) {
			if (visited.count({i, j}) == 0) {
				Q.push({m[i][j] + m[u.first][u.second], {i, j}});
			}
		}
	}
}

float luis(Matrix<float>& m) {

	for (int i = 0; i < m.height; i++) {

		for (int j = 0; j < m.width; j++) {

			if (i == 0 && j == 0) continue;

			if (!m.inBounds(i - 1, j)) {
				m[i][j] += m[i][j - 1];
			}

			else if (!m.inBounds(i, j - 1)) {
				m[i][j] += m[i - 1][j];
			}

			else m[i][j] += min(m[i - 1][j], m[i][j - 1]);
		}
	}

	return m[m.height - 1][m.width - 1];
}

int main() {

	Matrix<float> m = {
		{0, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};

	Graph g = {
		{0, {{1, 3}, {3, 1}}},
		{1, {{0, 1}, {2, 1}, {4, 5}}},
		{2, {{1, 3}, {5, 1}}},
		{3, {{0, 1}, {4, 5}, {6, 4}}},
		{4, {{1, 3}, {3, 1}, {5, 1}, {7, 2} }},
		{5, {{2, 1}, {4, 5}, {8, 1}}},
		{6, {{3, 1}, {7, 2}}},
		{7, {{4, 5}, {6, 4}, {8, 1}}},
		{8, {{5, 1}, {7, 2}}},
	};

	cout << "Distances: " << g.dijkstra(0, m[0][0]) << endl;

	cout << "luis: " << luis(m) << endl;

	cout << m << endl;
}
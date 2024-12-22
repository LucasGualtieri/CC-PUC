#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cmath>

#include "../DataStructures/utils/Pair.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/list/linearList.hpp"

#include "../imageToMatrix.hpp"
#include "../utils.hpp"

using namespace std;

using Vertex = int;

using Edges = LinearList<Pair<Pair<Vertex, Vertex>, float>>;

// clear && g++ main.cc -std=c++20 && ./a.out

class UnionFind {

	LinearList<int> parent;
	LinearList<float> maxWeight; // Store the maximum weight for each set root
	size_t sets = 0;

  public:

	UnionFind(size_t n) : parent(n, 0), maxWeight(n, 0) { }

	size_t numberOfSets() { return sets; }

	void insert(Vertex vertex) {

		if (parent[vertex] == 0) {
			parent[vertex] = -1; // Initialize as its own root with size 1
			maxWeight[vertex] = 0; // Initially no edges, so max weight is 0
			sets++;
		}
	}

	bool connected(Vertex u, Vertex v) { return find(u) == find(v); }

	Vertex find(Vertex vertex) {

		if (parent[vertex] < 0) {
			return vertex; // Root element
		}

		return parent[vertex] = find(parent[vertex]); // Path compression
	}

	void join(Vertex u, Vertex v, float weight) {

		Vertex rootU = find(u), rootV = find(v);

		if (rootU == rootV) {
			// If already in the same set, update the max weight if needed
			maxWeight[rootU] = max(maxWeight[rootU], weight);
			return;
		}

		sets--;

		// Union by size: Attach the smaller tree under the larger tree

		// rootU has larger size
		if (parent[rootU] < parent[rootV]) {

			parent[rootU] += parent[rootV]; // Update size of rootU
			parent[rootV] = rootU;

			// Update max weight for the new root
			maxWeight[rootU] = max({ maxWeight[rootU], maxWeight[rootV], weight });
			// maxWeight.erase(rootV);
		}

		// rootV has larger or equal size
		else {

			parent[rootV] += parent[rootU]; // Update size of rootV
			parent[rootU] = rootV;

			// Update max weight for the new root
			maxWeight[rootV] = max({ maxWeight[rootV], maxWeight[rootU], weight });
			// maxWeight.erase(rootU);
		}
	}

	int setSize(Vertex vertex) {
		return -parent[find(vertex)];
	}

	int getMaxWeight(Vertex vertex) {
		return maxWeight[find(vertex)];
	}
};

float Int(Vertex x, UnionFind& unionFind) {
	return unionFind.getMaxWeight(x);
}

int threshold(Vertex& v, const int K, UnionFind& unionFind) {
	return K / unionFind.setSize(v);
}

float MInt(Vertex& u, Vertex& v, const int& K, UnionFind& unionFind) {
	return min(Int(u, unionFind) + threshold(u, K, unionFind), Int(v, unionFind) + threshold(v, K, unionFind));
}

bool D(const float& weight, Vertex& u, Vertex& v, const int& K, UnionFind& unionFind) {
	return weight > MInt(u, v, K, unionFind);
}

Segmentation ImageSegmentation(const int K, const Matrix<Pixel>& m, bool eightConnected = false) {

	int n = m.width * m.height;

	Edges sortedEdges(n * (eightConnected ? 8 : 4));

	for (int i = 0; i < m.height; i++) {

		for (int j = 0; j < m.width; j++) {

			Vertex u = i * m.width + j;

			for (auto& [x, y] : getNeighbors(i, j, m, eightConnected)) {

				float weight = dissimilarity(m[i][j], m[x][y]);

				Vertex v = x * m.width + y;

				sortedEdges += {{ u, v }, weight};
			}
		}
	}

	sortedEdges.sort([](auto& a, auto& b) {
		return a.second < b.second;
	});

	UnionFind unionFind(n);

	for (int i = 0; i < n; i++) {
		unionFind.insert(i);
	}
	
	for (auto [edge, w] : sortedEdges) {

		auto [u, v] = edge;

		if (!unionFind.connected(u, v) && !D(w, u, v, K, unionFind)) {
			unionFind.join(u, v, w);
		}
	}

	Segmentation segmentation;

	for (Vertex i = 0; i < n; i++) {
		Vertex root = unionFind.find(i);
		segmentation[root] += i;
	}

	int min = 50;

	for (auto [edge, w] : sortedEdges) {

		auto [u, v] = edge;

		if (unionFind.connected(u, v)) continue;

		Vertex rootU = unionFind.find(u);
		Vertex rootV = unionFind.find(v);

		LinearList<Vertex>& cU = segmentation[rootU];
		LinearList<Vertex>& cV = segmentation[rootV];

		if (cU.size() < min) {

			for (Vertex& x : cU) cV += x;

			unionFind.join(rootU, rootV, 0);
			segmentation.erase(rootU);
		}

		else if (cV.size() < min) {

			for (Vertex& x : cV) cU += x;

			unionFind.join(rootV, rootU, 0);
			segmentation.erase(rootV);
		}
	}

	return segmentation;
}

int main() {

	Matrix<Pixel> image = loadPPM("inputImages/paper", .8);

	Segmentation segment = ImageSegmentation(100'000, image, true);

	cout << "Seg size: " << segment.size() << endl;

	saveSegmentedImage("outputImages/paper", segment, image);

	return 0;
}

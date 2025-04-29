#include <iostream>
#include <stdexcept>

#include "../../../PAA-TP01/DataStructures/include/graph/Graph.hpp"
#include "../../../PAA-TP01/DataStructures/include/graph/GraphBuilder.hpp"
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
#include "../../../PAA-TP01/include/timer.hpp"

// clear && g++ independentSet.cpp -std=c++20 && ./a.out

using namespace std;

// size_t factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }
//
// size_t subsetCombinations(int k, int n) {
// 	return factorial(n) / (factorial(k) * factorial(n - k));
// }

size_t subsetCombinations(int k, int n) {

    if (k > n) return 0;
    if (k > n - k) k = n - k;  // Use symmetry: C(n, k) == C(n, n-k)
    
    size_t result = 1;

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);  // Divide step-by-step to prevent overflow
    }

    return result;
}

template <typename T>
LinearList<LinearList<T>> GenerateKSubsets(const LinearList<T>& set, size_t k) {

	int N = set.size();

	if (k < 0 || N < k) {
		throw runtime_error("Value of k must be 0 < k < n");
	}

	LinearList<LinearList<T>> subsets(k);

	LinearList<T> aux(k);

	int currentIndex = 0;

	size_t combinations = subsetCombinations(k, N);

	for (int j = 0; j < combinations; j++) {

		while (aux.size() < k) {

			if (currentIndex >= N) {
				if (aux.back() == set.back()) aux.pop_back();
				currentIndex = set.indexOf(aux.pop_back()) + 1;
			}

			aux += set[currentIndex++];
		}

		subsets += aux;

		if (!aux.empty()) aux.pop_back();
	}

	return subsets;
}

bool isIndependentSet(const Graph& G, const LinearList<Vertex>& subset) {

	for (const Vertex& u : subset) {
		for (const Vertex& v : subset) {
			if (G.hasEdge({u, v})) return false;
		}
	}

	return true;
}

LinearList<Vertex> LargestIndependentSet(const Graph& G, const LinearList<Vertex>& vertices) {

	int l = 1, r = vertices.size(), k;

	LinearList<LinearList<Vertex>> subsets;
	LinearList<Vertex> largestIndependentSet;

	while (l <= r) {

		k = (l + r) / 2;

		subsets = GenerateKSubsets(vertices, k);

		for (const LinearList<Vertex>& subset : subsets) {

			if (isIndependentSet(G, subset)) {

				largestIndependentSet = subset;
				l = k + 1;

				break;
			}
		}

		if (l != k + 1) r = k - 1;
	}

	// for (int i = vertices.size(); i >= 0; i--) {
	//
	// 	subsets = GenerateKSubsets(vertices, i);
	//
	// 	for (const LinearList<Vertex>& subset : subsets) {
	//
	// 		if (isIndependentSet(G, subset)) return subset;
	// 	}
	// }

	return largestIndependentSet;
}

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	Timer t;

	size_t n = 25;

	for (Vertex v = 0; v < n; v++) {
		G.addVertex(v);
	}

	for (Vertex u = 0; u < n - 1; u++) {
		for (Vertex v = u + 1; v < n; v++) {
			G.addEdge({u, v});
		}
	}

	G.removeEdge({0, 1});
	G.removeEdge({0, 2});
	G.removeEdge({1, 2});

	G.removeEdge({3, 4});

	// G.export_to("test", "circo");

	const LinearList<Vertex> vertices = G.vertices();

	t.start();
	LinearList<Vertex> largestIndependentSet = LargestIndependentSet(G, vertices);
	t.stop();

	cout << t << "s" << endl;

	cout << largestIndependentSet << endl;

	return 0;
}

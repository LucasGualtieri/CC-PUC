#include <format>
#include <iostream>
#include <random>

#include "../../../PAA-TP01/DataStructures/utils/UnionFind.hpp"
#include "../../../PAA-TP01/DataStructures/include/graph/Graph.hpp"
#include "../../../PAA-TP01/DataStructures/include/list/linearList.hpp"
// #include "../../../PAA-TP01/DataStructures/include/queue/maxHeap.hpp"
#include "../../../PAA-TP01/DataStructures/include/graph/GraphBuilder.hpp"

// clear && g++ -std=c++23 greedyVertexCover.cpp && ./a.out

using namespace std;

int Random(const int& inferiorLimit, const int& superiorLimit) {

	std::random_device rd;  // Obtain a random seed from hardware
	std::mt19937 gen(rd()); // Initialize Mersenne Twister PRNG
	std::uniform_int_distribution<int> dist(inferiorLimit, superiorLimit); // Inclusive Range [a, b]

	return dist(gen);
}

Graph GenerateRandomConnectedGraph(const size_t& n, const float& density) {

	float minDensity = (2.0 * n - 2) / (n * n - n);

	if (density < minDensity) {
		throw std::runtime_error(std::format("Density must be greater than {}", minDensity));
	}

	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	LinearList<Vertex> D(n, 0);
	UnionFind<Vertex> uf;

	for (Vertex v = 0; v < n; v++) {
		uf.insert(v);
		G.addVertex(v);
	}

	const LinearList<Vertex> vertices = G.vertices();

	int contador = 0, colisions = 0;
	int m = ((n * n - n) / 2.0) * density;

	while (contador < m) {

		Vertex u = Random(0, n - 1);
		Vertex v = Random(0, n - 1);

		if (u != v && !G.hasEdge({v, u})) {

			uf.join(u, v);
			G.addEdge({u, v});
			D[u]++, D[v]++;

			contador++;
		}
	}

	if (uf.numberOfSets() > 1) {

		LinearList<Vertex> heads = uf.heads();

		Vertex u = heads[0];

		for (int i = 1; i < heads.size(); i++) {
			Vertex v = heads[i];
			uf.join(u, v);
			G.addEdge({u, v});
			D[u]++, D[v]++;
		}
	}

	return G;
}

void GraphStats(const Graph& G) {

	cout << format("n: {}", G.n) << endl;
	cout << format("m: {}", G.m) << endl;
	cout << format("density: {}", G.density()) << endl;
	cout << "--------------------" << endl;
}

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

LinearList<Vertex> OptimumVC(const Graph& G) {

	const LinearList<Vertex> vertices = G.vertices();

	return vertices - LargestIndependentSet(G, vertices);
}

LinearList<Vertex> GreedyVC(const Graph& G) {

	LinearList<Vertex> vertices = G.vertices(), degrees(G.n, 0), result;

	for (Vertex v : vertices) {
		degrees[v] = G.degree(v);
	}

	vertices.sort([degrees](auto a, auto b) {
		return degrees[a] > degrees[b];
	});

	int count = G.m;

	for (int i = 0; i < G.n && count > 0; i++) {

		Vertex u = vertices[i];

		count -= degrees[u];
		result += u;

		for (Vertex v : G.neighbors(u)) {
			degrees[v]--;
		}

		degrees[u] = 0;
	}

	return result;
}

void TestandoGrafoRoda() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
	.build();

	for (int i = 0; i < 7; i++) {
		G.addVertex(i);
	}

	G.addEdge({0, 1});
	G.addEdge({0, 2});
	G.addEdge({0, 3});
	G.addEdge({0, 4});
	G.addEdge({0, 5});
	G.addEdge({0, 6});
	G.addEdge({1, 2});
	G.addEdge({2, 3});
	G.addEdge({3, 4});
	G.addEdge({4, 5});
	G.addEdge({5, 6});
	G.addEdge({6, 1});

	G.export_to("Grafo_Roda", "circo");

	LinearList<Vertex> OCV = OptimumVC(G);
	LinearList<Vertex> GCV = GreedyVC(G);

	cout << "OCV: " << OCV << endl;
	cout << "GCV: " << GCV << endl;
}

int main() {

	int counter = 0;
	float error = 0;
	LinearList<Vertex> OCV, GCV;

	for (int i = 0; i < 30; i++) {

		float density = Random(25, 100) / 100.0f;

		for (int n = 10; n <= 15; n++) { // Da pra ir ate uns 25-28

			Graph G = GenerateRandomConnectedGraph(n, density);

			OCV = OptimumVC(G);
			GCV = GreedyVC(G);

			error += 1 - OCV.size() / (float)GCV.size();
			counter++;

			{
				cout << format("|OCV| = {}", OCV.size()) << endl;
				cout << format("|GCV| = {}", GCV.size()) << endl;
				cout << format("Current average: {:.2f}%", (error / counter) * 100) << endl;

				GraphStats(G);
			}
		}
	}

	error /= counter;

	cout << format("Average error is: {:.2f}%", error * 100) << endl;

	return 0;
}

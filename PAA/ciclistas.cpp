#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>

#include "../../PAA-TP01/DataStructures/include/graph/Graph.hpp"
#include "../../PAA-TP01/DataStructures/include/graph/GraphBuilder.hpp"
#include "../../PAA-TP01/DataStructures/include/matrix/matrix.hpp"

// clear && g++ -std=c++20 ciclistas.cpp && ./a.out

using namespace std;

template <typename T>
void backtrack(vector<T>& nums, int start, vector<vector<T>>& result) {

    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {

        swap(nums[start], nums[i]);
        backtrack(nums, start + 1, result);
        swap(nums[start], nums[i]);  // Backtrack
    }
}

template <typename T>
vector<vector<T>> generatePermutations(vector<T> nums) {

    vector<vector<T>> result;
    backtrack(nums, 0, result);

    return result;
}

Graph BuildGraph(const vector<int>& A, const vector<int>& C) {

	int n = A.size();

	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
		.directed()
		.weighted()
	.build();

	float infinity = numeric_limits<float>::infinity();

	G.addVertex(0);
	G.addVertex(1);
	G.changeVertexLabel(0, "S");
	G.changeVertexLabel(1, "T");

	for (int i = 2; i < n + 2; i++) {
		G.addVertex(i);
		G.changeVertexLabel(i, format("a[{}]", A[i - 2]));
	}

	for (int i = 2 + n; i < 2 * n + 2; i++) {
		G.addVertex(i);
		G.changeVertexLabel(i, format("c[{}]", C[i - n - 2]));
	}

	// S -> V1
	for (int i = 2; i < n + 2; i++) {
		G.addEdge({0, i, 1.0f});
	}

	// V2 -> T
	for (int i = n + 2; i < 2 * n + 2; i++) {
		G.addEdge({i, 1, 1.0f});
	}

	// V1 -> V2
	for (int i = 2; i < n + 2; i++) {

		for (int j = n + 2; j < 2 * n + 2; j++) {

			float weight = abs(A[i - 2] - C[j - n - 2]);

			G.addEdge({i, j, weight});
		}
	}

	return G;
}

using Path = vector<Edge>;

float Bottleneck(Path& P, const Graph& gf) {

	float bottleneck = P[0].weight;

	for (const Edge& e : P) {
		bottleneck = min(bottleneck, e.weight);
	}

	return bottleneck;
}

Graph CreateResidualGraph(Matrix<int>& flow, const Graph& G) {

	Graph gf = G.cloneDataStructure(G.n);
	float newWeight;

	for (const Edge& e : G.edges()) {

		newWeight = e.weight - flow[e.u][e.v];

		if (newWeight > 0) {
			gf.addEdge({ e.u, e.v, newWeight });
		}

		newWeight = flow[e.u][e.v];

		if (newWeight > 0) {
			gf.addEdge({ e.v, e.u, newWeight });
		}
	}

	return gf;
}

Path FindPath(const Vertex& source, const Vertex& sink, const Graph& graph) {

    unordered_map<Vertex, float> dist;
    unordered_map<Vertex, Vertex> prev;
    priority_queue<pair<float, Vertex>, vector<pair<float, Vertex>>, greater<>> pq;

    for (const Vertex& v : graph.vertices()) {
        dist[v] = numeric_limits<float>::infinity();
        prev[v] = -1; // Sentinel value for undefined predecessors
    }

    dist[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {

        auto [currentDist, u] = pq.top();
        pq.pop();

        if (u == sink) break; // Stop early if we reach the destination

        for (auto [v, weight] : graph.edgesOf(u)) {

            float newDist = dist[u] + weight;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                prev[v] = u;
                pq.emplace(newDist, v);
            }
        }
    }

    if (dist[sink] == numeric_limits<float>::infinity()) {
        return {}; // No path found
    }

    // Reconstruct the shortest path
    Path path;

	for (Vertex v = sink; v != source; v = prev[v]) {
        path.push_back({prev[v], v});
    }

    reverse(path.begin(), path.end());

    return path;
}

void FordFulkerson(const Vertex& s, const Vertex& t, const Graph& G) {

	Matrix<int> flow(G.n, G.n);

	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			flow[i][j] = 0;
		}
	}

	Graph gf = CreateResidualGraph(flow, G);

	Path P;

	do {

		P = FindPath(s, t, gf);

		cout << "Path:" << endl;

		for (auto p : P) {
			cout << format("{{{}, {}}}", G.getLabel(p.u), G.getLabel(p.v)) << endl;
		}

		if (P.empty()) break;

		for (Edge& e : P) {

			// if (e.u == s) continue;

			if (G.hasEdge(e)) {
				flow[e.u][e.v] += e.weight;
			}

			else flow[e.v][e.u] -= e.weight;
		}

		gf = CreateResidualGraph(flow, G);

	} while (!P.empty());

	for (int i = 2; i < G.n; i++) {
		for (int j = 2; j < G.n; j++) {
			if (flow[i][j] > 0) {
				cout << format("e = ({}, {})", G.getLabel(i), G.getLabel(j)) << endl;
			}
		}
	}
}

int main() {

	vector<int> A = {0, 1, 2, 3, 4, 5, 6};
	vector<int> C = {0, 1, 2, 3, 4, 5, 0};
	vector<int> bestPermutation;

	int n = A.size(), bestSum = numeric_limits<int>::max();

	int count = 0;

	for (auto& permutation : generatePermutations(C)) {

		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += abs(A[i] - permutation[i]);
		}

		if (sum < bestSum) {
			bestSum = sum;
			bestPermutation = permutation;
		}

		// cout << count++ << "th permutation has sum: " << sum << endl;
	}

	cout << format("Best permutation has sum {}", bestSum) << endl;

	cout << "Best match is:" << endl;

	for (int i = 0; i < n; i++) {
		cout << format("({}, {})", A[i], bestPermutation[i]) << endl;
	}

	cout << endl;

	// Graph G = BuildGraph(A, C);
	//
	// G.export_to("teste");

	// FordFulkerson(0, 1, G);

	return 0;
}

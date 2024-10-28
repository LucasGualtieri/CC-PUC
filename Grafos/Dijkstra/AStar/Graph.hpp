#include <iostream>
#include <limits>
#include <sstream>
#include <utility>
#include <initializer_list>
#include <random>
#include <vector>

#include "../../DataStructures/include/list/linearList.hpp"
#include "../../DataStructures/include/queue/linkedQueue.hpp"
#include "../../DataStructures/include/queue/maxHeap.hpp"
#include "../../DataStructures/include/queue/minHeap.hpp"
#include "../../DataStructures/include/Triple.hpp"

#include "../timer.hpp"

// Define constants for infinity values
#define FLOAT_INFINITY std::numeric_limits<float>::max()
#define INT_INFINITY std::numeric_limits<int>::max()

// #define FLOAT_INFINITY std::numeric_limits<float>::infinity()
// #define INT_INFINITY std::numeric_limits<int>::infinity()

// Graph class definition
class Graph {

	// Construct the path from source to target using the predecessor array
	LinearList<int> constructPath(const int& source, int target, LinearList<int> predecessors) {

		LinearList<int> path;

		if (predecessors[target] != -1) {
			while (target != -1) {
				path.push_front(target);
				target = predecessors[target];
			}
		}

		return path;
	}

	// Check if the edge index is within bounds for the given vertex
	inline bool isEdgeInBounds(int i, int vertex) const {
		return 0 <= i && i < m && i < abs(V[vertex + 1]);
	}

	// Return the edge target and weight for a given index
	std::pair<int, float> getEdge(int index) {
		return { E[index], W[index] };
	}

	// Max and min helper functions
	auto max(auto a, auto b) { return a > b ? a : b; }
	auto min(auto a, auto b) { return a < b ? a : b; }

  public:

	// Adjacency list representation: arrays for vertices, edges, and weights
	int *V, *E;
	size_t n = 0, m = 0;
	float *W, *H;

	// Constructor that initializes the graph from an adjacency list
	Graph(std::initializer_list<std::pair<std::pair<int, int>, std::initializer_list<std::pair<int, float>>>> graph) {

		V = E = nullptr;
		W = H = nullptr;

		H = new float[n];

		// Determine the number of vertices (n)
		for (auto node : graph) {
			if (node.first.first > n) {
				n = node.first.first;
				H[node.first.first] = node.first.second;
			}
		}

		n++;
		V = new int[n + 1];

		// Initialize all vertices with -1
		for (int i = 0; i < n; i++) V[i] = -1;

		// Determine the number of edges (m)
		for (auto node : graph) m += node.second.size();

		E = new int[m];
		W = new float[m];

		int adjStartIndex = 0;

		// Populate the edge list and weights
		for (auto node : graph) {

			if (node.second.size() == 0) continue;

			V[node.first.first] = adjStartIndex;

			for (auto edge : node.second) {
				E[adjStartIndex] = edge.first;
				W[adjStartIndex] = edge.second;
				adjStartIndex++;
			}
		}

		V[n] = -INT_INFINITY;

		// Update the V for vertices without edges
		for (int i = n - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	Graph() {

		n = m = 0;
		V = E = nullptr;
		W = H = nullptr;
	}

	// Destructor to deallocate dynamic arrays
	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (W) delete[] W;
		if (H) delete[] H;
	}

	LinearList<int> Astar(int source, int target) {

		LinearList<float> D(n, FLOAT_INFINITY);
		LinearList<int> predecessors(n, -1);
		MinHeap<int, float> Q(n);

		D[source] = 0;
		Q.push({source, 0});

		while (!Q.empty()) {

			int u = Q.pop().first;

			for (int j = V[u]; isEdgeInBounds(j, u); j++) {

				const auto& [v, weight] = getEdge(j);

				if (D[u] + weight < D[v]) {

					D[v] = D[u] + weight;

					predecessors[v] = u;

					if (!Q.contains(v)) {
						Q.push({v, D[v] + H[v]});
					} else {
						Q.decreaseKey({v, D[v] + H[v]});
					}
				}
			}
		}

		return constructPath(source, target, predecessors);
	}

	// Print the graph as an adjacency list
	std::string str() const {

		std::stringstream output;

		for (int i = 1; i < n; i++) {

			output << "{ " << i << ", " << H[i] << " } : { ";

			for (int j = V[i]; isEdgeInBounds(j, i); j++) {
				output << "(" << E[j] << ", " << W[j] << ")";
				if (isEdgeInBounds(j + 1, i)) output << ", ";
			}

			output << " }";

			if (i < n - 1) output << std::endl;
		}

		return output.str();
	}

	// Overload the << operator to print the graph using std::ostream
	friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
		os << g.str();
		return os;
	}
};
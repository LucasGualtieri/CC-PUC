#include <iostream>
#include <limits>
#include <sstream>
#include <utility>
#include <initializer_list>

#include "../../DataStructures/include/list/linearList.hpp"
#include "../../DataStructures/include/queue/linkedQueue.hpp"
#include "../../DataStructures/include/queue/maxHeap.hpp"
#include "../../DataStructures/include/queue/minHeap.hpp"
#include "../../DataStructures/include/matrix/matrix.hpp"

// Define constants for infinity values
#define FLOAT_INFINITY std::numeric_limits<float>::max()
#define INT_INFINITY std::numeric_limits<int>::max()

// Graph class definition
class Graph {

	// Check if the edge index is within bounds for the given vertex
	inline bool isEdgeInBounds(int i, int vertex) const {
		return 0 <= i && i < m && i < abs(V[vertex + 1]);
	}

	// Return the edge target and weight for a given index
	std::pair<int, float> getEdge(int index) {
		return { E[index], edgeWeights[index] };
	}

  public:

	// Adjacency list representation: arrays for vertices, edges, and weights
	int *V, *E;
	size_t n = 0, m = 0;
	float *edgeWeights;

	// Constructor that initializes the graph from an adjacency list
	Graph(std::initializer_list<std::pair<int, std::initializer_list<std::pair<int, float>>>> graph) {

		V = E = nullptr;
		edgeWeights = nullptr;

		// Determine the number of vertices (n)
		for (auto node : graph) {
			if (node.first > n) n = node.first;
		}

		n++;
		V = new int[n + 1];

		// Initialize all vertices with -1
		for (int i = 0; i < n; i++) V[i] = -1;

		// Determine the number of edges (m)
		for (auto node : graph) m += node.second.size();

		E = new int[m];
		edgeWeights = new float[m];

		int adjStartIndex = 0;

		// Populate the edge list and weights
		for (auto node : graph) {

			if (node.second.size() == 0) continue;

			V[node.first] = adjStartIndex;

			for (auto edge : node.second) {
				E[adjStartIndex] = edge.first;
				edgeWeights[adjStartIndex++] = edge.second;
			}
		}

		V[n] = -INT_INFINITY;

		// Update the V for vertices without edges
		for (int i = n - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	// Destructor to deallocate dynamic arrays
	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (edgeWeights) delete[] edgeWeights;
	}

	LinearList<float> dijkstra(int x, float val) {

		LinearList<float> D(n, FLOAT_INFINITY);
		MinHeap<int, float> Q(n);

		Q.push({x, val});
		D[x] = val;

		while (!Q.empty()) {

			int u = Q.pop().first;

			for (int i = V[u]; isEdgeInBounds(i, u); i++) {

				auto [v, weight] = getEdge(i);

				if (D[u] + weight < D[v]) {

					D[v] = D[u] + weight;

					if (!Q.contains(v)) Q.push({v, D[v]});

					else Q.decreaseKey({v, D[v]});
				}
			}
		}

		return D;
	}

	// Print the graph as an adjacency list
	std::string str() const {

		std::stringstream output;

		for (int i = 0; i < n; i++) {

			output << i << ": { ";

			for (int j = V[i]; isEdgeInBounds(j, i); j++) {
				output << "(" << E[j] << ", " << edgeWeights[j] << ")";
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
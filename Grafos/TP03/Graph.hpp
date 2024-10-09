#include <iostream>
#include <limits>
#include <sstream>
#include <utility>
#include <initializer_list>

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/queue/maxHeap.hpp"
#include "../DataStructures/include/queue/minHeap.hpp"

// Define constants for infinity values
#define FLOAT_INFINITY std::numeric_limits<float>::max()
#define INT_INFINITY std::numeric_limits<int>::max()

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
		return { E[index], edgeWeights[index] };
	}

	// Max and min helper functions
	auto max(auto a, auto b) { return a > b ? a : b; }
	auto min(auto a, auto b) { return a < b ? a : b; }

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
		for (auto node : graph)
			if (node.first > n)
				n = node.first;

		n++;
		V = new int[n + 1];

		// Initialize all vertices with -1
		for (int i = 0; i < n; i++)
			V[i] = -1;

		// Determine the number of edges (m)
		for (auto node : graph)
			m += node.second.size();

		E = new int[m];
		edgeWeights = new float[m];

		int adjStartIndex = 0;

		// Populate the edge list and weights
		for (auto node : graph) {

			if (node.second.size() == 0)
				continue;

			V[node.first] = adjStartIndex;

			for (auto edge : node.second) {
				E[adjStartIndex] = edge.first;
				edgeWeights[adjStartIndex++] = edge.second;
			}
		}

		V[n] = -INT_INFINITY;

		// Update the V for vertices without edges
		for (int i = n - 1; i >= 0; i--) {
			if (V[i] == -1)
				V[i] = -abs(V[i + 1]);
		}
	}

	// Constructor for an empty graph with specified number of vertices and edges
	Graph(int n, int m) : n(n), m(m) {

		V = E = nullptr;
		edgeWeights = nullptr;

		V = new int[n + 1];
		E = new int[m];

		V[n] = -INT_INFINITY;
	}

	// Destructor to deallocate dynamic arrays
	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (edgeWeights) delete[] edgeWeights;
	}

	// Um array de visitados é importante para evitar loops infitos quando há ciclo negativo.
	LinearList<float> dijkstra(int x) {

		LinearList<float> D(n, FLOAT_INFINITY);
		MinHeap<int, float> Q(n);

		Q.push({x, 0});
		D[x] = 0;

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

	// Max-Min Capacity Path Algorithm
	LinearList<int> maxMinPath(int source, int target) {

		LinearList<int> predecessors(n, -1);
		MaxHeap<int, float> Q(n, -FLOAT_INFINITY);
		LinearList<float> nodeCapacity(n, -FLOAT_INFINITY);

		nodeCapacity[source] = FLOAT_INFINITY;

		while (!Q.empty()) {

			int u = Q.pop().first;

			if (u == target) break;

			for (int i = V[u]; isEdgeInBounds(i, u); i++) {

				auto [v, weight] = getEdge(i);
				float newCapacity = min(nodeCapacity[u], weight);

				if (nodeCapacity[v] < newCapacity) {
					predecessors[v] = u;
					nodeCapacity[v] = max(nodeCapacity[v], newCapacity);
					Q.decreaseKey({v, nodeCapacity[v]});
				}
			}
		}

		return constructPath(source, target, predecessors);
	}

	// Min-Max Capacity Path Algorithm
	LinearList<int> minMaxPath(int source, int target) {

		LinearList<int> predecessors(n, -1);
		MinHeap<int, float> Q(n, FLOAT_INFINITY);
		LinearList<float> nodeCapacity(n, FLOAT_INFINITY);

		nodeCapacity[source] = -FLOAT_INFINITY;

		while (!Q.empty()) {

			int u = Q.pop().first;

			if (u == target) break;

			for (int i = V[u]; isEdgeInBounds(i, u); i++) {

				auto [v, weight] = getEdge(i);
				float newCapacity = max(nodeCapacity[u], weight);

				if (nodeCapacity[v] > newCapacity) {
					predecessors[v] = u;
					nodeCapacity[v] = min(nodeCapacity[v], newCapacity);
					Q.decreaseKey({v, nodeCapacity[v]});
				}
			}
		}

		return constructPath(source, target, predecessors);
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
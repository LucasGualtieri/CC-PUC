#include <iostream>
#include <limits>
#include <sstream>
#include <utility>
#include <initializer_list>
#include <random>
#include <vector>

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

	Graph(std::vector<std::pair<int, std::vector<std::pair<int, float>>>> graph) {

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

	// Constructor for an empty graph with specified number of vertices and edges
	Graph(int n, int m) : n(n), m(m) {

		V = E = nullptr;
		edgeWeights = nullptr;

		V = new int[n + 1];
		E = new int[m];

		V[n] = -INT_INFINITY;
	}

	Graph() {

		n = m = 0;
		V = E = nullptr;
		edgeWeights = nullptr;
	}

	Graph(const Graph& g) {

		V = E = nullptr;
		edgeWeights = nullptr;

		n = g.n;
		m = g.m;

		V = new int[n];
		E = new int[m];
		edgeWeights = new float[m];

		for (int i = 0; i < n; i++) V[i] = g.V[i];
		for (int i = 0; i < m; i++) E[i] = g.E[i];
		for (int i = 0; i < m; i++) edgeWeights[i] = g.edgeWeights[i];
	}

	Graph operator=(const Graph& g) {

		V = E = nullptr;
		edgeWeights = nullptr;

		n = g.n;
		m = g.m;

		V = new int[n];
		E = new int[m];
		edgeWeights = new float[m];

		for (int i = 0; i < n; i++) V[i] = g.V[i];
		for (int i = 0; i < m; i++) E[i] = g.E[i];
		for (int i = 0; i < m; i++) edgeWeights[i] = g.edgeWeights[i];

		return *this;
	}

	// Graph operator=(Graph g) {

	// 	V = E = nullptr;
	// 	edgeWeights = nullptr;

	// 	n = g.n;
	// 	m = g.m;

	// 	V = new int[n];
	// 	E = new int[m];
	// 	edgeWeights = new float[m];

	// 	for (int i = 0; i < n; i++) V[i] = g.V[i];
	// 	for (int i = 0; i < m; i++) E[i] = g.E[i];
	// 	for (int i = 0; i < m; i++) edgeWeights[i] = g.edgeWeights[i];
	// }

	// Destructor to deallocate dynamic arrays
	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (edgeWeights) delete[] edgeWeights;
	}

	// Um array de visitados é importante para evitar loops infitos quando há ciclo negativo.
	LinearList<float> dijkstra(int x) {

		LinearList<float> D(n, FLOAT_INFINITY);
		LinearList<bool> visited(n, false);
		MinHeap<int, float> Q(n);

		Q.push({x, 0});
		D[x] = 0;

		while (!Q.empty()) {

			int u = Q.pop().first;
			visited[u] = true;

			for (int i = V[u]; isEdgeInBounds(i, u); i++) {

				auto [v, weight] = getEdge(i);

				// if (!visited[v]) {
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

	// Bellman-Ford algorithm to detect negative cycles and modify graph
    LinearList<float> bellmanFord(int source) {
        LinearList<float> distance(n, FLOAT_INFINITY);
        std::vector<int> predecessors(n, -1);
        distance[source] = 0;

        // Relax edges n-1 times
        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int j = V[u]; isEdgeInBounds(j, u); ++j) {
                    auto [v, weight] = getEdge(j);
                    if (distance[u] != FLOAT_INFINITY && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                        predecessors[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        bool negativeCycleDetected = false;
        std::vector<int> cycleVertices;
        for (int u = 0; u < n; ++u) {
            for (int j = V[u]; isEdgeInBounds(j, u); ++j) {
                auto [v, weight] = getEdge(j);
                if (distance[u] != FLOAT_INFINITY && distance[u] + weight < distance[v]) {
                    // Negative cycle detected
                    negativeCycleDetected = true;
                    cycleVertices.push_back(u);
                }
            }
        }

        // If a negative cycle is detected, make all edges in the cycle positive
        if (negativeCycleDetected) {
            modifyNegativeCycleEdges(cycleVertices);
            // Re-run Bellman-Ford after modifying the graph
            return bellmanFord(source);
        }

        return distance;
    }

    // Function to identify and modify negative cycle edges
    void modifyNegativeCycleEdges(const std::vector<int> &cycleVertices) {
        LinkedQueue<int> q;
        std::vector<bool> visited(n, false);

        // BFS to find all reachable vertices from the negative cycle nodes
        for (int vertex : cycleVertices) {
            q.push(vertex);
            visited[vertex] = true;
        }

        while (!q.empty()) {
            int u = q.pop();

            for (int j = V[u]; isEdgeInBounds(j, u); ++j) {
                auto [v, weight] = getEdge(j);

                // Modify the edge weight to a positive value (absolute value)
                // edgeWeights[j] = std::abs(weight);
                edgeWeights[j] = weight + 5;

                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

	// Method to generate a random graph with specified parameters
	static Graph generateRandom(int numVertices, int minWeight, int maxWeight) {

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> edgeDist(0, numVertices - 1);
		std::uniform_real_distribution<> weightDist(minWeight, maxWeight);

		std::initializer_list<std::pair<int, std::initializer_list<std::pair<int, float>>>> edges = {};

		Graph g(numVertices, 0);

		int edgeCount = 0;
		std::vector<std::pair<int, std::vector<std::pair<int, float>>>> adjList(numVertices);

		// Generate random edges and weights
		for (int i = 0; i < numVertices; ++i) {

			std::vector<std::pair<int, float>> vertexEdges = {};
			for (int j = 0; j < numVertices; ++j) {
				if (i != j && edgeDist(gen) < numVertices / 2) {  // Randomly select some edges to keep the graph sparse
					float weight = weightDist(gen);
					vertexEdges.push_back({j, weight});
					++edgeCount;
				}
			}
			adjList[i] = {i, vertexEdges};
		}

		g = Graph(adjList);
		return g;
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
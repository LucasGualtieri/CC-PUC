#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <fstream>  // For file operations
#include <cstdlib>  // For system()

#include "../DataStructures/include/list/linearList.hpp"

template <typename T>
class Graph {

	std::unordered_map<T, std::list<std::pair<T, float>>> adjList;
	bool diGraph;

public:

	Graph(bool diGraph = false) : diGraph(diGraph) {}

	Graph(std::initializer_list<std::pair<T, std::initializer_list<std::pair<T, float>>>> init, bool isDirected = false) {

		this->diGraph = diGraph;

		for (const auto& [vertex, edges] : init) {
			for (const auto& [neighbor, weight] : edges) {
				addEdge(vertex, neighbor, weight);
			}
		}
	}

	T getFirstVertex() const {

		if (!adjList.empty()) {
			return adjList.begin()->first;
		}

		throw std::runtime_error("Graph is empty!");
	}

	Graph generateMST(T u) {

		Graph mst;

		std::unordered_set<T> visited;

		std::priority_queue<std::pair<float, std::pair<T, T>>, std::vector<std::pair<float, std::pair<T, T>>>, std::greater<>> Q;

		for (const auto& [v, weight] : getNeighbors(u)) {
			Q.push({weight, {u, v}});
		}

		visited.insert(u);

		while (!Q.empty() && visited.size() != adjList.size()) { // O !Q.empty() é importante pra grafos desconexos

			const auto [weight, edge] = Q.top();
			const auto [u, v] = edge;
			Q.pop();

			if (visited.count(v)) continue; // Talvez isso seja desnecessario se usarmos decrease key

			mst.addEdge(u, v, weight);
			visited.insert(v);

			for (const auto& [w, weight] : getNeighbors(v)) {
				if (!visited.count(w)) Q.push({weight, {v, w}});
			}
		}

		return mst;
	}

	void addEdge(T u, T v, float weight) {

		if (!edgeExists(u, v)) {
			adjList[u].push_back({v, weight});
			if (!diGraph) adjList[v].push_back({u, weight});
		}
	}

	bool edgeExists(T u, T v) const {

		if (adjList.find(u) != adjList.end()) {
			for (const auto& [neighbor, _] : adjList.at(u)) {
				if (neighbor == v) {
					return true;
				}
			}
		}

		return false;
	}

	std::list<std::pair<T, float>> getNeighbors(T u) const {

		if (adjList.find(u) != adjList.end()) {
			return adjList.at(u);
		}

		return {};
	}

	// Function to export the graph to a PNG image using Graphviz
	void exportGraph(const std::string& filename, const std::string& engine = "dot") const {

		// 1. Create a DOT file representing the graph
		std::string dotFilename = filename + ".dot";
		std::ofstream dotFile(dotFilename);

		if (!dotFile) {
			throw std::runtime_error("Could not create the DOT file.");
		}

		dotFile << (diGraph ? "digraph" : "graph") << " G {\n";

		for (const auto& [u, neighbors] : adjList) {
			for (const auto& [v, weight] : neighbors) {
				if (!diGraph && u > v) continue;  // Avoid duplicate edges for undirected graphs

				dotFile << "    " << u << (diGraph ? " -> " : " -- ") << v << " [label=\"" << weight << "\"];\n";
			}
		}

		dotFile << "}\n";
		dotFile.close();

		// 2. Use the system() function to run the Graphviz command
		std::string command = engine + " -Tpng " + dotFilename + " -o " + filename + ".png";

		if (system(command.c_str()) != 0) {
			throw std::runtime_error("Failed to execute Graphviz command.");
		}

		std::cout << "Graph exported successfully to " << filename << ".png\n";
	}

	std::string str() const {

		std::stringstream os;
		std::vector<T> vertices;

		for (const auto& [vertex, _] : adjList) vertices.push_back(vertex);

		std::sort(vertices.begin(), vertices.end());

		for (T vertex : vertices) {

			os << vertex << ": { ";

			for (const auto& [neighbor, weight] : adjList.at(vertex)) {
				os << "(" << neighbor << ", " << weight << ") ";
			}

			os << "}" << std::endl;
		}

		std::string result = os.str();

		return result.empty() ? result : result.substr(0, result.size() - 1);
	}

	friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
		os << g.str();
		return os;
	}
};

#endif
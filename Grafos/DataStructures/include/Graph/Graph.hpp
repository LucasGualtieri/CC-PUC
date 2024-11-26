#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../list/linearList.hpp"
#include "../../utils/Pair.hpp"

#include "AdjacencyMatrix.hpp"
#include "AdjacencyMatrixPointers.hpp"
#include "DataStructure.hpp"
#include "Edge.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <format>

// TODO: Incluir m para keep count do numero de arestas em O(1)
class Graph {

public:

	enum DataStructures {
		AdjacencyMatrix, AdjacencyMatrixPointers
	};

private:

	DataStructure* dataStructure;
	bool directed, weighted;
	DataStructures choice;

	Graph(DataStructure* dataStructure, size_t n, bool directed, bool weighted) {

		this->directed = directed;
		this->weighted = weighted;
		this->n = n;
		this->dataStructure = dataStructure;
	}

	DataStructure* dataStructureChoice(DataStructures choice) {

		switch (choice) {
			case AdjacencyMatrix:
				return new class AdjacencyMatrix(n);
			break;
			case AdjacencyMatrixPointers:
				return new class AdjacencyMatrixPointers(n);
			break;
			// case AdjacencyList
			// 	dataStructure = new class AdjacencyList;
			// break;
		}

		return nullptr;
	}

public:

	size_t n;

	Graph(DataStructures choice, size_t n, bool directed, bool weighted) {

		this->directed = directed;
		this->weighted = weighted;
		this->choice = choice;
		this->n = n;

		dataStructure = dataStructureChoice(choice);

		this->dataStructure->directed(directed);
		this->dataStructure->weighted(weighted);
	}

	Graph (const Graph& clone) {

		directed = clone.directed;
		weighted = clone.weighted;
		choice = clone.choice;
		n = clone.n;

		dataStructure = dataStructureChoice(choice);

		this->dataStructure->directed(directed);
		this->dataStructure->weighted(weighted);

		for (const Edge& e : clone.edges()) {
			addEdge(e);
		}
	}

	Graph& operator=(const Graph& G) {

		// NOTE: This is the function called by the "return graph;" "context".

		if (this != &G) {

			directed = G.directed;
			weighted = G.weighted;
			choice = G.choice;
			n = G.n;

			delete dataStructure;

			dataStructure = dataStructureChoice(choice);

			dataStructure->directed(directed);
			dataStructure->weighted(weighted);

			for (const Edge& e : G.edges()) {
				addEdge(e);
			}
        }

		return *this;
	}	

	Graph cloneDataStructure(size_t n = 0) const {
		return { choice, n, directed, weighted };
	}

	void printDataStructure() { dataStructure->print(); }

	~Graph() { delete dataStructure; }

	void addVertex(const Vertex& v) {
		dataStructure->addVertex(v);
		n++;
	}

	void addEdge(const Vertex& u, const Vertex& v, const float& weight) {

		if (!weighted) {
			throw std::runtime_error("You should not pass the weight of the edge");
		}

		if (!dataStructure->hasVertex(u)) addVertex(u);

		if (!dataStructure->hasVertex(v)) addVertex(v);

		dataStructure->addEdge(u, v, weight);

		if (!directed) dataStructure->addEdge(v, u, weight);
	}
	
	void addEdge(const Vertex& u, const Vertex& v) {

		if (weighted) {
			throw std::runtime_error("You must pass the weight of the edge");
		}

		if (!dataStructure->hasVertex(u)) addVertex(u);

		if (!dataStructure->hasVertex(v)) addVertex(v);

		dataStructure->addEdge(u, v);

		if (!directed) dataStructure->addEdge(v, u);
	}

	void addEdge(const Edge& e) {

		if (!dataStructure->hasVertex(e.u)) addVertex(e.u);

		if (!dataStructure->hasVertex(e.v)) addVertex(e.v);

		if (weighted) {

			dataStructure->addEdge(e.u, e.v, e.weight);

			if (!directed) dataStructure->addEdge(e.v, e.u, e.weight);
		}

		else {

			dataStructure->addEdge(e.u, e.v);

			if (!directed) dataStructure->addEdge(e.v, e.u);
		}
	}

	void changeEdgeWeight(const Edge& e, const float& weight) {
		dataStructure->changeEdgeWeight(e, weight);
	}

	void changeEdgeWeight(const Vertex& u, const Vertex& v, const float& weight) {
		dataStructure->changeEdgeWeight({ u, v }, weight);
	}

	Edge getEdge(const Edge& e) const {
		return dataStructure->getEdge(e);
	}

	Edge getEdge(const Vertex& u, const Vertex& v) const {
		return dataStructure->getEdge({u, v});
	}

	bool hasEdge(const Edge& e) const {
		return dataStructure->hasEdge(e.u, e.v);
	}

	bool hasEdge(const Vertex& u, const Vertex& v) const {
		return dataStructure->hasEdge(u, v);
	}

	size_t degree(const Vertex& v) const {
		return dataStructure->degree(v);
	}

	LinearList<Edge> edges() const { return dataStructure->edges(); }

	LinearList<Vertex> vertices() const {
		return dataStructure->vertices();
	}

	LinearList<Pair<Vertex, float>> neighbors(const Vertex& u) const {
		return dataStructure->neighbors(u);
	}

	LinearList<Vertex> neighbors(const Vertex& u, const bool& b) const {

		LinearList<Vertex> _kneighbors;

		for (Pair<Vertex, float> p : dataStructure->neighbors(u)) {
			_kneighbors.push_back(p.first);
		}

		return _kneighbors;
	}

	LinearList<Pair<Vertex, float>> operator[](const Vertex& u) {
		return dataStructure->neighbors(u);
	}

	// Function to export the graph to a PNG image using Graphviz
	void export_to(const std::string& filename, const std::string& engine = "dot") const {

		// 1. Create a DOT file representing the graph
		std::string dotFilename = filename + ".dot";
		std::ofstream dotFile(dotFilename);

		if (!dotFile) {
			throw std::runtime_error("Could not create the DOT file.");
		}

		dotFile << (directed ? "digraph" : "graph") << " G {\n";

		for (const Edge& e : edges()) {

			if (!directed && e.u > e.v) continue;  // Avoid duplicate edges for undirected graphs

			dotFile << "    " << e.u << (directed ? " -> " : " -- ") << e.v << " [label=\"" << (weighted ? std::format("{:.6g}", e.weight) : "") << "\"];\n";
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

	// TODO: Separar as arestas por virgulas
	std::string str() const {

		std::stringstream os;

		for (Vertex& u : vertices()) {

			os << u << ": { ";

			for (auto& [v, w] : neighbors(u)) {

				if (weighted) {
					os << "(" << v << ", " << w << ") ";
				}

				else os << v << " ";
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

	float density(const int& precision = 3) const {
		
		float m = edges().size();
		float n = this->n;

		float density = m / ((n * n - n) / (directed ? 1 : 2));

		float factor = std::pow(10, precision);
		return std::round(density * factor) / factor;
	}

	float sparsness() const { return 1 - density(); }

	// TODO: import function
};

#endif

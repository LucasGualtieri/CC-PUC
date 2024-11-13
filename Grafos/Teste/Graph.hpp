#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/Pair.hpp"

#include "AdjacencyMatrix.hpp"
#include "DataStructure.hpp"
#include "Edge.hpp"
#include <stdexcept>

class Graph {

	DataStructure* dataStructure;
	bool directed, weighted;

	public:

	size_t n;

	enum DataStructures {
		AdjacencyMatrix
	};

	Graph(DataStructures choice, size_t n, bool directed, bool weighted) {

		this->directed = directed;
		this->weighted = weighted;
		this->n = n;

		switch (choice) {
			case AdjacencyMatrix:
				dataStructure = new class AdjacencyMatrix(n);
			break;
		}

		this->dataStructure->directed(directed);
		this->dataStructure->weighted(weighted);
	}

	~Graph() { delete dataStructure; }

	void addEdge(int u, int v, float weight) {

		if (!weighted) {
			throw std::runtime_error("You should not pass the weight of the edge");
		}

		dataStructure->addEdge(u, v, weight);

		if (!directed) dataStructure->addEdge(v, u, weight);
	}
	
	void addEdge(int u, int v) {

		if (weighted) {
			throw std::runtime_error("You must pass the weight of the edge");
		}

		dataStructure->addEdge(u, v);

		if (!directed) dataStructure->addEdge(v, u);
	}

	void addEdge(const Edge& e) {

		if (weighted) {

			dataStructure->addEdge(e.u, e.v, e.weight);

			if (!directed) dataStructure->addEdge(e.v, e.u, e.weight);
		}

		else {

			dataStructure->addEdge(e.u, e.v);

			if (!directed) dataStructure->addEdge(e.v, e.u);
		}

	}

	LinearList<Edge> edges() const {
		return dataStructure->edges();
	}

	LinearList<Vertex> vertices() const {
		return dataStructure->vertices();
	}

	LinearList<Pair<Vertex, float>> kneighbors(Vertex u) const {
		return dataStructure->kneighbors(u);
	}

	LinearList<Pair<Vertex, float>> operator[](Vertex u) {
		return dataStructure->kneighbors(u);
	}

	std::string str() const {

		std::stringstream os;

		for (Vertex u : this->vertices()) {

			os << u << ": { ";

			for (const auto& [v, w] : this->kneighbors(u)) {

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

	// export
	// import
};

#endif

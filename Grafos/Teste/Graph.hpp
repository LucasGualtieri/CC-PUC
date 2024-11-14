#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/Pair.hpp"

#include "AdjacencyMatrix.hpp"
#include "DataStructure.hpp"
#include "Edge.hpp"
#include <iostream>
#include <stdexcept>

class Graph {

public:

	enum DataStructures {
		AdjacencyMatrix
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

public:

	size_t n;

	Graph(DataStructures choice, size_t n, bool directed, bool weighted) {

		this->directed = directed;
		this->weighted = weighted;
		this->choice = choice;
		this->n = n;

		switch (choice) {
			case AdjacencyMatrix:
				dataStructure = new class AdjacencyMatrix;
			break;
		}

		this->dataStructure->directed(directed);
		this->dataStructure->weighted(weighted);
	}

	Graph clone() const {

		// return Graph(dataStructure->clone(), n, directed, weighted);

		Graph G(this->choice, n, directed, weighted);

		for (const Edge& e : this->edges()) {
			G.addEdge(e);
		}

		return G;
	}

	~Graph() { delete dataStructure; }

	void addVertex(const Vertex& v) {
		n++;
		dataStructure->addVertex(v);
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

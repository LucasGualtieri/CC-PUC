#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include "DataStructure.hpp"
#include "Edge.hpp"

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/Pair.hpp"
#include <cstddef>
#include <limits>
#include <stdexcept>

const float INFINITY = std::numeric_limits<float>::infinity();

class AdjacencyMatrix : public DataStructure {

	LinearList<LinearList<float>> matrix;
	bool _weighted, _directed;

	public:

	AdjacencyMatrix() { }

	void directed(bool _directed) override {
		this->_directed = _directed;
	}

	void weighted(bool _weighted) override {
		this->_weighted = _weighted;
	}

	void addVertex(const Vertex& v) override {

		matrix.push_back(LinearList<float>(matrix.size() + 1, INFINITY));
		size_t size = matrix.size();

		for (LinearList<float>& list : matrix) {
			list.push_back(INFINITY);
		}
	}

	void addEdge(const Vertex& u, const Vertex& v, float weight = 1.0) override {
		matrix[u][v] = weight;
	}

	void changeEdgeWeight(const Edge& e, const float& weight) override {
		matrix[e.u][e.v] = weight;
	}

	virtual Edge getEdge(const Edge& e) const override {
		return { e.u, e.v, matrix[e.u][e.v] };
	}

	bool hasEdge(const Vertex& u, const Vertex& v, const float& weight) const override {
		return matrix[u][v] == weight;
	}

	bool hasEdge(const Vertex& u, const Vertex& v) const override {
		return matrix[u][v] != INFINITY;
	}

	bool hasVertex(const Vertex& v) const override {

		try {
			matrix[v];
			return true;
		}

		catch (std::out_of_range e) {
			return false;
		}
	}

	LinearList<Edge> edges() const override {

		LinearList<Edge> _edges;

		size_t n = matrix.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] != INFINITY) {
					_edges.push_back({ i, j, matrix[i][j], _directed, _weighted });
				}
			}
		}

		return _edges;
	}

	LinearList<Vertex> vertices() const override {

		size_t n = matrix.size();

		LinearList<Vertex> vertices(n);

		for (int i = 0; i < n; i++) {
			vertices.push_back(i);
		}

		return vertices;
	}

	LinearList<Pair<Vertex, float>> kneighbors(const Vertex& u) const override {

		size_t n = matrix.size();

		LinearList<Pair<Vertex, float>> _kneighbors(n);

		for (int i = 0; i < n; i++) {
			if (matrix[u][i] != INFINITY) {
				_kneighbors.push_back({i, matrix[u][i]});
			}
		}

		return _kneighbors;
	}
};

#endif

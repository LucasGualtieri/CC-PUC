#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include "DataStructure.hpp"
#include "Edge.hpp"
#include <iostream>

#include "../list/linearList.hpp"
#include "../../utils/Pair.hpp"
#include <cstddef>
// #include <limits>
#include <cmath>

// NOTE: Performance can be improved if we use LinearList<LinearList<float>*> matrix;
class AdjacencyMatrix : public DataStructure {

	// const float INFINITY = std::numeric_limits<float>::infinity();

	LinearList<LinearList<float>> matrix;
	bool _weighted, _directed;

	public:

	AdjacencyMatrix() { }

	AdjacencyMatrix(size_t n) {

		LinearList<float> row(n, INFINITY);

		for (int i = 0; i < n; i++) {
			matrix.push_back(row);
		}
	}

	void directed(bool _directed) override {
		this->_directed = _directed;
	}

	void weighted(bool _weighted) override {
		this->_weighted = _weighted;
	}

	// WARNING: esse metodo tem um problema se eu adicionar o vertice 5 ante do 1, tenho que criar uma matriz 5x5!
	void addVertex(const Vertex& v) override {

		for (LinearList<float>& list : matrix) {
			list.push_back(INFINITY);
		}

		matrix.push_back(LinearList<float>(matrix.size() + 1, INFINITY));
	}

	// WARNING: The function as it is will override edges
	// NOTE: It makes sense to check first and maybe throw an exception?
	void addEdge(const Vertex& u, const Vertex& v, float weight) override {
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
		return v < matrix.size();
	}

	size_t degree(const Vertex& v) const override {

		size_t _degree = 0;
		int n = matrix.size();

		for (int i = 0; i < n; i++) {
			if (matrix[v][i] != INFINITY) {
				_degree++;
			}
		}

		return _degree;
	}

	LinearList<Edge> edges() const override {

		LinearList<Edge> _edges;

		size_t n = matrix.size();

		for (int i = 0; i < n; i++) {
			for (int j = _directed ? 0 : i; j < n; j++) {
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

	LinearList<Pair<Vertex, float>> neighbors(const Vertex& u) const override {

		size_t n = matrix.size();

		LinearList<Pair<Vertex, float>> _kneighbors(n);

		for (int i = 0; i < n; i++) {
			if (matrix[u][i] != INFINITY) {
				_kneighbors.push_back({i, matrix[u][i]});
			}
		}

		return _kneighbors;
	}

	void print() override {

		for (LinearList<float>& list : matrix) {
			std::cout << "{ ";
			for (float w : list) {
				std::cout << w << " ";
			}
			std::cout << "}" << std::endl;
		}
	}
};

#endif

#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include "DataStructure.hpp"
#include "Edge.hpp"

#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/Pair.hpp"

class AdjacencyMatrix : public DataStructure {

	Matrix<float> matrix;
	int n;
	bool _weighted, _directed;

	public:

	AdjacencyMatrix(int n) : n(n), matrix(n, n) { }

	void directed(bool _directed) override {
		this->_directed = _directed;
	}

	void weighted(bool _weighted) override {
		this->_weighted = _weighted;
	}

	void addEdge(int u, int v, float weight = 1.0) override {
		matrix[u][v] = weight;
	}

	LinearList<Edge> edges() const override {

		LinearList<Edge> _edges;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j]) {
					_edges.push_back({ i, j, matrix[i][j], _directed, _weighted });
				}
			}
		}

		return _edges;
	}

	LinearList<Vertex> vertices() const override {

		LinearList<Vertex> vertices(n);

		for (int i = 0; i < n; i++) {
			vertices.push_back(i);
		}

		return vertices;
	}

	LinearList<Pair<Vertex, float>> kneighbors(Vertex u) const override {

		LinearList<Pair<Vertex, float>> _kneighbors(n);

		for (int i = 0; i < n; i++) {
			if (matrix[u][i]) {
				_kneighbors.push_back({i, matrix[u][i]});
			}
		}

		return _kneighbors;
	}
};

#endif

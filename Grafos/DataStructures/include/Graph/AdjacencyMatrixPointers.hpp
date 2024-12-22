#ifndef ADJACENCY_MATRIX_FAST_HPP
#define ADJACENCY_MATRIX_FAST_HPP

#include "DataStructure.hpp"
#include "Edge.hpp"
#include <iostream>

#include "../list/linearList.hpp"
#include "../../utils/Pair.hpp"
#include <cstddef>
// #include <limits>
#include <cmath>

class AdjacencyMatrixPointers : public DataStructure {

	// const float INFINITY = std::numeric_limits<float>::infinity();

    LinearList<LinearList<float>*> matrix;
    bool _weighted, _directed;

public:

    AdjacencyMatrixPointers() { }

    AdjacencyMatrixPointers(size_t n) {
        for (size_t i = 0; i < n; i++) {
            matrix.push_back(new LinearList<float>(n, INFINITY));
        }
    }

    ~AdjacencyMatrixPointers() {

        for (auto row : matrix) {
            delete row;
        }
    }

    void directed(bool _directed) override {
        this->_directed = _directed;
    }

    void weighted(bool _weighted) override {
        this->_weighted = _weighted;
    }

    void addVertex(const Vertex& v) override {

        size_t newSize = matrix.size() + 1;

        for (auto row : matrix) {
            row->push_back(INFINITY); // Add a new column
        }

        matrix.push_back(new LinearList<float>(newSize, INFINITY)); // Add a new row
    }

    void addEdge(const Vertex& u, const Vertex& v, float weight) override {
        (*matrix[u])[v] = weight;
    }

    void changeEdgeWeight(const Edge& e, const float& weight) override {
        (*matrix[e.u])[e.v] = weight;
    }

    virtual Edge getEdge(const Edge& e) const override {
        return {e.u, e.v, (*matrix[e.u])[e.v]};
    }

    bool hasEdge(const Vertex& u, const Vertex& v, const float& weight) const override {
        return (*matrix[u])[v] == weight;
    }

    bool hasEdge(const Vertex& u, const Vertex& v) const override {
        return (*matrix[u])[v] != INFINITY;
    }

    bool hasVertex(const Vertex& v) const override {
        return v < matrix.size();
    }

	size_t degree(const Vertex& v) const override {

		size_t _degree = 0;
		int n = matrix.size();

		for (int i = 0; i < n; i++) {
			if (matrix[v][i] != (size_t)INFINITY) {
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
                if ((*matrix[i])[j] != INFINITY) {
                    _edges.push_back({i, j, (*matrix[i])[j], _directed, _weighted});
                }
            }
        }

        return _edges;
    }

    LinearList<Vertex> vertices() const override {

        LinearList<Vertex> vertices;

        for (size_t i = 0; i < matrix.size(); i++) {
            vertices.push_back(i);
        }

        return vertices;
    }

    LinearList<Pair<Vertex, float>> neighbors(const Vertex& u) const override {

        LinearList<Pair<Vertex, float>> _kneighbors;

        for (int i = 0; i < matrix.size(); i++) {
            if ((*matrix[u])[i] != INFINITY) {
                _kneighbors.push_back({i, (*matrix[u])[i]});
            }
        }
        return _kneighbors;
    }

    void print() override {

        for (auto row : matrix) {

            std::cout << "{ ";

            for (float w : *row) {
                std::cout << w << " ";
            }

            std::cout << "}" << std::endl;
        }
    }
};

#endif

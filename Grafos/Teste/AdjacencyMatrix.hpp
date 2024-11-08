#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include <iostream>

#include "DataStructure.hpp"
/*#include "WeightedEdge.hpp"*/
#include "Edge.hpp"

template <typename T>
class AdjacencyMatrix : public DataStructure<T> {

	public:

	void foo() const override {
		std::cout << "Usando AdjacencyMatrix" << std::endl;
	}

	LinearList<Edge> edges() const override {

		return {};
	}
};

#endif

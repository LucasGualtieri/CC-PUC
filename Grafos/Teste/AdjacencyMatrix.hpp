#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include <iostream>

// #include "DataStructure.hpp"

class AdjacencyMatrix : public DataStructure {

	public:

	void foo() const override {
		std::cout << "Usando AdjacencyMatrix" << std::endl;
	}
};

#endif
#ifndef GRAPH_BUILDER_HPP
#define GRAPH_BUILDER_HPP

#include "Graph.hpp"
#include <cstddef>
/*#include <initializer_list>*/

class GraphBuilder {

	Graph::DataStructures choice;
	bool _directed = false, _weighted = false;
	size_t _n = 0;

	public:

	// GraphBuilder& vertices() { return *this; }
	//
	// GraphBuilder& edges() { return *this; }

	// This should serve to avoid unecessary reallocs if the number of vertices and edges is pre known
	GraphBuilder& n(size_t _n) {

		this->_n = _n;

		return *this;
	}

	GraphBuilder& weighted() {

		_weighted = true;

		return *this;
	}

	GraphBuilder& directed() {

		_directed = true;

		return *this;
	}

	GraphBuilder& dataStructure(Graph::DataStructures choice) {
		this->choice = choice;
		return *this;
	}

	//
	// Essa função vai depender do grafo ser ou não ponderado, acho que o apropriado é ter um Overload e lançar uma exceção
	/*Graph build(std::initializer_list<std::initializer_list<T>>) {*/
	/*	return Graph(_dataStructure);*/
	/*}*/

	Graph build() { return Graph(choice, _n, _directed, _weighted); }

};

#endif

#ifndef GRAPH_BUILDER_HPP
#define GRAPH_BUILDER_HPP

#include "Graph.hpp"
#include "DataStructure.hpp"

class GraphBuilder {

	DataStructure* d;

	public:

	GraphBuilder& vertices() {
		return *this;
	}

	GraphBuilder& edges() {
		return *this;
	}

	GraphBuilder& dataStructure(DataStructure* d) {
		this->d = d;
		return *this;
	}

	Graph build() {
		return Graph(d);
	}

};

#endif

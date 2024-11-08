#ifndef GRAPH_BUILDER_HPP
#define GRAPH_BUILDER_HPP

#include "Graph.hpp"
#include "DataStructure.hpp"
#include <initializer_list>

template <typename T>
class GraphBuilder {

	DataStructure<T>* d = nullptr;

	public:

	GraphBuilder& vertices() { return *this; }

	GraphBuilder& edges() { return *this; }

	GraphBuilder& weighted() {



		return *this;
	}

	GraphBuilder& directed() {



		return *this;
	}

	GraphBuilder& dataStructure(DataStructure<T>* d) {
		this->d = d;
		return *this;
	}

	Graph<T> build(std::initializer_list<std::initializer_list<T>>) {
		return Graph<T>(d);
	}

	Graph<T> build() { return Graph<T>(d); }

};

#endif

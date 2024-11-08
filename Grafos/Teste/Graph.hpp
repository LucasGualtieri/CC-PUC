#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../DataStructures/include/list/linearList.hpp"

#include "DataStructure.hpp"
#include "Edge.hpp"

template <typename T>
class Graph {

	DataStructure<T>* d;

	public:

	Graph(DataStructure<T>* a) : d(d) {}

	void foo() { d->foo(); }

	LinearList<Edge> edges() {

		/*return d->edges();*/
		return {};
	}

	// export
	// import
	// print

};

#endif

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "DataStructure.hpp"

class Graph {

	DataStructure* d;

	public:

	Graph(DataStructure* a) : d(d) {}

	void foo() {
		d->foo();
	}

	// export
	// import
	// print

};

#endif
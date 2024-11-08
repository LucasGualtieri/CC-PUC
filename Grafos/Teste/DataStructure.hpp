#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include "../DataStructures/include/list/linearList.hpp"

#include "Edge.hpp"

template<typename T> 
class DataStructure {

	public:
	virtual void foo() const = 0;
	virtual LinearList<Edge> edges() const = 0;
	virtual ~DataStructure() {}
};

#endif

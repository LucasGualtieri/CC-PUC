#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include "../list/linearList.hpp"
#include "../../utils/Pair.hpp"

#include "Edge.hpp"

class DataStructure {

	public:
	virtual void addEdge(const Vertex& u, const Vertex& v, float weight = 1.0) = 0;
	virtual void changeEdgeWeight(const Edge& e, const float& weight) = 0;
	virtual Edge getEdge(const Edge& e) const = 0;
	virtual void addVertex(const Vertex& v) = 0;
	virtual size_t degree(const Vertex& v) const = 0;
	virtual bool hasEdge(const Vertex& u, const Vertex& v, const float& weight) const = 0;
	virtual bool hasEdge(const Vertex& u, const Vertex& v) const = 0;
	virtual bool hasVertex(const Vertex& v) const = 0;
	virtual void weighted(bool _weighted) = 0;
	virtual void directed(bool _directed) = 0;
	virtual LinearList<Edge> edges() const = 0;
	virtual LinearList<Vertex> vertices() const = 0;
	virtual LinearList<Pair<Vertex, float>> neighbors(const Vertex& u) const = 0;
	virtual void print() = 0;
	virtual ~DataStructure() {}
};

#endif

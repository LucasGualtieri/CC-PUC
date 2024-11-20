#ifndef EDGE_HPP
#define EDGE_HPP

#include <ostream>

using Vertex = int;

class Edge {

    bool weighted, directed;

public:
    Vertex u, v;
    float weight;

    Edge() : u(Vertex()), v(Vertex()), weight(float()), weighted(false), directed(false) { }

	Edge(const Vertex& u, const Vertex& v, const float& weight, const bool& directed, const bool& weighted) : u(u), v(v), weight(weight), directed(directed), weighted(weighted) { }

	// I don't know about these two here... Maybe they can cause issues?
	Edge(const Vertex& u, const Vertex& v, const bool& directed = false) : u(u), v(v), weight(1.0), directed(directed), weighted(false) { }
	Edge(const Vertex& u, const Vertex& v, const float& weight, const bool& directed = false) : u(u), v(v), weight(weight), directed(directed), weighted(true) { }

    Vertex getFirst() const { return u; }
    Vertex getSecond() const { return v; }
    float getWeight() const { return weight; }

    bool operator==(const Edge& other) const {
        return (this->u == other.u) && (this->v == other.v) && (this->weight == other.weight);
    }

    bool operator>(const Edge& other) const {
        return (this->weight > other.weight);
    }
	
    bool operator>=(const Edge& other) const {
        return (this->weight >= other.weight);
    }

    bool operator<(const Edge& other) const {
        return (this->weight < other.weight);
    }

    bool operator<=(const Edge& other) const {
        return (this->weight <= other.weight);
    }

	friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {

		if (edge.weighted && edge.directed) {
			os << "(" << edge.u << ", " << edge.v << ", " << edge.weight << ")";
		}

		else if (edge.weighted && !edge.directed) {
			os << "{" << edge.u << ", " << edge.v << ", " << edge.weight << "}";
		}

		else if (!edge.weighted && edge.directed) {
			os << "(" << edge.u << ", " << edge.v << ")";
		}

		else {
			os << "{" << edge.u << ", " << edge.v << "}";
		}

		return os;
	}
};

#endif

#ifndef FAST_ADJACENCY_LIST_HPP
#define FAST_ADJACENCY_LIST_HPP

#include "DataStructure.hpp"
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class FastAdjacencyList : public DataStructure {
private:
    std::unordered_map<Vertex, std::unordered_map<Vertex, float>> adjList;
    std::unordered_set<Vertex> vertexSet;
    bool isWeighted;
    bool isDirected;

public:
    FastAdjacencyList() : isWeighted(false), isDirected(false) {}

    void addEdge(const Vertex& u, const Vertex& v, float weight = 1.0) override {

        if (!isWeighted) weight = 1.0;

        adjList[u][v] = weight;
        vertexSet.insert(u);
        vertexSet.insert(v);

        if (!isDirected) {
            adjList[v][u] = weight;
        }
    }

    void changeEdgeWeight(const Edge& e, const float& weight) override {

		if (adjList[e.u].count(e.v)) {
			adjList[e.u][e.v] = weight;
			if (!isDirected) {
				adjList[e.v][e.u] = weight;
			}
		}

		else {
			throw std::runtime_error("Edge not found");
		}
	}

	Edge getEdge(const Edge& e) const override {
		if (adjList.count(e.u) && adjList.at(e.u).count(e.v)) {
			return {e.u, e.v, adjList.at(e.u).at(e.v)};
		}
		throw std::runtime_error("Edge not found");
	}

	void addVertex(const Vertex& v) override {
        if (!hasVertex(v)) {
            adjList[v] = {};
            vertexSet.insert(v);
        }
    }

    size_t degree(const Vertex& v) const override {
        if (!hasVertex(v)) throw std::runtime_error("Vertex not found");
        return adjList.at(v).size();
    }

    bool hasEdge(const Vertex& u, const Vertex& v, const float& weight) const override {
        return adjList.count(u) && adjList.at(u).count(v) && adjList.at(u).at(v) == weight;
    }

    bool hasEdge(const Vertex& u, const Vertex& v) const override {
        return adjList.count(u) && adjList.at(u).count(v);
    }

    bool hasVertex(const Vertex& v) const override {
        return vertexSet.count(v);
    }

    void weighted(bool _weighted) override {
        isWeighted = _weighted;
    }

    void directed(bool _directed) override {
        isDirected = _directed;
    }

    LinearList<Edge> edges() const override {
        LinearList<Edge> edgeList;
        for (const auto& [u, neighbors] : adjList) {
            for (const auto& [v, weight] : neighbors) {
                if (isDirected || u <= v) {
                    edgeList.push_back({u, v, weight});
                }
            }
        }
        return edgeList;
    }

    LinearList<Vertex> vertices() const override {

		LinearList<Vertex> vertexList(vertexSet.size());

		for (Vertex v : vertexSet) vertexList += v;

		return vertexList;
    }

    LinearList<Pair<Vertex, float>> neighbors(const Vertex& u) const override {

        if (!hasVertex(u)) throw std::runtime_error("Vertex not found");

        LinearList<Pair<Vertex, float>> neighborList;

        for (const auto& [v, weight] : adjList.at(u)) {
            neighborList.push_back({v, weight});
        }

        return neighborList;
    }

    void print() override {
        for (const auto& [u, neighbors] : adjList) {
            std::cout << u << ": ";
            for (const auto& [v, weight] : neighbors) {
                std::cout << "(" << v << ", " << weight << ") ";
            }
            std::cout << std::endl;
        }
    }

    ~FastAdjacencyList() override {}
};

#endif

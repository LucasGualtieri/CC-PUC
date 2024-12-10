#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include "DataStructure.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

class AdjacencyList : public DataStructure {
private:
    std::unordered_map<Vertex, std::vector<Pair<Vertex, float>>> adjList;
    std::unordered_set<Vertex> vertexSet;
    bool isWeighted;
    bool isDirected;

public:
	AdjacencyList() : isWeighted(false), isDirected(false) {}

	void addEdge(const Vertex& u, const Vertex& v, float weight = 1.0) override {
		if (!isWeighted) weight = 1.0;

		// Add the edge u -> v only if it doesn't already exist
		auto& neighbors = adjList[u];
		bool edgeExists = false;
		for (const auto& neighbor : neighbors) {
			if (neighbor.first == v) {
				edgeExists = true;
				break;
			}
		}
		if (!edgeExists) {
			neighbors.emplace_back(v, weight);
		}

		// Add vertices to the vertex set
		vertexSet.insert(u);
		vertexSet.insert(v);

		// For undirected graphs, add the edge v -> u as well
		if (!isDirected) {
			auto& reverseNeighbors = adjList[v];
			edgeExists = false;
			for (const auto& neighbor : reverseNeighbors) {
				if (neighbor.first == u) {
					edgeExists = true;
					break;
				}
			}
			if (!edgeExists) {
				reverseNeighbors.emplace_back(u, weight);
			}
		}
	}

    void changeEdgeWeight(const Edge& e, const float& weight) override {
        for (auto& neighbor : adjList[e.u]) {
            if (neighbor.first == e.v) {
                neighbor.second = weight;
                break;
            }
        }

        if (!isDirected) {
            for (auto& neighbor : adjList[e.v]) {
                if (neighbor.first == e.u) {
                    neighbor.second = weight;
                    break;
                }
            }
        }
    }

    Edge getEdge(const Edge& e) const override {
        for (const auto& neighbor : adjList.at(e.u)) {
            if (neighbor.first == e.v) {
                return {e.u, e.v, neighbor.second};
            }
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
        if (!hasVertex(u)) return false;
        for (const auto& neighbor : adjList.at(u)) {
            if (neighbor.first == v && neighbor.second == weight) {
                return true;
            }
        }
        return false;
    }

    bool hasEdge(const Vertex& u, const Vertex& v) const override {
        if (!hasVertex(u)) return false;
        for (const auto& neighbor : adjList.at(u)) {
            if (neighbor.first == v) {
                return true;
            }
        }
        return false;
    }

    bool hasVertex(const Vertex& v) const override {
        return vertexSet.find(v) != vertexSet.end();
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
                edgeList.push_back({u, v, weight});
            }
        }

        return edgeList;
    }

    LinearList<Vertex> vertices() const override {

        LinearList<Vertex> vertexList;

        for (const auto& v : vertexSet) {
            vertexList.push_back(v);
        }

        return vertexList;
    }

    LinearList<Pair<Vertex, float>> neighbors(const Vertex& u) const override {

        if (!hasVertex(u)) throw std::runtime_error("Vertex not found");

		LinearList<Pair<Vertex, float>> _neighbors;

		for (auto p: adjList.at(u)) {
			_neighbors += p;
		}

		return _neighbors;
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

    ~AdjacencyList() override {}
};

#endif

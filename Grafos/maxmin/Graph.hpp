#include <iostream>

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"

#define Infinity 0x7FFFFFFF

class Graph {
  public:

	int *V, *E, *C;
	int vSize = 0, eSize = 0;

	Graph(std::initializer_list<std::pair<int, std::initializer_list<std::pair<int, float>>>> graph) {

		V = E = C = nullptr;

		for (auto i : graph) if (i.first > vSize) vSize = i.first;
		vSize++;
		V = new int[vSize + 1];

		for (int i = 0; i < vSize; i++) V[i] = -1;

		for (auto i : graph) eSize += i.second.size();
		E = new int[eSize];

		C = new int[eSize];

		int adjStart = 0;

		for (auto j : graph) {

			if (j.second.size() == 0) continue;

			V[j.first] = adjStart;

			for (auto adj : j.second) {
				E[adjStart] = adj.first;
				C[adjStart++] = adj.second;
			}
		}

		V[vSize] = -Infinity;

		for (int i = vSize - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	Graph(int vSize, int eSize) : vSize(vSize), eSize(eSize) {

		V = E = C = nullptr;

		V = new int[vSize + 1];
		E = new int[eSize];

		V[vSize] = -Infinity;
	}

	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (C) delete[] C;
	}

	inline bool inBounds(int j, int i) const {
		return 0 <= j && j < eSize && j < abs(V[i + 1]);
	}

	int Max(int maxFlow[], bool visitados[], bool descobertos[]) {

		float maxFlowVal = std::numeric_limits<int>::min();
		int maxElement = 0;

		for (int i = 0; i < vSize; i++) {
			if (!visitados[i] && descobertos[i] && maxFlow[i] > maxFlowVal) {
				maxFlowVal = maxFlow[i];
				maxElement = i;
			}
		}

		return maxElement;
	}

	LinearList<int> maxmin(int u, int v) {

		int maxFlow[vSize], antecessores[vSize];
		bool visitados[vSize], descobertos[vSize];

		for (int i = 0; i < vSize; i++) {
			maxFlow[i] = std::numeric_limits<int>::max();
			visitados[i] = descobertos[i] = false;
			antecessores[i] = -1;
		}

		for (int i = 0; i < vSize; i++) {

			int w = Max(maxFlow, visitados, descobertos);
			visitados[w] = true;

			// std::cout << "w: " << w << std::endl;

			for (int y = V[w]; inBounds(y, w); y++) {

				int neighbor = E[y];

				descobertos[neighbor] = true;
				if (!visitados[neighbor]) {
					maxFlow[neighbor] = std::min(maxFlow[w], C[y]);
					antecessores[neighbor] = w;
				}
			}

			// LinearList<int> distances(vSize, maxFlow);
			// std::cout << distances << std::endl;
		}

		// LinearList<int> distances(vSize, maxFlow);
		// std::cout << distances << std::endl;

		return buildPath(u, v, antecessores);
	}

	int Min(int maxCapacity[], bool visitados[], bool descobertos[]) {

		float minFlowVal = std::numeric_limits<int>::max();
		int minElement = 0;

		for (int i = 0; i < vSize; i++) {
			if (!visitados[i] && descobertos[i] && maxCapacity[i] < minFlowVal) {
				minFlowVal = maxCapacity[i];
				minElement = i;
			}
		}

		return minElement;
	}

	LinearList<int> minmax(int u, int v) {

		int maxCapacity[vSize];
		int antecessores[vSize];
		bool visitados[vSize];
		bool descobertos[vSize];

		for (int i = 0; i < vSize; i++) {
			maxCapacity[i] = std::numeric_limits<int>::min();
			visitados[i] = descobertos[i] = false;
			antecessores[i] = -1;
		}

		maxCapacity[u] = 0;
		maxCapacity[v] = std::numeric_limits<int>::max();

		for (int i = 0; i < vSize; i++) {

			int w = Min(maxCapacity, visitados, descobertos);
			visitados[w] = true;

			// std::cout << "w: " << w << std::endl;

			for (int y = V[w]; inBounds(y, w); y++) {

				int neighbor = E[y];

				if (neighbor != v) descobertos[neighbor] = true;

				if (!visitados[neighbor]) {

					if (neighbor == v) {

						if (maxCapacity[v] > std::max(maxCapacity[w], C[y])) {

							antecessores[v] = w;
							maxCapacity[v] = std::max(maxCapacity[w], C[y]);
						}
					}

					else {
						maxCapacity[neighbor] = std::max(maxCapacity[w], C[y]);
						antecessores[neighbor] = w;
					}
				}
			}

			// LinearList<int> distances(vSize, maxCapacity);
			// std::cout << distances << std::endl;
		}

		// LinearList<int> distances(vSize, maxCapacity);
		// std::cout << distances << std::endl;

		return buildPath(u, v, antecessores);
	}

	LinearList<int> buildPath(const int& u, int v, int antecessores[]) {

		LinearList<int> shortestPath;

		if (antecessores[v] != -1) {

			while (v != u) {
				shortestPath.push_front(v);
				v = antecessores[v];
			}

			shortestPath.push_front(v);
		}

		return shortestPath;
	}

	LinearList<LinearList<int>> maxminMultiple(int u, int v) {

		int maxFlow[vSize];
		int antecessores[vSize];
		bool visitados[vSize];
		bool descobertos[vSize];

		for (int i = 0; i < vSize; i++) {
			maxFlow[i] = std::numeric_limits<int>::max();
			visitados[i] = descobertos[i] = false;
			antecessores[i] = -1;
		}

		LinearList<int> paths;

		for (int i = 0; i < vSize; i++) {

			int w = Max(maxFlow, visitados, descobertos);
			visitados[w] = true;

			// std::cout << "w: " << w << std::endl;

			for (int y = V[w]; inBounds(y, w); y++) {

				int neighbor = E[y];

				if (neighbor != v) descobertos[neighbor] = true;

				if (!visitados[neighbor]) {

					maxFlow[neighbor] = std::min(maxFlow[w], C[y]);

					if (neighbor == v) paths.push_back(w);
					else antecessores[neighbor] = w;
				}
			}
		}

		paths.sort([&maxFlow](int a, int b) { return maxFlow[a] - maxFlow[b]; });

		LinearList<LinearList<int>> shortestPath;

		while (!paths.empty()) {

			LinearList<int> caminho = buildPath(u, paths.pop_front(), antecessores);

			caminho.push_back(v);

			shortestPath.push_back(caminho);
		}

		return shortestPath;
	}

	std::string str() const {

		std::stringstream os;

		for (int i = 0; i < vSize; i++) {

			os << i << ": { ";

			for (int j = V[i]; inBounds(j, i); j++) {
				os << "(" << E[j] << ", " << C[j] << ")";
				if (inBounds(j + 1, i)) os << ", ";
			}

			os << " }";

			if (i < vSize - 1) os << std::endl;
		}

		return os.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
		os << g.str();
		return os;
	}
};
#include <iostream>

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/queue/minHeap.hpp"
#include "../DataStructures/include/Pair.hpp"

#define Infinity 0x7FFFFFFF

class Graph {

	inline bool inBounds(int j, int i) const {
		return 0 <= j && j < eSize && j < abs(V[i + 1]);
	}

  public:

	int *V, *E;
	float* W;
	int vSize = 0, eSize = 0;

	Graph(std::initializer_list<std::pair<int, std::initializer_list<std::pair<int, float>>>> graph) {

		V = E = nullptr;
		W = nullptr;

		for (auto i : graph) if (i.first > vSize) vSize = i.first;
		vSize++;
		V = new int[vSize + 1];

		for (int i = 0; i < vSize; i++) V[i] = -1;

		for (auto i : graph) eSize += i.second.size();
		E = new int[eSize];

		W = new float[eSize];

		int adjStart = 0;

		for (auto j : graph) {

			if (j.second.size() == 0) continue;

			V[j.first] = adjStart;

			for (auto adj : j.second) {
				E[adjStart] = adj.first;
				W[adjStart++] = adj.second;
			}
		}

		V[vSize] = -Infinity;

		for (int i = vSize - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	Graph(int vSize, int eSize) : vSize(vSize), eSize(eSize) {

		V = E = nullptr;
		W = nullptr;

		V = new int[vSize + 1];
		E = new int[eSize];

		V[vSize] = -Infinity;
	}

	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (W) delete[] W;
	}

	Pair<int, float> teste(int i) { return { E[i], W[i]}; }

	std::string str() const {

		std::stringstream os;

		for (int i = 0; i < vSize; i++) {

			os << i << ": { ";

			for (int j = V[i]; inBounds(j, i); j++) {
				os << "(" << E[j] << ", " << W[j] << ")";
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
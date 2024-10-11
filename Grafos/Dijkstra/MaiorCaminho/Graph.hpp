#include <initializer_list>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <queue>
#include <fstream>

#include "../../DataStructures/include/list/linkedList.hpp"
#include "../../DataStructures/include/list/linearList.hpp"
#include "../../DataStructures/include/queue/linkedQueue.hpp"
#include "../../DataStructures/include/stack/linkedStack.hpp"
#include "../../DataStructures/include/matrix/matrix.hpp"
#include "../../DataStructures/include/Pair.hpp"
#include "../../DataStructures/include/Triple.hpp"

#define Infinity 0x7FFFFFFF

class Graph {
  public:

	int *V, *E;
	int vSize = 0, eSize = 0;

	Graph(std::initializer_list<std::pair<int, std::initializer_list<int>>> graph) {

		V = E = nullptr;

		for (auto i : graph) if (i.first > vSize) vSize = i.first;
		vSize++;
		V = new int[vSize + 1];

		for (int i = 0; i < vSize; i++) V[i] = -1;

		for (auto i : graph) eSize += i.second.size();
		E = new int[eSize];

		int adjStart = 0;

		for (auto j : graph) {

			if (j.second.size() == 0) continue;

			V[j.first] = adjStart;

			for (auto adj : j.second) {
				E[adjStart++] = adj;
			}
		}

		V[vSize] = -Infinity;

		for (int i = vSize - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
	}

	inline bool inBounds(int y, int Y) {
		return 0 <= y && y < eSize && y < abs(V[Y + 1]);
	}

	LinearList<int> maiorCaminho(int source) {

		LinearList<int> grauDeEntrada(vSize);
		LinearList<int> predecessors(vSize);
		// LinearList<bool> visited(vSize);

		for (int i = 0; i < vSize; i++) {
			grauDeEntrada.push_back(0);
			predecessors.push_back(-1);
			// visited.push_back(false);
		}

		for (int i = 0; i < vSize; i++) {
			for (int j = V[i]; j >= 0 && inBounds(j, i); j++) {
				grauDeEntrada[E[j]]++;
			}
		}

		LinkedQueue<int> Q;

		for (int i = 0; i < vSize; i++) {
			if (grauDeEntrada[i] == 0) Q.push(i);
		}

		int lastVertex;

		while (!Q.empty()) {

			int u = Q.pop();
			lastVertex = u;
			// visited[u] = true;

			for (int i = V[u]; inBounds(i, u); i++) {

				int v = E[i];

				if (/* !visited[v] && */--grauDeEntrada[v] == 0) {
					Q.push(v);
					predecessors[v] = u;
				}
			}
		}

		return constructPath(source, lastVertex, predecessors);
	}

	// Construct the path from source to target using the predecessor array
	LinearList<int> constructPath(const int& source, int target, LinearList<int> predecessors) {

		LinearList<int> path;

		if (predecessors[target] != -1) {
			while (target != -1) {
				path.push_front(target);
				target = predecessors[target];
			}
		}

		return path;
	}

	std::string str() const {

		std::stringstream os;

		os << "V = { ";
		for (int i = 0; i < vSize; i++) {
			if (V[i] == Infinity) {
				os << "∞";
			}

			else if (V[i] == -Infinity) {
				os << "-∞";
			}
			else os << V[i];

			if (i < vSize - 1) os << ", ";
		}
		os << " }" << std::endl;

		os << "E = { ";
		for (int i = 0; i < eSize; i++) {
			os << E[i];
			if (i < eSize - 1) os << ", ";
		}
		os << " }" << std::endl;

		return os.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
		os << g.str();
		return os;
	}
};
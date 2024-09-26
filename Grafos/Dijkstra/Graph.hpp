#include <initializer_list>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

#include "../DataStructures/include/list/linkedList.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"

#define Infinity 0x7FFFFFFF

class Graph {
  public:

	int *V, *E;
	float *D;
	int vSize = 0, eSize = 0;

	Graph(std::initializer_list<std::pair<int, std::initializer_list<std::pair<int, float>>>> graph) {

		V = E = nullptr;
		D = nullptr;

		for (auto i : graph) if (i.first > vSize) vSize = i.first;
		vSize++;
		V = new int[vSize + 1];

		for (int i = 0; i < vSize; i++) V[i] = -1;

		for (auto i : graph) eSize += i.second.size();
		E = new int[eSize];

		D = new float[eSize];

		int adjStart = 0;

		for (auto j : graph) {

			if (j.second.size() == 0) continue;

			V[j.first] = adjStart;

			for (auto adj : j.second) {
				E[adjStart] = adj.first;
				D[adjStart++] = adj.second;
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
		if (D) delete[] D;
	}

	inline bool inBounds(int y, int Y) {
		return 0 <= y && y < eSize && y < abs(V[Y + 1]);
	}

	LinearList<int> DFS(int v) {

		LinearList<int> fechoTransitivoDireto;

		LinkedStack<int> s(v);

		int visitados[vSize];
		for (int i = 0; i < vSize; i++) visitados[i] = 0;

		visitados[v] = 1;

		while(!s.empty()) {

			int u = s.pop();
			fechoTransitivoDireto.push_back(u);

			for (int i = V[u]; inBounds(i, u); i++) {
				if (!visitados[E[i]]) {
					visitados[E[i]] = 1;
					s.push(E[i]);
				}
			}
		}

		fechoTransitivoDireto.sort();

		return fechoTransitivoDireto;
	}

	int findMin(float Lx[], bool S[]) {

		int argMin = 0;
		float minDistance = std::numeric_limits<float>::max();

		for (int i = 0; i < vSize; i++) {
			if (S[i] && Lx[i] < minDistance) {
				minDistance = Lx[i]; argMin = i;
			}
		}

		// Se todos os vertices de S estiverem com distancias infinitas retornamos qualquer um
		if (minDistance == std::numeric_limits<float>::max()) {
			for (int i = 0; i < vSize; i++) {
				if (S[i]) return i;
			}
		}

		return argMin;
	}

	LinearList<float> dijkstra(int x, int destino) {

		float Lx[vSize];
		bool S[vSize];
		int antecessores[vSize];

		for (int i = 0; i < vSize; i++) {
			Lx[i] = std::numeric_limits<float>::max();
			S[i] = true;
		}

		Lx[x] = 0;
		int k = 0;
		float u = 0;

		while (k < vSize && u != std::numeric_limits<float>::max()) {

			int Y = findMin(Lx, S); S[Y] = false;

			k++; u = Lx[Y];

			for (int y = V[Y]; inBounds(y, Y); y++) {

				if (S[E[y]]) {
					float temp = Lx[Y] + D[y];
					if (Lx[E[y]] > temp) antecessores[E[y]] = Y;
					Lx[E[y]] = std::min(Lx[E[y]], temp);
				}
			}
		}

		// while (Lx[destino] != std::numeric_limits<float>::max() && destino != x) {
		// 	std::cout << destino << " ";
		// 	destino = antecessores[destino];
		// }

		// std::cout << destino << std::endl;

		LinearList<float> distances(vSize, Lx);

		return distances;
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

		os << "D = { ";
		for (int i = 0; i < eSize; i++) {
			os << D[i];
			if (i < eSize - 1) os << ", ";
		}
		os << " }";

		return os.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
		os << g.str();
		return os;
	}
};
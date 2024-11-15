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

#include "../DataStructures/include/list/linkedList.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/Pair.hpp"
#include "../DataStructures/include/Triple.hpp"

#define Infinity 0x7FFFFFFF

class Graph {
  public:

	int *V, *E;
	float *W;
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

	Graph(std::initializer_list<std::pair<int, std::initializer_list<int>>> graph) {

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
		if (W) delete[] W;
	}

	inline bool inBounds(int y, int Y) {
		return 0 <= y && y < eSize && y < abs(V[Y + 1]);
	}

	LinearList<int> BFS(int v, int destino) {

		LinearList<int> fechoTransitivoDireto;

		LinkedQueue<Triple<int, int, int>> q({v, 0, -1});

		int visitados[vSize], antecessores[vSize];

		for (int i = 0; i < vSize; i++) {
			visitados[i] = 0;
			antecessores[i] = -1;
		}

		while(!q.empty()) {

			// std::cout << q << std::endl;

			auto [u, w, ancestral] = q.pop();

			if (visitados[u]) continue;

			if (w > 1) {
				q.push({u, w - 1, ancestral});
				continue;
			}

			antecessores[u] = ancestral;

			visitados[u] = 1;

			if (u == destino) break;

			fechoTransitivoDireto.push_back(u);

			for (int i = V[u]; inBounds(i, u); i++) {
				if (!visitados[E[i]]) {
					q.push({E[i], (int)W[i], u});
				}
			}
		}

		LinearList<int> shortestPath;

		if (antecessores[destino] != -1) {

			while (destino != v) {
				shortestPath.push_front(destino);
				destino = antecessores[destino];
			}

			shortestPath.push_front(v);

			// std::cout << "\nShortest Path: " << shortestPath << std::endl;

		}

		// fechoTransitivoDireto.sort();

		return shortestPath;
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
			antecessores[i] = -1;
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
					float temp = Lx[Y] + W[y];
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

	LinearList<int> maiorCaminho(int x) {

		LinearList<int> grauDeEntrada(vSize, 0);
		LinearList<int> antecessores(vSize, -1);
		LinearList<bool> visitados(vSize, false);
		LinkedQueue<int> Q;

		// montar o grau de entrada e inserir os de 0 na fila

		for (int i = 0; i < vSize; i++) {

			for (int j = V[i]; i >= 0 && inBounds(j, i); j++) {

				int v = E[j];


			}
		}

		while (!Q.empty()) {

			int u = Q.pop();
			visitados[u] = true;

			for (int i = V[u]; inBounds(i, u); i++) {

				int v = E[i];

				if (!visitados[v] && --grauDeEntrada[v] == 0) {
					Q.push(v);
					antecessores[v] = u;
				}
			}
		}

		// return buildPath()
	}

	int Min(float D[], bool visitados[]) {

		float minDist = std::numeric_limits<float>::max();
		int minElement;

		for (int i = 0; i < vSize; i++) {
			if (!visitados[i] && D[i] < minDist) {
				minDist = D[i];
				minElement = i;
			}
		}

		return minElement;
	}

	// Implementação intuitiva feita no quadro pelo Silvio
	LinearList<float> dijkstra1(int u) {

		float D[vSize];
		bool visitados[vSize];

		for (int i = 0; i < vSize; i++) {
			D[i] = std::numeric_limits<float>::max();
			visitados[i] = false;
		}

		D[u] = 0;

		for (int i = 0; i < vSize; i++) {

			int Y = Min(D, visitados);

			visitados[Y] = true;

			for (int y = V[Y]; inBounds(y, Y); y++) {
				D[E[y]] = std::min(D[E[y]], D[Y] + W[y]);
			}
		}

		LinearList<float> distances(vSize, D);

		return distances;
	}

	Pair<int, int> Min2(float D[], bool visitados[]) {

		Pair<int, int> pair;
		float minDist = std::numeric_limits<float>::max();

		for (int i = 0; i < vSize; i++) {

			for (int j = V[i]; visitados[i] && inBounds(j, i); j++) {

				int distance = D[i] + W[j];

				if (!visitados[E[j]] && distance < minDist) {
					minDist = distance;
					pair = {j, i};
				}
			}
		}

		return pair;
	}

	LinearList<float> dijkstra2(int u) {

		float D[vSize];
		bool visitados[vSize];

		for (int i = 0; i < vSize; i++) {
			D[i] = std::numeric_limits<float>::max();
			visitados[i] = false;
		}

		D[u] = 0;
		visitados[u] = true;

		for (int i = 0; i < vSize; i++) {

			auto [y, Y] = Min2(D, visitados);

			visitados[E[y]] = true;

			D[E[y]] = D[Y] + W[y];
		}

		LinearList<float> distances(vSize, D);

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
			os << W[i];
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

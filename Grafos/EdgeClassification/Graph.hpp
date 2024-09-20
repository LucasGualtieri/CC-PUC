#include <initializer_list>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>

#include "../DataStructures/include/list/linkedList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"

class Graph {
  public:

	int *V, *E;
	int vSize = 0, eSize = 0;
	int *tInicial, *tFinal;
	std::string* colors;
	std::string** labels;

	Graph(std::initializer_list<std::pair<int, std::initializer_list<int>>> graph) {

		for (auto i : graph) if (i.first > vSize) vSize = i.first;
		V = new int[++vSize];

		for (int i = 0; i < vSize; i++) V[i] = -1;

		for (auto i : graph) eSize += i.second.size() + 1;
		E = new int[eSize];

		int adjStart = 0;

		for (auto j : graph) {

			V[j.first] = adjStart;

			for (int adj : j.second) {
				E[adjStart++] = adj;
			}

			E[adjStart++] = -1;
		}

		labels = new std::string*[vSize];

		for (int i = 0; i < vSize; i++) {
			labels[i] = new std::string[vSize];
		}

		for (int i = 0; i < vSize; i++) {
			for (int j = 0; j < vSize; j++) {
				labels[i][j] = "\"\"";
			}
		}
	}

	void categorizarAresta(int u, int v) {

		if (tInicial[v] == 0 && tFinal[v] == 0) {
			labels[u][v] = "arv";
		}

		else if (tFinal[v] == 0) {
			labels[u][v] = "ret";
		}

		else if (tInicial[u] < tInicial[v]) {
			labels[u][v] = "ava";
		}

		else if (tInicial[v] < tInicial[u]) {
			labels[u][v] = "cruz";
		}
	}

	void DFS(int u, int& tempo, int visitados[]) {

		visitados[u] = 1;
		colors[u] = "\"blue\"";
		tInicial[u] = tempo++;

		exportar();

		for (int i = V[u]; V[u] != -1 && E[i] != -1; i++) {

			categorizarAresta(u, E[i]);

			if (!visitados[E[i]]) {
				DFS(E[i], tempo, visitados);
			}

			else if (E[i + 1] != -1) exportar();
		}

		tFinal[u] = tempo++;
		colors[u] = "\"red\"";
		exportar();
	}

	void Classificacao(int v = 0) {

		tInicial = new int[vSize];
		tFinal = new int[vSize];
		colors = new std::string[vSize];
		int visitados[vSize];

		for (int i = 0; i < vSize; i++) {
			tFinal[i] = tInicial[i] = visitados[i] = 0;
			colors[i] = "\"white\"";
		}

		int tempo = 1;

		exportar();

		DFS(v, tempo, visitados);

		for (int i = 0; i < vSize; i++) {
			if (!visitados[i] && V[i] != -1) DFS(i, tempo, visitados);
		}
	}

	void exportar() {

		static int index = 1;

		std::string filename = "graph.dot";

		std::ofstream outfile;

		outfile.open(filename, std::ios::out);

		if (!outfile.is_open()) {
			std::cerr << "Error: Could not open the file " << filename << " for writing." << std::endl;
			exit(-1);
		}

		// -------------------------------------------------------------------------------------------

		outfile << "digraph G {" << std::endl;

		// outfile << "\tsize=\"10!\";" << std::endl;

		outfile << "\t//Nodes" << std::endl;

		for (int i = 0; i < vSize; i++) {

			std::string var1 = tInicial[i] == 0 ? "-" : std::to_string(tInicial[i]);
			std::string var2 = tFinal[i] == 0 ? "-" : std::to_string(tFinal[i]);

			outfile << "\t" << std::to_string(i) << "[label = \"" << i << "[" << var1 << "," << var2 << "]\" fillcolor=" << colors[i] << ", style=\"filled\"];" << std::endl;
		}

		outfile << std::endl;

		outfile << "\t//Edges" << std::endl;

		for (int i = 0; i < vSize; i++) {
			for (int j = V[i]; V[i] != -1 && E[j] != -1; j++) {
				outfile << "\t" << std::to_string(i) << " -> " << E[j] << "[label=" << labels[i][E[j]] << "];" << std::endl;
			}
		}

		outfile << "}";

		outfile.close();

		std::string script = std::string("dot -Tpng graph.dot -o images/image") + std::to_string(index++) + std::string(".png");
		system(script.c_str());

	}

	LinkedList<int> BFS(int v) {

		LinkedList<int> fechoTransitivoDireto;

		LinkedQueue<int> q(v);

		int visitados[vSize];
		for (int i = 0; i < vSize; i++) visitados[i] = 0;

		visitados[v] = 1;

		while(!q.empty()) {

			int u = q.pop();
			fechoTransitivoDireto.push_back(u);

			for (int i = V[u]; V[u] != -1 && E[i] != -1; i++) {
				if (!visitados[E[i]]) {
					visitados[E[i]] = 1;
					q.push(E[i]);
				}
			}
		}

		return fechoTransitivoDireto;
	}

	LinkedList<int> DFS(int v) {

		LinkedList<int> fechoTransitivoDireto;

		LinkedStack<int> s(v);

		int visitados[vSize];
		for (int i = 0; i < vSize; i++) visitados[i] = 0;

		visitados[v] = 1;

		while(!s.empty()) {

			int u = s.pop();
			fechoTransitivoDireto.push_back(u);

			for (int i = V[u]; i != -1 && E[i] != -1; i++) {
				if (!visitados[E[i]]) {
					visitados[E[i]] = 1;
					s.push(E[i]);
				}
			}
		}

		return fechoTransitivoDireto;
	}

	std::string str() const {

		std::stringstream os;

		os << "V = { ";
		for (int i = 0; i < vSize; i++) {
			os << V[i];
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

	friend std::ostream& operator<<(std::ostream& os, const Graph g) {
		os << g.str();
		return os;
	}

	// ~Graph(); // para dar free para todos os arrays
};

// void Classificacao() {

// 	tInicial = new int[vSize];
// 	tFinal = new int[vSize];
// 	int visitados[vSize];

// 	for (int i = 0; i < vSize; i++) {
// 		tFinal[i] = tInicial[i] = visitados[i] = 0;
// 	}

// 	int tempo = 1;

// 	exportar();

// 	for (int i = 0; i < vSize; i++) {

// 		if (visitados[i] == 1) continue;

// 		LinkedStack<int> s(i);
// 		visitados[i] = 1;

// 		while (!s.empty()) {

// 			int u = s.peek();

// 			if (tInicial[u] == 0) {
// 				tInicial[u] = tempo++;
// 				exportar();
// 			}

// 			bool teste = false;

// 			for (int j = V[u]; j != -1; j = E[j]) {

// 				int neighbor = E[j];

// 				if (!visitados[neighbor]) {

// 					teste = true;
// 					visitados[neighbor] = 1;
// 					s.push(neighbor);

// 					break; // Process one neighbor at a time
// 				}
// 			}

// 			if (!teste) {
// 				tFinal[u] = tempo++;
// 				s.pop();
// 				exportar();
// 			}
// 		}
// 	}
// }
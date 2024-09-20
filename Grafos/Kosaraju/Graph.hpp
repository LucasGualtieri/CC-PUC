#include <initializer_list>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "../DataStructures/include/list/linkedList.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"

class Graph {
  public:

	int *V, *E, *colors, *tInicial, *tFinal;
	int vSize = 0, eSize = 0, color;

	Graph(std::initializer_list<std::pair<int, std::initializer_list<int>>> graph) {

		V = E = tInicial = tFinal = colors = nullptr;

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
	}

	Graph(int vSize, int eSize) : vSize(vSize), eSize(eSize) {

		V = E = tInicial = tFinal = colors = nullptr;

		V = new int[vSize];
		E = new int[eSize];
	}

	Graph(const Graph& g) {

		V = E = tInicial = tFinal = colors = nullptr;

		vSize = g.vSize;
		eSize = g.eSize;

		V = new int[vSize];
		E = new int[eSize];

		for (int i = 0; i < vSize; i++) V[i] = g.V[i];
		for (int i = 0; i < eSize; i++) E[i] = g.E[i];
	}

	Graph operator=(const Graph& g) {

		V = E = tInicial = tFinal = colors = nullptr;

		vSize = g.vSize;
		eSize = g.eSize;

		V = new int[vSize];
		E = new int[eSize];

		for (int i = 0; i < vSize; i++) V[i] = g.V[i];
		for (int i = 0; i < eSize; i++) E[i] = g.E[i];

	// 	if (g.V) delete[] g.V;
	// 	if (g.E) delete[] g.E;
	// 	if (g.tInicial) delete[] g.tInicial;
	// 	if (g.tFinal) delete[] g.tFinal;
	// 	if (g.colors) delete[] g.colors;
	}

	Graph operator=(Graph g) {

		V = E = tInicial = tFinal = colors = nullptr;

		vSize = g.vSize;
		eSize = g.eSize;

		V = new int[vSize];
		E = new int[eSize];

		for (int i = 0; i < vSize; i++) V[i] = g.V[i];
		for (int i = 0; i < eSize; i++) E[i] = g.E[i];

		// if (g.V) delete[] g.V;
		// if (g.E) delete[] g.E;
		// if (g.tInicial) delete[] g.tInicial;
		// if (g.tFinal) delete[] g.tFinal;
		// if (g.colors) delete[] g.colors;
	}

	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (tInicial) delete[] tInicial;
		if (tFinal) delete[] tFinal;
		if (colors) delete[] colors;
	}

	Graph transpose() {

		Graph g(vSize, eSize);

		Matrix<int> m(vSize, vSize);

		for (int i = 0; i < vSize; i++) {

			int ultimaAresta = V[i];

			while (E[ultimaAresta] != -1) {
				m[E[ultimaAresta++]][i] = 1;
			}
		}

		// // std::cout << m << std::endl;

		int ultimaAresta = 0;

		for (int i = 0; i < vSize; i++) {

			g.V[i] = ultimaAresta;

			for (int j = 0; j < vSize; j++) {
				if (m[i][j]) g.E[ultimaAresta++] = j;
			}

			g.E[ultimaAresta++] = -1;
		}

		return g;
	}

	LinearList<int> TopSorting() {

		LinearList<int> vInTopOrder;

		int visitados[vSize];

		for (int i = 0; i < vSize; i++) visitados[i] = 0;

		int tempo = 1;

		for (int i = 0; i < vSize; i++) {
			if (!visitados[i] && V[i] != -1) {
				DFS(i, tempo, vInTopOrder, visitados);
			}
		}

		return vInTopOrder;
	}

	LinearList<LinearList<int>> kosaraju(std::string engine = "dot") {

		tInicial = new int[vSize];
		tFinal = new int[vSize];
		colors = new int[vSize];
		int visitados[vSize];

		for (int i = 0; i < vSize; i++) {
			colors[i] = tFinal[i] = tInicial[i] = visitados[i] = 0;
		}

		LinearList vInTopOrder = TopSorting();

		// std::cout << "vInTopOrder: " << vInTopOrder << std::endl;

		Graph t = transpose();

		// std::cout << t << std::endl;

		LinearList<LinearList<int>> componentes;

		color = 0;

		// while (!vInTopOrder.empty()) {
		for (int i = 0; i < vSize; i++) {

			// int v = vInTopOrder.pop_front();
			int v = vInTopOrder[i];

			if (visitados[v]) continue;

			// std::cout << "v: " << v << std::endl;

			LinearList<int> fechoTransitivoDireto;

			LinkedStack<int> s(v);

			visitados[v] = 1;

			fechoTransitivoDireto.push_back(v);

			colors[v] = color;

			while(!s.empty()) {

				int u = s.pop();

				for (int i = t.V[u]; i != -1 && t.E[i] != -1; i++) {

					if (!visitados[t.E[i]]) {

						// vInTopOrder.pop_front();
						// vInTopOrder.remove(t.E[i]);
						visitados[t.E[i]] = 1;
						fechoTransitivoDireto.push_back(t.E[i]);
						colors[t.E[i]] = color;

						s.push(t.E[i]);
					}
				}
			}

			fechoTransitivoDireto.sort();
			componentes.push_back(fechoTransitivoDireto);

			color++;
		}

		// std::cout << "Color: " << color << std::endl;

		exportar(engine);

		componentes.sort();

		return componentes;
	}

	void DFS(int u, int& tempo, LinearList<int>& vInTopOrder, int visitados[]) {

		visitados[u] = 1;
		tInicial[u] = tempo++;

		// exportar();

		for (int i = V[u]; V[u] != -1 && E[i] != -1; i++) {

			if (!visitados[E[i]]) {
				DFS(E[i], tempo, vInTopOrder, visitados);
			}

			// else if (E[i + 1] != -1) exportar();
		}

		vInTopOrder.push_front(u);
		tFinal[u] = tempo++;

		// exportar();
	}

	std::string Color(int v) {

		static std::vector<std::string> cores = generateColors(color);

		// std::cout << "Cores geradas:" << std::endl;
		// for (const auto& color : cores) {
		// 	std::cout << color << std::endl;
		// }

		return cores[v];
	}

	std::string HSLToHex(int h, double s, double l) {

		double C = (1 - std::fabs(2 * l - 1)) * s;  // Chroma
		double X = C * (1 - std::fabs(fmod(h / 60.0, 2) - 1));
		double m = l - C / 2;

		double r, g, b;

		if (h >= 0 && h < 60) {
			r = C, g = X, b = 0;
		} else if (h >= 60 && h < 120) {
			r = X, g = C, b = 0;
		} else if (h >= 120 && h < 180) {
			r = 0, g = C, b = X;
		} else if (h >= 180 && h < 240) {
			r = 0, g = X, b = C;
		} else if (h >= 240 && h < 300) {
			r = X, g = 0, b = C;
		} else {
			r = C, g = 0, b = X;
		}

		// Convert to 0-255 range
		int R = static_cast<int>((r + m) * 255);
		int G = static_cast<int>((g + m) * 255);
		int B = static_cast<int>((b + m) * 255);

		// Convert to hexadecimal
		std::ostringstream oss;
		oss << "#" << std::setfill('0') << std::setw(2) << std::hex << R
			<< std::setfill('0') << std::setw(2) << std::hex << G
			<< std::setfill('0') << std::setw(2) << std::hex << B;

		return oss.str();
	}

	std::vector<std::string> generateColors(int n) {

		std::vector<std::string> colors;
		double saturation = 0.8; // Saturação fixa
		double lightness = 0.5;  // Luminosidade fixa

		for (int i = 0; i < n; ++i) {
			int hue = static_cast<int>((i * (360 / n)) % 360);
			colors.push_back(HSLToHex(hue, saturation, lightness));
		}

		return colors;
	}

	void exportar(std::string engine) {

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

		outfile << "\tsize=\"10!\";" << std::endl;

		outfile << "\t//Nodes" << std::endl;

		for (int j = 0; j < color; j++) {

			outfile << "\tsubgraph cluster_" << j << " {\n\t\t"
			<< "node [style=filled, color=\"" << Color(j) << "\"];"
			// << "\n\t\t";
			<< "\n\t\trank=same;\n\t";

			for (int i = 0; i < vSize; i++) {

				if (colors[i] != j) continue;

				std::string var1 = tInicial[i] == 0 ? "-" : std::to_string(tInicial[i]);
				std::string var2 = tFinal[i] == 0 ? "-" : std::to_string(tFinal[i]);

				// outfile << std::to_string(i) << "; ";
				outfile << "\t" << std::to_string(i) <<
				"[label = \"" << i << "[" << var1 << "," << var2 << "]\"];\n\t";
			}

			outfile << "}\n\n";
		}

		// for (int i = 0; i < vSize; i++) {

		// 	std::string var1 = tInicial[i] == 0 ? "-" : std::to_string(tInicial[i]);
		// 	std::string var2 = tFinal[i] == 0 ? "-" : std::to_string(tFinal[i]);

		// 	outfile << "\t" << std::to_string(i) <<
		// 	"[label = \"" << i << "[" << var1 << "," <<
		// 	var2 << "]\" fillcolor=\"" << Color(colors[i]) << "\", style=\"filled\"];" << std::endl;
		// }

		// outfile << std::endl;

		outfile << "\t//Edges" << std::endl;

		for (int i = 0; i < vSize; i++) {
			for (int j = V[i]; V[i] != -1 && E[j] != -1; j++) {
				outfile << "\t" << std::to_string(i) << " -> " << E[j]
				// << "[label=" << labels[i][E[j]] << "];"
				<< std::endl;
			}
		}

		outfile << "}";

		outfile.close();

		std::string script = engine + std::string(" -Tpng graph.dot -o images/image") + std::to_string(index++) + std::string(".png");
		system(script.c_str());

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
};
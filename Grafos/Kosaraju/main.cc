#include <iostream>

#include <iostream>
#include <sstream>
#include <iomanip>
// #include <vector>
// #include <cmath>

#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"

using namespace std;

// clear && g++ main.cc && ./a.out

LinearList<LinearList<int>> Kosaraju(const Graph& G, tuple<string, string, int> configs) {

	// tInicial = new int[vSize];
	// tFinal = new int[vSize];
	// colors = new int[vSize];
	// int visitados[vSize];
	//
	// for (int i = 0; i < vSize; i++) {
	// 	colors[i] = tFinal[i] = tInicial[i] = visitados[i] = 0;
	// }
	//
	// LinearList vInTopOrder = TopSorting();
	//
	// // cout << "vInTopOrder: " << vInTopOrder << endl;
	//
	// Graph t = transpose();
	//
	// // cout << t << endl;
	//
	LinearList<LinearList<int>> componentes;
	//
	// color = 0;
	//
	// // while (!vInTopOrder.empty()) {
	// for (int i = 0; i < vSize; i++) {
	//
	// 	// int v = vInTopOrder.pop_front();
	// 	int v = vInTopOrder[i];
	//
	// 	if (visitados[v]) continue;
	//
	// 	// cout << "v: " << v << endl;
	//
	// 	LinearList<int> fechoTransitivoDireto;
	//
	// 	LinkedStack<int> s(v);
	//
	// 	visitados[v] = 1;
	//
	// 	fechoTransitivoDireto.push_back(v);
	//
	// 	colors[v] = color;
	//
	// 	while(!s.empty()) {
	//
	// 		int u = s.pop();
	//
	// 		for (int i = t.V[u]; i != -1 && t.E[i] != -1; i++) {
	//
	// 			if (!visitados[t.E[i]]) {
	//
	// 				// vInTopOrder.pop_front();
	// 				// vInTopOrder.remove(t.E[i]);
	// 				visitados[t.E[i]] = 1;
	// 				fechoTransitivoDireto.push_back(t.E[i]);
	// 				colors[t.E[i]] = color;
	//
	// 				s.push(t.E[i]);
	// 			}
	// 		}
	// 	}
	//
	// 	fechoTransitivoDireto.sort();
	// 	componentes.push_back(fechoTransitivoDireto);
	//
	// 	color++;
	// }
	//
	// // cout << "Color: " << color << endl;
	//
	// exportar(engine);
	//
	// componentes.sort();

	return componentes;
}

Graph Transpose(const Graph& G);
// LinearList<int> TopSorting();
// void DFS(int u, int& tempo, LinearList<int>& vInTopOrder, int visitados[]);
// string Color(int v);
// string HSLToHex(int h, double s, double l);
LinearList<string> generateColors(int n);

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)	
		.directed()
	.build();

	{
		G.addEdge(0, 1);
		G.addEdge(1, 2);
		G.addEdge(1, 4);
		G.addEdge(2, 3);
		G.addEdge(3, 0);
		G.addEdge(4, 5);
		G.addEdge(5, 6);
		G.addEdge(6, 4);
		G.addVertex(7);
	}

	{
		// Graph g = {
		//	 { 0, { 1 }},
		//	 { 1, { 3 }},
		//	 { 2, { 1, 3, 4 }},
		//	 { 3, { 0, 4, 5 }},
		//	 { 4, { 5, 6, 7 }},
		//	 { 5, { 4 }},
		//	 { 6, { 7 }},
		//	 { 7, {}},
		//	 { 8, { 5, 9, }},
		//	 { 9, { 5, 7, 10, 11, }},
		//	 { 10, { 6, 8, 11, 13 }},
		//	 { 11, { 8, 9 }},
		//	 { 12, { 10 }},
		//	 { 13, { 12 }},
		//	 // { 14, { }}
		// };
	}

	cout << G << endl;

	// Graph t = Transpose(G);
	// cout << t << endl;

	// cout << "Componentes: " << Kosaraju(G, {"SCC", "dot", 600}) << endl;

}

Graph Transpose(const Graph& G) {

	Graph transposed = GraphBuilder().build();
	//
	// int ultimaAresta = 0;
	//
	// for (int i = 0; i < vSize; i++) {
	//
	// 	g.V[i] = ultimaAresta;
	//
	// 	for (int j = 0; j < vSize; j++) {
	// 		if (containsInAdjList(j, i)) g.E[ultimaAresta++] = j;
	// 	}
	//
	// 	g.E[ultimaAresta++] = -1;
	// }

	return transposed;
}

LinearList<int> TopSorting() {

	LinearList<int> vInTopOrder;
	//
	// int visitados[vSize];
	//
	// for (int i = 0; i < vSize; i++) visitados[i] = 0;
	//
	// int tempo = 1;
	//
	// for (int i = 0; i < vSize; i++) {
	// 	if (!visitados[i] && V[i] != -1) {
	// 		DFS(i, tempo, vInTopOrder, visitados);
	// 	}
	// }
	//
	return vInTopOrder;
}

void DFS(int u, int& tempo, LinearList<int>& vInTopOrder, int visitados[]) {

	// visitados[u] = 1;
	// tInicial[u] = tempo++;
	//
	// // exportar();
	//
	// for (int i = V[u]; V[u] != -1 && E[i] != -1; i++) {
	//
	// 	if (!visitados[E[i]]) {
	// 		DFS(E[i], tempo, vInTopOrder, visitados);
	// 	}
	//
	// 	// else if (E[i + 1] != -1) exportar();
	// }
	//
	// vInTopOrder.push_front(u);
	// tFinal[u] = tempo++;
	//
	// // exportar();
}

string Color(int v, int colorsCount) {

	static LinearList<string> cores = generateColors(colorsCount);

	// cout << "Cores geradas:" << endl;
	cout << cores << endl;

	return cores[v];
}

string HSLToHex(int h, double s, double l) {

	double C = (1 - fabs(2 * l - 1)) * s;  // Chroma
	double X = C * (1 - fabs(fmod(h / 60.0, 2) - 1));
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
	ostringstream oss;
	oss << "#" << setfill('0') << setw(2) << hex << R
	<< setfill('0') << setw(2) << hex << G
	<< setfill('0') << setw(2) << hex << B;

	return oss.str();
}

LinearList<string> generateColors(int n) {

	LinearList<string> colors;

	double saturation = 0.8; // Saturação fixa
	double lightness = 0.5;  // Luminosidade fixa

	for (int i = 0; i < n; ++i) {
		int hue = static_cast<int>((i * (360 / n)) % 360);
		colors.push_back(HSLToHex(hue, saturation, lightness));
	}

	return colors;
}

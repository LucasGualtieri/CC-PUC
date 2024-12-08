#include <iomanip>
#include <iostream>
// #include <vector>
// #include <cmath>

#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"

using namespace std;

// clear && g++ bruteForce.cc -std=c++20 && ./a.out

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
		colors += HSLToHex(hue, saturation, lightness);
	}

	return colors;
}

// Função para verificar se uma coloração é válida
bool isValidColoring(const LinearList<int>& colors, const Graph& G) {

	for (Vertex& u : G.vertices()) {

		for (Vertex& v : G.neighbors(u, 0)) {

			if (colors[u] == colors[v]) {
				return false; // Vértices adjacentes têm a mesma cor
			}

		}
	}

	return true;
}

// // Função recursiva para gerar todas as combinações possíveis de cores
bool exhaustiveColoring(Vertex v, int k, LinearList<int>& colors, const Graph& G) {

	if (v == G.n) {
		// Chegou ao fim: verificar se a coloração é válida
		return isValidColoring(colors, G);
	}

	// Testar todas as cores possíveis para o vértice atual
	for (int color = 0; color < k; color++) {

		colors[v] = color;

		if (exhaustiveColoring(v + 1, k, colors, G)) {

			return true; // Encontrou uma solução válida
		}
	}

	// Não foi possível colorir com a configuração atual

	return false;
}

// Função principal para encontrar o número cromático
int chromaticNumber(Graph& G) {

	int chromaticNum = G.n; // No pior caso, usa-se n cores (grafo completo)

	LinearList<int> colors(G.n, -1); // Inicializa todas as cores como não atribuídas

	for (int k = 1; k <= G.n; k++) {

		if (exhaustiveColoring(0, k, colors, G)) {

			chromaticNum = k; // Retorna o menor número de cores válido
			break;
		}
	}

	LinearList<string> cores = generateColors(chromaticNum);

	for (Vertex& v : G.vertices()) {
		G.changeVertexProps(v, {cores[v], ""});
		// G.changeVertexProps(v, {colors[v], ""});
	}

	return chromaticNum; 
}

int main() {

	Graph G = GraphBuilder()
		.dataStructure(Graph::AdjacencyMatrix)
	.build();

	for (int i = 0; i <= 12; i++) G.addVertex(i);

	// G.addEdge(0, 1);
	// G.addEdge(0, 2);
	// G.addEdge(0, 3);
	// G.addEdge(1, 2);

	// Funciona para o novo algoritmo
	// G.addEdge(0, 1);
	// G.addEdge(1, 2);
	// G.addEdge(1, 3);
	// G.addEdge(2, 4);

	G.addEdge(0, 12);
	G.addEdge(0, 11);
	G.addEdge(0, 10);
	G.addEdge(0, 9);
	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(2, 4);
	G.addEdge(3, 5);
	G.addEdge(4, 5);
	G.addEdge(4, 6);
	G.addEdge(4, 7);

	cout << chromaticNumber(G) << endl;

	G.export_to("teste");

	return 0;
}

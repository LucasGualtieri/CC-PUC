#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <fstream>  // Include fstream for file handling
#include <unordered_set>

#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/queue/linkedQueue.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"

#define Infinity 0x7FFFFFFF

class Graph {
  public:

	int *V, *E, *visitados, *colors;
	int vSize = 0, eSize = 0;

	Graph(std::string filePath) {

		std::ifstream file(filePath);

		if (!file.is_open()) {
			throw "Error: Could not open the file " + filePath + "\n";
		}

		std::string line;

		file >> vSize >> eSize;

		V = new int[vSize + 1];
		E = new int[eSize];
		colors = visitados = nullptr;

		for (int i = 0; i < vSize; i++) V[i] = -1;

		int u, v;

		int lastEdgePos = 0, lastVertex = -1;

		while (file >> u >> v) {
			if (u != lastVertex) V[u] = lastEdgePos;
			E[lastEdgePos++] = v;
			lastVertex = u;
		}

		V[vSize] = -Infinity;

		for (int i = vSize - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	Graph(std::initializer_list<std::pair<int, std::initializer_list<int>>> graph) {

		V = E = colors = visitados = nullptr;

		for (auto i : graph) if (i.first > vSize) vSize = i.first;
		V = new int[++vSize];

		for (int i = 0; i < vSize; i++) V[i] = -1;

		for (auto i : graph) eSize += i.second.size();
		E = new int[eSize];

		int adjStart = 0;

		for (auto j : graph) {

			V[j.first] = adjStart;

			for (int adj : j.second) {
				E[adjStart++] = adj;
			}
		}

		V[vSize] = -Infinity;

		for (int i = vSize - 1; i >= 0; i--) {
			if (V[i] == -1) V[i] = -abs(V[i + 1]);
		}
	}

	Graph(int vSize, int eSize) : vSize(vSize), eSize(eSize) {

		V = E = colors = visitados = nullptr;

		V = new int[vSize + 1];
		E = new int[eSize];

		V[vSize] = -Infinity;
	}

	~Graph() {
		if (V) delete[] V;
		if (E) delete[] E;
		if (colors) delete[] colors;
		if (visitados) delete[] visitados;
	}

	inline bool inBounds(int j, int i) const {
		return 0 <= j && j < eSize && j < abs(V[i + 1]);
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

	LinearList<std::string> generateColors(int n) {

		LinearList<std::string> colors;
		double saturation = 0.8; // Saturação fixa
		double lightness = 0.5;  // Luminosidade fixa

		for (int i = 0; i < n; ++i) {
			int hue = static_cast<int>((i * (360 / n)) % 360);
			colors.push_back(HSLToHex(hue, saturation, lightness));
		}

		return colors;
	}

	int max(const int* array, size_t size) {

		if (size == 0) {
			throw std::invalid_argument("Array size must be greater than zero.");
		}

		int max_value = std::numeric_limits<int>::lowest(); // Initialize to the lowest possible int value

		for (size_t i = 0; i < size; ++i) {
			if (array[i] > max_value) {
				max_value = array[i];
			}
		}

		return max_value;
	}

	bool contains(const std::unordered_set<int>& set, const int& val) {
		return set.find(val) != set.end();
	}

	void generateImage() {

		LinearList<std::string> verticeColors;

		LinearList<std::string> colorsString = generateColors(max(colors, vSize) + 1);

		for (int i = 0; i < vSize; i++) {
			verticeColors.push_back(
				std::to_string(i) + ": " + colorsString[colors[i]]
			);
		}

		std::ofstream outFile("state_colors.txt");

		for (std::string str : verticeColors) {
			outFile << str << std::endl;
		}

		outFile.close();

		int result = system("python3 ScriptsPython/Coloring.py");
	}

	void updateColor(const int& u) {

		std::unordered_set<int> set;

		int numberOfNeighbors = 0;

		for (int i = V[u]; inBounds(i, u); i++) {

			int v = E[i];

			if (visitados[v]) {
				numberOfNeighbors++;
				set.insert(colors[v]);
			}
		}

		for (int i = 0; i < numberOfNeighbors; i++) {
			if (!contains(set, colors[u])) break;
			else colors[u]++;
		}
	}

	void colorVertices() {

		colors = new int[vSize];
		visitados = new int[vSize];

		int descobertos[vSize];

		for (int i = 0; i < vSize; i++) {
			descobertos[i] = visitados[i] = colors[i] = 0;
		}

		LinkedQueue<int> s(0);

		descobertos[0] = 1;

		while(!s.empty()) {

			int u = s.pop();
			visitados[u] = 1;

			updateColor(u);

			for (int i = V[u]; inBounds(i, u); i++) {

				int v = E[i];

				if (!descobertos[v]) {
					descobertos[v] = 1;
					s.push(v);
				}
			}
		}

		generateImage();
	}

	std::string str() const {

		std::stringstream os;

		for (int i = 0; i < vSize; i++) {

			os << i << ": { ";

			for (int j = V[i]; inBounds(j, i); j++) {
				os << E[j];
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

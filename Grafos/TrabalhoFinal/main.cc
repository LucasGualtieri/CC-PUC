#include <iostream>
#include <queue>

#include "../DataStructures/utils/Pair.hpp"
#include "../DataStructures/include/stack/linkedStack.hpp"
#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"

#include "imageToMatrix.hpp"

using namespace std;

using Segmentation = LinearList<LinearList<Vertex>>;
using Component = LinearList<Vertex>;
using PriorityQueue = priority_queue<pair<float, pair<Vertex, Vertex>>, vector<pair<float, pair<Vertex, Vertex>>>, greater<>>;

// clear && g++ main.cc -std=c++20 && ./a.out

class UnionFind {

	unordered_map<Vertex, int> parent;
	unordered_map<Vertex, float> maxWeight; // Store the maximum weight for each set root
	size_t sets = 0;

  public:

	size_t numberOfSets() { return sets; }

	void insert(Vertex vertex) {

		if (parent.find(vertex) == parent.end()) {
			parent[vertex] = -1; // Initialize as its own root with size 1
			maxWeight[vertex] = 0; // Initially no edges, so max weight is 0
			sets++;
		}
	}

	bool connected(Vertex u, Vertex v) { return find(u) == find(v); }

	Vertex find(Vertex vertex) {

		if (parent[vertex] < 0) {
			return vertex; // Root element
		}

		return parent[vertex] = find(parent[vertex]); // Path compression
	}

	void join(Vertex u, Vertex v, float weight) {

		Vertex rootU = find(u), rootV = find(v);

		if (rootU == rootV) {
			// If already in the same set, update the max weight if needed
			maxWeight[rootU] = max(maxWeight[rootU], weight);
			return;
		}

		sets--;

		// Union by size: Attach the smaller tree under the larger tree
		if (parent[rootU] < parent[rootV]) { // rootU has larger size
			parent[rootU] += parent[rootV]; // Update size of rootU
			parent[rootV] = rootU;
			// Update max weight for the new root
			maxWeight[rootU] = max(maxWeight[rootU], maxWeight[rootV]);
			maxWeight[rootU] = max(maxWeight[rootU], weight);
			maxWeight.erase(rootV);
		} else { // rootV has larger or equal size
			parent[rootV] += parent[rootU]; // Update size of rootV
			parent[rootU] = rootV;
			// Update max weight for the new root
			maxWeight[rootV] = max(maxWeight[rootV], maxWeight[rootU]);
			maxWeight[rootU] = max(maxWeight[rootV], weight);
			maxWeight.erase(rootU);
		}
	}

	int setSize(Vertex vertex) {
		Vertex root = find(vertex);
		return -parent[root];
	}

	int getMaxWeight(Vertex vertex) {
		Vertex root = find(vertex);
		return maxWeight[root];
	}
};

LinearList<Pair<int, int>> getNeighbors(int i, int j, const Matrix<Pixel>& m, bool eightConnected = false);
float dissimilarity(const Pixel& a, const Pixel& b);
Graph createGraph(const Matrix<Pixel>& m, const bool& eightConnected = false);
void saveSegmentedImage(const string& outputFilename, const LinearList<LinearList<Vertex>>& segment, Matrix<Pixel>& image);
void convertPpmToPng(const string& inputFile, const string& outputFile);

float Int(Vertex x, UnionFind& unionFind) {
	return unionFind.getMaxWeight(x);
}

Component DFS(Vertex& x, const Graph& G, LinearList<bool>& descobertos) {

	LinearList<Vertex> FTD; // Fecho Transitivo Direto

	LinkedStack<Vertex> stack = {x};
	descobertos[x] = true;

	while (!stack.empty()) {

		Vertex u = stack.pop();
		FTD += u;

		for (auto [v, w] : G.neighbors(u)) {
			if (!descobertos[v]) {
				stack.push(v);
				descobertos[v] = true;
			}
		}
	}

	return FTD;
}

int threshold(Vertex& v, const int K, UnionFind& unionFind) {
	// cout << "unionFind.setSize(v): " << unionFind.setSize(v) << endl;
	return K / unionFind.setSize(v);
};

float MInt(Vertex& u, Vertex& v, const int& K, UnionFind& unionFind, const Graph& G) {
	return min(Int(u, unionFind) + threshold(u, K, unionFind), Int(v, unionFind) + threshold(v, K, unionFind));
};

bool D(const float& weight, Vertex& u, Vertex& v, const int& K, UnionFind& unionFind, const Graph& G) {
	float valor = MInt(u, v, K, unionFind, G);
	// cout << "valor: " << valor << endl;
	return weight > valor;
};

Segmentation ImageSegmentation(const int K, const Graph& G) {

	LinearList<Edge> sortedEdges = G.edges();
	sortedEdges.sort();

	UnionFind unionFind;

	Graph aux = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
		.weighted()
	.build();

	for (Vertex& v : G.vertices()) {
		unionFind.insert(v);
		aux.addVertex(v);
	}
	
	for (Edge& e : sortedEdges) {

		if (!unionFind.connected(e.u, e.v)) {

			if (!D(e.weight, e.u, e.v, K, unionFind, aux)) {
				unionFind.join(e.u, e.v, e.weight);
				aux.addEdge(e);
			}
		}
	}

	Segmentation segmentation(unionFind.numberOfSets());

	LinearList<bool> descobertos(G.n, false);

	for (Vertex& v : G.vertices()) {
		if (!descobertos[v]) {
			segmentation += DFS(v, aux, descobertos);
		}
	}

	return segmentation;
}

// NOTE: HERE IS MAIN
int main() {

	Matrix<Pixel> image = loadPPM("inputImages/dog", 0.8);

	Graph G = createGraph(image, true);

	Segmentation segment = ImageSegmentation(1'500'000, G);
	// cout << segment << endl;
	cout << "Seg size: " << segment.size() << endl;

	saveSegmentedImage("outputImages/dog.ppm", segment, image);
	
	// WARNING: This will attempt to call a python script
	convertPpmToPng("outputImages/dog", "outputImages/dog");

	return 0;
}

LinearList<Pair<int, int>> getNeighbors(int i, int j, const Matrix<Pixel>& m, bool eightConnected) {

	static const LinearList<Pair<int, int>> directions4 = {
		{-1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	static const LinearList<Pair<int, int>> directions8 = {
		{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
	};

	const auto& directions = eightConnected ? directions8 : directions4;

	LinearList<Pair<int, int>> neighbors;

	for (auto [dx, dy] : directions) {

		int x = i + dx, y = j + dy;

		if (m.inBounds(x, y)) {
			neighbors += {x, y};
		}
	}

	return neighbors;
}

float dissimilarity(const Pixel& a, const Pixel& b) {
	// Euclidean distance
	return sqrt(pow(a.R - b.R, 2) + pow(a.G - b.G, 2) + pow(a.B - b.B, 2));
}

Graph createGraph(const Matrix<Pixel>& m, const bool& eightConnected) {

	// TODO: Implementar uma lista de adjacencia, para o grafo que e sparse
	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
		.weighted()
	.build();

	// for (auto& [i, j] : m) {
	for (int i = 0; i < m.height; i++) {

		for (int j = 0; j < m.width; j++) {

			// NOTE: Um array de visitados aqui nos permitiria não "re inserir" certas arestas

			for (auto& [x, y] : getNeighbors(i, j, m, eightConnected)) {

				float weight = dissimilarity(m[i][j], m[x][y]);

				Vertex u = i * m.width + j;
				Vertex v = x * m.width + y;

				G.addEdge(u, v, weight);
			}
		}
	}

	return G;
}

Pixel HSLToHex(int h, double s, double l) {

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

	// // Convert to hexadecimal
	// ostringstream oss;
	// oss << "#" << setfill('0') << setw(2) << hex << R
	// 	<< setfill('0') << setw(2) << hex << G
	// 	<< setfill('0') << setw(2) << hex << B;
	//
	// return oss.str();
	return {
		.R = static_cast<Byte>(R),
		.G = static_cast<Byte>(G),
		.B = static_cast<Byte>(B),
	};
}

LinearList<Pixel> generateColors(int n) {

	LinearList<Pixel> colors;
	double saturation = 0.8; // Saturação fixa
	double lightness = 0.5;  // Luminosidade fixa

	for (int i = 0; i < n; ++i) {
		int hue = (int)((i * (360 / n)) % 360);
		colors += HSLToHex(hue, saturation, lightness);
	}

	return colors;
}

void saveSegmentedImage(const string& outputFilename, const LinearList<LinearList<Vertex>>& segment, Matrix<Pixel>& image) {

	// Paint the pixels
	LinearList<Pixel> color = generateColors(segment.size());

	int index = 0;
    for (LinearList<Vertex> C : segment) {

		for (Vertex v : C) {

			int i = v / image.width;
			int j = v % image.width;

			if (image.inBounds(i, j)) { // Ensure pixel is within image bounds
				image[i][j] = color[index];
			}
		}

		index++;
    }

    // Save the updated image as a new PPM file
    ofstream outFile(outputFilename, ios::binary);
    if (!outFile.is_open()) {
        throw runtime_error("Cannot open file: " + outputFilename);
    }

    // Write PPM header
    outFile << "P6\n";
    outFile << image.width << " " << image.height << "\n";
    outFile << "255\n";

    // Write pixel data
    for (int i = 0; i < image.height; ++i) {

        for (int j = 0; j < image.width; ++j) {

            const Pixel& pixel = image[i][j];

            outFile.put(pixel.R);
            outFile.put(pixel.G);
            outFile.put(pixel.B);
        }
    }

    outFile.close();
}

void convertPpmToPng(const string& inputFile, const string& outputFile) {

    // Construct the Python command
    string command = "python3 ppmToPng.py \"" + inputFile + ".ppm\" \"" + outputFile + ".png\"";

    // Execute the command
    int result = system(command.c_str());

	// Check if the command executed successfully
	if (result != 0) {
		cerr << "Error occurred while attempting to convert the file." << endl;
	}
}

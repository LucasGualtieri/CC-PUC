#include <iostream>
// #include <cmath>

#include "../DataStructures/utils/Pair.hpp"
#include "../DataStructures/include/Graph/Graph.hpp"
#include "../DataStructures/include/matrix/matrix.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "../DataStructures/include/Graph/GraphBuilder.hpp"

#include "imageToMatrix.hpp"

using namespace std;

// clear && g++ main.cc -std=c++20 && ./a.out

LinearList<Pair<int, int>> getNeighbors(int i, int j, const Matrix<Pixel>& m, bool eightConnected = false) {

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

// TODO:
float dissimilarity(const Pixel& a, const Pixel& b) {
	return sqrt(pow(a.R - b.R, 2) + pow(a.G - b.G, 2) + pow(a.B - b.B, 2));
}	

Graph createGraph(const Matrix<Pixel>& m, const bool& eightConnected = false) {

	// TODO: Implementar uma lista de adjacencia, para o grafo que e sparse
	Graph G = GraphBuilder()
		.dataStructure(Graph::FastAdjacencyList)
		.weighted()
		.n(m.width * m.width)
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

void saveSegmentedImage(const string& outputFilename, const LinearList<LinearList<Vertex>>& segment, const LinearList<Pixel>& color, Matrix<Pixel>& image) {

	// Paint the pixels

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

int main() {

	// Matrix<Pixel> image = {
	// 	{{0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
	// 	{{255, 255, 255}, {0, 0, 0}, {255, 255, 255}},
	// 	{{0, 0, 0}, {255, 255, 255}, {0, 0, 0}},
	// };

	Matrix<Pixel> image = loadPPM("inputImages/horse.ppm");

	Graph G = createGraph(image);

	// LinearList<LinearList<Vertex>> segment = ImageSegmentation(5, G);
	
	Pixel red = {255, 0, 0};
	Pixel green = {0, 255, 0};
	Pixel blue = {0, 0, 255};

	saveSegmentedImage("outputImages/output.ppm", {{0,1,2}, {4, 5, 6}, {8, 9, 10}}, {red, green, blue}, image);
	
	// WARNING: This will attempt to call a python script
	convertPpmToPng("outputImages/output", "outputImages/output");

	return 0;
}

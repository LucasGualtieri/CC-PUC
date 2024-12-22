#ifndef UTILS
#define UTILS

#include "../DataStructures/utils/Pair.hpp"
#include "../DataStructures/include/list/linearList.hpp"
#include "imageToMatrix.hpp"
#include <cmath>
#include <unordered_map>

using Vertex = int;
using Segmentation = unordered_map<Vertex, LinearList<Vertex>>;

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

Pixel generateColor(const LinearList<Vertex>& component, const Matrix<Pixel>& image) {
	
	int R = 0, G = 0, B = 0;

	for (Vertex v : component) {

		int i = v / image.width;
		int j = v % image.width;

		R += image[i][j].R;
		G += image[i][j].G;
		B += image[i][j].B;
	}

	return {
		.R = (Byte)(R / component.size()),
		.G = (Byte)(G / component.size()),
		.B = (Byte)(B / component.size())
	};
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

void saveSegmentedImage(const string& outputFilename, const Segmentation& segment, Matrix<Pixel>& image) {

	// Paint the pixels
	// LinearList<Pixel> color = generateColors(segment.size());
	// LinearList<Pixel> color = generateColors(20);

	// int index = 0;
	for (auto& [_, C] : segment) {

		Pixel color = generateColor(C, image);

		for (Vertex v : C) {

			int i = v / image.width;
			int j = v % image.width;

			image[i][j] = color;
			// image[i][j] = color[index % 20];
			// image[i][j] = color[index];
		}

		// index++;
	}

	// Save the updated image as a new PPM file
	ofstream outFile(outputFilename + ".ppm", ios::binary);
	if (!outFile.is_open()) {
		throw runtime_error("Cannot open file: " + outputFilename + ".ppm");
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
	
	convertPpmToPng(outputFilename, outputFilename);
}

#endif

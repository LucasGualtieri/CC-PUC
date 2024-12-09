#include <format>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "../DataStructures/include/matrix/matrix.hpp"

using namespace std;

typedef unsigned char Byte;

// clear && g++ readingPPM.cc -std=c++20 && ./a.out

struct Pixel {

	Byte R, G, B;

	friend ostream& operator<<(ostream& os, const Pixel& pixel) {
		// NOTE: This is just to make the Matrix print prettier
		os << pixel.R + pixel.G + pixel.B;
		// os << format("({}, {}, {})", pixel.R, pixel.G, pixel.B);
		return os;
	}
};

// Function to load PGM file
Matrix<int> loadPGM(const string& filename) {

    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    string magicNumber;
    file >> magicNumber;

    if (magicNumber != "P2" && magicNumber != "P5") {
        throw runtime_error("Unsupported PGM format: " + magicNumber);
    }

    // Read image dimensions and max value
    int width, height, maxVal;
    file >> width >> height >> maxVal;

    // Skip single whitespace
    file.ignore();

    // Prepare a matrix to hold the pixel data
    Matrix<int> image(height, width);

	if (magicNumber == "P2") {

		// ASCII format
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				file >> image[i][j];
			}
		}
	}

	else if (magicNumber == "P5") {

		// Binary format
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				image[i][j] = file.get();
			}
		}
	}

	file.close();

	return image;
}

// Function to load PPM file
Matrix<Pixel> loadPPM(const string& filename) {

    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    string magicNumber;
    file >> magicNumber;

    if (magicNumber != "P3" && magicNumber != "P6") {
        throw runtime_error("Unsupported PPM format: " + magicNumber);
    }

    // Read image dimensions and max value
    int width, height, maxVal;
    file >> width >> height >> maxVal;

    if (maxVal > 255) {
        throw runtime_error("Only 8-bit PPM files are supported.");
    }

    // Skip single whitespace
    file.ignore();

    // Prepare a matrix to hold the pixel data
    Matrix<Pixel> image(width, height);

	if (magicNumber == "P3") {

		// ASCII format
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {

				int r, g, b;
				file >> r >> g >> b;

				image[i][j] = {(Byte)r, (Byte)g, (Byte)b};
			}
		}
	}

	else if (magicNumber == "P6") {

		// Binary format
		for (int i = 0; i < height; i++) {

			for (int j = 0; j < width; j++) {

				Pixel pixel {
					.R = (Byte)file.get(),
					.G = (Byte)file.get(),
					.B = (Byte)file.get(),
				};

				image[i][j] = pixel;
			}
		}
	}

	file.close();

	return image;
}

int main() {

	try {
		Matrix<int> imagePGM = loadPGM("exemplo.pgm");
		cout << "imagePGM loaded successfully: " << imagePGM.height << "x" << imagePGM.width << "\n";
		cout << imagePGM << endl;

		Matrix<Pixel> imagemPPM = loadPPM("exemplo.ppm");
		cout << "imagemPPM loaded successfully: " << imagemPPM.height << "x" << imagemPPM.width << "\n";
		cout << imagemPPM << endl;
	}

	catch (const exception& e) {
		cerr << e.what() << '\n';
	}

	return 0;
}

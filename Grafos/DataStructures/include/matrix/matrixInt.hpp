#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <sstream>
#include <iomanip>

// Ainda tem um bug nessa classe que causou o transpose bugar

class Matrix {

	int** matrix;

	public:

	const int height, width;

	Matrix(int height, int width) : height(height), width(width) {

		matrix = new int*[height];

		for (int i = 0; i < height; i++) {
			matrix[i] = new int[width];
		}
	}

	~Matrix() {

		for (int i = 0; i < height; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	bool inBounds(int i, int j) {
		return 0 <= i && i < height && 0 <= j && j < width;
	}

	bool notInBounds(int i, int j) {
		return !inBounds(i, j);
	}

	// Const version of operator[]
	int* operator[](int i) {

		if (i < 0 || i >= height) {
			throw std::out_of_range("Index out of range: " + std::to_string(i));
		}

		return matrix[i];
	}

	std::string str() const {

		std::ostringstream oss;
		int colWidth = 0;

		// First pass: Determine the width needed for each column
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::ostringstream temp;
				temp << matrix[i][j];
				colWidth = std::max(colWidth, static_cast<int>(temp.str().length()));
			}
		}

		oss << "  ";

		for (int i = 0; i < width; i++) {
			oss << std::setw(colWidth) << i << " ";
		}

		oss << "\n";

		// Second pass: Generate the string with alignment
		for (int i = 0; i < height; i++) {
			oss << i << " ";
			for (int j = 0; j < width; j++) {
				oss << std::setw(colWidth) << matrix[i][j];
				if (j < width - 1) oss << " ";
			}
			oss << '\n';
		}

		return oss.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
		os << m.str();
		return os;
	}

	// Iterator for Matrix
	class Iterator {

		Matrix& matrix;
		int row, col;

		public:
		Iterator(Matrix& mat, int r = 0, int c = 0) : matrix(mat), row(r), col(c) {}

		bool operator!=(Iterator& other) {
			return row != other.row || col != other.col;
		}

		Iterator& operator++() {
			col++;
			if (col >= matrix.width) {
				col = 0;
				row++;
			}
			return *this;
		}

		int& operator*() { return matrix[row][col]; }
	};

	Iterator begin() {
		return Iterator(*this, 0, 0);
	}

	Iterator end() {
		return Iterator(*this, height, 0);
	}

};

#endif

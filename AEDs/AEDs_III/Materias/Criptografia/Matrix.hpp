#ifndef MATRIX
#define MATRIX

#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class Matrix {
	vector<vector<T>> matrix;
  public:

	const int height, width;

	Matrix(int height, int width) : height(height), width(width) {

		matrix.reserve(height); // Optionally reserve memory for efficiency

		for (int i = 0; i < height; i++) {
			vector<T> row(width);
			matrix.push_back(row);
		}
	}

	Matrix(initializer_list<initializer_list<T>> list) : height(list.size()), width(list.begin()->size()) {
		
		matrix.reserve(height); // Optionally reserve memory for efficiency

		for (auto row : list) {
			matrix.push_back(row);
		}
	}

	bool inBounds(int i, int j) {
		return 0 <= i && i < height && 0 <= j && j < width;
	}

	vector<T>& operator[](int i) { return matrix[i]; }

	string toString() const {

		string str;

		for (int i = 0; i < height; i++) {
			ostringstream oss;

			for (int j = 0; j < width; j++) {
				oss << matrix[i][j] << ", ";
			}

			str += oss.str() + '\n';
			str.erase(str.length() - 3, 2);
		}

		str.erase(str.length() - 1, 1);

		return str;
	}

	friend ostream& operator<<(ostream& os, const Matrix<T>& m) {
		os << m.toString();
		return os;
	}
};

#endif
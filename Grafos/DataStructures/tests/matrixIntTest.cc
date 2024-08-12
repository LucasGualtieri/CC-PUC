#include <iostream>
#include <cassert>
#include "../include/matrix/matrix.hpp"

// clear && g++ tests/matrixIntTest.cc -o bin/matrixIntTest && bin/matrixIntTest

using namespace std;

void testLinearMatrix() {

	Matrix<int> matrix(3, 3);

	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[2][0] = 7;
	matrix[2][1] = 8;
	matrix[2][2] = 9;

	// Check dimensions
	assert(matrix.height == 3);
	assert(matrix.width == 3);

	// Check element access
	assert(matrix[0][0] == 1);
	assert(matrix[1][1] == 5);
	assert(matrix[2][2] == 9);

	// Check inBounds method
	assert(matrix.inBounds(0, 0));
	assert(!matrix.inBounds(-1, 0));
	assert(!matrix.inBounds(3, 3));

	// Check out-of-bounds access
	try {
		matrix[3][0];
		assert(false); // Should not reach this line
	}

	catch (const std::out_of_range& e) {
		assert(true); // Exception should be thrown
	}

	// Check string representation
	std::string expectedStr = "  0 1 2 \n0 1 2 3\n1 4 5 6\n2 7 8 9\n";
	assert(matrix.str() == expectedStr);

	// Iterator test
	int sum = 0;
	for (int i : matrix) sum += i;
	assert(sum == 45);

	cout << matrix << endl;
}

int main() {

	testLinearMatrix();

	cout << "All tests passed!" << endl;

	return 0;
}
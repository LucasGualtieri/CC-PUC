#include <iostream>

// clear && g++ tes.cc && ./a.out

int& foo() {
	static int n = 5;
	return n;
}

int main() {

	int& n = foo();
	n = 3;

	std::cout << n << std::endl;

	std::cout << foo() << std::endl;
}
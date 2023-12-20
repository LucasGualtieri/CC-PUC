#include <iostream>

using namespace std;

// clear && g++ IntroCpp.cc && ./a.out

// Polimorfismo = Overload = Sobrecarga

void fn() {
	cout << "OI" << endl;
}

void fn() {
	cout << "TCHAU" << endl;
}

int main() {

	fn();
	fn();

	return 0;
}
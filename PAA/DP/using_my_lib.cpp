#include <iostream>
#include "cpp-datastructures/list/linear_list.hpp"

using namespace std;

// clear && g++ -std=c++23 using_my_lib.cpp && ./a.out

int main() {

	LinearList<int> list = { 1, 2, 3, 4, 5 };

	cout << list << endl;

	return 0;
}

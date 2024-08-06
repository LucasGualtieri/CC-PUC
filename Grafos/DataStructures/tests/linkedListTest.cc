#include <iostream>
#include "../include/linkedList.hpp"
#include <iostream>
#include <cassert>

// clear && g++ tests/linkedListTest.cc -o bin/linkedListTest && bin/linkedListTest

void testLinkedList() {

	LinkedList<int> list;

	// Test initial state
	assert(list.size() == 0);
	assert(list.empty() == true);

	// Test push_front
	list.push_front(10);
	assert(list.size() == 1);
	assert(list.front() == 10);
	assert(list.back() == 10);

	// Test push_back
	list.push_back(20);
	assert(list.size() == 2);
	assert(list.front() == 10);
	assert(list.back() == 20);

	// Test pop_front
	int frontValue = list.pop_front();
	assert(frontValue == 10);
	assert(list.size() == 1);
	assert(list.front() == 20);
	assert(list.back() == 20);

	// Test pop_back
	int backValue = list.pop_back();
	assert(backValue == 20);
	assert(list.size() == 0);
	assert(list.empty() == true);

	// Test push_back
	list.push_back(30);
	list.push_back(40);
	list.push_back(50);
	assert(list.size() == 3);
	assert(list.front() == 30);
	assert(list.back() == 50);

	// Test add (insert at position)
	list.add(35, 1);
	assert(list.size() == 4);
	assert(list.front() == 30);
	assert(list.erase(1) == 35);
	assert(list.size() == 3);

	// // Test erase (remove by position)
	// assert(list.erase(1) == 40);
	// assert(list.size() == 2);
	// assert(list.front() == 30);
	// assert(list.back() == 50);

	// // Test edge case of empty list operations
	// try {
	// 	list.pop_front();
	// 	list.pop_back();
	// }

	// catch (const std::runtime_error &e) {
	// 	std::cout << "Caught expected exception: " << e.what() << std::endl;
	// }

	std::cout << "All tests passed!" << std::endl;
}

int main() {

	testLinkedList();

	return 0;
}

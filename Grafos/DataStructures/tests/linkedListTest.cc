#include <iostream>
#include <iostream>
#include <cassert>
#include "../include/linkedList.hpp"
#include "../include/list.hpp"
#include "../util.hpp"

// clear && g++ tests/linkedListTest.cc -o bin/linkedListTest && bin/linkedListTest

using namespace std;

void testLinkedList() {

	LinkedList<int> list;

	// Test initial state
	assert(list.size() == 0);
	assert(list.empty());

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
	assert(list.empty());

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
	assert(list.remove(1) == 35);
	assert(list.size() == 3);

	// Test remove (remove by position)
	assert(list.remove(1) == 40);
	assert(list.size() == 2);
	assert(list.front() == 30);
	assert(list.back() == 50);

	list.erase();

	// Test edge case of empty list operations
	try { list.remove(0); }
	catch (const std::runtime_error& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	// cout << list << endl;
	// list.sort();

	// assert(isSorted(list));

	std::cout << "All tests passed!" << std::endl;
}

int main() {

	testLinkedList();

	return 0;
}

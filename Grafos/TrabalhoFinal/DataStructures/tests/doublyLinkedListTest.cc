#include <iostream>
#include <cassert>
#include "../include/list/doublyLinkedList.hpp"
#include "../util/util.hpp"

// clear && g++ tests/doublyLinkedListTest.cc -o bin/doublyLinkedListTest && bin/doublyLinkedListTest

using namespace std;

void testDLinkedList() {

	DLinkedList<int> list;

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

	// Test erasing the list
	list.clear();
	assert(list.empty());

	// Test front and back on empty list
	try {
		list.front();
		list.back();
		assert(false); // Should not reach this point
	}

	catch (const runtime_error& e) {
		assert(string(e.what()) == "List is empty.");
	}

	for (int i = 0; i < 20; i++) list.push_back(i);
	assert(list.size() == 20);

	// list.sort();
	// assert(isSorted(list));

	cout << list << endl;

	cout << list.reverseTraversal() << endl;

	// for (int i : stack) cout << i << endl;
}

int main() {

	testDLinkedList();

	cout << "All tests passed!" << endl;

	return 0;
}
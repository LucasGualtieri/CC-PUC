#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../include/queue/MinHeap.hpp"

using namespace std;

// clear && g++ tests/minHeapTest.cc -o bin/minHeapTest && bin/minHeapTest

void testInsert() {

	MinHeap<int, int> heap;

	heap.push({0, 10});
	heap.push({1, 4});
	heap.push({2, 15});
	heap.push({3, 20});
	heap.push({4, 1});

	cout << "Test Insert: ";
	// heap.printHeap();

	assert(heap.peek().first == 4);
}

void testExtractMin() {

	MinHeap<int, int> heap;

	heap.push({1, 10});
	heap.push({2, 4});
	heap.push({3, 15});
	heap.push({4, 20});
	heap.push({5, 1});

	int minElement = heap.pop().first;
	cout << "Test Extract Min: Extracted " << minElement << endl;
	assert(minElement == 5);
	assert(heap.peek().first == 2);
}

void testIsEmpty() {

	MinHeap<int, int> heap;

	assert(heap.empty() == true);

	heap.push({1, 5});
	assert(heap.empty() == false);
}

void testGetMin() {

	MinHeap<int, int> heap;

	heap.push({8, 1});
	heap.push({3, 2});
	heap.push({7, 3});
	heap.push({1, 4});

	cout << "Test Get Min: Minimum is " << heap.peek() << endl;
	assert(heap.peek().first == 8);
}

void testExtractUntilEmpty() {

	MinHeap<int, int> heap;

	heap.push({8, 1});
	heap.push({3, 2});
	heap.push({7, 3});
	heap.push({1, 4});

	cout << "Test Extract Until Empty: ";
	while (!heap.empty()) {
		cout << heap.pop() << " ";
	}
	cout << endl;

	assert(heap.empty() == true);
}

void testDecreaseKey() {

	MinHeap<int, int> heap;

	heap.push({0, 10});
	heap.push({1, 4});
	heap.push({2, 15});
	heap.push({3, 20});
	heap.push({4, 1});

	// cout << heap << endl;

	assert(heap.peek().first == 4);

	heap.decreaseKey({0, 0});

	assert(heap.peek().first == 0);

	heap.decreaseKey({2, -5});

	assert(heap.peek().first == 2);

}

int main() {

	cout << "Running MinHeap Tests...\n";

	testInsert();
	testExtractMin();
	testIsEmpty();
	testGetMin();
	testExtractUntilEmpty();
	testDecreaseKey();

	cout << "All tests passed successfully!" << endl;
	return 0;
}

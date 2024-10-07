#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../include/queue/MinHeap.hpp" // Include your MinHeap class here

using namespace std;

// clear && g++ tests/minHeapTest.cc -o bin/minHeapTest && bin/minHeapTest

#include <iostream>
#include <stdexcept>
#include <cassert> // For testing assertions

void testInsert() {

	MinHeap<int> heap;

	heap.push(10);
	heap.push(4);
	heap.push(15);
	heap.push(20);
	heap.push(1);

	cout << "Test Insert: ";
	// heap.printHeap();

	assert(heap.peek() == 1); // Check if the minimum element is 1
}

void testExtractMin() {

	MinHeap<int> heap;

	heap.push(10);
	heap.push(4);
	heap.push(15);
	heap.push(20);
	heap.push(1);

	int minElement = heap.pop();
	cout << "Test Extract Min: Extracted " << minElement << endl;
	assert(minElement == 1); // The first extracted element should be the smallest (1)
	assert(heap.peek() == 4); // After extraction, the new minimum should be 4
}

void testIsEmpty() {

	MinHeap<int> heap;

	assert(heap.empty() == true); // The heap should be empty initially

	heap.push(5);
	assert(heap.empty() == false); // The heap should not be empty after inserting an element
}

void testGetMin() {

	MinHeap<int> heap;

	heap.push(8);
	heap.push(3);
	heap.push(7);
	heap.push(1);

	cout << "Test Get Min: Minimum is " << heap.peek() << endl;
	assert(heap.peek() == 1); // Check if the minimum element is 1
}

void testExtractUntilEmpty() {

	MinHeap<int> heap;

	heap.push(6);
	heap.push(2);
	heap.push(8);
	heap.push(4);

	cout << "Test Extract Until Empty: ";
	while (!heap.empty()) {
		cout << heap.pop() << " ";
	}
	cout << endl;

	assert(heap.empty() == true); // The heap should be empty after extracting all elements
}

int main() {

	cout << "Running MinHeap Tests...\n";

	testInsert();
	testExtractMin();
	testIsEmpty();
	testGetMin();
	testExtractUntilEmpty();

	cout << "All tests passed successfully!" << endl;
	return 0;
}

#include <iostream>
#include <cassert>
#include "../include/queue/linearQueue.hpp"

// clear && g++ tests/linearQueueTest.cc -o bin/linearQueueTest && bin/linearQueueTest

using namespace std;

void testLinearQueue() {

	LinearQueue<int> queue;

	// Test push and size
	queue.push(10);
	assert(queue.size() == 1);

	queue.push(20);
	assert(queue.size() == 2);

	// Test peek
	assert(queue.peek() == 10); // Oldest pushed element should be on top

	// Test contains
	assert(queue.contains(10)); // 10 should be found
	assert(queue.contains(20)); // 20 should be found
	assert(!queue.contains(30)); // 30 should not be found

	// Test pop
	assert(queue.pop() == 10); // Oldest pushed element should be popped
	assert(queue.size() == 1);
	assert(queue.peek() == 20); // 20 should now be on top

	// Test empty and clear
	queue.clear();
	assert(queue.empty());
	assert(queue.size() == 0);

	// Test peek on empty queue
	try {
		queue.peek();
		assert(false); // Should not reach this point
	}

	catch (const runtime_error& e) {
		assert(string(e.what()) == "Queue underflow: Attempt to peek an empty queue.");
	}

	// Testing expansion
	for (int i = 0; i < 20; i++) queue.push(i);
	assert(queue.size() == 20);
	assert(queue.capacity() >= queue.size());

	queue.shrink_to_fit();
	assert(queue.capacity() == queue.size());

	cout << queue << endl;

	// for (int i : queue) cout << i << endl;
}

int main() {

	testLinearQueue();

	cout << "All tests passed!" << endl;

	return 0;
}
#include <iostream>
#include <cassert>
#include "../include/stack/linearStack.hpp"

// clear && g++ tests/linearStackTest.cc -o bin/linearStackTest && bin/linearStackTest

using namespace std;

void testLinearStack() {

	LinearStack<int> stack;

	// Test push and size
	stack.push(10);
	assert(stack.size() == 1);

	stack.push(20);
	assert(stack.size() == 2);

	// Test peek
	assert(stack.peek() == 20); // Last pushed element should be on top

	// Test contains
	assert(stack.contains(10)); // 10 should be found
	assert(stack.contains(20)); // 20 should be found
	assert(!stack.contains(30)); // 30 should not be found

	// Test pop
	assert(stack.pop() == 20); // Last pushed element should be popped
	assert(stack.size() == 1);
	assert(stack.peek() == 10); // 10 should now be on top

	// Test empty and clear
	stack.clear();
	assert(stack.empty());
	assert(stack.size() == 0);

	// Test peek on empty stack
	try {
		stack.peek();
		assert(false); // Should not reach this point
	}

	catch (const runtime_error& e) {
		assert(string(e.what()) == "Stack underflow: Attempt to peek an empty stack.");
	}

	// Testing expansion
	for (int i = 0; i < 20; i++) stack.push(i);
	assert(stack.size() == 20);
	assert(stack.capacity() >= stack.size());

	stack.shrink_to_fit();
	assert(stack.capacity() == stack.size());

	cout << stack << endl;

	// for (int i : stack) cout << i << endl;

}

int main() {

	testLinearStack();

	cout << "All tests passed!" << endl;

	return 0;
}
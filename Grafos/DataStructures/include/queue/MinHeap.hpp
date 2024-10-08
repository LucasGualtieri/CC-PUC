#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <sstream>

#include "queue.hpp"
#include "../Pair.hpp"

template <typename Key, typename Value>
class MinHeap {

	using pair = Pair<Key, Value>;

	pair* heap;
	size_t size, maxSize;
	int* hash;

	int parent(int i) { return (i - 1) / 2; }
	int leftChild(int i) { return (2 * i) + 1; }
	int rightChild(int i) { return (2 * i) + 2; }

	void swap(pair &x, pair &y) {

		pair temp = x;
		x = y;
		y = temp;

		int index = hash[x.first];
		hash[x.first] = hash[y.first];
		hash[y.first] = index;
	}

	// Heapify down the heap from index i
	void heapifyDown(int i) {

		int left = leftChild(i);
		int right = rightChild(i);
		int smallest = i;

		// Check if the left child is smaller than current node
		if (left < size && heap[left].second < heap[smallest].second) {
			smallest = left;
		}

		// Check if the right child is smaller than the smallest found so far
		if (right < size && heap[right].second < heap[smallest].second) {
			smallest = right;
		}

		// Swap and heapify down further if needed
		if (smallest != i) {
			swap(heap[i], heap[smallest]);
			heapifyDown(smallest);
		}
	}

	void heapifyUp(int i) {

		if (i && heap[parent(i)].second > heap[i].second) {
			swap(heap[i], heap[parent(i)]);
			heapifyUp(parent(i));
		}
	}

	void resize(size_t newSize) {

		if (newSize <= maxSize) return;

		maxSize = newSize;

		pair* aux = new pair[maxSize];

		for (int i = 0; i < maxSize; i++) {
			aux[i] = heap[i];
		}

		delete[] heap;
		heap = aux;
	}

public:

	MinHeap(size_t maxSize = 10) {

		maxSize = maxSize;

		heap = new pair[maxSize];
		hash = new int[maxSize];

		for (int i = 0; i < maxSize; i++) hash[i] = -1;

		size = 0;
	}

	~MinHeap() {
		delete[] heap;
		delete[] hash;
	}

	bool contains(const Key& key) const { return hash[key] != -1; }

	bool empty() const { return size == 0; }


	pair& peek() const {

		if (empty()) {
			throw std::runtime_error("MinHeap underflow: Attempt to peek an empty heap.");
		}

		return heap[0];
	}

	void push(const pair& pair) {

		if (size == maxSize) resize(maxSize * 2);

		heap[size] = pair;
		hash[pair.first] = size;

		heapifyUp(size++);
	}

	pair pop() {

		if (empty()) {
			throw std::runtime_error("MinHeap underflow: Attempt to pop an empty heap.");
		}

		pair root = heap[0];
		hash[root.first] = -1;

		heap[0] = heap[--size];
		hash[heap[0].first] = 0;

		heapifyDown(0);

		return root;
	}

	// Decrease the value of the element at index hash[pair.first] to pair.
	void decreaseKey(pair pair) {

		// if (i < 0 || i >= size) {
		// 	throw std::out_of_range("Index out of range for decreaseKey operation.");
		// }

		// if (new_val > heap[i]) {
		// 	throw std::invalid_argument("New value is greater than the current value.");
		// }

		int index = hash[pair.first];

		if (index == -1 || heap[hash[pair.first]].second < pair.second) return;

		heap[index] = pair;

		heapifyUp(index);
	}

	std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (int i = 0; i < size; i++) {
			oss << heap[i] << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const MinHeap<Key, Value>& minHeap) {
		os << minHeap.str();
		return os;
	}
};

#endif
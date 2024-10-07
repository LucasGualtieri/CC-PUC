#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include <sstream>

#include "queue.hpp"

template <typename T>
class MinHeap : public Queue<T> {

	T* heap;
	size_t maxSize;

	int parent(int i) { return (i - 1) / 2; }
	int leftChild(int i) { return (2 * i) + 1; }
	int rightChild(int i) { return (2 * i) + 2; }

	void swap(T &x, T &y) {
		T temp = x;
		x = y;
		y = temp;
	}

	// Heapify down the heap from index i
	void heapifyDown(int i) {

		int left = leftChild(i);
		int right = rightChild(i);
		int smallest = i;

		// Check if the left child is smaller than current node
		if (left < this->_size && heap[left] < heap[smallest]) {
			smallest = left;
		}

		// Check if the right child is smaller than the smallest found so far
		if (right < this->_size && heap[right] < heap[smallest]) {
			smallest = right;
		}

		// Swap and heapify down further if needed
		if (smallest != i) {
			swap(heap[i], heap[smallest]);
			heapifyDown(smallest);
		}
	}

	void heapifyUp(int i) {

		if (i && heap[parent(i)] > heap[i]) {
			swap(heap[i], heap[parent(i)]);
			heapifyUp(parent(i));
		}
	}

	void resize(size_t newSize) {

		if (newSize <= maxSize) return;

		maxSize = newSize;

		T* aux = new T[maxSize];

		for (int i = 0; i < maxSize; i++) {
			aux[i] = heap[i];
		}

		delete[] heap;
		heap = aux;
	}


public:

	MinHeap(size_t maxSize = 10) {

		this->maxSize = maxSize;

		heap = new T[maxSize];

		this->_size = 0;
	}

	~MinHeap() { delete[] heap; }

	bool contains(const T& value) const override { return T(); }

	void push(const T& key) override {

		if (this->_size == maxSize) resize(maxSize * 2);

		heap[this->_size] = key;

		heapifyUp(this->_size++);
	}

	T pop() override {

		if (this->empty()) {
			throw std::runtime_error("MinHeap underflow: Attempt to pop an empty heap.");
		}

		T root = heap[0];

		heap[0] = heap[--this->_size];

		heapifyDown(0);

		return root;
	}

	// Decrease the value of the element at index i to new_val.
    void decreaseKey(int i, const T& new_val) {

        if (i < 0 || i >= this->_size) {
            throw std::out_of_range("Index out of range for decreaseKey operation.");
        }

        if (new_val > heap[i]) {
            throw std::invalid_argument("New value is greater than the current value.");
        }

        heap[i] = new_val;
        heapifyUp(i);
    }

	T& peek() const override {

		if (this->empty()) {
			throw std::runtime_error("MinHeap underflow: Attempt to peek an empty heap.");
		}

		return heap[0];
	}

	virtual std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		// for (Cell<T>* i = head->next; i; i = i->next) {
		// 	oss << i->value << " ";
		// }

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const Queue<T>& list) {
		os << list.str();
		return os;
	}
};

#endif
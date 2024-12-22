#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <sstream>
#include "queue.hpp"

template <typename T>
class LinearQueue : public Queue<T> {

	size_t maxSize, head, tail;
	T* array;

	void resize(size_t newSize) {

		maxSize = newSize + 1;

		T* aux = new T[maxSize];

		for (int i = head; i != tail; i = (i + 1) % maxSize) {
			aux[i] = array[i];
		}

		delete[] array;
		array = aux;
	}

  public:

	LinearQueue(size_t maxSize = 5) {

		this->maxSize = maxSize + 1;
		this->_size = head = tail = 0;

		array = new T[maxSize];
	}

	~LinearQueue() override { delete[] array; }

	bool contains(const T& value) const override {

		for (int i = 0; i < this->_size; i++) {
			if (array[i] == value) return true;
		}

		return false;
	}

	void push(const T& value) override {

		if (((tail + 1) % maxSize) == head) resize((maxSize - 1) * 2);

		array[tail] = value;
		tail = (tail + 1) % maxSize;
		this->_size++;
	}

	T pop() override {

		if (this->empty()) {
			throw std::runtime_error("Stack underflow: Attempt to pop from an empty stack.");
		}

		T deleted = array[head];

		this->_size--;
		head = (head + 1) % maxSize;

		return deleted;
	}

	T& peek() const override {

		if (this->empty()) {
			throw std::runtime_error("Queue underflow: Attempt to peek an empty queue.");
		}

		return array[head];
	}

	void reserve(size_t newCapacity) {

		if (newCapacity > maxSize) {
			resize(newCapacity);
		}
	}

	void shrink_to_fit() { resize(this->_size); }
	virtual void clear() { this->_size = head = tail = 0; }
	size_t capacity() { return maxSize - 1; }

	virtual std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (int i = head; i != tail; i = (i + 1) % maxSize) {
			oss << array[i] << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const LinearQueue& list) {
		os << list.str();
		return os;
	}

	T* begin() const { return array; }
	T* end() const { return array + this->_size; }
};

#endif
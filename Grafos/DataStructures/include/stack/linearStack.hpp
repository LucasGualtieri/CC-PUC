#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <sstream>
#include "../iterable.hpp"
#include "stack.hpp"

template <typename T>
class LinearStack : public Stack<T> {

	size_t maxSize;
	T* array;

	void expand() {

		maxSize *= 2;

		T* aux = new T[maxSize];

		for (int i = 0; i < this->_size; i++) {
			aux[i] = array[i];
		}

		delete[] array;

		array = aux;
	}

  public:

	LinearStack(size_t maxSize = 5) {

		this->maxSize = maxSize;
		this->_size = 0;

		array = new T[maxSize];
	}

	~LinearStack() override { delete[] array; }

	void push(const T& value) override {

		if (this->_size + 1 == maxSize) expand();

		array[this->_size++] = value;
	}

	T pop() override {

		if (this->empty()) throw std::runtime_error("Stack is empty.");

		return array[--this->_size];
	}

	bool search(const T& value) override {

		LinearStack<T> aux;

		while (!this->empty() && this->peek() != value) aux.push(pop());

		bool found = !this->empty();

		while (!aux.empty()) push(aux.pop());

		return found;
	}

	T& peek() const override {

		if (this->empty()) throw std::runtime_error("Stack is empty.");

		return array[this->_size - 1];
	}

	void shrink_to_fit() {

		maxSize = this->_size / 2;
		expand();

	}

	size_t capacity() { return maxSize; }

	friend std::ostream& operator<<(std::ostream& os, const LinearStack& list) {
		os << list.str();
		return os;
	}
};

#endif
#ifndef LINEAR_STACK_HPP
#define LINEAR_STACK_HPP

#include <sstream>
#include "stack.hpp"

template <typename T>
class LinearStack : public Stack<T> {

	size_t maxSize;
	T* array;

	void resize(size_t newSize) {

		maxSize = newSize;

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

	bool contains(const T& value) const override {

		for (int i = 0; i < this->_size; i++) {
			if (array[i] == value) return true;
		}

		return false;
	}

	void push(const T& value) override {

		if (this->_size == maxSize) resize(maxSize * 2);

		array[this->_size++] = value;
	}

	T pop() override {

		if (this->empty()) {
			throw std::runtime_error("Stack underflow: Attempt to pop from an empty stack.");
		}

		return array[--this->_size];
	}

	T& peek() const override {

		if (this->empty()) {
			throw std::runtime_error("Stack underflow: Attempt to peek an empty stack.");
		}

		return array[this->_size - 1];
	}

	void reserve(size_t newCapacity) {

		if (newCapacity > maxSize) {
			resize(newCapacity);
		}
	}

	void shrink_to_fit() { resize(this->_size); }
	virtual void clear() { this->_size = 0; }
	size_t capacity() { return maxSize; }

	virtual std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (int i = this->_size - 1; i >= 0; i--) {
			oss << array[i] << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const LinearStack& list) {
		os << list.str();
		return os;
	}

	T* begin() const { return array; }
	T* end() const { return array + this->_size; }
};

#endif
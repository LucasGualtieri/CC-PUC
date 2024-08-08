#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <sstream>
#include "../iterable.hpp"
#include "stack.hpp"

template <typename T>
class LinkedStack : public Stack<T> {

	struct Cell {

		T value;
		Cell* next;

		Cell() : value(T()) {}
		Cell(T value) : value(value), next(nullptr) {}
		Cell(T value, Cell *next) : value(value), next(next) {}

		bool operator==(const Cell*& other) const { return value == other->value; }
		bool operator!=(const Cell*& other) const { return value != other->value; }
		bool operator<(const Cell*& other) const { return value < other->value; }
		bool operator<=(const Cell*& other) const { return value <= other->value; }
		bool operator>(const Cell*& other) const { return value > other->value; }
		bool operator>=(const Cell*& other) const { return value >= other->value; }
	};

	Cell* top;

  public:

	LinkedStack() : top(nullptr) { this->_size = 0; }

	~LinkedStack() override { this->erase(); }

	void push(const T& value) override {
		top = new Cell(value, top);
		this->_size++;
	}

	T pop() override {

		if (this->empty()) {
			throw std::runtime_error("Stack underflow: Attempt to pop from an empty stack.");
		}

		T value = top->value;
		Cell* temp = top;
		top = top->next;
		delete temp;

		this->_size--;

		return value;
	}

	T& peek() const override {

		if (this->empty()) {
			throw std::runtime_error("Stack underflow: Attempt to pop from an empty stack.");
		}

		return top->value;
	}

	bool search(const T& value) override {

		LinkedStack<T> aux;

		while (!this->empty() && this->peek() != value) aux.push(pop());

		bool found = !this->empty();

		while (!aux.empty()) push(aux.pop());

		return found;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedStack& list) {
		os << list.str();
		return os;
	}
};

#endif
#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <sstream>
#include "stack.hpp"
#include "../cell.hpp"

template <typename T>
class LinkedStack : public Stack<T> {

    Cell<T>* top;

public:

    LinkedStack() : top(nullptr) { this->_size = 0; }

    LinkedStack(T value) : top(nullptr) {

		this->_size = 0;
		push(value);
	}

    ~LinkedStack() override { this->clear(); }

	bool contains(const T& value) const override {

		for (Cell<T>* i = top; i; i = i->next) {
			if (i->value == value) return true;
		}

		return false;
	}

    void push(T value) override {
        top = new Cell<T>(value, top);
        this->_size++;
    }

    T pop() override {
        if (this->empty()) {
            throw std::runtime_error("Stack underflow: Attempt to pop from an empty stack.");
        }

        T value = top->value;
        Cell<T>* temp = top;
        top = top->next;
        delete temp;

        this->_size--;
        return value;
    }

    T& peek() const override {
        if (this->empty()) {
            throw std::runtime_error("Stack underflow: Attempt to peek an empty stack.");
        }

        return top->value;
    }

	virtual std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (Cell<T>* i = top; i; i = i->next) {
			oss << i->value << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& list) {
		os << list.str();
		return os;
	}
};

#endif
#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include <sstream>
#include "queue.hpp"
#include "../../utils/cell.hpp"

template <typename T>
class LinkedQueue : public Queue<T> {

    Cell<T> *head, *tail;

public:

	LinkedQueue() {
		head = tail = new Cell<T>;
		this->_size = 0;
	}

	LinkedQueue(T value) {
		head = tail = new Cell<T>;
		this->_size = 0;
		this->push(value);
	}

	~LinkedQueue() override {
		this->clear();
		delete head;
	}

	bool contains(const T& value) const override {

		for (Cell<T>* i = head; i; i = i->next) {
			if (i->value == value) return true;
		}

		return false;
	}

	void push(const T& value) override {

		tail = tail->next = new Cell<T>(value);
		this->_size++;
	}

	T pop() override {

		if (this->empty()) {
			throw std::runtime_error("Queue underflow: Attempt to pop an empty queue.");
		}

		T& value = head->next->value;

		Cell<T>* temp = head;
		head = head->next;

		delete temp;

		this->_size--;

		return value;
	}

	T& peek() const override {

		if (this->empty()) {
			throw std::runtime_error("Queue underflow: Attempt to peek an empty queue.");
		}

        return head->next->value;
    }

	virtual std::string str() const override {

		std::ostringstream oss;

		oss << "{ ";

		for (Cell<T>* i = head->next; i; i = i->next) {
			oss << i->value << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const Queue<T>& list) {
		os << list.str();
		return os;
	}
};

#endif

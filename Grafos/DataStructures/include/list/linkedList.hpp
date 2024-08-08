#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "list.hpp"
#include "../iterable.hpp"

template <typename T>
class LinkedList : public List<T>, public Iterable<T> {

	struct Cell {

		T value;
		Cell *next;

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

	Cell *head, *tail;

  public:

	LinkedList() {
		head = tail = new Cell;
		this->_size = 0;
	}

	~LinkedList() override {

		while(!this->empty()) pop_back();

		delete head;
	}

	void push_front(const T& value) override {

		head->next = new Cell(value, head->next);

		if (this->empty()) tail = head->next;
		this->_size++;
	}

	void push_back(const T& value) override {

		tail = tail->next = new Cell(value);
		this->_size++;
	}

	T pop_front() override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		T& value = head->next->value;

		Cell* temp = head;
		head = head->next;

		delete temp;

		this->_size--;

		return value;
	}

	T pop_back() override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		Cell* i = head;
		while (i->next != tail) i = i->next;

		T value = i->next->value;

		Cell* temp = i->next;

		if (i == head) {
			delete head;
	 		head = temp;
		}

		else {
			i->next = nullptr;
			tail = i;
			delete temp;
		}


		this->_size--;

		return value;
	}

	void add(const T& value, unsigned int pos = 0) override {

		if (pos < 0 || this->_size < pos) {
			throw std::runtime_error("Invalid position.");
		}

		Cell* cell = head->next;

		for (int i = 0; i < pos - 1; i++, cell = cell->next);

		cell->next = new Cell(value, cell->next);

		this->_size++;
	}

	T remove(unsigned int pos) override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		if (pos < 0 || pos >= this->_size) {
			throw std::runtime_error("Invalid position.");
		}

		if (pos == 0) return pop_front();

		if (pos == this->_size - 1) return pop_back();

		Cell *aux = head;
		for (int i = 0; i < pos; i++) aux = aux->next;

		Cell *temp = aux->next;
		T value = temp->value;
		aux->next = aux->next->next;

		delete temp;

		this->_size--;

		return value;
	}

	T& front() const override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		return head->next->value;
	}

	T& back() const override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		return tail->value;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
		os << list.str();
		return os;
	}

	void quicksort(Cell* left, Cell* right) {}

	void sort() override { quicksort(head->next, tail); }
};

#endif
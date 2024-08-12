#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <sstream>
#include "list.hpp"

template <typename T>
class DLinkedList : public List<T> {

	struct Cell {

		T value;
		Cell *prev, *next;

		Cell() : value(T()) {}
		Cell(T value, Cell* prev = nullptr, Cell* next = nullptr) : value(value), prev(prev), next(next) {}

		bool operator==(const Cell*& other) const { return value == other->value; }
		bool operator!=(const Cell*& other) const { return value != other->value; }
		bool operator<(const Cell*& other) const { return value < other->value; }
		bool operator<=(const Cell*& other) const { return value <= other->value; }
		bool operator>(const Cell*& other) const { return value > other->value; }
		bool operator>=(const Cell*& other) const { return value >= other->value; }
	};

	Cell *head, *tail;

  public:

	DLinkedList() {
		head = tail = new Cell;
		this->_size = 0;
	}

	~DLinkedList() override {

		while(!this->empty()) pop_back();

		delete head;
	}

	bool contains(const T& value) const override {

		for (Cell* i = head->next; i; i = i->next) {
			if (i->value == value) return true;
		}

		return false;
	}

	void push_front(T value) override {

		head->next = new Cell(value, head, head->next);

		if (this->empty()) tail = head->next;

		this->_size++;
	}

	void push_back(T value) override {

		tail = tail->next = new Cell(value, tail);
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

		T value = tail->value;
		tail = tail->prev;

		Cell* temp = tail->next;
		tail->next = nullptr;

		delete temp;

		this->_size--;

		return value;
	}

	void add(const T& value, unsigned int pos = 0) override {

		if (pos < 0 || this->_size < pos) {
			throw std::runtime_error("Invalid position.");
		}

		Cell* cell = head->next;

		for (int i = 0; i < pos - 1; i++, cell = cell->next);

		cell->next = new Cell(value, cell, cell->next);

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
		if (aux->next->next) aux->next->next->prev = aux;

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

	std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (Cell* i = head->next; i; i = i->next) {
			oss << i->value << " ";
		}

		oss << "}";

		return oss.str();

	}

	std::string reverseTraversal() const {

		std::ostringstream oss;

		oss << "{ ";

		for (Cell* i = tail; i != head; i = i->prev) {
			oss << i->value << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const DLinkedList<T>& list) {
		os << list.str();
		return os;
	}

	void quicksort(Cell* left, Cell* right) {}

	void sort() override { quicksort(head->next, tail); }
};

#endif
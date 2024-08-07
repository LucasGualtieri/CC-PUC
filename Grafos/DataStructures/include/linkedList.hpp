#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <sstream>
#include "list.hpp"

template <typename T>
class LinkedList : public List<T> {

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

	size_t _size;
	Cell *head, *tail;

  public:

	LinkedList() {
		head = tail = new Cell;
		_size = 0;
	}

	~LinkedList() override {

		while(!empty()) pop_back();

		delete head;
	}

	void push_front(const T& value) override {

		head->next = new Cell(value, head->next);

		if (empty()) tail = head->next;
		_size++;
	}

	void push_back(const T& value) override {

		tail = tail->next = new Cell(value);
		_size++;
	}

	T pop_front() override {

		if (empty()) throw std::runtime_error("List is empty.");

		T& value = head->next->value;

		Cell* temp = head;
		head = head->next;

		delete temp;

		_size--;

		return value;
	}

	T pop_back() override {

		if (empty()) throw std::runtime_error("List is empty.");

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


		_size--;

		return value;
	}

	void add(const T& value, unsigned int pos = 0) override {

		if (pos < 0 || _size < pos) {
			throw std::runtime_error("Invalid position.");
		}

		Cell* cell = head->next;

		for (int i = 0; i < pos - 1; i++, cell = cell->next);

		cell->next = new Cell(value, cell->next);

		_size++;
	}

	T remove(unsigned int pos) override {

		if (empty()) throw std::runtime_error("List is empty.");

		if (pos < 0 || pos >= _size) {
			throw std::runtime_error("Invalid position.");
		}

		if (pos == 0) return pop_front();

		if (pos == _size - 1) return pop_back();

		Cell *aux = head;
		for (int i = 0; i < pos; i++) aux = aux->next;

		Cell *temp = aux->next;
		T value = temp->value;
		aux->next = aux->next->next;

		delete temp;

		_size--;

		return value;
	}

	void erase() { while(!empty()) pop_back(); }

	size_t size() const override { return _size; }

	bool empty() const override { return _size == 0; }

	T& front() override {

		if (empty()) throw std::runtime_error("List is empty.");

		return head->next->value;
	}

	T& back() override {

		if (empty()) throw std::runtime_error("List is empty.");

		return tail->value;
	}

	std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (Cell* i = head->next; i; i = i->next) {
			oss << i->value << ", ";
		}

		oss << "}";

		return oss.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
		os << list.str();
		return os;
	}

	// Cell* getMiddle() {

	// 	if (!head) return nullptr;

	// 	Cell* slow = head;
	// 	Cell* fast = head;

	// 	while (fast && fast->next) {
	// 		slow = slow->next;
	// 		fast = fast->next->next;
	// 	}

	// 	return slow;
	// }

	// void swap(T& a, T& b) {
	// 	T aux = a;
	// 	a = b;
	// 	b = aux;
	// }

	// Cell* getLeft(const Cell* j) {

	// 	if (!head || head == j) return nullptr;

	// 	Cell* left = head;
	// 	while (left->next && left->next != j) left = left->next;

	// 	return left->next == j ? left : nullptr;
	// }

	// void quicksort(Cell* left, Cell* right) {

	// 	Cell *pivot = left, *i = left->next, *j = right;

	// 	while (j->next != i && j->next != getLeft(i)) {

	// 		while (i && i < pivot) i = i->next;
	// 		while (j > pivot) j = getLeft(j);

	// 		if (j->next != i) {
	// 			swap(i->value, j->value);
	// 			i = i->next, j = getLeft(j);
	// 		}
	// 	}

	// 	swap(pivot->value, j->value);

	// 	if (j != left) quicksort(left, getLeft(j));
	// 	if (j != right) quicksort(j->next, right);
	// }

	// void sort() override { quicksort(head->next, tail); }

	// class Iterator : public List<T>::Iterator {
	//   private:
	// 	Cell* current;

	//   public:
	// 	Iterator(Cell* start) : current(start) {}

	// 	T& operator*() const override {
	// 		return current->value;
	// 	}

	// 	T* operator->() const override {
	// 		return &(current->value);
	// 	}

	// 	Iterator& operator++() override {
	// 		if (current) current = current->next;
	// 		return *this;
	// 	}

	// 	Iterator operator++(int) override {
	// 		Iterator tmp = *this;
	// 		if (current) current = current->next;
	// 		return tmp;
	// 	}

	// 	bool operator==(const List<T>::Iterator& other) const override {
	// 		const Iterator& other_it = static_cast<const Iterator&>(other);
	// 		return current == other_it.current;
	// 	}

	// 	bool operator!=(const List<T>::Iterator& other) const override {
	// 		const Iterator& other_it = static_cast<const Iterator&>(other);
	// 		return current != other_it.current;
	// 	}
	// };

	// typename List<T>::Iterator begin() const override { return Iterator(head->next); }
    // typename List<T>::Iterator end() const override { return Iterator(nullptr); }

};

#endif
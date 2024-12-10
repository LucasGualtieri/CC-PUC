#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <sstream>
#include "list.hpp"
#include "../../utils/cell.hpp"

template <typename T>
class LinkedList : public List<T> {

	Cell<T> *head, *tail;

  public:

	LinkedList() {
		head = tail = new Cell<T>;
		this->_size = 0;
	}

	~LinkedList() override {

		while(!this->empty()) pop_back();

		delete head;
	}

	bool contains(const T& value) const override {

		for (Cell<T>* i = head->next; i; i = i->next) {
			if (i->value == value) return true;
		}

		return false;
	}

	void push_front(T value) override {

		head->next = new Cell<T>(value, head->next);

		if (this->empty()) tail = head->next;
		this->_size++;
	}

	void push_back(T value) override {

		tail = tail->next = new Cell<T>(value);
		this->_size++;
	}

	T pop_front() override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		T& value = head->next->value;

		Cell<T>* temp = head;
		head = head->next;

		delete temp;

		this->_size--;

		return value;
	}

	T pop_back() override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		Cell<T>* i = head;
		while (i->next != tail) i = i->next;

		T value = i->next->value;

		Cell<T>* temp = i->next;

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

	void add(T value, unsigned int pos = 0) override {

		if (pos < 0 || this->_size < pos) {
			throw std::runtime_error("Invalid position.");
		}

		Cell<T>* cell = head->next;

		for (int i = 0; i < pos - 1; i++, cell = cell->next);

		cell->next = new Cell<T>(value, cell->next);

		this->_size++;
	}

	T remove(unsigned int pos) override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		if (pos < 0 || pos >= this->_size) {
			throw std::runtime_error("Invalid position.");
		}

		if (pos == 0) return pop_front();

		if (pos == this->_size - 1) return pop_back();

		Cell<T> *aux = head;
		for (int i = 0; i < pos; i++) aux = aux->next;

		Cell<T> *temp = aux->next;
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

	virtual std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (Cell<T>* i = head->next; i; i = i->next) {
			oss << i->value << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
		os << list.str();
		return os;
	}

	void quicksort(Cell<T>* left, Cell<T>* right) {}

	void sort() override { quicksort(head->next, tail); }
};

#endif

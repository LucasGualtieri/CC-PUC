#ifndef LINEAR_LIST_HPP
#define LINEAR_LIST_HPP

#include <sstream>
#include "list.hpp"

template <typename T>
class LinearList : public List<T> {

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

	LinearList(size_t maxSize = 5) {

		this->maxSize = maxSize;
		this->_size = 0;

		array = new T[maxSize];
	}

	LinearList(const LinearList& other) : maxSize(other.capacity()) {

		this->_size = other.size();

		array = new T[maxSize];

		for (int i = 0; i < this->_size; i++) {
			array[i] = other.array[i];
		}
	}

	~LinearList() override { delete[] array; }

	bool contains(const T& value) const override {

		for (int i = 0; i < this->_size; i++) {
			if (array[i] == value) return true;
		}

		return false;
	}

	void push_front(T value) override {

		if (this->_size == maxSize) resize(maxSize * 2);

		for (int i = this->_size; i > 0; i--) {
			array[i] = array[i - 1];
		}

		array[0] = value;

		this->_size++;
	}

	void push_back(T value) override {

		if (this->_size == maxSize) resize(maxSize * 2);

		array[this->_size++] = value;
	}

	T pop_front() override {

		if (this->empty()) {
			throw std::runtime_error("List underflow: Attempt to pop_front() an empty list.");
		}

		T value = array[0];

		for (int i = 0; i < this->_size - 1; i++) {
			array[i] = array[i + 1];
		}

		this->_size--;

		return value;
	}

	T pop_back() override {

		if (this->empty()) {
			throw std::runtime_error("List underflow: Attempt to pop_front() an empty list.");
		}

		return array[--this->_size];
	}

	void add(const T& value, unsigned int pos) override {

		if (this->_size == maxSize) resize(this->_size * 2);

		if (pos < 0 || this->_size < pos) {
			throw std::runtime_error("Invalid position.");
		}

		for (int i = this->_size; i > pos; i--) {
			array[i] = array[i - 1];
		}

		array[pos] = value;

		this->_size++;
	}

	T remove(unsigned int pos) override {

		if (this->empty()) throw std::runtime_error("List is empty.");

		if (pos < 0 || pos >= this->_size) {
			throw std::runtime_error("Invalid position.");
		}

		if (pos == 0) return pop_front();

		if (pos == this->_size - 1) return pop_back();

		T value = array[pos];

		for (int i = pos; i < this->_size - 1; i++) {
			array[i] = array[i + 1];
		}

		this->_size--;

		return value;
	}

	T& front() const override {

		if (this->empty()) throw std::runtime_error("List underflow: Attempt to front() an empty list.");

		return array[0];
	}

	T& back() const override {

		if (this->empty()) throw std::runtime_error("List underflow: Attempt to back() an empty list.");

		return array[this->_size - 1];
	}

	void reserve(size_t newCapacity) {

		if (newCapacity > maxSize) {
			resize(newCapacity);
		}
	}

	void shrink_to_fit() { resize(this->_size); }
	size_t capacity() const { return maxSize; }

	std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		for (int i = 0; i < this->_size; i++) {
			oss << array[i] << " ";
		}

		oss << "}";

		return oss.str();

	}

	friend std::ostream& operator<<(std::ostream& os, const LinearList<T>& list) {
		os << list.str();
		return os;
	}

	T& operator[](size_t index) const {

		if (index >= this->_size) {
			throw std::out_of_range("Index out of bounds");
		}

		return array[index];
	}

	T& operator[](size_t index) {

		if (index >= this->_size) {
			throw std::out_of_range("Index out of bounds");
		}

		return array[index];
	}

	bool operator==(const LinearList<T> other) const {

		if (this->size() != other.size()) return false;

		for (int i = 0; i < this->size(); i++) {
			if (array[i] != other[i]) return false;
		}

		return true;
	}

	void quicksort(int left, int right) {}

	void sort() override { quicksort(0, this->_size - 1); }
};

#endif
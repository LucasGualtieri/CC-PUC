#ifndef LINEAR_LIST_HPP
#define LINEAR_LIST_HPP

#include <sstream>
#include <limits>
#include "list.hpp"
#include "../../util/util.hpp"

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

	LinearList(int n, T array[]) {

		this->maxSize = n;
		this->_size = 0;

		this->array = new T[maxSize];

		for (int i = 0; i < n; i++) {
			push_back(array[i]);
		}
	}

	LinearList(size_t maxSize = 5) {

		this->maxSize = maxSize;
		this->_size = 0;

		array = new T[maxSize];
	}

	LinearList(std::initializer_list<T> list) {

		this->maxSize = list.size();
		this->_size = 0;

		array = new T[maxSize];

		for (T i : list) push_back(i);
	}

	LinearList(size_t first, size_t last) {

		if (first > last) swap(first, last);

		this->maxSize = (last - first) + 1;
		this->_size = 0;

		array = new T[maxSize];

		for (int i = first; i <= last; i++) push_back(i);
	}

	LinearList(const LinearList &other) : maxSize(other.capacity()) {

		this->_size = other.size();

		array = new T[maxSize];

		for (int i = 0; i < this->_size; i++) {
			array[i] = other.array[i];
		}
	}

	bool operator!=(const LinearList<T>& other) const {

		if (this->size() != other.size()) return true;

		for (int i = 0; i < this->size(); i++) {
			if (array[i] != other[i]) return true;
		}

		return false;
	}

	LinearList<T>& operator=(const LinearList<T>& other) {

		if (this != &other) {

			delete[] array;

			this->_size = other._size;
			this->maxSize = other.maxSize;

			array = new T[maxSize];

			for (int i = 0; i < this->_size; i++) {
				array[i] = other.array[i];
			}
		}

		return *this;
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
			throw std::runtime_error("List underflow: Attempt to pop_back() an empty list.");
		}

		return array[--this->_size];
	}

	void add(T value, unsigned int pos) override {

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

	size_t indexOf(T value) {

		for (int i = 0; i < this->_size; i++) {
			if (array[i] == value) return i;
		}

		return -1;
	}

	std::string str() const {

		if (this->size() == 0) return "∅";

		std::ostringstream oss;

		oss << "{ ";

		for (int i = 0; i < this->_size; i++) {

			if (array[i] == std::numeric_limits<T>::max()) {
				oss << "∞";
			}

			else if (array[i] == std::numeric_limits<T>::min()) {
				oss << "-∞";
			}

			else oss << array[i];

			if (i < this->_size - 1) oss << ", ";
		}

		oss << " }";

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

	int compareListsLexicographically(const LinearList& list) {

		int minSize = std::min(this->_size, list.size());

		// If all elements are the same up to the shorter size, compare sizes
		if (this->_size < list.size()) {
			return -1;  // arr1 is lexicographically smaller because it's shorter
		} else if (this->_size > list.size()) {
			return 1;   // arr1 is lexicographically greater because it's longer
		}

		// Compare elements one by one
		for (int i = 0; i < minSize; ++i) {

			if (array[i] < list.array[i]) {
				return -1;  // arr1 is lexicographically smaller
			} else if (array[i] > list.array[i]) {
				return 1;   // arr1 is lexicographically greater
			}
		}

		return 0;  // Both arrays are lexicographically equal
	}

	bool operator<(const LinearList& list) {
		return compareListsLexicographically(list) < 0;
	}

	bool operator>(const LinearList& list) {
		return compareListsLexicographically(list) > 0;
	}

	void quicksort(int left, int right) {

		int i = left, j = right;
		T pivo = array[(right + left) / 2];

		while (i <= j) {
			while (array[i] < pivo) i++;
			while (array[j] > pivo) j--;
			if (i <= j) swap(array[i++], array[j--]);
		}

		if (left < j) quicksort(left, j);
		if (i < right) quicksort(i, right);
	}

	void quicksort(int left, int right, auto& compare) {

		int i = left, j = right;
		T pivo = array[(right + left) / 2];

		while (i <= j) {
			while (compare(array[i], pivo) < 0) i++;
			while (compare(array[j], pivo) > 0) j--;
			if (i <= j) swap(array[i++], array[j--]);
		}

		if (left < j) quicksort(left, j);
		if (i < right) quicksort(i, right);
	}

	void sort() override { quicksort(0, this->_size - 1); }

	void sort(auto compare) { quicksort(0, this->_size - 1); }

	class Iterator {
		T* current;
	public:
		Iterator(T* ptr) : current(ptr) {}

		T& operator*() const {
			return *current;
		}

		Iterator& operator++() {
			current++;
			return *this;
		}

		Iterator operator++(int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		bool operator==(const Iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
	};

	Iterator begin() {
		return Iterator(array);
	}

	Iterator end() {
		return Iterator(array + this->_size);
	}
};

#endif
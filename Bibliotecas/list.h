#ifndef LIST_H
#define LIST_H

#include <biblioteca_cpp.h>

template <typename T>
class List {
	T* array;
	size_t arraySize, size;
	bool initialized;

public:
	List() {
		array = nullptr;
		this->arraySize = 0;
		this->size = 0;
		this->initialized = false;
	}

	List(size_t arraySize) {
		this->array = new T[arraySize];
		this->arraySize = arraySize;
		size = 0;
		initialized = true;
	}

	~List() {
		// cout << "List being deallocated." << endl;
		delete[] array;
	}

	void initialize(size_t arraySize) {
		if (initialized) {
			cout << "List already initialized!" << endl;
			return;
		}

		this->array = make_unique<T[]>(arraySize);
		this->arraySize = arraySize;
		size = 0;
		initialized = true;
	}

	size_t getSize() {
		return size;
	}

	T operator[](size_t index) {
		if (index >= size) {
			throw string("Error: Index [" + to_string(index) + "] is out of bounds!");
		}

		return array[index];
	}

	void insert(T value, size_t index) {

		if (size >= arraySize || index < 0 || index > size) {
			throw string("Erro ao inserir!");
		}

		for (size_t i = size; i > index; i--) {
			array[i] = array[i - 1];
		}

		array[index] = value;
		size++;
	}

	void insertBeggining(T value) {

		if (size >= arraySize) throw string("Erro ao inserir!");

		for (size_t i = size; i > 0; i--) {
			array[i] = array[i - 1];
		}

		array[0] = value;
		size++;
	}

	void insertEnd(T value) {
		if (size >= arraySize) throw string("Erro ao inserir!");
		array[size++] = value;
	}

	T remove(int index) {
		if (size == 0 || index < 0 || index >= size) {
			throw string("Erro ao remover!");
		}

		T removed = array[index];
		size--;

		for (int i = index; i < size; i++) {
			array[i] = array[i + 1];
		}

		return removed;
	}

	T removeBeggining() {

		if (size == 0) throw string("Erro ao remover!");

		size--;

		T removed = array[0];

		for (int i = 0; i < size; i++) {
			array[i] = array[i + 1];
		}

		return removed;
	}

	T removeEnd() {
		if (size == 0) throw string("Erro ao remover!");
		return array[--size];
	}

	int SelectionRecSort(int& numberOfSwaps, int minIndex = 0, int i = 0, int j = 1) {
		int numberOfComparisons = 0;

		if (j < size) {
			if (array[minIndex] > array[j]) {
				minIndex = j;
			}
			if (++j < size) {
				numberOfComparisons += SelectionRecSort(numberOfSwaps, minIndex, i, j);
			}
			numberOfComparisons += 2;
		}
		numberOfComparisons++;

		if (i < size - 1 && j == size) {
			if (array[minIndex] != array[i]) {
				T swap = array[minIndex];
				array[minIndex] = array[i];
				array[i] = swap;

				numberOfSwaps++;
			}

			if (++i < size - 1) {
				numberOfComparisons += SelectionRecSort(numberOfSwaps, i, i, i + 1);
			}
			numberOfComparisons += 4;
		}
		return numberOfComparisons += (j == size) ? 2 : 1;
	}

	int SelectionSort(int& numberOfSwaps) {
		int numberOfComparisons = 1;
		numberOfSwaps = 0;

		for (int i = 0; i < size - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < size; j++) {
				if (array[minIndex] > array[j]) minIndex = j;
				numberOfComparisons += 2;
			}
			if (array[minIndex] != array[i]) {
				int swap = array[minIndex];
				array[minIndex] = array[i];
				array[i] = swap;

				numberOfSwaps++;
			}

			numberOfComparisons += 3;
		}

		return numberOfComparisons;
	}

	template <typename U>
	bool BinarySearch(U searching) {
		bool found = false;

		int start = 0, end = size - 1;

		while (start <= end && !found) {
			int middle = (start + end) / 2;

			if (searching == array[middle]) {
				found = true;
			} else if (searching > array[middle]) {
				start = ++middle;
			} else {
				end = --middle;
			}
		}

		return found;
	}

	template <typename U>
	bool BinarySearch(U searching, int& numberOfComparisons) {
		bool found = false;

		int start = 0, end = size - 1;

		while (start <= end && !found) {
			int middle = (start + end) / 2;

			if (searching == array[middle]) {
				found = true;
				numberOfComparisons++;
			} else if (searching > array[middle]) {
				start = ++middle;
				numberOfComparisons++;
			} else {
				end = --middle;
			}

			numberOfComparisons++;
		}

		return found;
	}

	template <typename U>
	bool SequentialSearch(U searching) {
		bool found = false;
		for (int i = 0; i < size && !found; i++) {
			found = array[i] == searching;
		}
		return found;
	}

	template <typename U>
	bool SequentialSearch(U searching, int& numberOfComparisons) {
		bool found = false;
		for (int i = 0; i < size && !found; i++) {
			found = array[i] == searching;
		}
		return found;
	}

	void move(T value, int index) { } // Swap?

	void populate() { }

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			int menor = i;
			for (int j = i + 1; j < size; j++) {
				if (array[menor] > array[j]) menor = j;
			}
			T swap = array[menor];
			array[menor] = array[i];
			array[i] = swap;
		}
	}

	void print(bool printIndex = true) {
		if (size == 0) {
			cout << "List is empty!" << endl;
			return;
		}

		cout << "{ ";
		for (int i = 0; i < size; i++) {
			cout << array[i];
			if (i < size - 1) {
				cout << ", ";
			} else {
				cout << " }" << endl;
			}
		}
	}
};

#endif
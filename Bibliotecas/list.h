#ifndef LIST_H
#define LIST_H

#include <biblioteca_cpp.h>

template <typename T>
class List {
	unique_ptr<T[]> array;
	size_t arraySize, size;
	bool initialized;

public:
	List() {
		this->array = nullptr;
		this->arraySize = 0;
		this->size = 0;
		this->initialized = false;
	}

	List(size_t arraySize) {
		array = make_unique<T[]>(arraySize);
		this->arraySize = arraySize;
		size = 0;
		initialized = true;
	}

	void initialize(size_t arraySize) {
		if (initialized) {
			cout << "List already initialized!" << endl;
			return;
		}

		array = make_unique<T[]>(arraySize);
		this->arraySize = arraySize;
		size = 0;
		initialized = true;
	}

	void insert(T value, size_t index) {

		if (size >= arraySize || index < 0 || index > size) {
			// throw new Exception("Erro ao inserir!"); // Java
			return;
		}

		// levar elementos para o fim do array
		for (size_t i = size; i > index; i--) {
			array[i] = array[i - 1];
		}

		array[index] = value;
		size++;
	}

	void insertBeggining(T value) {

		if (size >= arraySize) {
			// throw new Exception("Erro ao inserir!"); // Java
			return;
		}

		for (size_t i = size; i > 0; i--) {
			array.get()[i] = array.get()[i - 1];
		}

		array.get()[0] = value;
		size++;
	}

	void insertEnd(T value) {
		if (size >= arraySize) {
			// throw new Exception("Erro ao inserir!"); // Java
			return;
		}

		array[size] = value;
		size++;
	}

	void remove(int index) { }

	void removeBeggining() {

		// validar remocao
		if (size == 0) {
			// throw new Exception("Erro ao remover!");
			return;
		}

		size--;

		for (int i = 0; i < size; i++) {
			array[i] = array[i + 1];
		}
	}

	void removeEnd() { }

	void move(T value, int index) { }

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

	void print() {
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
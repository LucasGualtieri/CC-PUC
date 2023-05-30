#ifndef LIST_H
#define LIST_H

#include <biblioteca_cpp.h>

template <typename T>
void Delete(T array, int index) {
	delete array[index];
}

template <>
void Delete(int* array, int index) { }

template <>
void Delete(char* array, int index) { }

template <>
void Delete(float* array, int index) { }

template <>
void Delete(double* array, int index) { }

template <typename T>
void FullFree(T array, int size) {
	for (int i = 0; i < size; i++) {
		Delete(array, i);
	}
	delete[] array;
}

template <typename T>
class List {
	T* array;
	size_t arraySize, size;
	bool initialized, fullFree;

public:
	List() {
		this->array = nullptr;
		this->arraySize = 0;
		this->size = 0;
		this->initialized = false;
	}

	List(size_t arraySize, bool fullFree = true) {
		this->array = new T[arraySize];
		this->arraySize = arraySize;
		this->size = 0;
		this->initialized = true;
		this->fullFree = fullFree;
	}

	~List() {
		if (fullFree) {
			FullFree(array, size);
		} else {
			delete array;
		}
	}

	void initialize(size_t arraySize, bool fullFree = true) {
		if (initialized) {
			cout << "List already initialized!" << endl;
			return;
		}

		this->array = new T[arraySize];
		this->arraySize = arraySize;
		this->size = 0;
		this->initialized = true;
		this->fullFree = fullFree;
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
			array[i] = array[i - 1];
		}

		this->array[0] = value;
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

		if (fullFree) {
			Delete(array, 0);
		}

		for (int i = 0; i < size; i++) {
			array[i] = array[i + 1];
		}
	}

	void removeEnd() {
		delete array[size - 1];
		size--;
	}

	void move(T value, int index) { }

	void sort() {
		for (T i = 0; i < size - 1; i++) {
			T menor = i;
			for (T j = i + 1; j < size; j++) {
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
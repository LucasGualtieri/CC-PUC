#ifndef LIST_H
#define LIST_H

#include <biblioteca_cpp.h>

template <typename T>
class List {
	T* array;
	int arraySize, size;
	bool initialized, fullFree;

public:
	List() {
		this->array = nullptr;
		this->arraySize = 0;
		this->size = 0;
		this->initialized = false;
	}

	List(int arraySize, bool fullFree = true) {
		this->array = new T[arraySize];
		this->arraySize = arraySize;
		this->size = 0;
		this->initialized = true;
		this->fullFree = fullFree;
	}

	~List() {
		if (fullFree) {
			FullFree();
		} else {
			delete array;
		}
	}

	void initialize(int arraySize, bool fullFree = true) {
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

	void insert(T value, int index) {

		if (size >= arraySize || index < 0 || index > size) {
			// throw new Exception("Erro ao inserir!"); // Java
			return;
		}

		// levar elementos para o fim do array
		for (int i = size; i > index; i--) {
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

		for (int i = size; i > 0; i--) {
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

	void remove(T value, int index) { }
	void removeBeggining(T value) { }
	void removeEnd(T value) {
		delete array[size - 1];
		size--;
	}

	void move(T value, int index) { }

	void FullFree() { }
	void sort() { }
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
#include <stddef.h>
#include "linkedList.hpp"
#include <stdexcept>

// Decisões que precisam ser tomadas:
// - Usar ou não usar smartpointers
// - Preciso corrigir a função pop_back
// - Simplifico as coisas? Uso só hpp, uso a cell publica dentro da lista?

template <typename T>
void LinkedList<T>::push_front(T value) {

	head->next = new Cell(value, head->next);
	if (tail == head) tail = head->next;
	n++;
}

template <typename T>
void LinkedList<T>::push_back(T value) {
	// tail = tail.next = new Cell(value);
}

template <typename T>
T& LinkedList<T>::pop_front(T value) {

	// if (head == tail) throw std::runtime_error("Cannot remove element from an empty list.");

	// T& removed = head->next->value;

	// head->next = head->next->next;

	// n--;

	// return removed;

	return T();
}

template <typename T>
T& LinkedList<T>::pop_back(T value) {

	// if (head == tail) throw std::runtime_error("Cannot remove element from an empty list.");

	// Cell* i;

	// for (i = head; i.next != tail; i = i.next);
	// i.prox = nullptr;

	// n--;

	return T();
}

template <typename T>
void add(int position, T value) {}

template <typename T>
T& LinkedList<T>::remove(int) { return T(); }

template <typename T>
T& LinkedList<T>::replace(int) { return T(); }

template <typename T>
T& LinkedList<T>::findAndRemove(T) { return T(); }

template <typename T>
T& LinkedList<T>::findAndReplace(T) { return T(); }

template <typename T>
size_t LinkedList<T>::size() { return 0; }

template <typename T>
bool LinkedList<T>::empty() { return T(); }

template <typename T>
T& LinkedList<T>::front() { return T(); }
template <typename T>
T& LinkedList<T>::back() { return T(); }
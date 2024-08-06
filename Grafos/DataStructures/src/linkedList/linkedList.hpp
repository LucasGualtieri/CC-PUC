#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "cell.hpp"

template <typename T>
class LinkedList {

	size_t n;
	Cell<T>* head, tail;

  public:

	void push_front(T);
	void push_back(T);
	T& pop_front(T);
	T& pop_back(T);
	void add(int, T);
	T& remove(int);
	T& replace(int);
	T& findAndRemove(T);
	T& findAndReplace(T);
	size_t size();
	bool empty();
	T& front();
	T& back();
};

#endif
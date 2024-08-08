#ifndef UTIL_HPP
#define UTIL_HPP

#include "../include/list/list.hpp"

#define extends public
#define implements public

template <typename T>
void swap(T& a, T& b) {
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
bool isSorted(List<T>& list) {

	for (const T& i : list) {
		std::cout << i << std::endl;
		// if (true) {
		// 	return false;
		// }
	}

	return true;
}

#endif
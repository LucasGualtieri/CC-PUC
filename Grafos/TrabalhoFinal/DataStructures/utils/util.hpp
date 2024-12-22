#ifndef UTIL_HPP
#define UTIL_HPP

#include "../include/list/list.hpp"

#define extends public
#define implements public

// template <typename T>
// void swap(T& a, T& b) {
// 	T aux = a;
// 	a = b;
// 	b = aux;
// }

template <typename T>
bool isSorted(List<T>& list) {

	T previous = list[0];

	for (size_t i = 1; i < list.size(); i++) {

		T current = list[i];
		if (current < previous) return false;
		previous = current;
	}

	return true;
}

#endif
#ifndef UTIL_HPP
#define UTIL_HPP

#include "include/list.hpp"

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
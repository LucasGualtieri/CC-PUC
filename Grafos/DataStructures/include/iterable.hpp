#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include <sstream>

// https://chatgpt.com/share/c077a9b1-4d31-45ea-97e9-670ffdd1576d

template <typename T>
struct Iterable {

	virtual std::string str() const {

		std::ostringstream oss;

		oss << "{ ";

		// for (T i : *this) {
			// oss << i << ", ";
		// }

		oss << "}";

		return oss.str();
	}
};

#endif
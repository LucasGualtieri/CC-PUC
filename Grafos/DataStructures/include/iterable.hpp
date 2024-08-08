#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include <sstream>

template <typename T>
struct Iterable {

	virtual std::string str() const final {

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
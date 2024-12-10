#ifndef PAIR_HPP
#define PAIR_HPP

#include <limits>
#include <ostream>

template<typename T1, typename T2>
class Pair {
public:
	T1 first;
	T2 second;

	Pair() : first(T1()), second(T2()) { }
	Pair(T1 first, T2 second) : first(first), second(second) { }

	T1 getFirst() const { return first; }
	T2 getSecond() const { return second; }

	// const T1& getFirst() { return first; }
	// const T2& getSecond() { return second; }

	bool operator==(const Pair& other) const {
		return (this->first == other.first) && (this->second == other.second);
	}

	bool operator<(const Pair& other) const {
		return (this->first < other.first);
	}

	bool operator>(const Pair& other) const {
		return (this->first > other.first);
	}

	friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {

		os << "(";

		if (pair.first == std::numeric_limits<T1>::max()) {
			os << "∞, ";
		}

		else if (pair.first == std::numeric_limits<T1>::min()) {
			os << "-∞";
		}

		else os << pair.first << ", ";

		if (pair.second == std::numeric_limits<T2>::max()) {
			os << "∞)";
		}

		else if (pair.second == std::numeric_limits<T2>::min()) {
			os << "-∞)";
		}

		else os << pair.second << ")";

		return os;
	}
};

#endif

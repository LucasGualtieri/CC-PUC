#include <ostream>

template<typename T1, typename T2, typename T3>
class Triple {
public:
	T1 first;
	T2 second;
	T3 third;

	Triple() : first(T1()), second(T2()), third(T3()) { }
	Triple(T1 first, T2 second, T3 third) : first(first), second(second), third(third) { }

	T1 getFirst() const { return first; }
	T2 getSecond() const { return second; }
	T3 getThird() const { return third; }

	// const T1& getFirst() { return first; }
	// const T2& getSecond() { return second; }

	bool operator==(const Triple& other) const {
		return (this->first == other.first) && (this->second == other.second) && (this->third == other.third);
	}

	bool operator>(const Triple& other) const {
		return (this->first > other.first);
	}

	bool operator<(const Triple& other) const {
		return (this->first < other.first);
	}

	friend std::ostream& operator<<(std::ostream& os, const Triple& pair) {
		os << "(" << pair.first << ", " << pair.second << ", " << pair.third << ")";
		return os;
	}
};

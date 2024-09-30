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

	friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
		os << "(" << pair.first << ", " << pair.second << ")";
		return os;
	}
};
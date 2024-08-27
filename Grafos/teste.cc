#include <iostream>
#include "DataStructures/include/list/linearList.hpp"

using namespace std;

template <typename T>
class Strategy {
  public:
	virtual LinearList<T> test() = 0;
};


template <typename T>
class TestStrategy : public Strategy<T> {
  public:
	LinearList<T> test() { return LinearList; }
};

class Class {

	Strategy* strategy;

  public:

	Class() {
		strategy = new TestStrategy<int>();
	}

	LinearList test() {
		return strategy->test();
	}
};

int main() {


}
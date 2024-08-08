#ifndef ITERABLE_HPP
#define ITERABLE_HPP

// 7. Template Parameter Handling
// Currently, the class template handles any type T.
// If you want to restrict T to types that support certain operations (like assignment),
// you could use static assertions or concepts (in C++20).

template <typename T>
struct DataStructure {

	LinearStack& operator=(const LinearStack& other) {
		if (this != &other) {
			delete[] array;
			max_size	= other.max_size;
			this->_size = other._size;
			array		= new T[max_size];
			std::copy(other.array, other.array + other._size, array);
		}
		return *this;
	}
};

#endif
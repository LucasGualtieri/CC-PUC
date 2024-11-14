#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>

template <typename T>
class List {
  protected:
	size_t _size;

  public:
	virtual ~List() = default;

	virtual void push_front(T value) = 0;
	virtual void push_back(T value) = 0;
	virtual T pop_front() = 0;
	virtual T pop_back() = 0;
	virtual void add(T value, unsigned int pos) = 0;
	virtual T remove(unsigned int pos) = 0;
	virtual T& front() const = 0;
	virtual T& back() const = 0;
	virtual void sort() = 0;

	virtual bool contains(const T& value) const = 0;
	virtual void clear() final { while (!empty()) pop_front(); }
	virtual size_t size() const final { return _size; }
	virtual bool empty() const final { return _size == 0; }

	// virtual bool is_sorted_ascending() const = 0;
	// virtual bool is_sorted_descending() const = 0;
};

#endif

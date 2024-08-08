#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List {
  protected:
	size_t _size;

  public:
	virtual ~List() = default;

	virtual void push_front(const T& value) = 0;
	virtual void push_back(const T& value) = 0;
	virtual T pop_front() = 0;
	virtual T pop_back() = 0;
	virtual void add(const T& value, unsigned int pos) = 0;
	virtual T remove(unsigned int pos) = 0;
	virtual T& front() const = 0;
	virtual T& back() const = 0;
	virtual void sort() = 0;

	virtual void erase() final { while (!empty()) pop_front(); }
	virtual size_t size() const final { return _size; }
	virtual bool empty() const final { return _size == 0; }

	// virtual bool is_sorted_ascending() const = 0;
	// virtual bool is_sorted_descending() const = 0;
};

#endif
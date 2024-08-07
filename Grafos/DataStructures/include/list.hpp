#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List {
  public:
	virtual ~List() = default;

	virtual void push_front(const T& value) = 0;
	virtual void push_back(const T& value) = 0;
	virtual T pop_front() = 0;
	virtual T pop_back() = 0;
	virtual void add(const T& value, unsigned int pos) = 0;
	virtual T remove(unsigned int pos) = 0;
	virtual void erase() = 0;
	virtual size_t size() const = 0;
	virtual bool empty() const = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;

	// virtual void sort() = 0;

	// class Iterator {
	//   public:
	// 	virtual ~Iterator() = default;
	// 	virtual T& operator*() const = 0;
	// 	virtual T* operator->() const = 0;
	// 	virtual Iterator& operator++() = 0;
	// 	virtual Iterator operator++(int) = 0;
	// 	virtual bool operator==(const Iterator& other) const = 0;
	// 	virtual bool operator!=(const Iterator& other) const = 0;
	// };

	// virtual typename List<T>::Iterator begin() const = 0;
	// virtual typename List<T>::Iterator end() const = 0;

	// virtual bool is_sorted_ascending() const = 0;
	// virtual bool is_sorted_descending() const = 0;
};

#endif
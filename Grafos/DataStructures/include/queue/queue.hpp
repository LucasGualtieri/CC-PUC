#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {

  protected:

	size_t _size;

  public:

	virtual ~Queue() = default;

	virtual void push(const T& value) = 0;
	virtual T pop() = 0;
	virtual T& peek() const = 0;

	virtual bool contains(const T& value) const = 0;
	virtual void clear() { while (!empty()) pop(); }
	virtual size_t size() const final { return _size; }
	virtual bool empty() const final { return _size == 0; }
	virtual std::string str() const = 0;
};

#endif
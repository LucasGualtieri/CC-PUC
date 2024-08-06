#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T>
class LinkedList {

	struct Cell {

		T value;
		Cell *next;

		Cell() : value(T()) {}
		Cell(T value) : value(value), next(nullptr) {}
		Cell(T value, Cell *next) : value(value), next(next) {}
	};

	size_t _size;
	Cell *head, *tail;

  public:

	LinkedList() {
		head = tail = new Cell;
		_size = 0;
	}

	~LinkedList() {

		while(!empty()) pop_back();

		delete head;
	}

	void push_front(T value) {

		head->next = new Cell(value, head->next);

		if (empty()) tail = head->next;
		_size++;
	}

	void push_back(T value) {

		tail = tail->next = new Cell(value);
		_size++;
	}

	T& pop_front() {

		if (empty()) throw std::runtime_error("List is empty.");

		T& deleted = head->next->value;

		Cell* temp = head;
		head = head->next;

		delete temp;

		_size--;

		return deleted;
	}

	// TODO GPT que fez quero refazer.
	T& pop_back() {

		if (empty()) throw std::runtime_error("List is empty.");

		if (head->next == tail) {

			T& value = tail->value;
			Cell* aux = head;
			head = head->next;
			delete aux;
			_size--;
			return value;
		}

		Cell *prev = head;
		while (prev->next != tail) prev = prev->next;

		T& value = tail->value;
		delete tail;
		tail = prev;
		tail->next = nullptr;

		_size--;

		return value;
	}

	void add(T value, int pos = 0) {

		if (pos < 0 || pos > _size) {
			throw std::runtime_error("Invalid position.");
		}

		Cell* cell = head->next;

		for (int i = 0; i < pos - 1; i++, cell = cell->next);

		cell->next = new Cell(value, cell->next);

		_size++;
	}

	// TODO GPT que fez quero refazer.
	T& erase(int pos) {
		if (empty()) {
			throw std::runtime_error("List is empty.");
		}

		if (pos < 0 || static_cast<size_t>(pos) >= _size) {
			throw std::runtime_error("Invalid position.");
		}

		if (pos == 0) return pop_front();

		if (static_cast<size_t>(pos) == _size - 1) return pop_back();

		// Traverse to the node just before the one to be deleted
		Cell *prev = head;
		for (int i = 0; i < pos; ++i) { prev = prev->next; }

		// Node to be deleted
		Cell *temp = prev->next;
		T& value = temp->value;
		prev->next = temp->next;

		// Update tail if the last node is deleted
		if (temp == tail) { tail = prev; }

		delete temp;
		_size--;

		return value;
	}

	size_t size() { return _size; }

	bool empty() { return _size == 0; }

	T& front() {

		if (empty()) throw std::runtime_error("List is empty.");

		return head->next->value;
	}

	T& back() {

		if (empty()) throw std::runtime_error("List is empty.");

		return tail->value;
	}

	// overload no operador <<

	// iterator
};

#endif
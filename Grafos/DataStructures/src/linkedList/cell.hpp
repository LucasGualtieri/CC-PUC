#ifndef LINKED_LIST_CELL_HPP
#define LINKED_LIST_CELL_HPP

template <typename T>
struct Cell {

	T value;
	Cell* next;

	Cell() : value(T()) {}
	Cell(T value) : value(value), next(nullptr) {}
	Cell(T value, Cell* next) : value(value), next(next) {}
};

#endif
#ifndef CELL_HPP
#define CELL_HPP

template <typename T>
struct Cell {

	T value;
	Cell *next;

	Cell() : value(T()) {}
	Cell(T value, Cell* next = nullptr) : value(value), next(next) {}

	bool operator==(const Cell*& other) const { return value == other->value; }
	bool operator!=(const Cell*& other) const { return value != other->value; }
	bool operator<(const Cell*& other) const { return value < other->value; }
	bool operator<=(const Cell*& other) const { return value <= other->value; }
	bool operator>(const Cell*& other) const { return value > other->value; }
	bool operator>=(const Cell*& other) const { return value >= other->value; }
};

#endif
#ifndef classPonto_H
#define classPonto_H

#include <math.h>

class Ponto {
	int x, y;

public:
	Ponto(int xArg, int yArg) {
		x = xArg;
		y = yArg;
	}

	void SetX(int arg) {
		x = arg;
	}
	void SetY(int arg) {
		y = arg;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}

	bool Equals(Ponto newPoint) {
		if (x == newPoint.GetX() && y == newPoint.GetY()) {
			return true;
		}
		return false;
	}

	float Distancia(Ponto newPoint) {
		return sqrt(pow(x - newPoint.GetX(), 2) + pow(y - newPoint.GetY(), 2));
	}
	float Distancia() {
		return x > y ? x - y : y - x;
	}
};

#endif /*classPonto_H*/
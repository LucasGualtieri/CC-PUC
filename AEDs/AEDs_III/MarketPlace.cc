#include <iostream>

// clear && g++ MarketPlace.cc && ./a.out

using namespace std;

#define extends public

class Product {
  private:
	static int lastId;
	int id;
  protected:
	double price;
	string name;
  public:
	Product() {
		this->id = Product::lastId++;
	}
};

int Product::lastId = 0;

class RubiksCube {
  public:
	int teste;
};

class ThreeByThree : extends Product, extends RubiksCube {
  public:
	int getId() { return this->id; }
};

int main() {
	ThreeByThree p0, p1, p2, p3, p4, p5, p6;
	p6.teste = 55;
	printf("p6.id: %d - p6.teste: %d\n", p6.getId(), p6.teste);
}
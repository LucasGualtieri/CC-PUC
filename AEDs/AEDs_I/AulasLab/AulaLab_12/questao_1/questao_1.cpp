#include "/home/lucas/CC-PUC/Bibliotecas/biblioteca_cpp.h"
#include "classPonto.h"

int main() {
	Ponto p1(2, 2), p2(3, 3);

	// cout << p1.GetX() << endl;
	cout << p1.Distancia(p2) << endl;
	cout << p1.Distancia() << endl;
	cout << ((p1.Equals(p2) == 1) ? "True" : "False") << endl;
}
#include <biblioteca_cpp.h>

typedef int lint; // Normal int -> 4 bytes
#define int short // short or short int -> 2 bytes
typedef long long llint; // long int or long long -> 8 bytes

class Elevador {
	int andarAtual; // 0 = Térreo
	int totalAndaresPredio; // Total excluindo o térreo, ou seja total - 1
	int capacidadeKgElevador;
	int pessoasPresentes;
};

lint main() {
	SetConsoleOutputCP(65001);

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}
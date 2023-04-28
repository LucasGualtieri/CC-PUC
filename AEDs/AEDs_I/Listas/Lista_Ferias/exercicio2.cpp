#include <biblioteca_cpp.h>

void isPositive(int number) {
	if (number <= 0) throw "";
}

int main() {

	int number;

	while (true) {
		try {
			number = readint("Digite um número positivo: ");
			isPositive(number);
			break;
		} catch (...) { };
	}

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}
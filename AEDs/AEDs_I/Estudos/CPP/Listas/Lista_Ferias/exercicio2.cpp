#include <biblioteca_cpp.h>

void isPositive(int number) {
	if (number <= 0) throw "";
}

int main() {
	SetConsoleOutputCP(65001);

	int number;

	while (1) {
		try {
			number = readint("Digite um número positivo: ");
			isPositive(number);
			break;
		} catch (...) { };
	}

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}
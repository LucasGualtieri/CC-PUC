#include <biblioteca_c.h>

// N = 1 limite inferior
// M = 5 limite superior
// 1 + 2 + 3 + 4 + 5 == 15
//   3 + 3 + 4 + 5 == 15
//     6 + 4 + 5 == 15
//       10 + 5 == 15
//         15

int somaRecursiva(int n, int m) {
	if (n != m) {
		return n + somaRecursiva(n + 1, m);
	} else {
		return n;
	}
}

int somaIterativa(int n, int m) {
	int soma = m;

	for (int i = n; i != m; i++) {
		soma += i;
	}

	return soma;
}

int main() {

	printf("Soma: %d\n", somaRecursiva(1, 5));
	printf("Soma: %d\n", somaIterativa(1, 5));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
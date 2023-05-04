#include <biblioteca_c.h>

int par(int n) {
	int par = 0;

	for (int i = 0; i < n; i++) {
		par += 2; // par = par + 2;
	}

	return par;
}

void mostrarParesEmOrdemDecrescente(int n) {

	for (int i = n - 1; i > 0; i--) {
		printf("%d ", par(i));
	}
}

int main() {

	mostrarParesEmOrdemDecrescente(5);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
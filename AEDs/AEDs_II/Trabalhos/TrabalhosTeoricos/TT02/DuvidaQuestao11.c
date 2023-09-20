#include <biblioteca_c.h>

int main() {

	for (int n = 50; n > 0; n--) {
		int cont = 0;
		for (int i = 1; i <= n; i *= 2) {
			cont++;
		}
		printf("N: %d Cont: %d\n", n, cont);
		printf("Formula: %d\n", (int)ceil(log2(n)) + 1);
		printf("---------------\n");
	}

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}
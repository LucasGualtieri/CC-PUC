#include <biblioteca_c.h>

void fn() {
	for (int i = 1; i < 25; i++) {
		if (i == 23) return;
		printf("%d é %s\n", i, i % 2 == 0 ? "par" : "ímpar");
	}
	printf("Olá mundo!\n");
}

int main() {
	fn();
	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
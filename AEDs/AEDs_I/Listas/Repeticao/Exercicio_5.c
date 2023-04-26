#include <stdio.h>

int main(void) {
	for (int i = 1; i <= 100; i++) {
		if (i % 5 == 0) {
			printf("%d é múltiplo de 5\n", i);
		}
	}
	printf("...\n");
	return 0;
}
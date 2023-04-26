#include <stdio.h>

int main(void) {
	for (int loop = 1; loop <= 25; loop++) {
		if (loop % 2 == 0) {
			printf("O número %d é par\n", loop);
		} else {
			printf("O número %d é impar\n", loop);
		}
	}
	return 0;
}
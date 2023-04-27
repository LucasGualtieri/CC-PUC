#include <stdbool.h>
#include <stdio.h>

bool testCaps(char letra, int isCaps) {
	if (letra >= 'A' && letra <= 'Z') {
		// printf("Letra maiúscula: %c\n", letra);
		isCaps = true;
	} else if ((letra >= 'a' && letra <= 'z')) {
		// printf("Letra minúscula: %c\n", letra);
		isCaps = false;
	} else {
		printf("\nDigite uma letra do Alfabeto: ");
		scanf(" %c", &letra);
		testCaps(letra, isCaps);
	}
	return isCaps;
}

int main(void) {
	bool isCaps;
	char letra;

	printf("Digite uma letra do Alfabeto: ");
	scanf("%c", &letra);

	printf("\n");

	isCaps = testCaps(letra, isCaps);

	if (isCaps) {
		for (int loop = letra; loop <= 'Z'; loop++) {
			printf("%c ", loop);
		}
	} else {
		for (int loop = letra; loop >= 'a'; loop--) {
			printf("%c ", loop);
		}
	}

	return 0;
}
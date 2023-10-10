#include <stdio.h>
#include <string.h>

// clear && gcc questao7.c && ./a.out

int main() {

	char string[80];
	scanf("%s", string);

	while (strcmp(string, "PARAR") != 0) { // -> -1, 0, 1
		int len = strlen(string);
		for (int i = 0; i < len; i++) {
			if (string[i] == '-') {
			printf("É composta\n");
				i = len;
			} else if (i == len - 1) {
				printf("Não é composta\n");
			}
		}
		scanf("%s", string);
	}
}
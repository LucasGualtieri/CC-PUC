#include <stdio.h>
#include <string.h>

// clear && gcc teste.c && ./a.out

int main() {
	int idade1 = 22, idade2 = 21;
	void *ptr1 = &idade1, *ptr2 = &idade2;

	int resultado = strcmp(ptr1, ptr2);

	printf("resultado: %d\n", resultado);
}
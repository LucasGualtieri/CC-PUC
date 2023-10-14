#include <stdio.h>
#include <string.h>

// clear && gcc PonteiroVoid.c && ./a.out

#define vint(var) *((int*)var) // Void to int
#define vstr(var) (char*)var // Void to char

int main() {
	void* x;
	int altura = 180;
	char* string = "Lucas";

	// x = (void*)&altura;
	x = string;

	printf("x: %s\n", vstr(x));
	// printf("x: %d\n", vint(x));
	// printf("x: %d\n", *((int*)x));
	// printf("x: %s\n", (char*)x);

	// if (vint(x) > 1) {
	// 	printf("x > 1\n");	
	// }

	if (!strcmp(x, "Lucas")) {
		printf("x = Lucas\n");
	}

	return 0;
}
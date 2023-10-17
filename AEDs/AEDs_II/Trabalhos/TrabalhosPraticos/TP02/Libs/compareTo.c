#include <stdio.h>
#include <string.h>
#include <stdint.h>

// clear && gcc compareTo.c && ./a.out

int isPotOfTwo(/*...*/) {
	// ...
}

uint32_t murmurhash(const void *key, int len, uint32_t seed) {
	const uint32_t m = 0x5bd1e995;
	const int r = 24;
	uint32_t h = seed ^ len;

	const uint8_t *data = (const uint8_t *)key;

	while (len >= 4) {
		uint32_t k;

		memcpy(&k, data, 4);

		k *= m;
		k ^= k >> r;
		k *= m;

		h *= m;
		h ^= k;

		data += 4;
		len -= 4;
	}

	switch (len) {
		case 3:
			h ^= data[2] << 16;
		case 2:
			h ^= data[1] << 8;
		case 1:
			h ^= data[0];
			h *= m;
	}

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}

int compare(char* var1, char* var2) {
	int len1 = (int)strlen(var1);
	int len2 = (int)strlen(var2);

	int menorLen = len1 < len2 ? len1 : len2;

	int resultado = -1;

	printf("var1: %d, len1: %d\n", *((int*)var1), len1);
	printf("var2: %d, len2: %d\n", *((int*)var2), len2);

	uint32_t valor1 = murmurhash(var1, strlen(var1), 0);
	uint32_t valor2 = murmurhash(var2, strlen(var2), 0);

	// int valor1 = converte(var1);
	// int valor2 = converte(var2);

	if (valor1 < valor2) return -1;
	else if (valor1 > valor2) return 1;
	else return 0;

	for (int i = 0; i < menorLen; i++) {

		printf("var1[%d]: %d -> ", i, var1[i]);
		printf("var2[%d]: %d\n", i, var2[i]);

		if (var1[i] < var2[i]) {
			i = menorLen;
		} else if (var1[i] > var2[i]) {
			resultado = 1;
			i = menorLen;
		} else if (i == menorLen - 1) {
			if (var1[i] < var2[i]) {
				resultado = -1;
			} else if (var1[i] < var2[i]) {
				resultado = 1;
			} else {
				resultado = 0;
			}
		}
	}

	return resultado;

}

int main() {

	// 8 bits = 00000000
	// int var1 = 0b00000100000001000000010000000100;
	// int var1 = 0b0000000100000001;
	// int var2 = 0b0000000000000010;

	// long int longVar1 = var1;
	// long int longVar2 = var2;

	// void* ptr1 = &longVar1;
	// void* ptr2 = &longVar2;

	// char* string1 = ptr1;
	// char* string2 = ptr2;

	// /* if (!isPotOfTwo(longVar1) ) */ longVar1++;
	// int len1 = (int)strlen(string1);
	// /* if (!isPotOfTwo(longVar1) ) */ longVar1--;

	// printf("strlen(string1): %d\n", len1);

	char* string1 = "AAAA";
	char* string2 = "AAA";

	int result = compare(string1, string2);
	printf("result: %d\n", result);

	// for (int i = 0; i < 200; i++) {
	// 	long int var = i;
	// 	void* teste = &var;
	// 	result = compare(string1, teste);
	// 	printf("i: %d - result: %d\n", i, result);
	// 	break;
	// }

	// for (int i = len1 - 1; i >= 0; i--) {
	// 	printf("%d", string1[i]);
	// }

	// for (int i = 0; i < len; i++) {
	// 	printf("%d", string[i]);
	// }

	printf("\n");

	return 0;
}
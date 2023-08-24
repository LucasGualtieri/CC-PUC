#include <stdio.h>
#include <stdbool.h>

#define arraysize(array) (int)(sizeof(array) / sizeof(array[0]));

bool binAux(int x, int* array, int esq, int dir) {
	bool hasFound = false;
	int meio = (esq + dir) / 2;
	int elementoBusca = array[meio];

	if (elementoBusca == x) esq = dir + 1;
	else if (elementoBusca < x) esq = meio + 1;
	else dir = meio - 1;

	return esq < dir && !hasFound ? binAux(x, array, esq, dir) : hasFound;
}

bool bin(int x, int* array, int tam) {
	return binAux(x, array, 0, tam - 1);
}

int main() {
	
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int tam = arraysize(array);

	for (int i = -50; i <= tam + 40; i++) {
		printf("%d%s pertence ao array.\n", i, bin(i, array, tam) ? "" : " não");
	}

}
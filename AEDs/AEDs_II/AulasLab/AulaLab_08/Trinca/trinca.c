#include <biblioteca_c.h>

// clear && gcc trinca.c -lm -I /home/lucas/CC-PUC/Bibliotecas -o trinca.exe && ./trinca.exe < pub.in > out.txt

void arrayRead(int* array, int arrayLength) {
	for (int j = 0; j < arrayLength; j++) {
		scanf("%d", &array[j]);
	}
}

void selectionSort(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < arrayLength; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		int swap = array[menor];
		array[menor] = array[i];
		array[i] = swap;
	}
}

int mostOcurrences(int* array, int arrayLength) {
	if (arrayLength < 3) return -1;
	int maior = INT_MIN;
	bool flag = false;

	for (int i = 0; i < arrayLength - 2; i++) {
		if (array[i] == array[i + 1] && array[i] == array[i + 2]) {
			if (array[i] > maior) {
				flag = true;
				maior = array[i];
			}
		}
	}
	return flag ? maior : -1;
}

void arrayPrint(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
}

int main() {

	int numeroDeTestes;
	scanf("%d", &numeroDeTestes);

	for (int i = 0; i < numeroDeTestes; i++) {
		int arrayLength;
		scanf("%d", &arrayLength);

		int* array = (int*)malloc(arrayLength * sizeof(int));

		arrayRead(array, arrayLength);

		selectionSort(array, arrayLength);

		// arrayPrint(array, arrayLength);

		printf("%d\n", mostOcurrences(array, arrayLength));

		free(array);
	}

	// puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
#include <stdio.h>

void selectionSort(int* array, int n) {

	int mov = 0;
	for (int i = 0; i < (n - 1); i++) {
		int menor = i;
		for (int j = (i + 1); j < n; j++) {
			if (array[menor] > array[j]) {
				menor = j;
			}
		}
		int temp	 = array[i];
		array[i]	 = array[menor];
		array[menor] = temp;
		mov += 3;
	}

	printf("Teoria: %d\n", (3 * n - 3));
	printf("Prática: %d\n", mov);
}

int main() {

	int array[] = {8, 7, 6, 5, 4, 3, 2, 1};
	selectionSort(array, sizeof(array) / sizeof(array[0]));

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}
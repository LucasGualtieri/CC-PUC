#include <stdio.h>

// clear && gcc provaTeorica.c && ./a.out 

void ArrayPrint(int N, int* array) {
	printf("{ ");
	for (int i = 0; i < N; i++) {
		printf("%d, ", array[i]);
	}
	printf("\b\b } \n");
}

int main() {

	int array[] = { 6, -4, 3, 4, -1, -2, 9, 10 };
	int N = sizeof(array) / sizeof(array[0]);

	ArrayPrint(N, array);

	for (int i = 0; i < N - 1; i++) {
		int tmp = array[i + 1];
		int j = i;
		while (j >= 0 && tmp >= 0 && (array[j] > tmp || array[j] < 0)) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}

	ArrayPrint(N, array);

	return 0;
}
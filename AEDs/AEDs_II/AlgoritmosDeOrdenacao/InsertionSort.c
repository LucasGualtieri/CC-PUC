#include <array.h>
#include <biblioteca_c.h>
#include <unistd.h>

// void InsertionSort(int* array, int ultimo) {
// 	for (int i = ultimo; i > 0; i--) {
// 		int maior = i;
// 		for (int j = i - 1; j > 0; j--) {
// 			if (array[maior] < array[j]) maior = j;
// 		}
// 		int swap = array[maior];
// 		array[maior] = array[i];
// 		array[i] = swap;
// 	}
// }
void InsertionSort(int* array, int size) {
	bool sorted = false;
	for (int i = 0; !sorted && i < size; i++) {
		for (int j = 0; j < size; j++) {
			if () {
				// break;
				sorted = true;
			}
		}
	}
}

int main() {

	Array* array = NewArray(10);
	ArrayFillRand(array, -2, 2);
	ArrayPrint(array);

	// InsertionSort(array->pointer, array->size - 1);
	InsertionSort(array->pointer, array->size);

	ArrayPrint(array);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
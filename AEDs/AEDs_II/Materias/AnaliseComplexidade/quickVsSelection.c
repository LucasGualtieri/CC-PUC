#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define arraysize(array) (int)(sizeof(array) / sizeof(array[0]));

bool binAux(int x, int* array, int esq, long int dir) {
	int meio = (esq + dir) / 2;
	int elementoBusca = array[meio];

	if (elementoBusca == x) return true;
	else if (elementoBusca < x) esq = meio + 1;
	else dir = meio - 1;

	return esq <= dir ? binAux(x, array, esq, dir) : false;
}

bool bin(int x, int* array, long int tam) {
	return binAux(x, array, 0, tam - 1);
}

void swap(int* value1, int* value2) {
	int aux = *value1;
	*value1 = *value2;
	*value2 = aux;
}

void quicksortRec(int* array, int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(dir+esq)/2];
    while (i <= j) {
        while (array[i] < pivo) i++;
        while (array[j] > pivo) j--;
        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}

void quicksort(int* array, int n) {
    quicksortRec(array, 0, n-1);
}

void selectionsort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < n; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		// swap(array + i, array + menor);
	}
}

struct Timer {
	clock_t startTime;
	clock_t elapsedTime;
	double totalTime;
} timer;

void startTimer() {
	timer.startTime = clock();
}

void stopTimer() {
	timer.elapsedTime = clock();
	timer.totalTime = ((double) (timer.elapsedTime - timer.startTime)) / CLOCKS_PER_SEC;
	// double teste = difftime(timer.elapsedTime, timer.startTime);
	// printf("Teste = %lf\n", teste);
}

int main() {

	// long int tam = 100000; // 100k
	// long int tam = 1000000; // 1M
	// long int tam = 10000000; // 10M
	// long int tam = 100000000; // 100 M
	long int tam = 1000000000; // 1 Bi
	// long int tam = 2000000000; // 2 Bi
	// long int tam = 3000000000; // 3 Bi
	int* array = (int*)malloc(tam * sizeof(int));

	double memGb = (tam * sizeof(int)) / (float)(1000 * 1000 * 1000);
	if (!array) {
		printf("Falha ao allocar %g GB de memória\n", memGb);
		printf("Saindo do programa.\n");
		exit(0);
	} else {
		printf("Allocando %g GB de memória\n", memGb);
	}

	startTimer();

	printf("Preenchendo o array\n");

	for (int i = 0; i < tam; i++) {
		array[i] = i + 1;
	}

	stopTimer();
	printf("Tempo decorrido para preencher o vetor: %.3lfs\n", timer.totalTime);

	// startTimer();
	// printf("Ordenando o array\n");
	// quicksort(array, tam);
	// // selectionsort(array, tam);

	// stopTimer();
	// printf("Tempo decorrido para ordenar o vetor: %.3lfs\n", timer.totalTime);

	printf("%d%s pertence ao array.\n", 23244, bin(23244, array, tam) ? "" : " não");

	startTimer();
	for (int i = 0; i <= tam / 10; i++) {
		// printf("%d%s pertence ao array.\n", i, bin(i, array, tam) ? "" : " não");
		bin(i, array, tam);
	}
	stopTimer();
	printf("Tempo decorrido para encontrar %d elementos no vetor: %.3lfs\n", (int)(tam / 10), timer.totalTime);



	printf("FIM DO PROGRAMA\n");
	free(array);
}

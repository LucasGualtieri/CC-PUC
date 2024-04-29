#include "Lib.h"

// clear && gcc Radix.c && ./a.out

char toUpper(char c) {
	return 'a' <= c && c <= 'z' ? c - 32 : c;
}

void CountingSort(int place, Log* log, Lista* lista) {

	int N = lista->size;
	String* array = lista->array;

	// Aloca espaço para todos os possíveis valores de um Byte.
	int* countArray = calloc(256, sizeof(int));

	for (int i = 0; i < N; i++) countArray[array[i][place]]++;

	for (int i = 1; i < 256; i++) countArray[i] += countArray[i - 1];

	String* auxArray = malloc(N * sizeof(String));

	for (int i = N - 1; i >= 0; i--) {
		char valor = array[i][place];
		auxArray[--countArray[valor]] = array[i];
	}

	String* aux = array; // Salva o array original para que possa ser liberado
	lista->array = auxArray; // Efetivamente faz o "swap"

	free(aux);
	free(countArray);
}

void RadixSort(Log* log, Lista* lista) {

	int max = 36; // Length da maior string

	for (int i = max - 1; i >= 0; i--) {
		CountingSort(i, log, lista);
	}
}

int main() {

	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(0);
	BD.ImportDataBase("ids.csv", &BD);

	// BD.Mostrar(BD);

	// printf("-----------------------------------------\n");
	timer.Start(&timer);
	RadixSort(&log, &BD);
	timer.Stop(&timer);

	BD.Mostrar(BD);

	bool result = BD.isSorted(BD);
	printf("Ordenação funcionou? %s\n", result ? "SIM" : "NÃO");

	log.RegistroOrdenacao(timer, log);

	BD.Close(&BD);
}
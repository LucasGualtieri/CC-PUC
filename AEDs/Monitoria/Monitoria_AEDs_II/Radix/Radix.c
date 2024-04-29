#include "Lib.h"

// clear && gcc Radix.c && ./a.out

char toUpper(char c) {
	return 'a' <= c && c <= 'z' ? c - 32 : c;
}

void CountingSort(int place, Log* log, Lista* lista) {

	char firstChar = '-';
	char lastChar = 'F';
	int ASCInterval = (lastChar - firstChar) + 1;

	int N = lista->size;
	String* array = lista->array;

	int* countArray = calloc(ASCInterval, sizeof(int));

	for (int i = 0; i < N; i++) {
		char c = toUpper(array[i][place]);
		countArray[c - firstChar]++;
	}

	for (int i = 1; i < ASCInterval; i++) countArray[i] += countArray[i - 1];

	String* auxArray = malloc(N * sizeof(String));

	for (int i = N - 1; i >= 0; i--) {
		log->movimentacoes++;
		char valor = toUpper(array[i][place]) - firstChar;
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

	timer.Start(&timer);
	RadixSort(&log, &BD);
	timer.Stop(&timer);

	BD.Mostrar(BD);

	bool result = BD.isSorted(BD);
	printf("\nOrdenação funcionou? %s\n", result ? "SIM" : "NÃO");

	log.RegistroOrdenacao(timer, log);

	BD.Close(&BD);
}
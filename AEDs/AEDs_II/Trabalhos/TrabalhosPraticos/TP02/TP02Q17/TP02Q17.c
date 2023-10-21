#include "../Libs/LibTP02.h"

// clear && gcc TP02Q17.c && ./a.out < pub.in > result.txt

void buildHeap(int root, int N, Log* log, Lista lista) {

	Jogador* array = lista.array;

	int largest = root, l = 2 * root + 1, r = 2 * root + 2;

	if (l < N && lista.CompareToInt(array[l], array[largest], log)) largest = l;
	if (r < N && lista.CompareToInt(array[r], array[largest], log)) largest = r;

	if (largest != root) {
		swap(&array[root], &array[largest], log);
		buildHeap(largest, N, log, lista);
	}
}

void HeapSortParcial(int k, Log* log, Lista lista) {

	int N = lista.size;
	Jogador* array = lista.array;

	for (int i = k; i < N; i++) {
		if (lista.CompareToInt(array[0], array[i], log)) {
			swap(&array[0], &array[i], log);
			buildHeap(0, k, log, lista);
		}
	}

	for (int i = k - 1; i > 0; i--) {
		swap(&array[0], &array[i], log);
		buildHeap(0, i, log, lista);
	}
}


int main() {

	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("/tmp/players.csv", &BD);

	Lista lista = newLista(465); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.Inserir(BD.Get(id, BD), &lista);
		lista.setAtributo(&BD.array[id].altura, lista);
	}

	int k = 10;

	timer.Start(&timer);
	HeapSortParcial(k, &log, lista);
	timer.Stop(&timer);

	lista.MostrarParcial(k, lista);

	log.RegistroOrdenacao("794989_heapsortParcial.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}

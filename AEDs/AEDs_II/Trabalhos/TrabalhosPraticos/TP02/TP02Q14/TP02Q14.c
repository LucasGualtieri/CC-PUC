#include "../Libs/LibTP02.h"

// clear && gcc TP02Q14.c && ./a.out < pub.in > result.txt

int GetMax(int place, Lista* lista) {
	int max = 0;
	for (int i = 1; i < lista->size; i++) {
		int valor = vint(lista->array[i].atributo) / place % 10;
		if (valor > max) max = valor;
	}
	return max;
}

void CountingSort(int place, Log* log, Lista* lista) {

	int N = lista->size;
	Jogador* array = lista->array;

	int maxValue = GetMax(place, lista);

	int* countArray = calloc((maxValue + 1),  sizeof(int));

	for (int i = 0; i < N; i++) {
		countArray[(vint(array[i].atributo) / place) % 10]++;
	}
	
	for (int i = 1; i <= maxValue; i++) countArray[i] += countArray[i - 1];

	Jogador* auxArray = malloc(N * sizeof(Jogador));

	for (int i = N - 1; i >= 0; i--) {
		log->movimentacoes++;
		int valor = (vint(array[i].atributo) / place) % 10;
		auxArray[--countArray[valor]] = array[i];
	}

	Jogador* aux = array;
	lista->array = auxArray;

	free(aux);
	free(countArray);

}

void RadixSort(Log* log, Lista* lista) {

	int N = lista->size;
	Jogador* array = lista->array;

	int max = vint(lista->array[0].atributo);
	for (int i = 1; i < lista->size; i++) {
		int valor = vint(lista->array[i].atributo);
		if (valor > max) max = valor;
	}

	for (int i = 1; max / i > 0; i *= 10) {
		CountingSort(i, log, lista);
	}

}

int main() {

	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista lista = newLista(465); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(stdin, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.Inserir(BD.Get(id, BD), &lista);
		lista.setAtributo(&BD.array[id].id, lista);
	}

	timer.Start(&timer);
	RadixSort(&log, &lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_radixsort.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}
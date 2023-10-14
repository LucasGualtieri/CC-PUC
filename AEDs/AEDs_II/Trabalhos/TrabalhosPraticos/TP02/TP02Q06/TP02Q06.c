#include "../Libs/LibTP02.h"

// clear && gcc TP02Q06.c && ./a.out < pub.in > result.txt

void SelectionSortRecursivo(int i, int j, int menor, Log* log, Lista lista) {

	Jogador* array = lista.array;

	if (j < lista.size) {
		if (lista.CompareToStr(array[menor], array[j], log) > 0) menor = j;
		SelectionSortRecursivo(i, j + 1, menor, log, lista);
	} else {
		swap(&array[i], &array[menor], log);
	}

	if (++i < lista.size - 1 && j == i) {
		SelectionSortRecursivo(i, i + 1, i, log, lista);
	}

}

void SelectionSort(Log* log, Lista array) {
	SelectionSortRecursivo(0, 1, 0, log, array);
}

int main() {
	
	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista lista = newLista(465); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.Inserir(BD.Get(id, BD), &lista);
		lista.setAtributo(BD.array[id].nome, lista); // Setta o atributo usado na ordenação
	}

	timer.Start(&timer);
	SelectionSort(&log, lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_selecaoRecursiva.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}
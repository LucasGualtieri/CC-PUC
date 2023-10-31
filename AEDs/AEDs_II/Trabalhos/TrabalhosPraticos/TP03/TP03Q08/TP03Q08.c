#include "../Libs/LibTP03.h"

// clear && gcc TP03Q08.c && ./a.out < pub.in > result.txt

void QuickSortRec(Celula* left, Celula* right, Log* log, ListaDupla lista) {

	Celula *pivot = left, i* = left->prox, *j = right;

	while (j->prox != i) { // i <= j
		while (!lista.CompareTo(i, pivot, log) && i != j->prox) i = i->prox;
		while (lista.CompareTo(j, pivot, log) && j != i->ant) j = j->ant;
		if (j->prox != i) { // i <= j
			swap(&i->jogador, &j->jogador, log);
			i = i->prox, j = j->ant;
		}
	}

	if (left != j && j != left->ant)  QuickSortRec(left, j, log, lista); // left < j
	if (i != right && right != i->ant)  QuickSortRec(i, right, log, lista); // i < right
}

void QuickSort(Log* log, ListaDupla lista) {
	QuickSortRec(lista.primeiro, lista.ultimo, log, lista);
}

int main() {
	
	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	ListaDupla lista = newListaDupla(); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.Inserir(BD.Get(id, BD), &lista);
	}

	timer.Start(&timer);
	QuickSort(&log, lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_quicksort2.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}

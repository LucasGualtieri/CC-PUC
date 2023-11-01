#include "../Libs/LibsC/LibTP03.h"
#include "../Libs/LibsC/ListaDupla.h"

// clear && gcc TP03Q08.c && ./a.out < pub.in > result.txt

void QuickSortRec(Celula* left, Celula* right, Log* log, ListaDupla lista) {

	Celula *pivot = left, *i = left->prox, *j = right;

	while (j->prox != i) { // i <= j
		while (lista.CompareTo(i, pivot, log) < 0) i = i->prox;
		while (lista.CompareTo(j, pivot, log) > 0) j = j->ant;
		if (j->prox != i) {
 			swap(&i->jogador, &j->jogador, log);
			i = i->prox, j = j->ant;
		}
	}

	swap(&pivot->jogador, &j->jogador, log);

	// left < j e i < right
	if (left != j && j != left->ant) QuickSortRec(left, j, log, lista);
	if (i != right && right->prox != i) QuickSortRec(i, right, log, lista);
}

void QuickSort(Log* log, ListaDupla lista) {
	QuickSortRec(lista.primeiro, lista.ultimo, log, lista);
}

int main() {
	
	Timer timer = newTimer();
	Log log = newLog();

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	ListaDupla lista = newListaDupla();

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.InserirFim(BD.Get(id, BD), &lista);
	}

	timer.Start(&timer);
	QuickSort(&log, lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_quicksort2.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}

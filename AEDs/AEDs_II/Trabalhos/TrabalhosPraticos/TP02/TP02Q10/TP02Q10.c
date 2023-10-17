#include "../Libs/LibTP02.h"

// clear && gcc TP02Q10.c && ./a.out < pub.in > result.txt

void QuickSortRec(int left, int right, Log* log, Lista lista) {

	int i = left, j = right;
	Jogador* array = lista.array;
	Jogador pivot = array[(right + left) / 2];
	// Jogador pivot = array[left];

	while (i <= j) {
		while (lista.CompareToStr(array[i], pivot, log) < 0) i++;
		while (lista.CompareToStr(array[j], pivot, log) > 0) j--;
		if (i <= j) swap(&array[i++], &array[j--], log);
	}

	if (left < j)  QuickSortRec(left, j, log, lista);
	if (i < right)  QuickSortRec(i, right, log, lista);
}

void QuickSort(Log* log, Lista lista) {
	QuickSortRec(0, lista.size - 1, log, lista);
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
		lista.setAtributo(BD.array[id].estadoNascimento, lista); // Setta o atributo usado na ordenação
	}

	timer.Start(&timer);
	QuickSort(&log, lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_quicksort.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}
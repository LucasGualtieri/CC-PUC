#include "../Libs/LibTP02.h"

// clear && gcc TP02Q06.c && ./a.out < pub.in > result.txt

#define strcmpr(jog1, jog2) strcmp(jog1.nome, jog2.nome)

void SelectionSortRecursivo(int i, int j, int menor, Log* log, Lista array) {

	if (j < array.size) {
		if (strcmpr(array.array[menor], array.array[j]) > 0) menor = j;
		log->comparacoes++;
		SelectionSortRecursivo(i, j + 1, menor, log, array);
	} else {
		swap(&array.array[i], &array.array[menor]);
		log->movimentacoes += 3;
	}

	if (++i < array.size - 1 && j == i) {
		SelectionSortRecursivo(i, i + 1, i, log, array);
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

	Lista listaJogadores = newLista(465); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	timer.Start(&timer);
	SelectionSort(&log, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.Mostrar(listaJogadores);

	log.RegistroOrdenacao("794989_selecaoRecursiva.txt", timer, log);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
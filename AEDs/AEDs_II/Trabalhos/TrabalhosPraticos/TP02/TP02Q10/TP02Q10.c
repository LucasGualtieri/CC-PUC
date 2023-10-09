#include "../Libs/LibTP02.h"

// clear && gcc TP02Q10.c && ./a.out < pub.in > result.txt

int strcmpr(Jogador jog1, Jogador jog2, Log* log) {
	log->comparacoes++;
	int strComp = strcmp(jog1.estadoNascimento, jog2.estadoNascimento);

	if (strComp != 0) {
		return strComp;
	} else {
		log->comparacoes++;
		return strcmp(jog1.nome, jog2.nome);
	}
}

void QuickSortRec(int left, int right, Log* log, Jogador* array) {

	int i = left, j = right;
	Jogador pivot = array[(right + left) / 2];

	while (i <= j) {
		while (strcmpr(array[i], pivot, log) < 0) i++;
		while (strcmpr(array[j], pivot, log) > 0) j--;
		if (i <= j) swap(&array[i++], &array[j--], log);
	}

	if (left < j)  QuickSortRec(left, j, log, array);
	if (i < right)  QuickSortRec(i, right, log, array);
}

void QuickSort(Log* log, Lista jogadores) {
    QuickSortRec(0, jogadores.size - 1, log, jogadores.array);
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
	QuickSort(&log, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.Mostrar(listaJogadores);

	log.RegistroOrdenacao("794989_quicksort.txt", timer, log);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
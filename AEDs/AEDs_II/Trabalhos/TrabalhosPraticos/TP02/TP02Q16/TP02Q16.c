#include "../Libs/LibTP02.h"

// clear && gcc TP02Q16.c && ./a.out < pub.in > result.txt

void InsertionSortParcial(int k, Log* log, Lista lista) {
	
	int N = lista.size;
	Jogador* array = lista.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {

		temp = array[i];
		j = (i < k) ? i - 1 : k - 1;
		if (i > k) array[i] = array[k];

		while (j >= 0 && lista.CompareToInt(array[j], temp, log)) {
			array[j-- + 1] = array[j];
			log->movimentacoes++;
		}

		array[j + 1] = temp;
		log->movimentacoes += i > k ? 3 : 2;
	}
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
		lista.setAtributo(&BD.array[id].anoNascimento, lista);
	}

	int k = 10;

	timer.Start(&timer);
	InsertionSortParcial(k, &log, lista);
	timer.Stop(&timer);

	lista.MostrarParcial(k, lista);

	log.RegistroOrdenacao("794989_insercaoParcial.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}

#include "../Libs/LibTP02.h"

// clear && gcc TP02Q12.c && ./a.out < pub.in > result.txt

void BubbleSort(Log* log, Lista lista) {

	int N = lista.size;
	Jogador* array = lista.array;

	for (int i = 0; i < N - 1; i++) {
		// for (j = 0; j < N - i - 1; j++) { // Bubble Otimizado
		for (int j = 0; j < N - 1; j++) {
			if (lista.CompareToInt(array[j], array[j + 1], log)) {
				swap(&array[j], &array[j + 1], log);
			}
		}
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

	timer.Start(&timer);
	BubbleSort(&log, lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_bolha.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}
#include "../Libs/LibTP02.h"

// clear && gcc TP02Q12.c && ./a.out < pub.in > result.txt

void BubbleSort(Log* log, Lista jogadores) {

	Jogador* array = jogadores.array;
	int N = jogadores.size;

	for (int i = 0; i < N - 1; i++) {
		// for (j = 0; j < N - i - 1; j++) { // Bubble Otimizado
		for (int j = 0; j < N - 1; j++) {
			if (array[j].anoNascimento > array[j + 1].anoNascimento) {
				swap(&array[j], &array[j + 1]);
				log->comparacoes++;
				log->movimentacoes += 3;
			}
		}
	}
}

void registroLog(Timer timer, Log log);

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

	listaJogadores.SortByNome(listaJogadores);

	timer.Start(&timer);
	BubbleSort(&log, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.Mostrar(listaJogadores);

	log.RegistroOrdenacao("794989_bolha.txt", timer, log);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
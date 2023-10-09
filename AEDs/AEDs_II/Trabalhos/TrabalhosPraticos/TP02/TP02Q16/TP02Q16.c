#include "../Libs/LibTP02.h"

// clear && gcc TP02Q16.c && ./a.out < pub.in > result.txt

bool AnoNascimentoCmp(Jogador jog1, Jogador jog2, Log* log) {
	log->comparacoes++;
	bool result = jog1.anoNascimento > jog2.anoNascimento;
	
	return result;
}

void InsertionSortParcial(int k, Log* log, Lista listaJogadores) {
	
	int N = listaJogadores.size;
	Jogador* array = listaJogadores.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {

		temp = array[i];
		j = (i < k) ? i - 1 : k - 1;

		if (i > k) {
			array[i] = array[k];
			log->movimentacoes++;
		}

		while (j >= 0 && AnoNascimentoCmp(array[j], temp, log)) {
			array[j-- + 1] = array[j];
			log->movimentacoes++;
		}

		array[j + 1] = temp;
		log->movimentacoes += 2;
	}
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

	listaJogadores.SortByNome(listaJogadores);

	int k = 10;

	timer.Start(&timer);
	InsertionSortParcial(k, &log, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.MostrarParcial(k, listaJogadores);

	log.RegistroOrdenacao("794989_insercaoParcial.txt", timer, log);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
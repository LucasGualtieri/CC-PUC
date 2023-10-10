#include "../Libs/LibTP02.h"

// clear && gcc TP02Q08.c && ./a.out < pub.in > result.txt

bool PesoCmp(Jogador jog1, Jogador jog2, Log* log) {
	log->comparacoes += 2;
	if (jog1.peso != jog2.peso) {
		return jog1.peso > jog2.peso;
	} else {
		return strcmp(jog1.nome, jog2.nome) > 0;
	}
}

void insertionSortByColor(int color, int h, int N, Log* log, Jogador* array) {
	int j;
	Jogador temp;
	for (int i = h + color; i < N; i += h) {
		temp = array[i];
		j = i - h;
		while (j >= 0 && PesoCmp(array[j], temp, log)) {
			array[j + h] = array[j];
			j -= h;
			log->movimentacoes++;
		}
		array[j + h] = temp;
		log->movimentacoes += 2;
	}
}

void ShellSort(Log* log, Lista jogadores) {

	int N = jogadores.size;
	Jogador* array = jogadores.array;

	int h;
	for (h = 1; h < N; h = (h * 3) + 1);

	while (h >= 1) {
		h /= 3;
		for (int color = 0; color < h; color++) {
			insertionSortByColor(color, h, N, log, array);
		}
	}
}

int main() {
	
	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(466); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	timer.Start(&timer);
	ShellSort(&log, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.Mostrar(listaJogadores);

	log.RegistroOrdenacao("794989_shellsort.txt", timer, log);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}

// Roda mais lento por algum motivo, alguns micro segundo mais lento
// Mas também tem um tempo mais constante, não varia mt mais que 0.000160
// Mas faz umas 2000 comps a menos.
// int PesoCmp(Jogador jog1, Jogador jog2, Log* log) {
// 	bool pesoCmp = jog1.peso > jog2.peso;
// 	if (pesoCmp) {
// 		log->comparacoes++;
// 		return pesoCmp;
// 	} else {
// 		log->comparacoes += 2;
// 		pesoCmp = jog1.peso < jog2.peso;
// 		return pesoCmp ? !pesoCmp : strcmp(jog1.nome, jog2.nome);
// 	}
// }
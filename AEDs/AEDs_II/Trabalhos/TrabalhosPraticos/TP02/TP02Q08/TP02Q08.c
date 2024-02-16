#include "../Libs/LibTP02.h"

// clear && gcc TP02Q08.c && ./a.out < pub.in > result.txt

void insertionSortByColor(int color, int h, Log* log, Lista lista) {
	
	int j, N = lista.size;
	Jogador* array = lista.array;
	
	Jogador temp;
	for (int i = h + color; i < N; i += h) {
		temp = array[i];
		j = i - h;
		while (j >= 0 && lista.CompareToInt(array[j], temp, log)) {
			array[j + h] = array[j];
			j -= h;
			log->movimentacoes++;
		}
		array[j + h] = temp;
		log->movimentacoes += 2;
	}
}

void ShellSort(Log* log, Lista lista) {

	int h, N = lista.size;
	Jogador* array = lista.array;

	for (h = 1; h < N; h = (h * 3) + 1);

	while (h >= 1) {
		h /= 3;
		for (int color = 0; color < h; color++) {
			insertionSortByColor(color, h, log, lista);
		}
	}
}

int main() {
	
	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista lista = newLista(466); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		lista.Inserir(BD.Get(id, BD), &lista);
		lista.setAtributo(&BD.array[id].peso, lista); // Setta o atributo usado na ordenação
	}

	timer.Start(&timer);
	ShellSort(&log, lista);
	timer.Stop(&timer);

	lista.Mostrar(lista);

	log.RegistroOrdenacao("794989_shellsort.txt", timer, log);

	lista.Close(&lista);
	BD.Close(&BD);

}

// Roda mais lento por algum motivo, alguns micro segundos mais lento
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
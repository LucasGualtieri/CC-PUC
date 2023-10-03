#include "../TP02Libs/LibsC/LibTP02.h"

// clear && gcc TP02Q04.c && ./a.out < pub.in > result.txt

bool PesquisaBinariaAux(String nome, int* comparacoes, Jogador* array, int left, int right) {
	int mid = (left + right) / 2;
	String elementoBusca = array[mid].nome;

	int result = strcmp(elementoBusca, nome);
	// (*comparacoes)++;

	if (result == 0) {
		(*comparacoes)++;
		return true;
	}	else if (result < 0) {
		left = mid + 1;
	}	else right = mid - 1;
	(*comparacoes) += 2;

	return left <= right ? PesquisaBinariaAux(nome, comparacoes, array, left, right) : false;
}

bool PesquisaBinaria(String nome, int* comparacoes, Lista lista) {
	return PesquisaBinariaAux(nome, comparacoes, lista.array, 0, lista.size - 1);
}

void registroLog(Timer timer, int comparacoes) {
	literal fileName = "794989_binaria.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "794989\t%.3fs\t%d", timer.Time(&timer), comparacoes);

	fclose(file);
}

int main() {

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(49); // Tamanho de entradada do Pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.Sort(listaJogadores);

	Timer timer = newTimerStart();
	int comparacoes = 0;
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		bool resultado = PesquisaBinaria(inputPUBIN, &comparacoes, listaJogadores);
		printf("%s\n", resultado ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	registroLog(timer, comparacoes);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}

#define strcmpr(jog1, jog2) strcmp(jog1.nome, jog2.nome)

void SortLista(Lista lista) {
	int N = lista.size;
	Jogador* array = lista.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && strcmpr(array[j], temp) > 0) {
			array[j-- + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}
#include "../TP02Libs/LibsC/LibTP02.h"

// clear && gcc TP02Q04.c && ./a.out < pub.in > result.txt

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

void registroLog(Timer timer, int comparacoes, int movimentacoes) {

	literal fileName = "794989_selecaoRecursiva.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %.3fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d\t", comparacoes);
	fprintf(file, "Número de movimentações: %d", movimentacoes);

	fclose(file);

}

int main() {

	// Tem que pegar os pub in certo e fazer o sort padrao da lista na classe lista e os sorts dos deveres separados igual fiz com a pesquisa
	
	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(49); // Tamanho de entradadas do pub.in

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
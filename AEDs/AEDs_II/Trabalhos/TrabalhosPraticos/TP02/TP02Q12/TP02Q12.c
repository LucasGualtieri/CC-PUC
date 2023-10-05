#include "../LibTP02.h"

// clear && gcc TP02Q12.c && ./a.out < pub.in > result.txt

void swap(Jogador* jog1, Jogador* jog2) {
	Jogador aux = *jog1;
	*jog1 = *jog2;
	*jog2 = aux;
}

void registroLog(Timer timer, Resultado resultado) {

	literal fileName = "794989_bolha.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d\t", resultado.comparacoes);
	fprintf(file, "Número de movimentações: %d", resultado.movimentacoes);

	fclose(file);

}

void BubbleSort(Resultado* resultado, Lista jogadores) {

	Jogador* array = jogadores.array;
	int N = jogadores.size;

	for (int i = 0; i < N - 1; i++) {
		// for (j = 0; j < N - i - 1; j++) { // Bubble Otimizado
		for (int j = 0; j < N - 1; j++) {
			if (array[j].anoNascimento > array[j + 1].anoNascimento) {
				resultado->comparacoes++;
				swap(&array[j], &array[j + 1]);
				resultado->movimentacoes += 3;
			}
		}
	}
}

int main() {
	
	Timer timer = newTimer();
	Resultado resultado = { 0, 0 };

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(465); // Tamanho de entradadas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.SortNome(listaJogadores);

	timer.Start(&timer);
	BubbleSort(&resultado, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.Mostrar(listaJogadores);

	registroLog(timer, resultado);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
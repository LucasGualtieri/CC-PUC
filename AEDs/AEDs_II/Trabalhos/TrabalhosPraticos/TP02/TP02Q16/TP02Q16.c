#include "../LibTP02.h"

// clear && gcc TP02Q16.c && ./a.out < pub.in > result.txt

void registroLog(Timer timer, Resultado resultado) {

	literal fileName = "794989_insercao.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d\t", resultado.comparacoes);
	fprintf(file, "Número de movimentações: %d", resultado.movimentacoes);

	fclose(file);

}

void InsertionSortParcial(int k, Resultado* resultado, Lista listaJogadores) {
	
	int N = listaJogadores.size;
	Jogador* array = listaJogadores.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {

		temp = array[i];
		j = (i < k) ? i - 1 : k - 1;
		// if (i == k) printf("Perdido: %s\n", array[k].nome);

		resultado->comparacoes++;
		while (j >= 0 && array[j].anoNascimento > temp.anoNascimento) {
			array[j-- + 1] = array[j];
			resultado->comparacoes++;
			resultado->movimentacoes++;
		}

		array[j + 1] = temp;
		resultado->movimentacoes += 2;
	}
}

int main() {
	
	Timer timer = newTimer();
	Resultado resultado = { 0, 0 };

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(465); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.SortNome(listaJogadores);

	int k = 10;

	timer.Start(&timer);
	InsertionSortParcial(k, &resultado, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.MostrarParcial(k, listaJogadores);

	registroLog(timer, resultado);

	// listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
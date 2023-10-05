#include "../LibTP02.h"

// clear && gcc TP02Q16.c && ./a.out < pub.in > result.txt

void InsertionSortParcial(int k, Lista listaJogadores) {
	
	int N = listaJogadores.size;
	Jogador* array = listaJogadores.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {
		temp = array[i];
		j = (i < k) ? i - 1 : k - 1;
		// if (i == k) printf("Perdido: %s\n", array[k].nome);
		while (j >= 0 && array[j].anoNascimento > temp.anoNascimento) {
			array[j-- + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}

int main() {
	
	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(465); // Tamanho de entradadas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.SortNome(listaJogadores);

	int k = 10;

	InsertionSortParcial(k, listaJogadores);

	listaJogadores.MostrarParcial(k, listaJogadores);

	// listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
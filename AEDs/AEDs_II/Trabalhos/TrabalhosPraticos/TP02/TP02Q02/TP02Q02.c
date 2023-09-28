#include "../TP02Libs/LibTP02.h"

// clear && gcc TP02Q02.c && ./a.out < pub.in > result.txt

int main() {

	Fila BD = newFila(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Fila listaJogadores = newFila(40); // Tamanho de entradada do Pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		Jogador jogador = BD.PesquisaBinaria(id);
		jogador.Mostrar(jogador);
		// printf("Id: %d\n", id);
		// listaJogadores.Inserir(BD.PesquisaBinaria(id));
		// Dentro do inserir fazer um .clone
	}

	// listaJogadores.Mostrar(listaJogadores);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
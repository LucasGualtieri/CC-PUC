#include "../TP02Libs/Fila.h"

// clear && gcc TP02Q02.c && ./a.out < pub.in > result.txt

int main() {

	Fila BD = newFila(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Fila listaJogadores = newFila(40); // Tamanho de entradada do Pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		// listaJogadores.Inserir(BD.PesquisaSenquencial(id));
		// Dentro do inserir fazer um .clone
	}

	listaJogadores.Mostrar(listaJogadores);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
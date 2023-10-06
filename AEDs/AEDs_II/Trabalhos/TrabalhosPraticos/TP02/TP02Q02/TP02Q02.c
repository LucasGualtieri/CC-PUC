#include "..LibTP02.h"

// clear && gcc TP02Q02.c && ./a.out < pub.in > result.txt

int main() {

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(40); // Tamanho de entradas do pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.Mostrar(listaJogadores);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}
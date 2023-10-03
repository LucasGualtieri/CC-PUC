#include "../TP02Libs/LibsC/LibTP02.h"

// clear && gcc TP02Q02.c && ./a.out < pub.in > result.txt

int main() {

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("/tmp/players.csv", &BD);


	Lista jogadores = newLista(40); // Tamanho de entradadas do pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		jogadores.Inserir(BD.Get(id, BD), &jogadores);
	}

	jogadores.Mostrar(jogadores);

	jogadores.Close(&jogadores);
	BD.Close(&BD);

}

void SortLista(Lista lista) {}
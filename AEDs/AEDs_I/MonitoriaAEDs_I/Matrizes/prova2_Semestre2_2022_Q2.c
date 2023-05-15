#include <biblioteca_c.h>

void printMatriz(int size, float matriz[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%g%s", matriz[i][j], " ");
		}
		printf("\n");
	}
}

bool function(int size, float matriz[size][size], int i, int j) {
	// printMatriz(size, matriz);

	// int negativosLinhai = 0, negativosColunaj;
}

int main() {

	int size = 2;
	float matriz[2][2] = { { 1, 2 }, { 3, 4 } }; // Função pra montar a matriz com malloc e size lido do teclado
	// descobrir o que é coluna e o que é linha col lin? ou lin col?

	function(size, matriz, 1, 4);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
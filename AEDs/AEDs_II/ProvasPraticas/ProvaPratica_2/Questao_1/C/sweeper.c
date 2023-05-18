#include "Cell.h"
#include "Matrix.h"
#include <biblioteca_c.h>

// clear && gcc sweeper.c -I /home/lucas/CC-PUC/Bibliotecas -o sweeper.exe && ./sweeper.exe < ../pub.in > out.txt

void MatrixFill(Matrix* matrix) {

	int matrixTotalValues = matrix->columns * matrix->rows;
	for (int i = 0; i < matrixTotalValues; i++) {
		int aux;
		scanf("%d", &aux);
		MatrixInsertEnd(aux, matrix);
	}
}

int adjacentes(Cell* cell) {
	int qtdAdjacentes = 0;

	if (cell->above->value == 1) qtdAdjacentes++;
	if (cell->below->value == 1) qtdAdjacentes++;
	if (cell->left->value == 1) qtdAdjacentes++;
	if (cell->right->value == 1) qtdAdjacentes++;

	return qtdAdjacentes;
}

void SweeperPrint(Matrix matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			if (MatrixGet(i, j, matrix) == 1) {
				printf("9");
			} else {
				int qtdAdjacentes = adjacentes(MatrixGetCell(i, j, matrix));
				if (qtdAdjacentes > 0) {
					printf("%d", qtdAdjacentes);
				} else {
					printf("0");
				}
			}
		}
	}
}

int main() {

	String* dimensoes = split(getstr(0), " ", 1);

	while (strcmp(dimensoes[0], "FIM")) {

		Matrix matrix;

		int rows = atoi(dimensoes[0]);
		int columns = atoi(dimensoes[1]);

		MatrixAlloc(rows, columns, &matrix); // To be created

		// MatrixFill(matrix); // To be created

		SweeperPrint(matrix);

		// MatrixFree(matrix); // To be created

		freeSplit(dimensoes);

		dimensoes = split(getstr(0), " ", 1);
	}

	free(dimensoes);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}

// Ideias para implementar isso em C++
// MatrixAlloc seria o contrutor
// matrix.Fill()
// 		matrix.Fill() poderia ter alguma forma de determinar limites inferiores inferiroes ou por leitra do teclado, algum tipo de variavel buleano que determine o que será feito
// Destrutor que chame this->free();
// Teria que implementar split para strings
// Quem sabe uma classe "scanner"? pra usar um destrutor também pra dar free sempre, que maravilha seria!
// Mas pensando bem, mais fácil fazer uma função que le uma string com cin >> string e retorna a string... :(
// seria legal sim! Ai eu poderia ter um metodo split e o destrutor da um free no malloc inevitavel pra fazer o vetor de strings (que serao destruidas no escopo), mas n o vetor em si
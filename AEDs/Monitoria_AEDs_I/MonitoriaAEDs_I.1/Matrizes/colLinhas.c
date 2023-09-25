#include <biblioteca_c.h>

#define SIZE 4
#define nCol SIZE
#define nLin SIZE

int fn(int matriz[nLin][nCol]);

int main() {

	int matriz[nLin][nCol] = { { 1, 2 }, { 3, 4 } };

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d", matriz[i][j]);
		}
		printf("\n");
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
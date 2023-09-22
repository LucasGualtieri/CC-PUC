#include <biblioteca_c.h>

int main() {

	FILE* file = fopen("file.txt", "r");

	char vetorLinha1[50][50];
	char vetorLinha2[50][50];

	int i = 0;
	do { // Linha1
		fscanf(file, "%s", vetorLinha1[i]);
		i++;
	} while (getc(file) != '\n');
	int vetorLinha1Len = i;

	i = 0;
	do { // Linha2
		fscanf(file, "%s", vetorLinha2[i]);
		i++;
	} while (getc(file) != EOF);
	int vetorLinha2Len = i;

	//                     								 TRUE            FALSE
	// int menor = (vetorLinha1Len < vetorLinha2Len) ? vetorLinha1Len : vetorLinha2Len;

	int	 menor, maior;
	char maiorVetor[50][50];

	if (vetorLinha1Len < vetorLinha2Len) {
		menor = vetorLinha1Len;
		maior = vetorLinha2Len;
		for (int i = 0; i < vetorLinha2Len; i++) {
			strcpy(maiorVetor[i], vetorLinha2[i]);
		}

	} else {
		menor = vetorLinha2Len;
		maior = vetorLinha1Len;
		for (int i = 0; i < vetorLinha1Len; i++) {
			strcpy(maiorVetor[i], vetorLinha1[i]);
		}
	}

	for (int i = 0; i < menor; i++) {
		printf("%s ", vetorLinha1[i]);
		printf("%s ", vetorLinha2[i]);
	}

	for (int i = menor; i < maior; i++) {
		printf("%s ", maiorVetor[i]);
	}

	puts("\n\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}
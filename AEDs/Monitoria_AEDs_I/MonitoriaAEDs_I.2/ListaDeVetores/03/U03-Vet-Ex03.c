#include <stdio.h>

// clear && gcc U03-Vet-Ex03.c && ./a.out < pub.in > pubResult.txt
// clear && gcc U03-Vet-Ex03.c && ./a.out < pri.in > priResult.txt

int main() {
	
	int N;
	scanf("%d", &N);
	int vetor[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &vetor[i]);
	}

	int maiorElemento = vetor[0];
	int posicaoMaiorElemento = 0;
	for (int i = 1; i < N; i++) {
		if (vetor[i] >= maiorElemento) {
			maiorElemento = vetor[i];
			posicaoMaiorElemento = i;
		}
	}

	printf("%d %d", maiorElemento, posicaoMaiorElemento);

	return 0;
}
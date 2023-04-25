#include <stdio.h>

int main(void) {

	int dimensao, diametro;
	int maiorDimensao = 0;
	int menorDimensao = 2000000000;
	
	scanf("%d", &diametro);

	for (int i = 0; i < 3; i++) {
		scanf("%d", &dimensao);
		if (dimensao > maiorDimensao) {
			maiorDimensao = dimensao;
		}
		if (dimensao < menorDimensao) {
			menorDimensao = dimensao;
		}
	}

	// printf("%d\n", maiorDimensao);
	// printf("%d\n", menorDimensao);
	
	if (diametro > maiorDimensao || diametro > menorDimensao) {
		printf("N");	
	} else {
		printf("S");
	}
	
  return 0;
}
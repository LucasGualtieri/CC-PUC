#include <stdio.h>
#include <limits.h>

int main(void) {
	int nTiposDeBala;
	int numeroDeRotulos;
	int rotuloComMenorQtd = INT_MAX;
	
	scanf("%d", &nTiposDeBala);

	for (int i = 0; i < nTiposDeBala; i++) {
		scanf("%d", &numeroDeRotulos);
		if (numeroDeRotulos < rotuloComMenorQtd) {
			rotuloComMenorQtd = numeroDeRotulos;
		}
	}

	printf("%d", rotuloComMenorQtd);
  	return 0;
}	
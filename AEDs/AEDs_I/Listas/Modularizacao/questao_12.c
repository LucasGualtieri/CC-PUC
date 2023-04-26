#include <stdio.h>

// Essa função recebe um número inteiro n e printa o n-ésimo múltiplo de 5.
int MultiploDe5(int n) {

	for (int i = 0, j = 5; i < n; i++, j += 5) {
		printf("%d° múltiplo de 5 é %d\n", i + 1, j);
	}
}

// Esse procedimento lê o valor de n e chama a função.
void ExercicioXII() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	MultiploDe5(n);
}

int main() {

	ExercicioXII();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}
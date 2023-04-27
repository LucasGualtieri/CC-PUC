#include <stdio.h>

int main(void) {
	const int numeroApartamentos = 75;
	const int desconto = 25;
	int diaria;
	float diariaPromocional, totalArrecadPromo, totalArrecad;

	printf("Valor da diária: ");
	scanf("%d", &diaria);

	diariaPromocional = diaria * 0.75;
	totalArrecadPromo = (75 * 0.8) * diariaPromocional;
	totalArrecad = (75 * 0.5) * diaria;

	printf("\nValor da diária promocional: %.2f", diariaPromocional);
	printf("\nValor arrecadado com 80%% de ocupação e diária promocional: R$ %.2f", totalArrecadPromo);
	printf("\nValor arrecadado com 50%% de ocupação e diária normal: R$ %.2f", totalArrecad);
	printf("\nA diferença entre os dois valores: R$ %.2f", (totalArrecadPromo - totalArrecad));

	return 0;
}
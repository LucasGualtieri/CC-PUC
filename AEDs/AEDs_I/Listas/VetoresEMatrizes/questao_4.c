#include <biblioteca_c.h>

int main() {

	int tempsJaneiro[31];
	int len = arrayLength(tempsJaneiro);

	IntArrayFillRand(tempsJaneiro, arrayLength(tempsJaneiro), 15, 40);

	int maxTemp = -Infinity, minTemp = Infinity, daysBelowAverage = 0;
	float averageTemp;

	for (int i = 0, soma = 0; i < len; i++) {
		soma += tempsJaneiro[i];
		if (tempsJaneiro[i] > maxTemp) maxTemp = tempsJaneiro[i];
		if (tempsJaneiro[i] < minTemp) minTemp = tempsJaneiro[i];
		if (i == len - 1) {
			averageTemp = soma / len;
			for (int i = 0; i < len; i++) {
				if (tempsJaneiro[i] < averageTemp) daysBelowAverage++;
			}
		}
	}

	// IntArrayPrint(tempsJaneiro, len);
	printf("Maior temperatura registrada: %d°c\n", maxTemp);
	printf("Menor temperatura registrada: %d°c\n", minTemp);
	printf("Média das temperaturas registradas: %g°c\n", averageTemp);
	printf("Dias abaixo da média: %d\n", daysBelowAverage);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}
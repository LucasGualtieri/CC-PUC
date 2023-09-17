#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include "Timer.h"

// clear && gcc custoDeOperacoes.c && ./a.out

double Media() {

	double media = 0;
	int reps = 30;
	long long var = 0;

	Timer tempoTotal = newTimer();
	Timer timer = newTimer();
	tempoTotal.Start(&tempoTotal);
	for (int i = 0; i < reps; i++) {
		timer.Start(&timer);
		for (int j = 0; j < 100000000; j++) {
			var *= 2;
			var /= 2;
			var += 1;
			var -= 1;
			var *= 2;
			var /= 2;
			var += 1;
			var -= 1;
			// for (int k = 0; k < 2; k++) {
			// 	var *= 2;
			// 	var /= 2;
			// 	var += 1;
			// 	var -= 1;
			// }
		}
		media += timer.Stop(&timer);
	}
	printf("Tempo total: %.3lfs\n", tempoTotal.Stop(&tempoTotal));

	return media /= reps;

}

void main() {

	// timer.Start(&timer);
	// for (int i = 0; i < 1; i++) {
	// 	int* array = (int*)malloc(sizeof(int));
	// 	free(array);
	// 	int* array1 = (int*)malloc(sizeof(int));
	// 	free(array1);
	// }
	// double resultado = timer.Stop(&timer);
	
	// printf("Resultado: %.3lfs\n", timer.Stop(&timer));
	// double tempoEsperado = resultado * 1500000;
	// printf("tempoEsperado: %.3lfs\n", tempoEsperado);

	printf("Resultado: %.3lfs\n", Media());	

	// printf("Resultado: %.3lfs\n", timer.Stop(&timer));
}
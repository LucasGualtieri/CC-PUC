#include <stdio.h>
#include "Timer.h"

// clear && gcc SemOtimizar.c && ./a.out
// clear && gcc SemOtimizar.c -O0 && ./a.out
// clear && gcc SemOtimizar.c -O3 && ./a.out

#define BILHAO 1000000

// PQ COM O BREAK É MAIS RÁPIDOOOO????

double fn() {

	Timer timer = newTimer();
	timer.Start(&timer);
	for (int i = 0; i < BILHAO; i++) {
		for (int j = 0; j < BILHAO; j++) {
			if (j == 5) {
				// j = BILHAO;
				break;
			}
		}
	}
	return timer.Stop(&timer);
}

int main() {

	int totalIterations = 250;

	double totalTime = 0;

	for (int i = 0; i < totalIterations; i++) totalTime += fn();
	
	printf("Tempo total: %lf\n", totalTime / totalIterations);
}
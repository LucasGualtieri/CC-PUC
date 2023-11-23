#include "../Libs/LibTP02.h"

// clear && gcc Teste.c && ./a.out
// clear && gcc Teste.c -O0 && ./a.out
// clear && gcc Teste.c -O3 && ./a.out

#define BILHAO 100000

void fn() {

	for (int i = 0; i < BILHAO; i++) {
		for (int j = 0; j < BILHAO; j++) {
			if (j == 5) {
				
			}
			// break;
		}
	}
	
}

int main() {

	Timer timer = newTimer();
	
	timer.Start(&timer);
	fn();
	timer.Stop(&timer);

	printf("Tempo total: %lf\n", totalTime / 100);

}
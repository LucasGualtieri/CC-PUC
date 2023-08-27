#include "../LibCTP01.h"
#include <time.h>

// clear && gcc TP01Q13.c -o TP01Q13 && ./TP01Q13 < pub.in > result.txt

String aleatorio(String str, int* rand) {
	
}

int main() {

	char str[STR_MAX_LEN];
	
	srand(time(0));
	int numeroAleatorio = rand();

	while (!isEqual(readstr(str), "FIM")) {
		printf("%s\n", aleatorio(str, &numeroAleatorio) ? "SIM" : "NAO");
	}

	return 0;
}

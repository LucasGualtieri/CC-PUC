#include <stdio.h>
// 3665 == 01h:01m:05s

void converteHora(int segundos, int* h, int* m, int* s) {
	*h = segundos / 3600;
	*m = (segundos % 3600) / 60;
	*s = (segundos % 60);
}

int main(void) {
	int segundos, h, m, s = 0;

	printf("Digite a quantidade de segundos: ");
	scanf("%d", &segundos);

	converteHora(segundos, &h, &m, &s);

	printf("%02d:%02d:%02ds", h, m, s);

	return 0;
}
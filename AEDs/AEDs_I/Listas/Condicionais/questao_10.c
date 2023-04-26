#include <stdio.h>

int vel, velMaxPermitida, multa;

void msg() {
	if (multa == 0) {
		printf("Motorista respeitou a lei");
	} else {
		printf("Motorista excedeu a velocida de permitida. Multa de R$%d.00", multa);
	}
}

int main(void) {

	printf("Digite a velocidade permitida em uma avenida: ");
	scanf("%d", &velMaxPermitida);
	printf("Digite a velocidade que o motorista estava dirigindo: ");
	scanf(" %d", &vel);

	if (vel > velMaxPermitida && vel <= (velMaxPermitida + 10)) {
		multa = 50;
		msg();
	} else if (vel > (velMaxPermitida + 10) && vel <= (velMaxPermitida + 30)) {
		multa = 100;
		msg();
	} else if (vel > (velMaxPermitida + 30)) {
		multa = 200;
		msg();
	} else {
		msg();
	}

	return 0;
}
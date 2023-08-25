#include <stdio.h>

typedef union {
	unsigned int num;
	unsigned char vet[8];
	float vfrac;
} dado;

dado var;

void print32(unsigned int number) {
	for (int i = 0; i < 32; i++) {
		unsigned char bitt = !(!(number & 0x80000000));
		if((i % 4) == 0) printf(" ");
		printf("%u", bitt);
		number = number << 1;
	}
	printf("\n");    
}

int main () {

	float aux = 15213.125;

	printf ("%04f\n", aux);
	var.vfrac = aux;
	printf ("%04f\n", var.vfrac);
	printf ("%02x %02x %02x %02x\n",var.vet[3],var.vet[2],var.vet[1],var.vet[0]);
	print32(var.num);

	return 0;
}
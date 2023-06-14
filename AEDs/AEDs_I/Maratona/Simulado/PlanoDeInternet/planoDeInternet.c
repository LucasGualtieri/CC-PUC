#include <stdio.h>
// ./main < in.txt > out.txt
// saldo += quotaMensalMB - scanf("%d", &gastoMensal); Isso não funciona no verde

int main() {

	int quotaMensalMB, numeroDeMeses, saldo = 0;

	scanf("%d %d", &quotaMensalMB, &numeroDeMeses);

	for (int i = 0; i < numeroDeMeses; i++) {
		int gastoNoMes;
		scanf("%d", &gastoNoMes);
		saldo += quotaMensalMB - gastoNoMes;
	}

	printf("%d", saldo + quotaMensalMB);

	return 0;
}

// Alternativa com vetor
// int main(void) {
//     int quotaMensalMB, numeroDeMeses, saldo = 0;

//     scanf("%d", &quotaMensalMB);
//     scanf("%d", &numeroDeMeses);

//     int vetorGastoMensal[numeroDeMeses];

//     for (int i = 0; i < numeroDeMeses; i++) {
//         scanf("%d", &vetorGastoMensal[i]);
//         saldo += quotaMensalMB - vetorGastoMensal[i];
//     }

//     printf("%d", saldo + quotaMensalMB);
//     return 0;
// }
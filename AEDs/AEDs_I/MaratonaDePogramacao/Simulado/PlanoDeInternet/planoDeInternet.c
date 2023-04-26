#include <stdio.h>
// ./main < in.txt > out.txt
// excessoQuota += quotaMbMensal - scanf("%d", &gastoMensal); Isso não funciona no verde

int main(void) {
	int quotaMbMensal, numeroDeMeses, gastoMensal, excessoQuota = 0;
	scanf("%d", &quotaMbMensal);
	scanf("%d", &numeroDeMeses);

	for (int i = 0; i < numeroDeMeses; i++) {
		scanf("%d", &gastoMensal);
		excessoQuota += quotaMbMensal - gastoMensal;
	}

	printf("%d", excessoQuota + quotaMbMensal);
	return 0;
}

// Alternativa com vetor
// int main(void) {
//     int quotaMbMensal, numeroDeMeses, excessoQuota = 0;

//     scanf("%d", &quotaMbMensal);
//     scanf("%d", &numeroDeMeses);

//     int vetorGastoMensal[numeroDeMeses];

//     for (int i = 0; i < numeroDeMeses; i++) {
//         scanf("%d", &vetorGastoMensal[i]);
//         excessoQuota += quotaMbMensal - vetorGastoMensal[i];
//     }

//     printf("%d", excessoQuota + quotaMbMensal);
//     return 0;
// }
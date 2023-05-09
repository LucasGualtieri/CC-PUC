#include <biblioteca_c.h>

void AtribuindoDiasAosMeses(int meses[]) {
	for (int i = 1; i <= 12; i++) {
		if (i < 8) {
			if (i == 2) {
				// Se o mês for Fevereiro -> atribuímos 28
				meses[i] = 28;
			} else if (i % 2 != 0) {
				// Se o mês for ímpar -> atribuímos 31
				meses[i] = 31;
			} else {
				// Se o mês for par -> atribuímos 30
				meses[i] = 30;
			}
		} else {
			// A partir do mês 8 a lógica muda
			if (i % 2 == 0) {
				// Se o mês for par -> atribuímos 31
				meses[i] = 31;
			} else {
				// Se o mês for ímpar -> atribuímos 30
				meses[i] = 30;
			}
		}
	}
}

int main() {

	int meses[12], mes, flag = false;

	AtribuindoDiasAosMeses(meses);

	printf("Digite o número do mês: ");

	do {
		if (flag) printf("Digite o número do mês (mês inválido!): ");
		scanf("%d", &mes);
		flag = true;
	} while (mes < 1 || mes > 12);

	printf("O mês %d tem %d dias\n", mes, meses[mes - 1]);

	// for (int i = 0; i < 12; i++) {
	// 	printf("Dias do mês %d: %d\n", i + 1, meses[i]);
	// }

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}

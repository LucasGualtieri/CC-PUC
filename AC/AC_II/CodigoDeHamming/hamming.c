#include <stdio.h>
#include <stdbool.h>

#define length(array) (int)(sizeof(array) / sizeof(array[0]))

int hammingPos(int n, int bits[]) {
	int errorPos = 0;

	for (int i = 0; i < n; i++) {
		if (!bits[i]) errorPos ^= i;
	}

	return errorPos;
}

int hammingError(int n, int bits[]) {
	// Conta a quantidade de UM's
	int onesCount = 0;
	for (int i = 0; i < n; i++) {
		if (bits[i] == 1) onesCount++;
	}

	// Verifica se o valor da posição 0 condiz com a quantidade geral de UM's
	bool overallParity = bits[0] == 0 && onesCount % 2 == 0 ? true : false;

	// Verifica se há erro de paridade em algum dos "setores"
	bool sectorParity = hammingPos(n, bits) == 0;

	int result = 0;

	if (overallParity && !sectorParity) result = 2;
	else if (!overallParity || !sectorParity) result = 1;

	return result;
}

void main() {
	int bits[] = {
		0, 0, 0, 1,
		1, 1, 0, 1,
		1, 1, 1, 0,
		0, 0, 1, 0
	};

	switch (hammingError(length(bits), bits)) {
		case 2:
			printf("Mais que dois erros, abortar!\n");
		break;
		case 1:
			int pos = hammingPos(length(bits), bits);
			printf("Apenas um erro detectado na posição: %d.\n", pos);
			bits[pos] = !bits[pos];
		break;
		case 0:
			printf("Nenhum erro detectado.\n");
		break;
	}
}
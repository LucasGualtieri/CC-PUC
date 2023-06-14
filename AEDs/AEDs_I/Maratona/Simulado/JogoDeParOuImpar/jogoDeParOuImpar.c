#include <stdio.h>

/*
	Se escolha == 0:
		Jogador1 pediu par e Jogador2 pediu ímpar
	Se escolha == 1:
		Jogador2 pediu par e Jogador1 pediu ímpar
	}

	Deve ser impresso na tela:
		Se jogador1 ganhar -> "0"
		Se jogador2 ganhar -> "1"
	}
*/

int main(void) {
	int escolha, jogador1, jogador2;

	scanf("%d, %d, %d", &escolha, &jogador2);

	if ((jogador1 + jogador2) % 2 == 0) {
		printf("%c", escolha ? '1' : '0');
	} else {
		printf("%c", escolha ? '0' : '1');
	}

	return 0;
}
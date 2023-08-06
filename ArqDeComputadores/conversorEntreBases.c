#include <stdbool.h>
#include <stdio.h>

int ReadingChoice() {
	int	 choice;
	bool invalid = false;

	do {
		if (invalid) {
			printf("Valor inválido, tente novamente: ");
		}
		scanf("%d", &choice);
		flush(0);
	} while ((invalid = choice < 0 || choice > 2));

	return choice;
}

int OptionsMenu() {

	puts("Escolha a base de origem:");
	puts("1- Binário");
	puts("2- Octal");
	puts("3- Decimal");
	puts("4- Hexadecimal");

	int escolha = ReadingChoice();

	switch (escolha) {
	case 1:
		CadastrarSenha();
		// 	break;
		// case 2:
		// 	// CadastrarSenhaCript();
		break;
	case 2:
		ValidarSenha();
		break;
	}

	return escolha;
}

int main() {

	while (OptionsMenu()) continue;

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}
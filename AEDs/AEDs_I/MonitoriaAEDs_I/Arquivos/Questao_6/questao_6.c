#include <biblioteca_c.h>
#include <termios.h>

char* readPassword() {
	struct termios term;
	tcgetattr(fileno(stdin), &term);

	// Disable terminal buffering and echoing
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fileno(stdin), TCSAFLUSH, &term);

	char* string = (char*)malloc(MaxStringLength * sizeof(char));

	for (int i = 0; true; i++) {
		char c = getchar();

		if (c == '\n') {
			printf("\n");
			string[i] = '\0';
			break;
		} else if (c == 127) {
			// printf("Ola");
			printf("\b"); // Moves the cursor back by one position
			printf(" "); // Overwrites the last character with a space
			printf("\b"); // Moves the cursor back again
			i -= 2;
		} else {
			string[i] = c;
			putchar('*');
		}
	}

	string = (char*)realloc(string, (strlen(string) + 1) * sizeof(char));

	// Restore terminal buffering and echoing
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(fileno(stdin), TCSAFLUSH, &term);

	return string;
}

int LendoEscolha() {
	int escolha;
	bool invalid = false;

	do {
		if (invalid) printf("Valor inválido (o valor deve ser >= 0 < 3): ");
		scanf("%d%*c", &escolha);
	} while (invalid = escolha < 0 || escolha > 2);

	return escolha;
}

bool CadastrarSenha() {
	printf("Digite sua senha: ");
	String password = readPassword();

	printf("Confirme sua senha: ");
	String passwordConfirmation = readPassword();

	if (!strcmp(password, passwordConfirmation)) {
		FILE* passwordStorage = fopen("senha.dat", "w");

		fprintf(passwordStorage, "%s", password);

		fclose(passwordStorage);
		free(password);
		free(passwordConfirmation);

		return true;
	} else {
		printf("senhas divergentes...\n");
		free(password);
		free(passwordConfirmation);
		return false;
	}
}

int MenuDeOpcoes() {
	printf("0 - Sair do programa.\n");
	printf("1 - Cadastrar uma nova senha.\n");
	printf("2 - Validar uma senha cadastrada.\n");
	printf("Escolha uma das opções acima: ");

	int escolha = LendoEscolha();

	switch (escolha) {
	case 1:
		while (!CadastrarSenha()) { }
		break;
	case 2:
		printf("Case2\n");
		break;
	default:
		return escolha;
	}
}

int main() {

	while (MenuDeOpcoes()) { }

	puts("\n******* | FIM DO PROGRAMA | *******\n");

	return 0;
}
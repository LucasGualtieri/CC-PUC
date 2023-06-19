#include <biblioteca_c.h>
#include <termios.h>

#define backspace 127

// Toggles the visibility of the input characters.
void ToggleConsoleVisibility() {
	static bool enabled = true;

	static struct termios term;
	tcgetattr(fileno(stdin), &term);

	if (enabled) {
		term.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(fileno(stdin), TCSAFLUSH, &term);
		enabled = false;
	} else {
		term.c_lflag |= (ICANON | ECHO);
		tcsetattr(fileno(stdin), TCSAFLUSH, &term);
		enabled = true;
	}
}

char* readPassword() {
	ToggleConsoleVisibility();

	char c, *password = (char*)malloc(MaxStringLength * sizeof(char));

	int passwordLength = 0;
	while ((c = getchar()) != '\n') {
		if (c != backspace) {
			password[passwordLength++] = c;
			putchar('*');
		} else if (passwordLength > 0) {
			printf("\b \b"); // Moves the cursor back by one position
			passwordLength--;
		}
	}
	password[passwordLength++] = '\0';
	putchar('\n');

	password = (char*)realloc(password, passwordLength * sizeof(char));

	ToggleConsoleVisibility();

	return password;
}

void CadastrarSenha() {
	system("clear");
	puts("------- Cadastrando uma nova senha -------\n");

	String password;
	String passwordConfirmation;
	bool   divergent = false;
	int	   chances	 = 0;

	do {

		if (divergent) {
			printf("\nSenhas divergentes, tente novamente [%d/3]: \n", ++chances);
		}

		printf("Digite sua senha: ");
		password = readPassword();

		printf("Confirme sua senha: ");
		passwordConfirmation = readPassword();

		divergent = strcmp(password, passwordConfirmation);

		if (divergent) {
			free(password);
			free(passwordConfirmation);
		}

	} while (divergent && chances < 3);

	system("clear");

	if (divergent) {
		puts("------- Falha no cadastro da senha! -------\n");
		return;
	}

	puts("------- Senha cadastrada com sucesso! -------\n");

	FILE* passwordStorage = fopen("password.dat", "w");
	fprintf(passwordStorage, "%s", password);

	fclose(passwordStorage);
	free(password);
	free(passwordConfirmation);
}

void ValidarSenha() {
	FILE*  passwordStorage = fopen("password.dat", "r");
	String password		   = getstr(passwordStorage);
	fclose(passwordStorage);

	String passwordValidation;
	bool   invalid = false;
	int	   chances = 0;

	system("clear");
	puts("------- Validar uma senha cadastrada -------\n");

	do {
		if (!invalid) {
			printf("Digite sua senha: ");
		} else {
			printf("Senha incorreta! Tente novamente [%d/3]: ", ++chances);
		}

		passwordValidation = readPassword();

		invalid = strcmp(password, passwordValidation);

		free(passwordValidation);
	} while (invalid && chances < 3);

	free(password);

	system("clear");

	if (invalid) {
		puts("------- Validação mal-sucedida! -------\n");
	} else {
		puts("------- Validação bem-sucedida! -------\n");
	}
}

int OptionsMenu() {

	puts("0 - Sair do programa.");
	puts("1 - Cadastrar uma nova senha.");
	puts("2 - Validar uma senha cadastrada.");
	printf("Escolha uma das opções acima: ");

	int	 escolha;
	bool invalid = false;

	do {
		if (invalid) {
			printf("Valor inválido, tente novamente: ");
		}
		scanf("%d%*c", &escolha);
	} while ((invalid = escolha < 0 || escolha > 2));

	return escolha;
}

void cadastrarVeiculo(Veiculos** vetorVeiculos, int tamanhoVetor){

	cout << "Castrando..."}

Veiculos* LêVeiculosDoArquivo(int* tamanhoDoVetor) {
	Veiculos* vetorVeiculos = malloc();

	FILE* arquivo = fopen("sfels.txt", "r");
	for (int i = 0; !feof(arquivo); i++) {
		Veiculos veiculo;

		fcanf("%s", veiculo.nome);
		fcanf("%s", veiculo.nome);
		fcanf("%s", veiculo.nome);
		fcanf("%s", veiculo.nome);

		vetorVeiculos[i] = veiculo;
	}

	return vetorVeiculos;
}

int main() {

	int		  tamanhoDoVetor = 0;
	Veiculos* vetorVeiculos	 = LêVeiculosDoArquivo(&tamanhoDoVetor);

	int escolha;
	while ((escolha = Menu()) != 0) {
		switch (escolha) {
		case 1:
			cadastrarVeiculo();
			break;
		default:
			break;
		}
	}

	free(vetorVeiculos);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}
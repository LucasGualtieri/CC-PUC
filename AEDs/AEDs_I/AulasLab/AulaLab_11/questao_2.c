#include <biblioteca_c.h>

/*
	Faca um programa em C para ler e manipular informações de um cadastro de automóveis
	São necessárias duas estruturas: carro e proprietario. Todos os dados de um carro
	devem ser lidos e depois impressos. Os campos das estruturas são:
	{
		carro: modelo(char), ano(int), placa (char), proprietario (proprietario);
		proprietario: CPF(long int), nome(char).
	}
*/

struct Proprietario {
	char cpf[15], *nome;
};
typedef struct Proprietario Proprietario;

struct Carro {
	char *modelo, *placa;
	int ano;
	struct Proprietario prop;
};
typedef struct Carro Carro;

int main() {
	Carro c1;

	printf("Digite o nome do proprietário: ");
	getptrs(&c1.prop.nome);

	printf("Digite o CPF do proprietário: ");
	scanf("%s", c1.prop.cpf);
	MaskCPF(c1.prop.cpf);

	printf("Digite o modelo do carro: ");
	getptrs(&c1.modelo);

	printf("Digite a placa do carro: ");
	getptrs(&c1.placa);

	printf("Digite o ano do carro: ");
	scanf("%d", &c1.ano);

	printf("\n*************************\n\n");

	printf("Nome do Proprietário: %s\n", c1.prop.nome);
	printf("CPF do Proprietário: %s\n", c1.prop.cpf);
	printf("Modelo do carro: %s\n", c1.modelo);
	printf("Placa do carro: %s\n", c1.placa);
	printf("Ano do carro: %d\n", c1.ano);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}
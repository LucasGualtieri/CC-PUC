#include <stdio.h>

// clear && gcc tabelaHash.c && ./a.out

typedef struct Pessoa {
	int id;
	char nome[80];
} Pessoa;

void InserirHash(Pessoa pessoa, Pessoa* hash) {
	int pos = pessoa.id % 31;
	if (hash[pos].id != 31) hash[pos] = pessoa;
}

Pessoa PesquisarHash(Pessoa pessoa, Pessoa* hash) {
	int pos = pessoa.id % 31;
	return hash[pos];
}

void StartHash(Pessoa* hash) {
	Pessoa vazia = { 0, "VAZIA" };
	for (int i = 0; i < 31; i++) {
		hash[i] = vazia;
	}
}

int main() {

	Pessoa hash[31];

	Pessoa pessoa = { 5, "Lucas" };

	// printf("nome: %s\n", pessoa.nome);

	InserirHash(pessoa, hash);

	Pessoa pesquisada = PesquisarHash(pessoa, hash);
	printf("Pessoa.nome: %s\n", pesquisada.nome);

	return 0;
}
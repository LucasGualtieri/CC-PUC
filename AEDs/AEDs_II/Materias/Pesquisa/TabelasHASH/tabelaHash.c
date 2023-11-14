#include <stdio.h>

// clear && gcc tabelaHash.c && ./a.out

#define TAM 7

typedef struct Pessoa {
	int id;
	char nome[80];
} Pessoa;

#define rehash(id) ((id + 1) % TAM)

void InserirHash(Pessoa pessoa, Pessoa* hash) {
	int pos = pessoa.id % TAM;
	if (hash[pos].id != TAM) hash[pos] = pessoa;
	else hash[rehash(pessoa.id)] = pessoa;
	// else printf("Erro ao inserir %s.\n", pessoa.nome);
}

Pessoa PesquisarHash(Pessoa pessoa, Pessoa* hash) {
	int pos = pessoa.id % TAM;
	return hash[pos];
}

void StartHash(Pessoa* hash) {
	Pessoa vazia = { 0, "VAZIA" };
	for (int i = 0; i < TAM; i++) {
		hash[i] = vazia;
	}
}

int main() {

	Pessoa hash[TAM];

	Pessoa lucas = { 7, "Lucas" };
	Pessoa joao = { 21, "João" };

	// printf("nome: %s\n", pessoa.nome);

	InserirHash(lucas, hash);
	InserirHash(joao, hash);

	Pessoa pesquisada = PesquisarHash(joao, hash);
	printf("Pessoa.nome: %s\n", pesquisada.nome);

	return 0;
}
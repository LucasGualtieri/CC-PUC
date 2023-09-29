#include "Split.h"
#include <string.h>

typedef char* String;

typedef struct Jogador {

	int id, altura, peso, anoNascimento;
	String nome;
	String universidade;
	String cidadeNascimento;
	String estadoNascimento;

	// Getter e Setter - Id
	int (*getId) (struct Jogador);
	void (*setId) (int id, struct Jogador*);

	// Getter e Setter - Altura
	int (*getAltura) (struct Jogador);
	void (*setAltura) (String altura, struct Jogador*);

	// Getter e Setter - Peso
	int (*getPeso) (struct Jogador);
	void (*setPeso) (String peso, struct Jogador*);

	// Getter e Setter - AnoNascimento
	int (*getAnoNascimento) (struct Jogador);
	void (*setAnoNascimento) (String anoNascimento, struct Jogador*);

	// Getter e Setter - Nome
	String (*getNome) (struct Jogador);
	void (*setNome) (String nome, struct Jogador*);

	// Getter e Setter - Universidade
	String (*getUniversidade) (struct Jogador);
	void (*setUniversidade) (String universidade, struct Jogador*);

	// Getter e Setter - CidadeNascimento
	String (*getCidadeNascimento) (struct Jogador);
	void (*setCidadeNascimento) (String cidadeNascimento, struct Jogador*);

	// Getter e Setter - EstadoNascimento
	String (*getEstadoNascimento) (struct Jogador);
	void (*setEstadoNascimento) (String estadoNascimento, struct Jogador*);

	void (*Construtor) (Split array, struct Jogador*);
	struct Jogador (*Clone) (struct Jogador);
	void (*Mostrar) (struct Jogador);
	void (*Close) (struct Jogador);

} Jogador;

// Getter e Setter - Id
int GetIdJogador(Jogador jogador) { return jogador.id; }
void SetIdJogador(int id, Jogador* jogador) { jogador->id = id; }

// Getter e Setter - Nome
String GetNomeJogador(Jogador jogador) { return jogador.nome; }
void SetNomeJogador(String nome, Jogador* jogador) { jogador->nome = strdup(nome); }

// Getter e Setter - Altura
int GetAlturaJogador(Jogador jogador) { return jogador.altura; }
void SetAlturaJogador(String altura, Jogador* jogador) {
	if (!strcmp(altura, "nao informado")) {
		jogador->altura = -1;
		return;
	}
	jogador->altura = atoi(altura);
}

// Getter e Setter - Peso
int GetPesoJogador(Jogador jogador) { return jogador.peso; }
void SetPesoJogador(String peso, Jogador* jogador) {
	if (!strcmp(peso, "nao informado")) {
		jogador->peso = -1;
		return;
	}
	jogador->peso = atoi(peso);
}

// Getter e Setter - AnoNascimento
int GetAnoNascimentoJogador(Jogador jogador) { return jogador.anoNascimento; }
void SetAnoNascimentoJogador(String anoNascimento, Jogador* jogador) {
	if (!strcmp(anoNascimento, "nao informado")) {
		jogador->anoNascimento = -1;
		return;
	}
	jogador->anoNascimento = atoi(anoNascimento);
}

// Getter e Setter - Universidade
String GetUniversidadeJogador(Jogador jogador) { return jogador.universidade; }
void SetUniversidadeJogador(String universidade, Jogador* jogador) {
	jogador->universidade = strdup(universidade);
}

// Getter e Setter - CidadeNascimento
String GetCidadeNascimentoJogador(Jogador jogador) { return jogador.cidadeNascimento; }
void SetCidadeNascimentoJogador(String cidadeNascimento, Jogador* jogador) {
	jogador->cidadeNascimento = strdup(cidadeNascimento);
}

// Getter e Setter - EstadoNascimento
String GetEstadoNascimentoJogador(Jogador jogador) { return jogador.estadoNascimento; }
void SetEstadoNascimentoJogador(String estadoNascimento, Jogador* jogador) {
	jogador->estadoNascimento = strdup(estadoNascimento);
}

void ConstrutorJogador(Split split, Jogador* jogador) {

	jogador->setId(atoi(split.array[0]), jogador);
	jogador->setNome(split.array[1], jogador);
	jogador->setAltura(split.array[2], jogador);
	jogador->setPeso(split.array[3], jogador);
	jogador->setUniversidade(split.array[4], jogador);
	jogador->setAnoNascimento(split.array[5], jogador);
	jogador->setCidadeNascimento(split.array[6], jogador);
	jogador->setEstadoNascimento(split.array[7], jogador);

}

Jogador CloneJogador(Jogador jogador) {

	Jogador clone = jogador;

	clone.setNome(jogador.getNome(jogador), &clone);
	clone.setUniversidade(jogador.getUniversidade(jogador), &clone);
	clone.setCidadeNascimento(jogador.getCidadeNascimento(jogador), &clone);
	clone.setEstadoNascimento(jogador.getEstadoNascimento(jogador), &clone);

	return clone;

}

void MostrarJogador(Jogador jogador) {
	printf("[%d ## ", jogador.getId(jogador));
	printf("%s ## ", jogador.getNome(jogador));
	printf("%d ## ", jogador.getAltura(jogador));
	printf("%d ## ", jogador.getPeso(jogador));
	printf("%d ## ", jogador.getAnoNascimento(jogador));
	printf("%s ## ", jogador.getUniversidade(jogador));
	printf("%s ## ", jogador.getCidadeNascimento(jogador));
	printf("%s]\n", jogador.getEstadoNascimento(jogador));
}

void CloseJogador(Jogador jogador) {

	free(jogador.getNome(jogador));
	free(jogador.getUniversidade(jogador));
	free(jogador.getCidadeNascimento(jogador));
	free(jogador.getEstadoNascimento(jogador));
}

Jogador newJogador() {

	Jogador jogador;

	jogador.getId = GetIdJogador;
	jogador.setId = SetIdJogador;

	jogador.getAltura = GetAlturaJogador;
	jogador.setAltura = SetAlturaJogador;

	jogador.getPeso = GetPesoJogador;
	jogador.setPeso = SetPesoJogador;
	
	jogador.getAnoNascimento = GetAnoNascimentoJogador;
	jogador.setAnoNascimento = SetAnoNascimentoJogador;

	jogador.getNome = GetNomeJogador;
	jogador.setNome = SetNomeJogador;

	jogador.getUniversidade = GetUniversidadeJogador;
	jogador.setUniversidade = SetUniversidadeJogador;

	jogador.getCidadeNascimento = GetCidadeNascimentoJogador;
	jogador.setCidadeNascimento = SetCidadeNascimentoJogador;

	jogador.getEstadoNascimento = GetEstadoNascimentoJogador;
	jogador.setEstadoNascimento = SetEstadoNascimentoJogador;

	jogador.Construtor = ConstrutorJogador;
	jogador.Clone = CloneJogador;
	jogador.Mostrar = MostrarJogador;
	jogador.Close = CloseJogador;

	return jogador;
}
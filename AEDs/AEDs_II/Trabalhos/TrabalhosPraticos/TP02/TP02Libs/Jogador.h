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
	void (*setAltura) (int altura, struct Jogador*);

	// Getter e Setter - Peso
	int (*getPeso) (struct Jogador);
	void (*setPeso) (int peso, struct Jogador*);

	// Getter e Setter - AnoNascimento
	int (*getAnoNascimento) (struct Jogador);
	void (*setAnoNascimento) (int anoNascimento, struct Jogador*);

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

	void (*Mostrar) (struct Jogador);

} Jogador;

// Getter e Setter - Id
int GetIdJogador(Jogador jogador) { return jogador.id; }
void SetIdJogador(int id, Jogador* jogador) { jogador->id = id; }

// Getter e Setter - Altura
int GetAlturaJogador(Jogador jogador) { return jogador.altura; }
void SetAlturaJogador(int altura, Jogador* jogador) { jogador->altura = altura; }

// Getter e Setter - Peso
int GetPesoJogador(Jogador jogador) { return jogador.peso; }
void SetPesoJogador(int peso, Jogador* jogador) { jogador->peso = peso; }

// Getter e Setter - AnoNascimento
int GetAnoNascimentoJogador(Jogador jogador) { return jogador.anoNascimento; }
void SetAnoNascimentoJogador(int anoNascimento, Jogador* jogador) { jogador->anoNascimento = anoNascimento; }

// Getter e Setter - Nome
String GetNomeJogador(Jogador jogador) { return jogador.nome; }
void SetNomeJogador(String nome, Jogador* jogador) { jogador->nome = nome; }

// Getter e Setter - Universidade
String GetUniversidadeJogador(Jogador jogador) { return jogador.universidade; }
void SetUniversidadeJogador(String universidade, Jogador* jogador) { jogador->universidade = universidade; }

// Getter e Setter - CidadeNascimento
String GetCidadeNascimentoJogador(Jogador jogador) { return jogador.cidadeNascimento; }
void SetCidadeNascimentoJogador(String cidadeNascimento, Jogador* jogador) { jogador->cidadeNascimento = cidadeNascimento; }

// Getter e Setter - EstadoNascimento
String GetEstadoNascimentoJogador(Jogador jogador) { return jogador.estadoNascimento; }
void SetEstadoNascimentoJogador(String estadoNascimento, Jogador* jogador) { jogador->estadoNascimento = estadoNascimento; }

void MostrarJogador(Jogador jogador) {
	printf("[ ");
	printf("%d ## ", jogador.getId(jogador));
	printf("%d ## ", jogador.getAltura(jogador));
	printf("%d ## ", jogador.getPeso(jogador));
	printf("%d ## ", jogador.getAnoNascimento(jogador));
	printf("%s ## ", jogador.getNome(jogador));
	printf("%s ## ", jogador.getUniversidade(jogador));
	printf("%s ## ", jogador.getCidadeNascimento(jogador));
	printf("%s ##", jogador.getEstadoNascimento(jogador));
	printf("]\n");
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

	jogador.Mostrar = MostrarJogador;

	return jogador;
}
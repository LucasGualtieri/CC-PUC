import java.util.*;
import java.io.File;
import java.time.Instant;
import java.time.Duration;
import java.io.FileWriter;
import java.io.PrintWriter;

class TP03Q06Verde {

	static void InserirERemover(String action, Lib.PilhaFlex pilha, Lib.Lista BD) throws Exception {

		String[] actions = action.split(" ");

		if (actions[0].equals("I")) {
			pilha.Inserir(BD.Get(actions[1]));
		} else {
			System.out.printf("(R) %s\n", pilha.Remover().getNome());
		}

	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Lista BD = new Lib.Lista("/tmp/players.csv", BD_SIZE);
		Lib.PilhaFlex pilha = new Lib.PilhaFlex();

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			pilha.Inserir(BD.Get(id));
		}

		int numberOfActions = Lib.readInt();

		for (int i = 0; i < numberOfActions; i++) {
			InserirERemover(Lib.readStr(), pilha, BD);
		}

		pilha.Mostrar();

	}
}

class Lib {

	// --------------------------- FUNÇÕES AUXILIARES ---------------------------

	static Scanner scanner = new Scanner(System.in);

	public static String readStr() {
		return scanner.nextLine();
	}

	public static int readInt() {
		int integer = scanner.nextInt();
		scanner.nextLine(); // Flushing
		return integer;
	}

	// --------------------------- CLASSE TIMER ---------------------------

	public static class Timer {
	
		private Instant startTime, endTime;

		public Timer() {}
		
		public void Start() { this.startTime = Instant.now(); }

		public void Stop() {
			this.endTime = Instant.now();
		}
		
		public double Time() {
			return Duration.between(startTime, endTime).getNano() / 1000000000.0;
		}

	}

	// --------------------------- CLASSE LOG ---------------------------

	public static class Log {
		private static int comparacoes, movimentacoes;

		public Log() {
			this(0, 0);
		}
		
		public Log(int comparacoes, int movimentacoes) {
			this.comparacoes = comparacoes;
			this.movimentacoes = movimentacoes;
		}

		public static void RegistroPesquisa(String fileName, Lib.Timer timer) throws Exception {

			PrintWriter printWriter = new PrintWriter(new FileWriter(fileName));

			printWriter.printf("Matrícula: 794989\t");
			printWriter.printf("Tempo de execução: %fs\t", timer.Time());
			printWriter.printf("Número de comparações: %d", comparacoes);

			printWriter.close();
				
		}

		public static void RegistroOrdenacao(String fileName, Lib.Timer timer) throws Exception {

			PrintWriter printWriter = new PrintWriter(new FileWriter(fileName));

			printWriter.printf("Matrícula: 794989\t");
			printWriter.printf("Tempo de execução: %fs\t", timer.Time());
			printWriter.printf("Número de comparações: %d\t", comparacoes);
			printWriter.printf("Número de movimentações: %d", movimentacoes);

			printWriter.close();
				
		}

		public void incrementarComparacoes() { this.comparacoes++; }
		public void incrementarComparacoes(int incremento) { this.comparacoes += incremento; }
		public void incrementarMovimentacoes() { this.movimentacoes++; }
		public void incrementarMovimentacoes(int incremento) {
			this.movimentacoes += incremento;
		}
	}

	// --------------------------- CLASSE JOGADOR ---------------------------

	public static class Jogador {
		private int id, altura, peso, anoNascimento;
		private String nome, universidade, cidadeNascimento, estadoNascimento;
		private String atributoStr;
		private int atributoInt;

		public Jogador() {}

		// Usado no MergeSort
		public Jogador(String sentinela) {
			this.atributoStr = sentinela;
		}

		public Jogador(String[] array) {
			this.setId(array[0]);
			this.setNome(array[1]);
			this.setAltura(array[2]);
			this.setPeso(array[3]);
			this.setUniversidade(array[4]);
			this.setAnoNascimento(array[5]);
			this.setCidadeNascimento(array[6]);
			this.setEstadoNascimento(array[7]);
		}

		// Getter e Setter - Id
		public int getId() { return this.id; }
		public void setId(String id) { this.id = Integer.parseInt(id); }
		public void setId(int id) { this.id = id; }
		
		// Getter e Setter - Nome
		public String getNome() { return this.nome; }
		public void setNome(String nome) { this.nome = nome; }

		// Getter e Setter - Altura
		public int getAltura() { return this.altura; }
		public void setAltura(int altura) { this.altura = altura; }
		public void setAltura(String altura) {
			if (altura.equals("nao informado")) {
				this.altura = -1;
				return;
			}
			this.altura = Integer.parseInt(altura);
		}

		// Getter e Setter - Peso
		public int getPeso() { return this.peso; }
		public void setPeso(int peso) { this.peso = peso; }
		public void setPeso(String peso) {
			if (peso.equals("nao informado")) {
				this.peso = -1;
				return;
			}
			this.peso = Integer.parseInt(peso);
		}

		// Getter e Setter - AnoNascimento
		public int getAnoNascimento() { return this.anoNascimento; }
		public void setAnoNascimento(int anoNascimento) { this.anoNascimento = anoNascimento; }
		public void setAnoNascimento(String anoNascimento) {
			if (anoNascimento.equals("nao informado")) {
				this.anoNascimento = -1;
				return;
			}
			this.anoNascimento = Integer.parseInt(anoNascimento);
		}

		// Getter e Setter - Universidade
		public String getUniversidade() { return this.universidade; }
		public void setUniversidade(String universidade) {
			this.universidade = universidade;
		}

		// Getter e Setter - CidadeNascimento
		public String getCidadeNascimento() { return this.cidadeNascimento; }
		public void setCidadeNascimento(String cidadeNascimento) {
			this.cidadeNascimento = cidadeNascimento;
		}

		// Getter e Setter - EstadoNascimento
		public String getEstadoNascimento() { return this.estadoNascimento; }
		public void setEstadoNascimento(String estadoNascimento) {
			this.estadoNascimento = estadoNascimento;
		}

		public Jogador Clone() {
			Jogador clone = new Jogador();

			clone.setId(this.getId());
			clone.setNome(this.getNome());
			clone.setAltura(this.getAltura());
			clone.setPeso(this.getPeso());
			clone.setUniversidade(this.getUniversidade());
			clone.setAnoNascimento(this.getAnoNascimento());
			clone.setCidadeNascimento(this.getCidadeNascimento());
			clone.setEstadoNascimento(this.getEstadoNascimento());

			return clone;

		}

		public void Mostrar() {
			// System.out.printf("[%d ## ", this.getId());
			System.out.printf("%s ## ", this.getNome());
			System.out.printf("%d ## ", this.getAltura());
			System.out.printf("%d ## ", this.getPeso());
			System.out.printf("%d ## ", this.getAnoNascimento());
			System.out.printf("%s ## ", this.getUniversidade());
			System.out.printf("%s ## ", this.getCidadeNascimento());
			System.out.printf("%s ##\n", this.getEstadoNascimento());
		}

	}

	// --------------------------- CLASSE LISTA ---------------------------

	public static class Lista {
		private int maxSize, size;
		private Jogador[] array;

		public Lista(String filePath, int size) throws Exception {
			this(size);
			this.ImportDataBase(filePath);
		}

		public Lista(int size) {
			this.array = new Jogador[size];
			this.maxSize = size;
			this.size = 0;
		}

		public int getSize() { return this.size; }

		public Jogador Get(int id) { return this.array[id]; }
		public Jogador Get(String id) {
			return this.array[Integer.parseInt(id)];
		}

		void ImportDataBase(String filePath) throws Exception {
		
			Scanner fileReader = new Scanner(new File(filePath));

			String inputCSV = new String();
			fileReader.nextLine(); // Despresando o header do .csv

			while (fileReader.hasNextLine()) {
				
				inputCSV = fileReader.nextLine();
				String[] array = inputCSV.split(",", -1);

				for (int i = 1; i < array.length; i++) {
					if (array[i].isEmpty()) {
						array[i] = "nao informado";
					}
				}

				this.InserirFim(new Jogador(array));
			}

		}

		public void Mostrar() {
			if (this.size == 0) {
				System.out.println("Erro ao mostrar: Fila vazia.");
				return;
			}

			for (int i = 0; i < this.size; i++) {
				System.out.printf("[%d] ## ", i);
				this.array[i].Mostrar();
			}
		}

		// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

		public void InserirInicio(Jogador jogador) throws Exception {

			if (size == maxSize) {
				throw new Exception("Erro ao inserir: Lista cheia.");
			}

			for (int i = size; i > 0; i--) array[i] = array[i - 1];

			array[0] = jogador.Clone();

			size++;

		}

		public void InserirFim(Jogador jogador) throws Exception {

			if (size == maxSize) {
				throw new Exception("Erro ao inserir: Fila cheia.\n");
			}

			array[size++] = jogador.Clone();

		}
		
		public void Inserir(String posStr, Jogador jogador) throws Exception {

			if (size == maxSize) {
				throw new Exception("Erro ao inserir: Lista cheia.");
			}

			int pos = Integer.parseInt(posStr);

			for (int i = size; i > pos; i--) array[i] = array[i - 1];

			array[pos] = jogador.Clone();

			size++;

		}

		public Jogador RemoverInicio() throws Exception {
			if (size == 0) {
				throw new Exception("Erro ao remover: Lista vazia.");
			}

			Jogador tmp = array[0];

			for (int i = 0; i < size - 1; i++) array[i] = array[i + 1];

			size--;

			return tmp;
		}

		public Jogador RemoverFim() throws Exception {
			if (size == 0) {
				throw new Exception("Erro ao remover: Lista vazia.");
			}
			
			return array[--size];
		}

		public Jogador Remover(String posStr) throws Exception {
			if (size == 0) {
				throw new Exception("Erro ao remover: Lista vazia.");
			}

			int pos = Integer.parseInt(posStr);

			Jogador tmp = array[pos];

			for (int i = pos; i < size - 1; i++) array[i] = array[i + 1];

			size--;

			return tmp;
		}

	}

	// --------------------------- CLASSE PILHA ---------------------------

	public static class Pilha {
		private Lista lista;

		public Pilha(int size) { this.lista = new Lista(size); }

		public int getSize() { return this.lista.getSize(); }

		public void Mostrar() { this.lista.Mostrar(); }

		// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

		public void Inserir(Jogador jogador) throws Exception {
			this.lista.InserirFim(jogador);
		}

		public Jogador Remover() throws Exception {
			return this.lista.RemoverFim();
		}

	}

	// --------------------------- CLASSE CELULA ---------------------------
	
	public static class Celula {
		private Jogador jogador;
		private Celula prox, baixo;
		public Celula() { this.prox = null; }
		public Celula(Jogador jogador) { this.jogador = jogador.Clone(); }
		public Celula(Jogador jogador, Celula prox) {
			this.jogador = jogador.Clone();
			this.prox = this.baixo = prox;
		}
	}

	// --------------------------- CLASSE LISTA FLEX ---------------------------

	public static class ListaFlex {
		private int size;
		private Celula primeiro, ultimo;

		public ListaFlex() {
			primeiro = ultimo = new Celula();
			size = 0;
		}

		public int getSize() { return this.size; }

		public void Mostrar() throws Exception {

			if (this.primeiro == this.ultimo) {
				throw new Exception("Erro ao mostrar: Lista vazia.");
			}

			int contador = 0;
			for (Celula i = this.primeiro.prox; i != null; i = i.prox) {
				System.out.printf("[%d] ## ", contador++);
				i.jogador.Mostrar();
			}

		}

		// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

		public void InserirInicio(Jogador jogador) {

			Celula newCelula = new Celula(jogador, primeiro.prox);
			if (primeiro == ultimo) ultimo = newCelula;
			primeiro.prox = newCelula;
			this.size++;

		}

		public void InserirFim(Jogador jogador) {

			Celula newCelula = new Celula(jogador, null);
			ultimo = ultimo.prox = newCelula;
			this.size++;

		}
		
		public void Inserir(String posStr, Jogador jogador) {

			int pos = Integer.parseInt(posStr);

			Celula i = primeiro.prox;
			for (int count = 0; count < pos - 1; count++, i = i.prox);

			i.prox = new Celula(jogador, i.prox);

			this.size++;

		}

		public Jogador RemoverInicio() throws Exception {

			if (this.primeiro == this.ultimo) {
				throw new Exception("Erro ao remover: Lista Flex vazia.");
			}

			Celula removido = primeiro.prox;
			primeiro.prox = removido.prox;

			this.size--;

			return removido.jogador;

		}

		public Jogador RemoverFim() throws Exception {

			if (this.primeiro == this.ultimo) {
				throw new Exception("Erro ao remover: Lista Flex vazia.");
			}
			
			Celula removido, i;
			for (i = primeiro; i.prox.prox != null; i = i.prox);

			removido = i.prox;
			i.prox = removido.prox;

			this.size--;

			return removido.jogador;

		}

		public Jogador Remover(String posStr) throws Exception {

			int pos = Integer.parseInt(posStr);

			if (this.primeiro == this.ultimo) {
				throw new Exception("Erro ao remover: Lista Flex vazia.");
			} else if (0 > pos || pos >= this.size) {
				throw new Exception("Erro ao remover: Posição inválida.");
			} else if (pos == 0) {
				return this.RemoverInicio();
			} else if (pos == this.size - 1) {
				return this.RemoverFim();
			}

			Celula removido, i = primeiro.prox;
			for (int count = 0; count < pos - 1; count++, i = i.prox);

			removido = i.prox;
			i.prox = removido.prox;

			this.size--;

			return removido.jogador;

		}
	}

	// --------------------------- CLASSE PILHA FLEX ---------------------------

	public static class PilhaFlex {
		private int size;
		private Celula topo;

		public PilhaFlex() {
			topo = null;
			size = 0;
		}

		public int getSize() { return this.size; }

		public void Mostrar() throws Exception {
			if (this.topo == null) {
				throw new Exception("Erro ao mostrar: Pilha vazia.");
			}

			MostrarRec(size - 1, topo);
		}

		private void MostrarRec(int contador, Celula i) {
			if (i.baixo != null) MostrarRec(contador - 1, i.baixo);
			System.out.printf("[%d] ## ", contador);
			i.jogador.Mostrar();
		}

		// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

		public void Inserir(Jogador jogador) {
			topo = new Celula(jogador, topo);
			this.size++;	
		}

		public Jogador Remover() throws Exception {

			if (this.topo == null) {
				throw new Exception("Erro ao remover: Pilha Flex vazia.");
			}

			Celula removido = topo;
			topo = topo.baixo;

			this.size--;

			return removido.jogador;

		}

	}
}
package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.TP04Q01;

import java.util.*;
import java.time.Instant;
import java.time.Duration;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

// clear && javac -cp ../.. TP04Q01.java && java -cp ../.. TP04Q01.java < pub.in > result.txt

class TP04Q01Verde {

	static public boolean Pesquisar(Arvore arvore, String chave, Lib.Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}
		System.out.printf("%s raiz ", chave);
		return Pesquisar(arvore.getRaiz(), chave, log);
	}
	
	static private boolean Pesquisar(No raiz, String chave, Lib.Log log) {

		boolean resultado;
		
		if (raiz == null) {
			resultado = false;
		} else if (Arvore.CompareTo(chave, raiz, log) < 0) {
			System.out.printf("esq ");
			resultado = Pesquisar(raiz.esq, chave, log);
		} else if (Arvore.CompareTo(chave, raiz, log) > 0) {
			System.out.printf("dir ");
			resultado = Pesquisar(raiz.dir, chave, log);
		} else {
			resultado = true;
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {

		Lib.BD BD = new Lib.BD("/tmp/players.csv");
		Arvore arvore = new Arvore();
		
		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore.Inserir(BD.Get(id));
		}

		Lib.Log log = new Lib.Log();
		Lib.Timer timer = new Lib.Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean resultado = Pesquisar(arvore, inputPUBIN, log);
			System.out.println(resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_arvoreBinaria.txt", timer);
	}
}

class Lib {

	// --------------------------- FUNÇÕES AUXILIARES ---------------------------

	static Scanner scanner = new Scanner(System.in);

	public static String readStr() {
		return scanner.nextLine();
	}

	public static int readInt(boolean flush) {
		int integer = scanner.nextInt();
		if (flush) scanner.nextLine(); // Flushing
		return integer;
	}

	public static int readInt() {
		int integer = scanner.nextInt();
		scanner.nextLine();
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
		private int comparacoes, movimentacoes;

		public Log() {
			this(0, 0);
		}
		
		public Log(int comparacoes, int movimentacoes) {
			this.comparacoes = comparacoes;
			this.movimentacoes = movimentacoes;
		}

		public void RegistroPesquisa(String fileName, Lib.Timer timer) throws Exception {

			PrintWriter printWriter = new PrintWriter(new FileWriter(fileName));

			printWriter.printf("Matrícula: 794989\t");
			printWriter.printf("Tempo de execução: %fs\t", timer.Time());
			printWriter.printf("Número de comparações: %d", comparacoes);

			printWriter.close();
				
		}

		public void RegistroOrdenacao(String fileName, Lib.Timer timer) throws Exception {

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

	// --------------------------- CLASSE BD ---------------------------

	public static class BD {
		private Jogador[] array;
		private int size;
		private static final int BD_SIZE = 3922;

		public BD(String filePath) throws Exception {
			this.size = 0;
			this.array = new Jogador[BD_SIZE];
			this.ImportDataBase(filePath);
		}

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

			fileReader.close();
		}

		public void InserirFim(Jogador jogador) throws Exception {

			array[size++] = jogador.Clone();

		}
	}

	// --------------------------- CLASSE JOGADOR ---------------------------

	public static class Jogador {
		private int id, altura, peso, anoNascimento;
		private String nome, universidade, cidadeNascimento, estadoNascimento;

		public Jogador() {}

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

		public void MostrarQuickSort() {
			System.out.printf("[%d ## ", this.getId());
			System.out.printf("%s ## ", this.getNome());
			System.out.printf("%d ## ", this.getAltura());
			System.out.printf("%d ## ", this.getPeso());
			System.out.printf("%d ## ", this.getAnoNascimento());
			System.out.printf("%s ## ", this.getUniversidade());
			System.out.printf("%s ## ", this.getCidadeNascimento());
			System.out.printf("%s]\n", this.getEstadoNascimento());
		}

	}

}

class No {

	public Lib.Jogador jogador;

	public No esq, dir;

	public No(Lib.Jogador jogador) { 
		this.jogador = jogador;
		this.esq = this.dir = null;
	}
}

class Arvore {

	private int size;
	private No raiz;

	public Arvore() {
		this.size = 0;
		this.raiz = null;
	}

	public No getRaiz() { return this.raiz; }

	public int getSize() { return this.size; }

	public void Mostrar() throws Exception {

		if (this.raiz == null) {
			throw new Exception("Erro ao printar na Árvore: Árvore vazia.");
		}

		Mostrar(raiz);
	}

	private void Mostrar(No raiz) {

		if (raiz != null) {
			Mostrar(raiz.esq);
			System.out.println(raiz.jogador.getNome());
			Mostrar(raiz.dir);
		}
	}

	private int CompareTo(Lib.Jogador jog, No raiz, Lib.Log log) {
		log.incrementarComparacoes();
		return jog.getNome().compareTo(raiz.jogador.getNome());
	}

	public static int CompareTo(String string, No raiz, Lib.Log log) {
		log.incrementarComparacoes();
		return string.compareTo(raiz.jogador.getNome());
	}

	public void Inserir(Lib.Jogador jogador) throws Exception {
		Lib.Log log = new Lib.Log();
		this.raiz = Inserir(jogador, this.raiz, log);
		this.size++;
	}

	public void Inserir(Lib.Jogador jogador, Lib.Log log) throws Exception {
		this.raiz = Inserir(jogador, this.raiz, log);
		this.size++;
	}

	private No Inserir(Lib.Jogador jogador, No raiz, Lib.Log log) throws Exception {

		if (raiz == null) {
			raiz = new No(jogador);
		} else if (CompareTo(jogador, raiz, log) > 0) {
			raiz.dir = Inserir(jogador, raiz.dir, log);
		} else if (CompareTo(jogador, raiz, log) < 0) {
			raiz.esq = Inserir(jogador, raiz.esq, log);
		} else {
			String nome = jogador.getNome();
			String erro = "Erro ao inserir na Árvore: Valor " + nome + " repetido.";
			throw new Exception(erro);
		}
		
		return raiz;
	}

}
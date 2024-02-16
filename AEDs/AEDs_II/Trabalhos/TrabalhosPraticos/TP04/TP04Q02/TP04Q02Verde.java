package TP04.TP04Q02;

import java.util.*;
import java.time.Instant;
import java.time.Duration;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

// clear && javac -cp ../.. TP04Q02Verde.java && java -cp ../.. TP04Q02Verde.java < pub.in > result.txt

class TP04Q02Verde {

	static public boolean Pesquisar(ArvoreArvore arvore, String nome, Lib.Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}

		System.out.printf("%s raiz ", nome);
		return Pesquisar(arvore.getRaiz(), nome, log);
	}

	static private boolean Pesquisar(No1 raiz, String nome, Lib.Log log) {

		boolean resultado = false;

		if (raiz != null) {

			resultado = Pesquisar(raiz.raiz, nome, log);

			if (!resultado) {
				System.out.printf("esq ");
				resultado = Pesquisar(raiz.esq, nome, log);
			}

			if (!resultado) {
				System.out.printf("dir ");
				resultado = Pesquisar(raiz.dir, nome, log);
			}
		}

		return resultado;
	}

	static private boolean Pesquisar(No2 raiz, String nome, Lib.Log log) {

		boolean resultado = false;

		if (raiz != null) {

			resultado = ArvoreArvore.CompareTo(nome, raiz, log) == 0;

			if (!resultado) {
				System.out.printf("ESQ ");
				resultado = Pesquisar(raiz.esq, nome, log);
			}

			if (!resultado) {
				System.out.printf("DIR ");
				resultado = Pesquisar(raiz.dir, nome, log);
			}
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {

		// int[] alturas = { 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 };
		int[] alturas = { 7, 3, 11, 1, 5, 9, 12, 0, 2, 4, 6, 8, 10, 13, 14 };

		Lib.BD BD = new Lib.BD("/tmp/players.csv");
		ArvoreArvore arvore = new ArvoreArvore(alturas, BD);

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

		log.RegistroPesquisa("794989_arvoreArvore.txt", timer);
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

class No1 {

	public int alturaMod15;
	public No1 esq, dir;
	public No2 raiz;

	public No1(int altura) { 
		this.alturaMod15 = altura;
		this.raiz = null;
		this.esq = this.dir = null;
	}
}

class No2 {

	public String nome;
	public No2 esq, dir;

	public No2(Lib.Jogador jogador) { 
		this.nome = jogador.getNome();
		this.esq = this.dir = null;
	}
}

class ArvoreArvore {

	private No1 raiz;

	public ArvoreArvore() {
		this.raiz = null;
	}

	public ArvoreArvore(int[] alturas, Lib.BD BD) {
		this.Montar(alturas, BD);
	}

	public void Montar(int[] alturas, Lib.BD BD) {
		for (int altura : alturas) {
			this.raiz = this.Montar(this.raiz, altura);
		}
	}

	private No1 Montar(No1 raiz, int alturaMod15) {

		if (raiz == null) {
			raiz = new No1(alturaMod15);
		} else if (alturaMod15 < raiz.alturaMod15) {
			raiz.esq = Montar(raiz.esq, alturaMod15);
		} else if (alturaMod15 > raiz.alturaMod15) {
			raiz.dir = Montar(raiz.dir, alturaMod15);
		}

		return raiz;
	}

	public No1 getRaiz() { return this.raiz; }

	public static int CompareTo(String nome, No2 raiz, Lib.Log log) {
		log.incrementarComparacoes();
		return nome.compareTo(raiz.nome);
	}

	public static int CompareTo(Lib.Jogador jogador, No2 raiz, Lib.Log log) {
		log.incrementarComparacoes();
		return jogador.getNome().compareTo(raiz.nome);
	}

	public static int CompareTo(Lib.Jogador jogador, No2 raiz) {
		return jogador.getNome().compareTo(raiz.nome);
	}

	public void Mostrar() throws Exception {

		if (this.raiz == null) {
			throw new Exception("Erro ao mostrar Árvore: Árvore vazia.");
		}

		System.out.print("{ ");
		Mostrar(this.raiz);
		System.out.println("\b\b }");
	}

	private void Mostrar(No1 raiz) {

		if (raiz != null) {
			Mostrar(raiz.esq);
			System.out.printf("%d, ", raiz.alturaMod15);
			Mostrar(raiz.dir);
		}
	}

	public void MostrarSub() throws Exception {

		if (this.raiz == null) {
			throw new Exception("Erro ao mostrar Sub Árvores: Árvore vazia.");
		}

		MostrarSub(this.raiz);
	}

	private void MostrarSub(No1 raiz) {

		if (raiz != null) {
			MostrarSub(raiz.esq);
			System.out.printf("AlturaMod15 - %d: \n", raiz.alturaMod15);
			MostrarSub(raiz.raiz);
			System.out.println("-----------------");
			MostrarSub(raiz.dir);
		}
	}

	private void MostrarSub(No2 raiz) {

		if (raiz != null) {
			MostrarSub(raiz.esq);
			System.out.println(raiz.nome);
			MostrarSub(raiz.dir);
		}
	}

	public void Inserir(Lib.Jogador jogador) throws Exception {
		No1 pesquisado = Pesquisar(this.raiz, jogador.getAltura() % 15);
		pesquisado.raiz = Inserir(pesquisado.raiz, jogador);
	}

	private No1 Pesquisar(No1 raiz, int alturaMod15) {

		No1 pesquisado = raiz;

		if (alturaMod15 % 15 < raiz.alturaMod15) {
			pesquisado = Pesquisar(raiz.esq, alturaMod15);
		} else if (alturaMod15 % 15 > raiz.alturaMod15) {
			pesquisado = Pesquisar(raiz.dir, alturaMod15);
		}

		return pesquisado;
	}

	private No2 Inserir(No2 raiz, Lib.Jogador jogador) throws Exception {

		if (raiz == null) {
			raiz = new No2(jogador);
		} else if (CompareTo(jogador, raiz) < 0) {
			raiz.esq = Inserir(raiz.esq, jogador);
		} else if (CompareTo(jogador, raiz) > 0) {
			raiz.dir = Inserir(raiz.dir, jogador);
		} else {
			String nome = jogador.getNome();
			String erro = "Erro ao inserir na Árvore: Jogador " + nome + " repetido.";
			throw new Exception(erro);
		}
		
		return raiz;
	}
}
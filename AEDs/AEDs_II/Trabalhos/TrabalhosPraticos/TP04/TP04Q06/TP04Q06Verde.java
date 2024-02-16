package TP04.TP04Q06;

import java.util.*;
import java.time.Instant;
import java.time.Duration;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

// clear && javac -cp ../.. TP04Q06.java && java -cp ../.. TP04Q06.java < pub.in > result.txt

class TP04Q06Verde {

    private static boolean Pesquisar(String nome, Trie arvore, Lib.Log log) {

		NoTrie atual = arvore.getRaiz();
        boolean resp = false;

        for (int i = 0; i < nome.length(); i++) {

			int index = (int)(nome.charAt(i)) - 32;

            if (atual.filhos[index] == null) resp = false;
            else atual = atual.filhos[index];
			log.incrementarComparacoes();
        }

        resp = atual.ehPalavra;

        return resp;
    }

	public static void main(String[] args) throws Exception {

		Lib.BD BD = new Lib.BD("/tmp/players.csv");
		Trie arvore1 = new Trie();
		Trie arvore2 = new Trie();

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore1.Inserir(BD.Get(id).getNome());
		}

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore2.Inserir(BD.Get(id).getNome());
		}

		Trie merged = new Trie(arvore1, arvore2);

		Lib.Log log = new Lib.Log();
		Lib.Timer timer = new Lib.Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean resultado = Pesquisar(inputPUBIN, merged, log);
			System.out.printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_arvoreTrie.txt", timer);
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
		private boolean ordenado;
		private static final int BD_SIZE = 3922;

		public BD(String filePath) throws Exception {
			this.ordenado = false;
			this.size = 0;
			this.array = new Jogador[BD_SIZE];
			this.ImportDataBase(filePath);
		}

		public Jogador Get(int id) { return this.array[id]; }

		int CompareToStr(String str1, String str2, Log log) {
			log.incrementarComparacoes();
			return str1.compareTo(str2);
		}

		int CompareToStr(int pos, String pivot) {
			return array[pos].getNome().compareTo(pivot);
		}

		private void swap(int i, int j) {
			Jogador aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}

		private void QuickSort(int left, int right) {

			int i = left, j = right;
			Jogador pivot = array[(right + left) / 2];
		
			while (i <= j) {
				while (CompareToStr(i, pivot.getNome()) < 0) i++;
				while (CompareToStr(j, pivot.getNome()) > 0) j--;
				if (i <= j) swap(i++, j--);
			}
		
			if (left < j)  QuickSort(left, j);
			if (i < right)  QuickSort(i, right);
		}
		
		public void OrdenarPorNome() {
			this.ordenado = true;
			QuickSort(0, size - 1);
		}

		public void Mostrar() {
			System.out.println("Banco de Dados:");
			for (Jogador jogador : array) {
				System.out.println(jogador.getNome());
			}
		}

		public Jogador PesquisarPorNomeBinario(String nome, Log log) {

			Jogador pesquisado = null;
			int	esquerda = 0, direita = size - 1, meio;
			
			while (esquerda <= direita) {

				meio = (esquerda + direita) / 2;
				pesquisado = array[meio];

				if (CompareToStr(nome, pesquisado.getNome(), log) < 0) {
					direita = meio - 1;
				} else if (CompareToStr(nome, pesquisado.getNome(), log) > 0) {
					esquerda = meio + 1;
				} else {
					esquerda = direita + 1;
				}
			}

			return pesquisado;
		}

		public Jogador PesquisarPorNome(String nome, Log log) {

			Jogador pesquisado = null;

			if (ordenado) {
				pesquisado = PesquisarPorNomeBinario(nome, log);
			} else {
				// pesquisado = PesquisarPorNomeSequencial(nome);
			}

			return pesquisado;
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


class NoTrie {

    public NoTrie[] filhos;
    public boolean ehPalavra;

    public NoTrie() {
        this.filhos = new NoTrie[95];
        this.ehPalavra = false;
    }
}

class Trie {

	NoTrie raiz;

	public Trie() {
		raiz = new NoTrie();
	}

	public Trie(Trie t1, Trie t2) {
		this();
		this.juntar(t1);
		this.juntar(t2);
	}

	public NoTrie getRaiz() {
		return raiz;
	}

	public void juntar(Trie t) {
		juntar(t.raiz, "");
	}

	private void juntar(NoTrie no, String s) {
		if (no.ehPalavra) {
			this.Inserir(s);
		}
		for (int i = 0; i < no.filhos.length; i++) {
			if (no.filhos[i] != null) {
				juntar(no.filhos[i], s + (char)(i + 32));
			}
		}
	}

	// INSERIR
	public void Inserir(String nome) {
		NoTrie atual = this.raiz;

		for (int i = 0; i < nome.length(); i++) {
			char c = nome.charAt(i);
			int index = c - 32;

			if (atual.filhos[index] == null) {
				NoTrie node = new NoTrie();
				atual.filhos[index] = node;

				atual = node;// avançando o NoTrie
			}
			else {
				atual = atual.filhos[index];
			}

		}

		atual.ehPalavra = true;
	}


	public void pesquisar(String nome)
	{

		if(pesquisar(nome, raiz))
		{
			System.out.println(nome+" SIM");
		}
		else
		{
			System.out.println(nome+" NAO");
		}
		
	}


	private boolean pesquisar(String nome, NoTrie raiz) {
		NoTrie atual = raiz;
		boolean resp = false;

		for (int i = 0; i < nome.length(); i++) {
			char c = nome.charAt(i);
			int index = c - 32;

			if (atual.filhos[index] == null) {
				resp = false;
			}
			else {
				atual = atual.filhos[index];
			}

		}

		if (atual.ehPalavra) {
			resp = true;
		} else {
			resp = false;
		}

		return resp;
	}

}
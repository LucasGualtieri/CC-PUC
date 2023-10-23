import java.util.*;
import java.io.File;
import java.time.Instant;
import java.time.Duration;
import java.io.FileWriter;
import java.io.PrintWriter;

class TP02Q18Verde {

	static void QuickSort(int k, int left, int right, Lib.Log log, Lib.Lista lista) {
		int i = left, j = right;
		Lib.Jogador pivot = lista.array[(right + left) / 2];

		while (i <= j) {
			while (lista.CompareToStr(i, pivot, log) < 0) i++;
			while (lista.CompareToStr(j, pivot, log) > 0) j--;
			if (i <= j) lista.swap(i++, j--, log);
		}

		if (left < j) QuickSort(k, left, j, log, lista);
		if (i < k && i < right) QuickSort(k, i, right, log, lista);
	}

	static void QuickSort(int k, Lib.Log log, Lib.Lista lista) {
		QuickSort(k, 0, lista.getSize() - 1, log, lista);
	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Timer timer = new Lib.Timer();
		Lib.Log log = new Lib.Log();

		Lib.Lista BD = new Lib.Lista("/tmp/players.csv", BD_SIZE);
		Lib.Lista lista = new Lib.Lista(465); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.Inserir(BD.Get(id));
			lista.setAtributoStr(BD.Get(id).getEstadoNascimento());
		}

		int k = 10;

		timer.Start();
		QuickSort(k, log, lista);
		timer.Stop();

		lista.MostrarParcial(k);

		log.RegistroOrdenacao("794989_quicksortParcial.txt", timer);

	}
}

class Lib {

	// --------------------------- FUNÇÕES AUXILIARES ---------------------------

	static Scanner scanner = new Scanner(System.in);

	public static String readStr() {
		return scanner.nextLine();
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

	// --------------------------- CLASSE LISTA ---------------------------

	public static class Lista {
		private int maxSize, size;
		public Jogador[] array;

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

		public void Inserir(Jogador jogador) throws Exception {

			if (this.size == this.maxSize) {
				throw new Exception("Erro ao inserir: Fila cheia.\n");
			}

			this.array[this.size++] = jogador.Clone();

		}

		public void setAtributoStr(String atributoStr) { 
			array[size - 1].atributoStr = atributoStr;
		}

		public void setAtributoInt(int atributoInt) {
			array[size - 1].atributoInt = atributoInt;
		}

		public boolean CompareToInt(int jog1, int jog2, Log log) {
			
			log.incrementarComparacoes(2);
			if (array[jog1].atributoInt != array[jog2].atributoInt) {
				return array[jog1].atributoInt > array[jog2].atributoInt;
			} else {
				return strcmp(array[jog1].nome, array[jog2].nome) > 0;
			}

		}

		public boolean CompareToInt(int jog1, Jogador jog2, Log log) {
			
			log.incrementarComparacoes(2);
			if (array[jog1].atributoInt != jog2.atributoInt) {
				return array[jog1].atributoInt > jog2.atributoInt;
			} else {
				return strcmp(array[jog1].nome, jog2.nome) > 0;
			}

		}

		private int strcmp(String str1, String str2) { return str1.compareTo(str2); }

		public int CompareToStr(int jog1, int jog2, Log log) {
			
			log.incrementarComparacoes();
			int strComp = strcmp(array[jog1].atributoStr, array[jog2].atributoStr);

			if (strComp == 0) {
				log.incrementarComparacoes();
				strComp = strcmp(array[jog1].nome, array[jog2].nome);
			}

			return strComp;
		}

		// Usado no MergeSort
		public boolean CompareToStr(Jogador jog1, Jogador jog2, Log log) {

			log.incrementarComparacoes();
			int strComp = strcmp(jog1.atributoStr, jog2.atributoStr);

			if (strComp == 0) {
				log.incrementarComparacoes();
				strComp = strcmp(jog1.nome, jog2.nome);
			}

			return strComp <= 0;
		}

		public int CompareToStr(int jog1, Jogador jog2, Log log) {
			
			log.incrementarComparacoes();
			int strComp = strcmp(array[jog1].atributoStr, jog2.atributoStr);

			if (strComp == 0) {
				log.incrementarComparacoes();
				strComp = strcmp(array[jog1].nome, jog2.nome);
			}

			return strComp;
		}

		public boolean CompareToStr(int jog1, String str, Log log) {
			log.incrementarComparacoes();
			return array[jog1].atributoStr.contains(str);
		}

		public int CompareToStr(int jog1, int jog2) {
			return strcmp(array[jog1].nome, array[jog2].nome);
		}

		public void swap(int jog1, int jog2, Log log) {
			Jogador aux = array[jog1];
			array[jog1] = array[jog2];
			array[jog2] = aux;
			log.incrementarMovimentacoes(3);
		}

		private void swap(int jog1, int jog2) {
			Jogador aux = array[jog1];
			array[jog1] = array[jog2];
			array[jog2] = aux;
		}

		public void SortByNome() {
			for (int i = 0; i < size - 1; i++) {
				int menor = i;
				for (int j = i; j < size; j++) {
					if (CompareToStr(menor, j) > 0) menor = j;
				}
				swap(i, menor);
			}
		}

		// Tenho que:
		// Implementar o swap tanto para o sortByNome, quanto para todos os outros methdos de ordenação
		// Implementar o compareToInt e compareToStr
		// Criar os dois atributos int atributoInt e String atributoStr
		// Criar o lista.SetAtributoInt e lista.SetAtributoStr
		// Refatorar a classe para ter tipo generico? Tavez implique em uma sintaxe feia com o Lib.Lista<Jogador>

		public void Mostrar() {
			if (this.size == 0) {
				System.out.println("Erro ao mostrar: Fila vazia.");
				return;
			}

			for (int i = 0; i < this.size; i++) {
				this.array[i].Mostrar();
			}
		}

		public void MostrarParcial(int k) {
			if (this.size == 0) {
				System.out.println("Erro ao mostrar: Fila vazia.");
				return;
			}

			for (int i = 0; i < k; i++) {
				this.array[i].Mostrar();
			}
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

				this.Inserir(new Jogador(array));
			}

		}

		public Jogador Get(int id) { return this.array[id]; }

	}

}
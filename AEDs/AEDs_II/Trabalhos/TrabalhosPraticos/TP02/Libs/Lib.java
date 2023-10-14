package TP02.Libs;

import java.util.*;
import java.io.File;
import java.time.Instant;
import java.time.Duration;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Lib {

	// --------------------------- FUNÇÕES AUXILIARES ---------------------------

	static Scanner scanner = new Scanner(System.in);

	public static String readStr() {
		return scanner.nextLine();
	}

	public static void swap(int i, int menor, Lib.Jogador[] array) {
		Lib.Jogador aux = array[i];
		array[i] = array[menor];
		array[menor] = aux;
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
		public void incrementarMovimentacoes(int incremento) {
			this.movimentacoes += incremento;
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
			showOnUpdate = false;
		}

		public int getSize() { return this.size; }

		public void Inserir(Jogador jogador) throws Exception {

			if (this.size == this.maxSize) {
				throw new Exception("Erro ao inserir: Fila cheia.\n");
			}

			this.array[this.size++] = jogador.Clone();

		}

		private int strcmp(Jogador jog1, Jogador jog2) {
			return jog1.getNome().compareTo(jog2.getNome());
		}

		public void SortByNome() {
			for (int i = 0; i < size - 1; i++) {
				int menor = i;
				for (int j = i; j < size; j++) {
					if (array[menor] > array[j]) menor = j;
				}
				swap();
			}
		}

		// Tenho que:
		// Implementar o swap tanto para o sortByNome, quanto para todos os outros methdos de ordenação
		// Implementar o compareToInt e compareToStr
		// Criar os dois atributos int atributoInt e String atributoStr
		// Criar o lista.SetAtributoInt e lista.SetAtributoStr
		// Refatorar a classe para ter tipo generico? Tavez implique em uma sintaxe feia com o Lib.Lista<Jogador>

		public void SortByNome() {
			int j;
			Jogador temp;
			for (int i = 1; i < this.size; i++) {
				temp = array[i];
				j = i - 1;
				while (j >= 0 && strcmp(this.array[j], temp) > 0) {
					this.array[j + 1] = this.array[j--];
				}
				this.array[j + 1] = temp;
			}
		}

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
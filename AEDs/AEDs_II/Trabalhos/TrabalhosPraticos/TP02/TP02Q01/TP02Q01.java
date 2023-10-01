// import TP02.Lib;
import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

// clear && javac -cp ../TP02Libs TP02Q01.java && java -cp ../TP02Libs TP02Q01
// clear && javac TP02Q01.java && java TP02Q01

class Jogador {
	private int id, altura, peso, anoNascimento;
	private String nome, universidade, cidadeNascimento, estadoNascimento;

	public Jogador(String[] array) {
		this.setId(this.array[0]);
		this.setNome(this.array[1]);
		this.setAltura(this.array[2]);
		this.setPeso(this.array[3]);
		this.setUniversidade(this.array[4]);
		this.setAnoNascimento(this.array[5]);
		this.setCidadeNascimento(this.array[6]);
		this.setEstadoNascimento(this.array[7]);
	}

	// Getter e Setter - Id
	public int getId() { return this.id; }
	public void setId(String id) { this.id = Integer.parseInt(id); }
	
	// Getter e Setter - Nome
	public int getNome() { return this.nome; }
	public void setNome(String nome) { this.nome = Integer.parseInt(nome); }

	// Getter e Setter - Altura
	public int getAltura() { return this.altura; }
	public void setAltura(String altura) {
		if (altura.equals("nao informado")) {
			this.altura = -1;
			return;
		}
		this.altura = Integer.parseInt(altura);
	}

	// Getter e Setter - Peso
	public int getPeso() { return this.peso; }
	public void setPeso(String peso) {
		if (peso.equals("nao informado")) {
			this.peso = -1;
			return;
		}
		this.peso = Integer.parseInt(peso);
	}

	// Getter e Setter - AnoNascimento
	public int getAnoNascimento() { return this.anoNascimento; }
	public void setAnoNascimento(String anoNascimento) {
		if (anoNascimento.equals("nao informado")) {
			this.anoNascimento = -1;
			return;
		}
		this.anoNascimento = Integer.parseInt(anoNascimento);
	}

	// Getter e Setter - Universidade
	public String GetUniversidade() { return this.universidade; }
	public void SetUniversidade(String universidade) {
		this.universidade = universidade;
	}

	// Getter e Setter - CidadeNascimento
	public String GetCidadeNascimento() { return this.cidadeNascimento; }
	public void SetCidadeNascimento(String cidadeNascimento) {
		this.cidadeNascimento = cidadeNascimento;
	}

	// Getter e Setter - EstadoNascimento
	public String GetEstadoNascimento() { return this.estadoNascimento; }
	public void SetEstadoNascimento(String estadoNascimento) {
		this.estadoNascimento = estadoNascimento;
	}

	public Jogador Clone() {
		Jogador clone;

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

class Lista {
	Jogador[] array;
	int maxSize, size;
	bool showOnUpdate;

	Lista(String filePath, int size) {
		this(size);
		this.ImportDataBase(filePath);
	}

	Lista(int size) {
		this.array = new Jogador[size];
		this.maxSize = size;
		this.size = 0;
		showOnUpdate = false;
	}

	public void Inserir(Jogador jogador) throws Exception {

		if (this.size == this.maxSize) {
			throw new Exception("Erro ao inserir: Fila fechada.\n");
		}

		this.array[this.size++] = jogador.Clone();

		if (this.showOnUpdate) this.Mostrar();

	}

	public Jogador Remover() throws Exception {

		if (this.size == 0) {
			throw new Exception("Erro ao remover: Fila vazia.\n");
		}

		Jogador removido = this.array[0];

		for (int i = 0; i < this.size - 1; i++) {
			this.array[i] = this.array[i + 1];
		}

		this.size--;

		if (this.showOnUpdate) this.Mostrar();

		return removido;

	}

	private int strcmp(Jogador jog1, Jogador jog2) {
		return jog1.getNome().compareTo(jog2.getNome());
	}

	public void Sort() {
		int j;
		Jogador temp;
		for (int i = 1; i < N; i++) {
			temp = array[i];
			j = i - 1;
			while (j >= 0 && strcmp(array[j], temp) > 0) {
				array[j-- + 1] = array[j];
			}
			array[j + 1] = temp;
		}
	}

	void ImportDataBase(String filePath) {
		Scanner fileReader = new Scanner(new File(filePath));
		// try {
		// 	fileReader = new Scanner(new File(filePath));
		// } catch (FileNotFoundException e) {
		// 	System.out.println("Erro: Falha ao abrir players.csv\n");
		// 	System
		// }

		String inputCSV = new String();
		inputCSV = fileReader.nextLine(); // Despresando o header do .csv

		Jogador jogador;

		while (fileReader.hasNextLine()) {
			String array = inputCSV.split(",", -1);
			jogador = new Jogador(array);
			this.Inserir(jogador);
		}

	}

	public Jogador Get(int id) { return this.array[id]; }

	public void ToggleShow() {}
	public void Mostrar() {}

}

class TP02Q01 {

	static Scanner scanner = new Scanner(System.in);

	static String readStr() {
		return scanner.nextLine();
	}

	public static void main(String[] args) {
		// Lista BD = new Lista("../tmp/players.csv", BD_SIZE);
		// Lista listaJogadores = new Lista(40);

		// String inputPUBIN = new String();
		String inputPUBIN;

		// while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
		while (!(inputPUBIN = readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			System.out.printf("Id: %d", id);
			// listaJogadores.Inserir(BD.Get(id));
		}

		// listaJogadores.Mostrar();

	}
}
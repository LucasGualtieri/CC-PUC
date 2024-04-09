package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava;

import java.io.File;
import java.util.*;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.Jogador;

public class Lista {
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

	static final int BD_SIZE = 3922; // DEIXAR COMO ATRIBUTO DA CLASSE BD

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
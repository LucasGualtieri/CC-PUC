package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Jogador;

public class Fila {
	private int maxSize, size;
	private Jogador[] array;

	public Fila(String filePath, int size) throws Exception {
		this(size);
	}

	public Fila(int maxSize) {
		this.array = new Jogador[maxSize];
		this.maxSize = maxSize;
		this.size = 0;
	}

	public int getSize() { return this.size; }

	public Jogador Get(int id) { return this.array[id]; }
	public Jogador Get(String id) {
		return this.array[Integer.parseInt(id)];
	}

	public void Mostrar() {
		if (this.size == 0) {
			System.out.println("Erro ao mostrar: Fila vazia.");
			return;
		}

		for (int i = 0; i < this.size; i++) {
			System.out.println(this.array[i].getNome() + " ");
		}
	}

	// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

	public void Inserir(Jogador jogador) throws Exception {

		if (size == maxSize) {
			throw new Exception("Erro ao inserir: Fila cheia.\n");
		}

		array[size++] = jogador.Clone();
	}

	public Jogador Remover() throws Exception {
		if (size == 0) {
			throw new Exception("Erro ao remover: Lista vazia.");
		}

		Jogador removido = array[0];

		for (int i = 0; i < size - 1; i++) array[i] = array[i + 1];

		size--;

		return removido;
	}
}
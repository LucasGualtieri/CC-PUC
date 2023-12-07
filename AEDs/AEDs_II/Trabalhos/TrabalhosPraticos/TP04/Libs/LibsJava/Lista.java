package TP04.Libs.LibsJava;

import TP04.Libs.LibsJava.Celulas.CelulaLista;
import TP04.Libs.LibsJava.Lib.Jogador;

public class Lista {
	private int size;
	private CelulaLista primeiro, ultimo;

	public Lista() {
		primeiro = ultimo = new CelulaLista();
		size = 0;
	}

	public int getSize() { return this.size; }

	public void Mostrar() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao mostrar: Lista vazia.");
		}

		int contador = 0;
		for (CelulaLista i = this.primeiro.prox; i != null; i = i.prox) {
			System.out.printf("[%d] ## ", contador++);
			i.jogador.Mostrar();
		}

	}

	// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

	public void InserirInicio(Jogador jogador) {

		CelulaLista newCelula = new CelulaLista(jogador, primeiro.prox);
		if (primeiro == ultimo) ultimo = newCelula;
		primeiro.prox = newCelula;
		this.size++;

	}

	public void InserirFim(Jogador jogador) {

		ultimo = ultimo.prox = new CelulaLista(jogador, null);
		this.size++;

	}
	
	public void Inserir(String posStr, Jogador jogador) {

		int pos = Integer.parseInt(posStr);

		CelulaLista i = primeiro.prox;
		for (int count = 0; count < pos - 1; count++, i = i.prox);

		i.prox = new CelulaLista(jogador, i.prox);

		this.size++;

	}

	public Jogador RemoverInicio() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao remover: Lista Flex vazia.");
		}

		CelulaLista removido = primeiro = primeiro.prox;
		this.size--;

		return removido.jogador;

	}

	public Jogador RemoverFim() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao remover: Lista Flex vazia.");
		}
		
		CelulaLista removido, i;
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

		CelulaLista removido, i = primeiro.prox;
		for (int count = 0; count < pos - 1; count++, i = i.prox);

		removido = i.prox;
		i.prox = removido.prox;

		this.size--;

		return removido.jogador;

	}
}

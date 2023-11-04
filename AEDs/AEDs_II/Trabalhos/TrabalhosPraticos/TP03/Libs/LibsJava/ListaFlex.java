package TP03.Libs.LibsJava;

import TP03.Libs.LibsJava.Celulas.CelulaLista;
import TP03.Libs.LibsJava.Lib.Jogador;

public class ListaFlex {
	private int size;
	private CelulaLista primeiro, ultimo;

	public ListaFlex() {
		primeiro = ultimo = new CelulaLista();
		size = 0;
	}

	public int getSize() { return this.size; }

	public void Mostrar() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao mostrar: Lista vazia.");
		}

		int contador = 0;
		for (CelulaLista i = this.primeiro.dir; i != null; i = i.dir) {
			System.out.printf("[%d] ## ", contador++);
			i.jogador.Mostrar();
		}

	}

	// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

	public void InserirInicio(Jogador jogador) {

		CelulaLista newCelula = new CelulaLista(jogador, primeiro.dir);
		if (primeiro == ultimo) ultimo = newCelula;
		primeiro.dir = newCelula;
		this.size++;

	}

	public void InserirFim(Jogador jogador) {

		ultimo = ultimo.dir = new CelulaLista(jogador, null);
		this.size++;

	}
	
	public void Inserir(String posStr, Jogador jogador) {

		int pos = Integer.parseInt(posStr);

		CelulaLista i = primeiro.dir;
		for (int count = 0; count < pos - 1; count++, i = i.dir);

		i.dir = new CelulaLista(jogador, i.dir);

		this.size++;

	}

	public Jogador RemoverInicio() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao remover: Lista Flex vazia.");
		}

		CelulaLista removido = primeiro = primeiro.dir;
		this.size--;

		return removido.jogador;

	}

	public Jogador RemoverFim() throws Exception {

		if (this.primeiro == this.ultimo) {
			throw new Exception("Erro ao remover: Lista Flex vazia.");
		}
		
		CelulaLista removido, i;
		for (i = primeiro; i.dir.dir != null; i = i.dir);

		removido = i.dir;
		i.dir = removido.dir;

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

		CelulaLista removido, i = primeiro.dir;
		for (int count = 0; count < pos - 1; count++, i = i.dir);

		removido = i.dir;
		i.dir = removido.dir;

		this.size--;

		return removido.jogador;

	}
}

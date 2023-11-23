package TP04.Libs.LibsJava;

import TP04.Libs.LibsJava.Lib.Jogador;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Celulas.No;

public class Arvore {

	private int size;
	private No raiz;

	public Arvore() {
		this.size = 0;
		this.raiz = null;
	}

	public No getRoot() { return this.raiz; }

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

	private int CompareTo(Jogador jog, No raiz, Log log) {
		log.incrementarComparacoes();
		return jog.getNome().compareTo(raiz.jogador.getNome());
	}

	public void Inserir(Jogador jogador, Log log) throws Exception {
		this.raiz = Inserir(jogador, this.raiz, log);
		this.size++;
	}

	private No Inserir(Jogador jogador, No raiz, Log log) throws Exception {

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
package TP03.Libs.LibsJava;

import TP03.Libs.LibsJava.Lib.Jogador;

public class Pilha {
	private Lista lista;

	public Pilha(int size) { this.lista = new Lista(size); }

	public int getSize() { return this.lista.getSize(); }

	public void Mostrar() { this.lista.Mostrar(); }

	// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

	public void Inserir(Jogador jogador) throws Exception {
		this.lista.InserirFim(jogador);
	}

	public Jogador Remover() throws Exception {
		return this.lista.RemoverFim();
	}

}
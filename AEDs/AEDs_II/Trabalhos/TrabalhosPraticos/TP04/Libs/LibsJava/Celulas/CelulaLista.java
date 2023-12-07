package TP04.Libs.LibsJava.Celulas;

import TP04.Libs.LibsJava.Lib.Jogador;

public class CelulaLista {
	public Jogador jogador;
	public CelulaLista prox;

	public CelulaLista() {
		this.jogador = null;
		this.prox = null;
	}

	public CelulaLista(Jogador jogador, CelulaLista prox) {
		this.jogador = jogador;
		this.prox = prox;
	}
}

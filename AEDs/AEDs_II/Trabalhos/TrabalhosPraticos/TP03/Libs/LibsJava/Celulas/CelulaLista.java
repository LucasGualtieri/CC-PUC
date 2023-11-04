package TP03.Libs.LibsJava.Celulas;

import TP03.Libs.LibsJava.Lib.Jogador;

public class CelulaLista {
	public Jogador jogador;
	public CelulaLista dir;

	public CelulaLista() {
		this.jogador = null;
		this.dir = null;
	}

	public CelulaLista(Jogador jogador, CelulaLista dir) {
		this.jogador = jogador;
		this.dir = dir;
	}
}

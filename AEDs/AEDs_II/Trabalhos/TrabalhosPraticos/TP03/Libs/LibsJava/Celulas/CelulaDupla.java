package TP03.Libs.LibsJava.Celulas;

import TP03.Libs.LibsJava.Lib.Jogador;

public class CelulaDupla {
	public Jogador jogador;
	public CelulaDupla esq, dir;

	public CelulaDupla() {
		this.jogador = null;
		this.esq = this.dir = null;
	}

	public CelulaDupla(Jogador jogador, CelulaDupla dir) {
		this.jogador = jogador;
		this.dir = dir;
	}

	public CelulaDupla(Jogador jogador, CelulaDupla esq, CelulaDupla dir) {
		this.jogador = jogador;
		this.esq = esq;
		this.dir = dir;
	}
}

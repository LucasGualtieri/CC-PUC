package TP04.Libs.LibsJava.Celulas;

import TP04.Libs.LibsJava.Lib.Jogador;

public class NoAN {
	public boolean cor;
	public Jogador jogador;
	public NoAN esq, dir;

	public NoAN() {
	this(null);
	}

	public NoAN(Jogador jogador) {
	this(jogador, false, null, null);
	}

	public NoAN(Jogador jogador, boolean cor) {
	this(jogador, cor, null, null);
	}

	public NoAN(Jogador jogador, boolean cor, NoAN esq, NoAN dir) {
	this.cor = cor;
	this.jogador = jogador;
	this.esq = esq;
	this.dir = dir;
	}
}
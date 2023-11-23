package TP04.Libs.LibsJava.Celulas;

import TP04.Libs.LibsJava.Lib.Jogador;

public class No {

	public Jogador jogador;

	public No esq, dir;

	public No(Jogador jogador) { 
		this.jogador = jogador;
		this.esq = this.dir = null;
	}
}

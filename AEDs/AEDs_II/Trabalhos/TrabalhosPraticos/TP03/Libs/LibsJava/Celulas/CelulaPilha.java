package TP03.Libs.LibsJava.Celulas;

import TP03.Libs.LibsJava.Lib.Jogador;

public class CelulaPilha {
	public Jogador jogador;
	public CelulaPilha baixo;

	public CelulaPilha() {
		this.jogador = null;
		this.baixo = null;
	}

	public CelulaPilha(Jogador jogador, CelulaPilha topo) {
		this.jogador = jogador;
		this.baixo = topo;
	}
}

package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Celulas;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Jogador;

public class NoAN {

	public boolean cor;
	public NoAN esq, dir;
	public Jogador jogador;

	public NoAN() {
		this(null, false);
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
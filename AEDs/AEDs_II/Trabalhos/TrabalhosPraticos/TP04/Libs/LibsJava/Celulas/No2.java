package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Celulas;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Jogador;

public class No2 {

	public String nome;
	public No2 esq, dir;

	public No2(Jogador jogador) { 
		this.nome = jogador.getNome();
		this.esq = this.dir = null;
	}
}

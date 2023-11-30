package TP04.Libs.LibsJava.Celulas;

import TP04.Libs.LibsJava.Lib.Jogador;

public class No2 {

	public String nome;
	public No2 esq, dir;

	public No2(Jogador jogador) { 
		this.nome = jogador.getNome();
		this.esq = this.dir = null;
	}
}

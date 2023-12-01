package TP04.Libs.LibsJava;

import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Jogador;
import TP04.Libs.LibsJava.Celulas.No1;
import TP04.Libs.LibsJava.Celulas.No2;

public class ArvoreArvore {

	private No1 raiz;

	public ArvoreArvore() {
		this.raiz = null;
	}

	public ArvoreArvore(int[] alturas, BD BD) {
		this.Montar(alturas, BD);
	}

	public No1 getRaiz() { return this.raiz; }

	public static int CompareTo(Jogador jogador, No2 raiz, Log log) {
		log.incrementarComparacoes();
		return jogador.getNome().compareTo(raiz.nome);
	}

	public static int CompareTo(Jogador jogador, No2 raiz) {
		return jogador.getNome().compareTo(raiz.nome);
	}

	public void Montar(int[] alturas, BD BD) {
		for (int altura : alturas) {
			this.raiz = this.Montar(this.raiz, altura);
		}
	}

	private No1 Montar(No1 raiz, int alturaMod15) {

		if (raiz == null) {
			raiz = new No1(alturaMod15);
		} else if (alturaMod15 < raiz.alturaMod15) {
			raiz.esq = Montar(raiz.esq, alturaMod15);
		} else if (alturaMod15 > raiz.alturaMod15) {
			raiz.dir = Montar(raiz.dir, alturaMod15);
		}

		return raiz;
	}

	private No1 Pesquisar(No1 raiz, Jogador jogador) {

		if (jogador.getAltura() % 15 < raiz.alturaMod15) {
			raiz.esq = Pesquisar(raiz.esq, jogador);
		} else if (jogador.getAltura() % 15 > raiz.alturaMod15) {
			raiz.dir = Pesquisar(raiz.dir, jogador);
		}
		
		return raiz;
	}

	public void Inserir(Jogador jogador) throws Exception {
		No1 pesquisado = Pesquisar(this.raiz, jogador);
		pesquisado.raiz = Inserir(pesquisado.raiz, jogador);
	}

	private No2 Inserir(No2 raiz, Jogador jogador) throws Exception {

		if (raiz == null) {
			raiz = new No2(jogador);
		} else if (CompareTo(jogador, raiz) < 0) {
			raiz.esq = Inserir(raiz.esq, jogador);
		} else if (CompareTo(jogador, raiz) > 0) {
			raiz.dir = Inserir(raiz.dir, jogador);
		} else {
			String nome = jogador.getNome();
			String erro = "Erro ao inserir na Árvore: Valor " + nome + " repetido.";
			throw new Exception(erro);
		}
		
		return raiz;
	}
}
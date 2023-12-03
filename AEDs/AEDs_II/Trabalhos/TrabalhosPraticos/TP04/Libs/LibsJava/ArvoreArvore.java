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

	public No1 getRaiz() { return this.raiz; }

	public static int CompareTo(String nome, No2 raiz, Log log) {
		log.incrementarComparacoes();
		return nome.compareTo(raiz.nome);
	}

	public static int CompareTo(Jogador jogador, No2 raiz, Log log) {
		log.incrementarComparacoes();
		return jogador.getNome().compareTo(raiz.nome);
	}

	public static int CompareTo(Jogador jogador, No2 raiz) {
		return jogador.getNome().compareTo(raiz.nome);
	}

	public void Mostrar() throws Exception {

		if (this.raiz == null) {
			throw new Exception("Erro ao mostrar Árvore: Árvore vazia.");
		}

		System.out.print("{ ");
		Mostrar(this.raiz);
		System.out.println("\b\b }");
	}

	private void Mostrar(No1 raiz) {

		if (raiz != null) {
			Mostrar(raiz.esq);
			System.out.printf("%d, ", raiz.alturaMod15);
			Mostrar(raiz.dir);
		}
	}

	public void MostrarSub() throws Exception {

		if (this.raiz == null) {
			throw new Exception("Erro ao mostrar Sub Árvores: Árvore vazia.");
		}

		MostrarSub(this.raiz);
	}

	private void MostrarSub(No1 raiz) {

		if (raiz != null) {
			MostrarSub(raiz.esq);
			System.out.printf("AlturaMod15 - %d: \n", raiz.alturaMod15);
			MostrarSub(raiz.raiz);
			System.out.println("-----------------");
			MostrarSub(raiz.dir);
		}
	}

	private void MostrarSub(No2 raiz) {

		if (raiz != null) {
			MostrarSub(raiz.esq);
			System.out.println(raiz.nome);
			MostrarSub(raiz.dir);
		}
	}

	public void Inserir(Jogador jogador) throws Exception {
		No1 pesquisado = Pesquisar(this.raiz, jogador.getAltura() % 15);
		pesquisado.raiz = Inserir(pesquisado.raiz, jogador);
	}

	private No1 Pesquisar(No1 raiz, int alturaMod15) {

		No1 pesquisado = raiz;

		if (alturaMod15 % 15 < raiz.alturaMod15) {
			pesquisado = Pesquisar(raiz.esq, alturaMod15);
		} else if (alturaMod15 % 15 > raiz.alturaMod15) {
			pesquisado = Pesquisar(raiz.dir, alturaMod15);
		}

		return pesquisado;
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
			String erro = "Erro ao inserir na Árvore: Jogador " + nome + " repetido.";
			throw new Exception(erro);
		}

		return raiz;
	}
}
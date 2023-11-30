package TP04.TP04Q02;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Lib.Jogador;
import TP04.Libs.LibsJava.Celulas.No1;
import TP04.Libs.LibsJava.Celulas.No2;
import TP04.Libs.LibsJava.ArvoreArvore;

// clear && javac -cp ../.. TP04Q02.java && java -cp ../.. TP04Q02.java < pub.in > result.txt

class TP04Q02 {

	static public boolean Pesquisar(ArvoreArvore arvore, Jogador jogador, Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}
		System.out.printf("%s raiz ", jogador.getNome());
		return Pesquisar(arvore.getRaiz(), jogador, log);
	}
	
	static private boolean Pesquisar(No1 raiz, Jogador jogador, Log log) {

		boolean resultado;
		
		if (raiz == null) {
			resultado = false;
		} else if (raiz.alturaMod15 < jogador.getAltura() % 15) {
			System.out.printf("esq ");
			resultado = Pesquisar(raiz.esq, jogador, log);
		} else if (raiz.alturaMod15 > jogador.getAltura() % 15) {
			System.out.printf("dir ");
			resultado = Pesquisar(raiz.dir, jogador, log);
		} else {
			resultado = Pesquisar(raiz.raiz, jogador, log);
		}

		return resultado;
	}

	static private boolean Pesquisar(No2 raiz, Jogador jogador, Log log) {

		boolean resultado;
		
		if (raiz == null) {
			resultado = false;
		} else if (ArvoreArvore.CompareTo(jogador, raiz, log) < 0) {
			System.out.printf("esq ");
			resultado = Pesquisar(raiz.esq, jogador, log);
		} else if (ArvoreArvore.CompareTo(jogador, raiz, log) > 0) {
			System.out.printf("dir ");
			resultado = Pesquisar(raiz.dir, jogador, log);
		} else {
			resultado = true;
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {
		
		BD BD = new BD("../tmp/players.csv");
		ArvoreArvore arvore = new ArvoreArvore();
		
		String inputPUBIN = new String();
		
		int[] alturas = { 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 };
		arvore.Montar(alturas, BD);

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore.Inserir(BD.Get(id));
		}

		Log log = new Log();
		Timer timer = new Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			Jogador pesquisado = BD.Get(inputPUBIN);
			boolean resultado = Pesquisar(arvore, pesquisado, log);
			System.out.println(resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_arvoreArvore.txt", timer);
	}
}
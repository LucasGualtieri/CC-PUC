package TP04.TP04Q02;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Celulas.No1;
import TP04.Libs.LibsJava.Celulas.No2;
import TP04.Libs.LibsJava.ArvoreArvore;

// clear && javac -cp ../.. TP04Q02.java && java -cp ../.. TP04Q02.java < pub.in > result.txt

class TP04Q02 {

	static public boolean Pesquisar(ArvoreArvore arvore, String nome, Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}

		System.out.printf("%s raiz ", nome);
		return Pesquisar(arvore.getRaiz(), nome, log);
	}

	static private boolean Pesquisar(No1 raiz, String nome, Log log) {

		boolean resultado = false;

		if (raiz != null) {

			resultado = Pesquisar(raiz.raiz, nome, log);

			if (!resultado) {
				System.out.printf("esq ");
				resultado = Pesquisar(raiz.esq, nome, log);
			}

			if (!resultado) {
				System.out.printf("dir ");
				resultado = Pesquisar(raiz.dir, nome, log);
			}
		}

		return resultado;
	}

	static private boolean Pesquisar(No2 raiz, String nome, Log log) {

		boolean resultado = false;

		if (raiz != null) {

			resultado = ArvoreArvore.CompareTo(nome, raiz, log) == 0;

			if (!resultado) {
				System.out.printf("ESQ ");
				resultado = Pesquisar(raiz.esq, nome, log);
			}

			if (!resultado) {
				System.out.printf("DIR ");
				resultado = Pesquisar(raiz.dir, nome, log);
			}
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {

		// int[] alturas = { 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 }; // Enunciado
		int[] alturas = { 7, 3, 11, 1, 5, 9, 12, 0, 2, 4, 6, 8, 10, 13, 14 };

		BD BD = new BD("../tmp/players.csv");
		ArvoreArvore arvore = new ArvoreArvore(alturas, BD);

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore.Inserir(BD.Get(id));
		}

		Log log = new Log();
		Timer timer = new Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean resultado = Pesquisar(arvore, inputPUBIN, log);
			System.out.println(resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_arvoreArvore.txt", timer);
	}
}
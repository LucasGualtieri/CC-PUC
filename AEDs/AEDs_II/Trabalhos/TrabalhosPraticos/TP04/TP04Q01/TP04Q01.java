package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.TP04Q01;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.BD;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Log;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Timer;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Celulas.No;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Arvore;

// clear && javac -cp ../.. TP04Q01.java && java -cp ../.. TP04Q01.java < pub.in > result.txt

class TP04Q01 {

	static public boolean Pesquisar(Arvore arvore, String chave, Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}
		System.out.printf("%s raiz ", chave);
		return Pesquisar(arvore.getRaiz(), chave, log);
	}
	
	static private boolean Pesquisar(No raiz, String chave, Log log) {

		boolean resultado;
		
		if (raiz == null) {
			resultado = false;
		} else if (Arvore.CompareTo(chave, raiz, log) < 0) {
			System.out.printf("esq ");
			resultado = Pesquisar(raiz.esq, chave, log);
		} else if (Arvore.CompareTo(chave, raiz, log) > 0) {
			System.out.printf("dir ");
			resultado = Pesquisar(raiz.dir, chave, log);
		} else {
			resultado = true;
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		Arvore arvore = new Arvore();
		
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

		log.RegistroPesquisa("794989_arvoreBinaria.txt", timer);
	}
}
package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.TP04Q04;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.BD;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Log;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Lib.Timer;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Celulas.NoAN;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP04.Libs.LibsJava.Alvinegra;

// clear && javac -cp ../.. TP04Q04.java && java -cp ../.. TP04Q04.java < pub.in > result.txt

class TP04Q04 {

	static public boolean Pesquisar(Alvinegra arvore, String chave, Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}
		System.out.printf("%s raiz ", chave);
		return Pesquisar(arvore.getRaiz(), chave, log);
	}
	
	static private boolean Pesquisar(NoAN raiz, String chave, Log log) {

		boolean resultado;

		if (raiz == null) {
			resultado = false;
		} else if (Alvinegra.CompareToStr(chave, raiz, log) < 0) {
			System.out.printf("esq ");
			resultado = Pesquisar(raiz.esq, chave, log);
		} else if (Alvinegra.CompareToStr(chave, raiz, log) > 0) {
			System.out.printf("dir ");
			resultado = Pesquisar(raiz.dir, chave, log);
		} else {
			resultado = true;
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		Alvinegra arvore = new Alvinegra();
		
		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore.Inserir(BD.Get(id));
			// arvore.MostrarPre();
		}

		Log log = new Log();
		Timer timer = new Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean resultado = Pesquisar(arvore, inputPUBIN, log);
			System.out.println(resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_alvinegra.txt", timer);
	}
}
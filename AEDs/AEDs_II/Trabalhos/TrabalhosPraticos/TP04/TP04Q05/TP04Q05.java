package TP04.TP04Q05;

import TP04.Libs.LibsJava.Celulas.No;
import TP04.Libs.LibsJava.Arvore;
import TP04.Libs.LibsJava.Fila;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Lib;

// clear && javac -cp ../.. TP04Q05.java && java -cp ../.. TP04Q05.java < pub.in > result.txt

class TP04Q05 {

	public static void TreeSort(Log log, Fila fila) throws Exception {

		Arvore arvore = new Arvore();

		int N = fila.getSize();

		for (int i = 0; i < N; i++) {
			arvore.Inserir(fila.Remover(), log);
		}

		TreeSort(arvore.getRoot(), log, fila);
	}
	
	private static void TreeSort(No raiz, Log log, Fila fila) throws Exception {

		if (raiz != null) {
			TreeSort(raiz.esq, log, fila);
			fila.Inserir(raiz.jogador);
			TreeSort(raiz.dir, log, fila);
		}
	}
	
	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		Fila fila = new Fila(74);
		
		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			fila.Inserir(BD.Get(id));
		}

		Log log = new Log();
		Timer timer = new Timer();

		timer.Start();
		TreeSort(log, fila);
		timer.Stop();

		fila.Mostrar();

		log.RegistroOrdenacao("794989_treesort.txt", timer);
	}
}
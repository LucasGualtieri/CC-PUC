package TP04.TP04Q06;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Celulas.NoTrie;
import TP04.Libs.LibsJava.Trie;

// clear && javac -cp ../.. TP04Q06.java && java -cp ../.. TP04Q06.java < pub.in > result.txt

class TP04Q06 {

    private static boolean Pesquisar(String nome, Trie arvore, Log log) {

		NoTrie atual = arvore.getRaiz();
        boolean resp = false;

        for (int i = 0; i < nome.length(); i++) {

			int index = (int)(nome.charAt(i)) - 32;

            if (atual.filhos[index] == null) resp = false;
            else atual = atual.filhos[index];
			log.incrementarComparacoes();
        }

        resp = atual.ehPalavra;

        return resp;
    }

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		Trie arvore1 = new Trie();
		Trie arvore2 = new Trie();

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore1.Inserir(BD.Get(id).getNome());
		}

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore2.Inserir(BD.Get(id).getNome());
		}

		Trie merged = new Trie(arvore1, arvore2);

		Log log = new Log();
		Timer timer = new Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean resultado = Pesquisar(inputPUBIN, merged, log);
			System.out.printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_arvoreTrie.txt", timer);
	}
}
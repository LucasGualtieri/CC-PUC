package TP04.TP04Q09;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Lib.Jogador;
import TP04.Libs.LibsJava.Lista;

// clear && javac -cp ../.. TP04Q09.java && java -cp ../.. TP04Q09.java < pub.in > result.txt

class TP04Q09 {

	static class HashInd {

		private Lista[] array;
		public final int tabelaLen;

		public HashInd(int tabelaLen) {
			this.tabelaLen = tabelaLen;
			this.array = new Lista[tabelaLen];
			for (int i = 0; i < tabelaLen; i++) {
				array[i] = new Lista();
			}
		}

		public void Mostrar() throws Exception {
			System.out.println("----- Tabela Hash -----");
			for (int i = 0; i < tabelaLen; i++) {
				array[i].Mostrar();
			}
		}

		private int hash(Jogador jogador) {
			return jogador.getAltura() % tabelaLen;
		}

		public void Inserir(Jogador jogador) {
			int pos = hash(jogador);
			array[pos].InserirFim(jogador);
		}

		boolean CompareToStr(String str1, String str2, Log log) {
			log.incrementarComparacoes();
			return str1.equals(str2);
		}

		public boolean Pesquisar(Jogador jogador, Log log) {
			int pos = hash(jogador);
			return array[pos].Pesquisar(jogador, log);
		}

	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		HashInd hash = new HashInd(25);

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			hash.Inserir(BD.Get(id));
		}

		Log log = new Log();
		Timer timer = new Timer();

		BD.OrdenarPorNome(); // Para possibilitar uma pesquisa binária.

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			Jogador pesquisado = BD.PesquisarPorNome(inputPUBIN, log);
			boolean resultado = hash.Pesquisar(pesquisado, log);
			System.out.printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_hashIndireta.txt", timer);
	}
}
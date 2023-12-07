package TP04.TP04Q06;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Lib.Jogador;

// clear && javac -cp ../.. TP04Q06.java && java -cp ../.. TP04Q06.java < pub.in > result.txt

class TP04Q06 {

	static class HashRes {

		private Jogador[] array;
		public final int tabelaLen, reservaLen;
		private int reservaN;

		public HashRes(int tabelaLen, int reservaLen) {

			this.reservaN = 0;
			this.tabelaLen = tabelaLen;
			this.reservaLen = reservaLen;
			this.array = new Jogador[tabelaLen + reservaLen];
			for (int i = 0; i < array.length; i++) array[i] = null;
		}

		private int hash(Jogador jogador) {
			return jogador.getAltura() % tabelaLen;
		}

		public void Inserir(Jogador jogador) {

			int pos = hash(jogador);
			if (array[pos] == null) array[pos] = jogador;
			else if (reservaN < reservaLen) array[tabelaLen + reservaN++] = jogador;
			// else System.out.println("Erro ao inserir: Hash cheia.");
		}

		public boolean Pesquisar(Jogador jogador, Log log) {

			boolean resultado = false;
			int pos = hash(jogador);

			if (array[pos] != null) {

				log.incrementarComparacoes();
				resultado = array[pos].getAltura() == jogador.getAltura();

				if (!resultado) {
					for (int i = tabelaLen; !resultado && i < tabelaLen + reservaLen; i++) {
						log.incrementarComparacoes();
						resultado = array[i].getAltura() == jogador.getAltura();
					}
				}
			}

			return resultado;
		}

	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		HashRes hash = new HashRes(21, 9);

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
			Jogador pesquisado = BD.PesquisarPorNome(inputPUBIN);
			boolean resultado = hash.Pesquisar(pesquisado, log);
			System.out.printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_hashReserva.txt", timer);
	}
}
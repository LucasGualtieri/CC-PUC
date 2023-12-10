package TP04.TP04Q07;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Lib.Jogador;

// clear && javac -cp ../.. TP04Q07.java && java -cp ../.. TP04Q07.java < pub.in > result.txt

class TP04Q07 {

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
			Jogador pesquisado = BD.PesquisarPorNome(inputPUBIN, log);
			boolean resultado = hash.Pesquisar(pesquisado, log);
			System.out.printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_hashReserva.txt", timer);
	}

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

		public void Mostrar() {
			System.out.println("----- Tabela Hash -----");
			for (int i = 0; i < tabelaLen + reservaLen; i++) {
				if (array[i] != null) System.out.println(array[i].getNome());
			}
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

		boolean CompareToNome(Jogador jog1, Jogador jog2, Log log) {
			log.incrementarComparacoes();
			return jog1.getNome().equals(jog2.getNome());
		}

		public boolean Pesquisar(Jogador jogador, Log log) {

			boolean resultado = false;
			int pos = hash(jogador);

			if (array[pos] != null) {

				resultado = CompareToNome(jogador, array[pos], log);

				for (int i = 0; !resultado && i < reservaLen; i++) {
					resultado = CompareToNome(jogador, array[i + tabelaLen], log);
				}
			}

			return resultado;
		}

	}

}
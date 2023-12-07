package TP04.TP04Q08;

import TP04.Libs.LibsJava.Lib;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Lib.Timer;
import TP04.Libs.LibsJava.Lib.Jogador;

// clear && javac -cp ../.. TP04Q08.java && java -cp ../.. TP04Q08.java < pub.in > result.txt

class TP04Q08 {

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		ReHash hash = new ReHash(25);

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

		log.RegistroPesquisa("794989_hashRehash.txt", timer);
	}

	static class ReHash {

		private Jogador[] array;
		public final int tabelaLen;

		public ReHash(int tabelaLen) {
			this.tabelaLen = tabelaLen;
			this.array = new Jogador[tabelaLen];
			for (int i = 0; i < array.length; i++) array[i] = null;
		}

		public void Mostrar() {
			System.out.println("----- Tabela Hash -----");
			for (int i = 0; i < tabelaLen; i++) {
				if (array[i] != null) System.out.println(array[i].getNome());
			}
		}

		private int hash(Jogador jogador) {
			return jogador.getAltura() % tabelaLen;
		}

		private int rehash(Jogador jogador) {
			return ((jogador.getAltura() + 1) % tabelaLen);
		}

		public void Inserir(Jogador jogador) {

			int pos = hash(jogador);
			int colisao = rehash(jogador);
			if (array[pos] == null) array[pos] = jogador;
			else if (array[colisao] == null) array[colisao] = jogador;
			// else System.out.println("Erro ao inserir: ReHash inválida.");
		}

		boolean CompareToStr(String str1, String str2, Log log) {
			log.incrementarComparacoes();
			return str1.equals(str2);
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

				if (!resultado) {
					int colisao = rehash(jogador);
					resultado = CompareToNome(jogador, array[colisao], log);
				}
			}

			return resultado;
		}

	}

}
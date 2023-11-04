package TP02.TP02Q03;

import TP02.Libs.Lib;
import TP02.Libs.Lib.Lista;
import TP02.Libs.Lib.Log;
import TP02.Libs.Lib.Timer;

// clear && javac -cp ../.. TP02Q03.java && java -cp ../.. TP02Q03.java < pub.in > result.txt

class TP02Q03 {

	static boolean PesquisaSequencial(String nome, Log log, Lista lista) {

		boolean hasFound = false;
		
		for (int i = 0; i < lista.getSize(); i++) {
			if (lista.CompareToStr(i, nome, log)) {
				i = lista.getSize();
				hasFound = true;
			}
			log.incrementarComparacoes();
		}

		return hasFound;
	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Timer timer = new Timer();
		Log log = new Log();

		Lista BD = new Lista("../tmp/players.csv", BD_SIZE);
		Lista lista = new Lista(74); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.Inserir(BD.Get(id));
			lista.setAtributoStr(BD.Get(id).getNome());
		}

		// lista.Mostrar();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean hasFound = PesquisaSequencial(inputPUBIN, log, lista);
			System.out.println(hasFound ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_sequencial.txt", timer);		

	}
}
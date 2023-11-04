package TP02.TP02Q01;

import TP02.Libs.Lib;
import TP02.Libs.Lib.Lista;

// clear && javac -cp ../.. TP02Q01.java && java -cp ../.. TP02Q01.java < pub.in > result.txt

class TP02Q01 {

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lista BD = new Lista("../tmp/players.csv", BD_SIZE);
		Lista listaJogadores = new Lista(40);

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			listaJogadores.Inserir(BD.Get(id));
		}

		listaJogadores.Mostrar();

	}
}
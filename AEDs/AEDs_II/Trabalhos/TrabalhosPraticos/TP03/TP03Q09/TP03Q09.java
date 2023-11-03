package TP03.TP03Q09;

import TP03.Libs.Lib;

// clear && javac -cp ../.. TP03Q09.java && java -cp ../.. TP03Q09.java < pub.in > result.txt

class TP03Q09 {

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Lista BD = new Lib.Lista("../tmp/players.csv", BD_SIZE);
		Lib.PilhaFlex pilha = new Lib.PilhaFlex();

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			pilha.Inserir(BD.Get(id));
		}

		int numberOfActions = Lib.readInt();

		for (int i = 0; i < numberOfActions; i++) {
			// InserirERemover(Lib.readStr(), pilha, BD);
		}

		pilha.Mostrar();

	}
}
package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.TP03Q06;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.PilhaFlex;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.BD;

// clear && javac -cp ../.. TP03Q06.java && java -cp ../.. TP03Q06.java < pub.in > result.txt

class TP03Q06 {

	static void InserirERemover(String action, PilhaFlex pilha, BD BD) throws Exception {

		String[] actions = action.split(" ");

		if (actions[0].equals("I")) {
			pilha.Inserir(BD.Get(actions[1]));
		} else {
			System.out.printf("(R) %s\n", pilha.Remover().getNome());
		}

	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		PilhaFlex pilha = new PilhaFlex();

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			pilha.Inserir(BD.Get(id));
		}

		int numberOfActions = Lib.readInt();

		for (int i = 0; i < numberOfActions; i++) {
			InserirERemover(Lib.readStr(), pilha, BD);
		}

		pilha.Mostrar();

	}
}
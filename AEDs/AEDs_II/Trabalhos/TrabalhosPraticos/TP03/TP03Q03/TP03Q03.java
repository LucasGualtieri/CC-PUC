package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.TP03Q03;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Pilha;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.BD;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib;

// clear && javac -cp ../.. TP03Q03.java && java -cp ../.. TP03Q03.java < pub.in > result.txt

class TP03Q03 {

	static void InserirERemover(String action, Pilha pilha, BD BD) throws Exception {

		String[] actions = action.split(" ");

		if (actions[0].equals("I")) {
			pilha.Inserir(BD.Get(actions[1]));
		} else {
			System.out.printf("(R) %s\n", pilha.Remover().getNome());
		}

	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		Pilha pilha = new Pilha(250);

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
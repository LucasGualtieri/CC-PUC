package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.TP03Q01;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.BD;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lista;

// clear && javac -cp ../.. TP03Q01.java && java -cp ../.. TP03Q01.java < pub.in > result.txt

class TP03Q01 {

	static void InserirERemover(String action, Lista lista, BD BD) throws Exception {

		String[] actions = action.split(" ");

		if (actions[0].equals("II")) {
			lista.InserirInicio(BD.Get(actions[1]));
		} else if (actions[0].equals("IF")) {
			lista.InserirFim(BD.Get(actions[1]));
		} else if (actions[0].equals("I*")) {
			lista.Inserir(actions[1], BD.Get(actions[2]));
		} else if (actions[0].equals("RI")) {
			System.out.printf("(R) %s\n", lista.RemoverInicio().getNome());
		} else if (actions[0].equals("RF")) {
			System.out.printf("(R) %s\n", lista.RemoverFim().getNome());
		} else if (actions[0].equals("R*")) {
			System.out.printf("(R) %s\n", lista.Remover(actions[1]).getNome());
		}

	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		Lista lista = new Lista(250);

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.InserirFim(BD.Get(id));
		}

		int numberOfActions = Lib.readInt();

		for (int i = 0; i < numberOfActions; i++) {
			InserirERemover(Lib.readStr(), lista, BD);
		}

		lista.Mostrar();

	}
}
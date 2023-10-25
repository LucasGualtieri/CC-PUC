import TP03.Libs.Lib;

// clear && javac -cp ../.. TP03Q03.java && java -cp ../.. TP03Q03.java < pub.in > result.txt

class TP03Q03 {

	static void InserirERemover(String action, Lib.Pilha pilha, Lib.Lista BD) throws Exception {

		String[] actions = action.split(" ");

		if (actions[0].equals("I")) {
			pilha.Inserir(BD.Get(actions[1]));
		} else {
			System.out.printf("(R) %s\n", pilha.Remover().getNome());
		}

	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Lista BD = new Lib.Lista("../tmp/players.csv", BD_SIZE);
		Lib.Pilha pilha = new Lib.Pilha(250);

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
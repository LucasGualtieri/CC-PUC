package TP04.TP04Q05;

import TP04.Libs.LibsJava.BST;
import TP04.Libs.LibsJava.Lib.BD;
import TP04.Libs.LibsJava.Lib;

// clear && javac -cp ../.. TP04Q05.java && java -cp ../.. TP04Q05.java < pub.in > result.txt

class TP04Q05 {

	static void TreeSort(Lista lista) {

		BST tree = new BST();

		for (int i = 0; i < array.length; i++) {
			tree.Inserir(lista.Get[i]); // X comparações
		}

		TreeSort(tree.getRoot(), array);
	}

	private static void TreeSort(Node root, Log log, ListaFlex lista) {
		// log.incrementarComparacoes();
		if (root != null) { // N comparações
			sort(root.left, array);
			lista.InserirFim(root.value);
			sort(root.right, array);
		}
	}

	public static void main(String[] args) throws Exception {

		BD BD = new BD("../tmp/players.csv");
		ListaFlex lista = new Pilha();

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.Inserir(BD.Get(id));
		}

		TreeSort.sort(lista);

		pilha.Mostrar();

	}
}
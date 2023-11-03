package TP02.TP02Q05;

import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q05.java && java -cp ../.. TP02Q05.java < pub.in > result.txt

class TP02Q05 {

	static void SelectionSort(Lib.Log log, Lib.Lista lista) {

		int i, j, menor;
		for (i = 0; i < lista.getSize() - 1; i++) {
			menor = i;
			for (j = i + 1; j < lista.getSize(); j++) {
				if (lista.CompareToStr(menor, j, log) > 0) menor = j;
			}
			lista.swap(i, menor, log);
		}

	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Timer timer = new Lib.Timer();
		Lib.Log log = new Lib.Log();

		Lib.Lista BD = new Lib.Lista("../tmp/players.csv", BD_SIZE);
		Lib.Lista lista = new Lib.Lista(465); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.Inserir(BD.Get(id));
			lista.setAtributoStr(BD.Get(id).getNome());
		}

		timer.Start();
		SelectionSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_selecao.txt", timer);		

	}

}
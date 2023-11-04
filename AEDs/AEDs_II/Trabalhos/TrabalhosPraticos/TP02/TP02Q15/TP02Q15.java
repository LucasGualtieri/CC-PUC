package TP02.TP02Q15;

import TP02.Libs.Lib;
import TP02.Libs.Lib.Lista;
import TP02.Libs.Lib.Log;
import TP02.Libs.Lib.Timer;

// clear && javac -cp ../.. TP02Q15.java && java -cp ../.. TP02Q15.java < pub.in > result.txt

class TP02Q15 {

	static void SelectionSortParcial(int k, Log log, Lista lista) {

		int i, j, menor;
		for (i = 0; i < k; i++) {
			menor = i;
			for (j = i + 1; j < lista.getSize(); j++) {
				if (lista.CompareToStr(menor, j, log) > 0) menor = j;
			}
			lista.swap(i, menor, log);
		}

	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Timer timer = new Timer();
		Log log = new Log();

		Lista BD = new Lista("../tmp/players.csv", BD_SIZE);
		Lista lista = new Lista(465); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.Inserir(BD.Get(id));
			lista.setAtributoStr(BD.Get(id).getNome());
		}

		int k = 10;

		timer.Start();
		SelectionSortParcial(k, log, lista);
		timer.Stop();

		lista.MostrarParcial(k);

		log.RegistroOrdenacao("794989_selecaoParcial.txt", timer);		

	}

}
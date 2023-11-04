package TP02.TP02Q18;

import TP02.Libs.Lib;
import TP02.Libs.Lib.Jogador;
import TP02.Libs.Lib.Lista;
import TP02.Libs.Lib.Log;
import TP02.Libs.Lib.Timer;

// clear && javac -cp ../.. TP02Q18.java && java -cp ../.. TP02Q18.java < pub.in > result.txt

class TP02Q18 {

	static void QuickSort(int k, int left, int right, Log log, Lista lista) {
		int i = left, j = right;
		Jogador pivot = lista.array[(right + left) / 2];

		while (i <= j) {
			while (lista.CompareToStr(i, pivot, log) < 0) i++;
			while (lista.CompareToStr(j, pivot, log) > 0) j--;
			if (i <= j) lista.swap(i++, j--, log);
		}

		if (left < j) QuickSort(k, left, j, log, lista);
		if (i < k && i < right) QuickSort(k, i, right, log, lista);
	}

	static void QuickSort(int k, Log log, Lista lista) {
		QuickSort(k, 0, lista.getSize() - 1, log, lista);
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
			lista.setAtributoStr(BD.Get(id).getEstadoNascimento());
		}

		int k = 10;

		timer.Start();
		QuickSort(k, log, lista);
		timer.Stop();

		lista.MostrarParcial(k);

		log.RegistroOrdenacao("794989_quicksortParcial.txt", timer);

	}
}
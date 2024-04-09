package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.TP03Q11;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.BD;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.Log;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Lib.Timer;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.ListaDupla;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP03.Libs.LibsJava.Celulas.CelulaDupla;

// clear && javac -cp ../.. TP03Q11.java && java -cp ../.. TP03Q11.java < pub.in > result.txt

class TP03Q11 {

	static void QuickSortRec(CelulaDupla left, CelulaDupla right, Log log, ListaDupla lista) {

		CelulaDupla pivot = left, i = left.dir, j = right;

		while (j.dir != i && j.dir != i.esq) {
			while (i != null && lista.CompareTo(i, pivot, log) < 0) i = i.dir;
			while (lista.CompareTo(j, pivot, log) > 0) j = j.esq;
			if (j.dir != i) {
				lista.swap(i, j, log);
				i = i.dir;
				j = j.esq;
			}
		}

		lista.swap(pivot, j, log);

		if (j != left) QuickSortRec(left, j.esq, log, lista);
		if (j != right) QuickSortRec(j.dir, right, log, lista);
	}

	static void QuickSort(Log log, ListaDupla lista) {
		QuickSortRec(lista.getPrimeiro(), lista.getUltimo(), log, lista);
	}

	public static void main(String[] args) throws Exception {

		Timer timer = new Timer();
		Log log = new Log();

		BD BD = new BD("../tmp/players.csv");
		ListaDupla lista = new ListaDupla();

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.InserirFim(BD.Get(id));
		}

		timer.Start();
		QuickSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_quicksort2.txt", timer);		

	}
}
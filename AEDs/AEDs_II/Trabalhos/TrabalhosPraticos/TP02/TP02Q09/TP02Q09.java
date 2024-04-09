package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.TP02Q09;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Lista;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Log;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Timer;

// clear && javac -cp ../.. TP02Q09.java && java -cp ../.. TP02Q09.java < pub.in > result.txt

class TP02Q09 {

	private static void buildHeap(int root, int N, Log log, Lista lista) {

		int largest = root, l = 2 * root + 1, r = 2 * root + 2;

		if (l < N && lista.CompareToInt(l, largest, log)) largest = l;
		if (r < N && lista.CompareToInt(r, largest, log)) largest = r;

		if (largest != root) {
			lista.swap(root, largest, log);
			buildHeap(largest, N, log, lista);
		}

	}

	public static void HeapSort(Log log, Lista lista) {

		int N = lista.getSize();

		for (int i = N / 2 - 1; i >= 0; i--) {
			buildHeap(i, N, log, lista);
		}

		for (int i = N - 1; i > 0; i--) {
			lista.swap(0, i, log);
			buildHeap(0, i, log, lista);
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
			lista.setAtributoInt(BD.Get(id).getAltura());
		}

		timer.Start();
		HeapSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_heapsort.txt", timer);

	}
}
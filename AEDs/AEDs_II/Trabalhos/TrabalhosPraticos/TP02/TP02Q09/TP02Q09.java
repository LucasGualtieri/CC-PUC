import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q09.java && java -cp ../.. TP02Q09.java < pub.in > result.txt

class TP02Q09 {

	static void buildHeap(int root, int N, Lib.Log log, Lib.Lista lista) {

		int largest = root, l = 2 * root + 1, r = 2 * root + 2;

		if (l < N && lista.CompareToInt(l, largest, log)) largest = l;
		if (r < N && lista.CompareToInt(r, largest, log)) largest = r;

		if (largest != root) {
			lista.swap(root, largest, log);
			buildHeap(largest, N, log, lista);
		}
	}

	static void HeapSort(Lib.Log log, Lib.Lista lista) {

		int N = lista.getSize();

		for (int i = N / 2 - 1; i >= 0; i--) buildHeap(i, N, log, lista);

		for (int i = N - 1; i > 0; i--) {
			lista.swap(0, i, log);
			buildHeap(0, i, log, lista);
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
			lista.setAtributoInt(BD.Get(id).getAltura());
		}

		timer.Start();
		HeapSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_heapsort.txt", timer);

	}
}
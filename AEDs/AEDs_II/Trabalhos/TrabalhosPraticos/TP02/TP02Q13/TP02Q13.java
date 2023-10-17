import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q13.java && java -cp ../.. TP02Q13.java < pub.in > result.txt

class TP02Q13 {

	static void Merge(int left, int mid, int right, Lib.Log log, Lib.Lista lista) {
		int i, j, k;

		int n1 = mid - left + 1;
		int n2 = right - mid;

		Lib.Jogador[] a1 = new Lib.Jogador[n1 + 1];
		Lib.Jogador[] a2 = new Lib.Jogador[n2 + 1];

		for (i = 0; i < n1; i++) a1[i] = lista.Get(left + i).Clone();
		for (j = 0; j < n2; j++) a2[j] = lista.Get(mid + j + 1).Clone();

		a1[i] = new Lib.Jogador();
		a2[j] = new Lib.Jogador();

		a1[i].setUniversidade("");
		a2[j].setUniversidade("");

		for (i = j = 0, k = left; k <= right; k++) {
			if (i < n1 && (j >= n2 || a1[i].getUniversidade().compareTo(a2[j].getUniversidade()) <= 0)) {
				lista.array[k] = a1[i++];
			} else {
				lista.array[k] = a2[j++];
			}
		}
	}

	static void MergeSort(int left, int right, Lib.Log log, Lib.Lista lista) {
		if (left < right) {
			int mid = (left + right) / 2;
			MergeSort(left, mid, log, lista);
			MergeSort(mid + 1, right, log, lista);
			Merge(left, mid, right, log, lista);
		}
	}

	static void MergeSort(Lib.Log log, Lib.Lista lista) {
		MergeSort(0, lista.getSize() - 1, log, lista);
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
			lista.setAtributoStr(BD.Get(id).getUniversidade());
		}

		lista.SortByNome();

		timer.Start();
		MergeSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_mergesort.txt", timer);		

	}

}
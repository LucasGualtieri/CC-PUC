import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q07.java && java -cp ../.. TP02Q07.java < pub.in > result.txt

class TP02Q07 {

	static boolean AnoNascimentoCmp(Lib.Jogador jog1, Lib.Jogador jog2, Lib.Log log) {
		log.incrementarComparacoes();
		return jog1.getAnoNascimento() > jog2.getAnoNascimento();
	}

	static void InsertionSort(Lib.Lista lista, Lib.Log log) {

		int	N = lista.getSize();
		Lib.Jogador[] array = lista.array;

		int j;
		for (int i = 1; i < N; i++) {
			Lib.Jogador temp = array[i];
			j = i - 1;
			while (j >= 0 && AnoNascimentoCmp(array[j], temp, log)) {
				array[j + 1] = array[j--];
				log.incrementarMovimentacoes(1);
			}
			array[j + 1] = temp;
			log.incrementarMovimentacoes(2);
		}

	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Timer timer = new Lib.Timer();
		Lib.Log log = new Lib.Log();

		Lib.Lista BD = new Lib.Lista("../tmp/players.csv", BD_SIZE);
		Lib.Lista listaJogadores = new Lib.Lista(465); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			listaJogadores.Inserir(BD.Get(id));
		}

	 	listaJogadores.SortByNome();

		timer.Start();
		InsertionSort(listaJogadores, log);
		timer.Stop();

		listaJogadores.Mostrar();

		log.RegistroOrdenacao("794989_insercao.txt", timer);		

	}

	// static int BinarySearch(int x, Lib.Jogador[] array, int right) {

	// 	int	left = 0, pivotValue, pivot;
	// 	do {
	// 		pivot = (left + right) / 2;
	// 		pivotValue = array[pivot].getAnoNascimento();
	// 		if (pivotValue < x) left = pivot + 1;
	// 		else right = pivot - 1;
	// 	} while (left <= right);
		
	// 	return pivotValue <= x ? pivot + 1 : pivot;
	// }

	// static void InsertionSort(Lib.Lista lista, Lib.Log log) {
		
	// 	int N = lista.getSize();
	// 	Lib.Jogador[] array = lista.array;

	// 	Lib.Jogador tmp;
	// 	int shiftIndex;
	// 	for (int i = 1; i < N; i++) {
	// 		tmp = array[i];
	// 		shiftIndex = BinarySearch(tmp.getAnoNascimento(), array, i - 1);
	// 		for (int j = i; j > shiftIndex; j--) {
	// 			array[j] = array[j - 1];
	// 			log.incrementarMovimentacoes(1);
	// 		}
	// 		array[shiftIndex] = tmp;
	// 		log.incrementarMovimentacoes(2);
	// 	}
	// }

}
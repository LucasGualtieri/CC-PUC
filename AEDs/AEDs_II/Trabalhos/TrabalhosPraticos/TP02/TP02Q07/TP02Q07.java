import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q07.java && java -cp ../.. TP02Q07.java < pub.in > result.txt

class TP02Q07 {

	static boolean AnoNascimentoCmp(Lib.Jogador jog1, Lib.Jogador jog2, Lib.Log log) {
		log.incrementarComparacoes(2);
		if (jog1.getAnoNascimento() != jog2.getAnoNascimento()) {
			return jog1.getAnoNascimento() > jog2.getAnoNascimento();
		} else {
			return jog1.getNome().compareTo(jog2.getNome()) > 0;
		}
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

		timer.Start();
		InsertionSort(listaJogadores, log);
		timer.Stop();

		listaJogadores.Mostrar();

		log.RegistroOrdenacao("794989_insercao.txt", timer);		

	}

	// Não consegue ordenar por nome como desempate, precisaria ordenar o array duas vezes
	// static int BinarySearch(int x, int right, Lib.Log log, Lib.Jogador[] array) {

	// 	int	left = 0, pivotValue, pivot;
	// 	do {
	// 		pivot = (left + right) / 2;
	// 		pivotValue = array[pivot].getAnoNascimento();
	// 		if (pivotValue < x) left = pivot + 1;
	// 		else right = pivot - 1;
	// 		log.incrementarComparacoes();
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
	// 		shiftIndex = BinarySearch(tmp.getAnoNascimento(), i - 1, log, array);
	// 		for (int j = i; j > shiftIndex; j--) {
	// 			array[j] = array[j - 1];
	// 			log.incrementarMovimentacoes(1);
	// 		}
	// 		array[shiftIndex] = tmp;
	// 		log.incrementarMovimentacoes(2);
	// 	}
	// }

}
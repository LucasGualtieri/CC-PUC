import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q11.java && java -cp ../.. TP02Q11.java < pub.in > result.txt

class TP02Q11 {

	static void CountingSort(Lib.Lista lista, Lib.Log log) {

		Lib.Jogador[] array = lista.array;
		int	N = lista.getSize();

		int maxValue = array[0].getAltura();
		int minValue = array[0].getAltura();

		for (int i = 0; i < N; i++) {
			int altura = array[i].getAltura();
			if (altura > maxValue) maxValue = altura;
			if (altura < minValue) minValue = altura;
		}

		int[] countArray = new int[++maxValue + 1];
		for (int i = 0; i < N; i++) countArray[array[i].getAltura()]++;
		for (int i = minValue; i < maxValue; i++) countArray[i] += countArray[i - 1];

		Lib.Jogador[] auxArray = new Lib.Jogador[N];

		for (int i = 0; i < N; i++) {
			auxArray[countArray[array[i].getAltura()]-- - 1] = array[i];
		}

		lista.array = auxArray;

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
		CountingSort(listaJogadores, log);
		timer.Stop();

		listaJogadores.Mostrar();

		log.RegistroOrdenacao("794989_countingsort.txt", timer);		

	}

}
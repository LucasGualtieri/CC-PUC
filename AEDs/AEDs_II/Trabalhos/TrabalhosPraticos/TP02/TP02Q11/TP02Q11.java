import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q11.java && java -cp ../.. TP02Q11.java < pub.in > result.txt

class TP02Q11 {

	static void CountingSort(Lib.Log log, Lib.Lista lista) {

		int	N = lista.getSize();
		Lib.Jogador[] array = lista.array;

		Lib.Jogador[] auxArray = new Lib.Jogador[N];

		int maxValue = array[0].getAltura();
		int minValue = array[0].getAltura();

		for (int i = 0; i < N; i++) {
			int altura = array[i].getAltura();
			if (altura > maxValue) maxValue = altura;
			if (altura < minValue) minValue = altura;
		}

		int countSize = (maxValue - minValue) + 1;
		int[] countArray = new int[countSize];

		for (int i = 0; i < N; i++) countArray[array[i].getAltura() - minValue]++;
		for (int i = 1; i < countSize; i++) countArray[i] += countArray[i - 1];

		for (int i = N - 1; i >= 0; i--) {
			int alturaPos = array[i].getAltura() - minValue;
			auxArray[countArray[alturaPos]-- - 1] = array[i];
		}

		lista.array = auxArray;

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
		}

	 	lista.SortByNome();

		timer.Start();
		CountingSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_countingsort.txt", timer);		

	}

}
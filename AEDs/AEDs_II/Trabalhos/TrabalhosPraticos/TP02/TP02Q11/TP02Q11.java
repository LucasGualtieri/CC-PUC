package TP02.TP02Q11;

import TP02.Libs.Lib;
import TP02.Libs.Lib.Jogador;
import TP02.Libs.Lib.Lista;
import TP02.Libs.Lib.Log;
import TP02.Libs.Lib.Timer;

// clear && javac -cp ../.. TP02Q11.java && java -cp ../.. TP02Q11.java < pub.in > result.txt

class TP02Q11 {

	static void CountingSort(Log log, Lista lista) {

		int	N = lista.getSize();
		Jogador[] array = lista.array;

		Jogador[] auxArray = new Jogador[N];

		int maxValue = array[0].getAltura();
		int minValue = array[0].getAltura();

		for (int i = 1; i < N; i++) {
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
			auxArray[--countArray[alturaPos]] = array[i];
			log.incrementarMovimentacoes();
		}

		lista.array = auxArray;

	}

	static void InsertionSort(Log log, Lista lista) {

		int N = lista.getSize();
		Jogador[] array = lista.array;

		for (int i = 1; i < N; i++) {
			Jogador temp = array[i];
			int j = i - 1;
			while (j >= 0 && lista.CompareToInt(j, temp, log)) {
				array[j + 1] = array[j--];
				log.incrementarMovimentacoes(1);
			}
			array[j + 1] = temp;
			log.incrementarMovimentacoes(2);
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
		CountingSort(log, lista);
		InsertionSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_countingsort.txt", timer);		

	}
}
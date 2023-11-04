package TP02.TP02Q07;

import TP02.Libs.Lib;
import TP02.Libs.Lib.Jogador;
import TP02.Libs.Lib.Lista;
import TP02.Libs.Lib.Log;
import TP02.Libs.Lib.Timer;

// clear && javac -cp ../.. TP02Q07.java && java -cp ../.. TP02Q07.java < pub.in > result.txt

class TP02Q07 {

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
			lista.setAtributoInt(BD.Get(id).getAnoNascimento());
		}

		timer.Start();
		InsertionSort(log, lista);
		// BinaryInsertionSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_insercao.txt", timer);

	}

	static void BinaryInsertionSort(Log log, Lista lista) {
		
		int N = lista.getSize();
		Jogador[] array = lista.array;

		Jogador temp;
		int shiftIndex;
		for (int i = 1; i < N; i++) {
			temp = array[i];
			shiftIndex = BinarySearch(temp, i - 1, log, array);
			for (int j = i; j > shiftIndex; j--) {
				array[j] = array[j - 1];
				log.incrementarMovimentacoes(1);
			}
			array[shiftIndex] = temp;
			log.incrementarMovimentacoes(2);
		}
	}

	static int BinarySearch(Jogador temp, int right, Log log, Jogador[] array) {

		int	nomeComp, left = 0, pivotValue = 0, pivot = 0;
		int tempVal = temp.getAnoNascimento();
		
		while (left <= right) {

			pivot = (left + right) / 2;
			pivotValue = array[pivot].getAnoNascimento();

			if (pivotValue == tempVal) {
				nomeComp = temp.getNome().compareTo(array[pivot].getNome());
				if (nomeComp < 0) right = pivot - 1;
				else left = pivot + 1;
			} else if (pivotValue > tempVal) {
				right = pivot - 1;
			} else {
				left = pivot + 1;
			}

			log.incrementarComparacoes(2);
		}
		
		return left;
	}
}
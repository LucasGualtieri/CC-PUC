package TP02.TP02Q13;

import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q13.java && java -cp ../.. TP02Q13.java < pub.in > result.txt

class TP02Q13 {

	static void Merge(int left, int right, Lib.Log log, Lib.Lista lista) {
		
		int auxSize = (right - left) + 1, mid = ((auxSize + 1) / 2);

		Lib.Jogador[] array = lista.array;
		Lib.Jogador[] auxArray = new Lib.Jogador[auxSize];

		for (int i = 0; i < auxSize; i++) auxArray[i] = array[left + i];
		log.incrementarMovimentacoes(auxSize);

		for (int i = 0, j = mid; left <= right; left++) {
			if (i < mid && j < auxSize) {
				boolean comp = lista.CompareToStr(auxArray[i], auxArray[j], log);
				array[left] = comp ? auxArray[i++] : auxArray[j++];
			} else {
				array[left] = i < mid ? auxArray[i++] : auxArray[j++];
			}
			log.incrementarMovimentacoes();
		}
	}

	static void MergeSort(int left, int right, Lib.Log log, Lib.Lista lista) {
		if (left < right) {
			int mid = (left + right) / 2;
			MergeSort(left, mid, log, lista);
			MergeSort(mid + 1, right, log, lista);
			Merge(left, right, log, lista);
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

		timer.Start();
		MergeSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_mergesort.txt", timer);		

	}

}
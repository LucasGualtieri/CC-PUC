package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.TP02Q13;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib;
// import TP02.Libs.Lib.Jogador;
// import TP02.Libs.Lib.Log;

// clear && javac -cp ../.. TP02Q13Padrao.java && java -cp ../.. TP02Q13Padrao.java < pub.in > result.txt

class TP02Q13Padrao {

	// public boolean CompareToStr(Jogador jog1, Jogador jog2, Log log) {

	// 	if (jog1.atributoStr.compareTo("ZZ") == 0) {
	// 		return false;
	// 	} else if (jog2.atributoStr.compareTo("ZZ") == 0) {
	// 		return true;
	// 	}

	// 	log.incrementarComparacoes();
	// int strComp = strcmp(jog1.atributoStr, jog2.atributoStr);

	// 	if (strComp == 0) {
	// 		log.incrementarComparacoes();
	// 		// strComp = strcmp(jog1.getNome(), jog2.getNome());
	// 	}

	// 	return strComp <= 0;
	// }

	static void Merge(int left, int mid, int right, Lib.Log log, Lib.Lista lista) {
		
		Lib.Jogador[] array = lista.array;

		int i, j, lSize = mid - left + 1, rSize = right - mid;

		Lib.Jogador[] aLeft = new Lib.Jogador[lSize + 1];
		Lib.Jogador[] aRight = new Lib.Jogador[rSize + 1];

		for (i = 0; i < lSize; i++) aLeft[i] = array[left + i];
		for (j = 0; j < rSize; j++) aRight[j] = array[mid + j + 1];
		log.incrementarMovimentacoes(lSize + rSize);

		aLeft[i] = aRight[j] = new Lib.Jogador("ZZ");

		for (i = j = 0; left <= right; left++) {
			boolean comp = lista.CompareToStr(aLeft[i], aRight[j], log);
			array[left] = comp ? aLeft[i++] : aRight[j++];
			log.incrementarMovimentacoes();
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

		timer.Start();
		MergeSort(log, lista);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao("794989_mergesort.txt", timer);		

	}

}
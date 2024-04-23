package AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.TP02Q05;

import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Log;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Lista;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Timer;
import AEDs.AEDs_II.Trabalhos.TrabalhosPraticos.TP02.Libs.Lib.Jogador;

// clear && javac -cp ../.. TP02Q05.java && java -cp ../.. TP02Q05.java < pub.in > result.txt

class TP02Q05 {

	interface Comparable {
		int compareTo(Jogador x, Jogador y);		
	}

	static void SelectionSort(Log log, Lista lista, Comparable c) {

		int i, j, menor;
		for (i = 0; i < lista.getSize() - 1; i++) {
			menor = i;
			for (j = i + 1; j < lista.getSize(); j++) {
				int compare = c.compareTo(lista.Get(menor), lista.Get(j));
				if (compare > 0) menor = j;
			}
			lista.swap(i, menor, log);
		}

	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Timer timer = new Timer();
		Log log = new Log();

		String path = "AEDs/AEDs_II/Trabalhos/TrabalhosPraticos/TP02/";

		Lista BD = new Lista(path + "tmp/players.csv", BD_SIZE);
		Lista lista = new Lista(465); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			lista.Inserir(BD.Get(id));
		}

		Comparable c = (x, y) -> {
			log.incrementarComparacoes();
			int r = Integer.compare(x.getAnoNascimento(), y.getAnoNascimento());
			return r != 0 ? r : x.getNome().compareTo(y.getNome());
		};

		timer.Start();
		SelectionSort(log, lista, c);
		timer.Stop();

		lista.Mostrar();

		log.RegistroOrdenacao(path + "TP02Q05/794989_selecao.txt", timer);		
	}
}
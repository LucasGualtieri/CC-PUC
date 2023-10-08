import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q15.java && java -cp ../.. TP02Q15.java < pub.in > result.txt

class TP02Q15 {

	static int strcmpr(Lib.Jogador jog1, Lib.Jogador jog2) {
		return jog1.getNome().compareTo(jog2.getNome());
	}

	static void SelectionSortParcial(int k, Lib.Lista lista, Lib.Log log) {

		int N = lista.getSize();
		Lib.Jogador[] array = lista.array;

		int i, j, menor;
		for (i = 0; i < k; i++) {
			menor = i;
			for (j = i + 1; j < N; j++) {
				if (strcmpr(array[menor], array[j]) > 0) menor = j;
				log.incrementarComparacoes();
			}
			Lib.swap(i, menor, array);
			log.incrementarMovimentacoes(3);
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

		int k = 10;

		timer.Start();
		SelectionSortParcial(k, listaJogadores, log);
		timer.Stop();

		listaJogadores.MostrarParcial(k);

		log.RegistroOrdenacao("794989_selecaoParcial.txt", timer);		

	}

}
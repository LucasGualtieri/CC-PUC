import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q05.java && java -cp ../.. TP02Q05.java < pub.in > result.txt

class TP02Q05 {

	static int strcmpr(Lib.Jogador jog1, Lib.Jogador jog2) {
		return jog1.getNome().compareTo(jog2.getNome());
	}

	static void SelectionSort(Lib.Lista lista, Lib.Log log) {

		int i, j, menor;
		for (i = 0; i < lista.getSize() - 1; i++) {
			menor = i;
			for (j = i + 1; j < lista.getSize(); j++) {
				if (strcmpr(lista.array[menor], lista.array[j]) > 0) menor = j;
				log.incrementarComparacoes();
			}
			Lib.swap(i, menor, lista.array);
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

		timer.Start();
		SelectionSort(listaJogadores, log);
		timer.Stop();

		listaJogadores.Mostrar();

		log.RegistroOrdenacao("794989_selecao.txt", timer);		

	}

}
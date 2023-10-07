import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q07.java && java -cp ../.. TP02Q07.java < pub.in > result.txt

class TP02Q07 {

	static boolean AnoNascimentoCmp(Lib.Jogador jog1, Lib.Jogador jog2, Lib.Log log) {
		log.incrementarComparacoes();
		return jog1.getAnoNascimento() > jog2.getAnoNascimento();
	}

	static void InsertionSort(Lib.Lista lista, Lib.Log log) {

		int j;
		for (int i = 1; i < lista.getSize(); i++) {
			Lib.Jogador temp = lista.array[i];
			j = i - 1;
			while (j >= 0 && AnoNascimentoCmp(lista.array[j], temp, log)) {
				lista.array[j + 1] = lista.array[j--];
				log.incrementarMovimentacoes(1);
			}
			lista.array[j + 1] = temp;
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

	 	listaJogadores.SortByNome();

		timer.Start();
		InsertionSort(listaJogadores, log);
		timer.Stop();

		listaJogadores.Mostrar();

		log.RegistroOrdenacao("794989_insercao.txt", timer);		

	}

}
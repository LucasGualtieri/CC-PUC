import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q03.java && java -cp ../.. TP02Q03.java < pub.in > result.txt

class TP02Q03 {

	static boolean PesquisaSequencial(String nome, Lib.Lista lista, Lib.Log resultado) {

		boolean hasFound = false;
		
		for (int i = 0; i < lista.getSize(); i++) {
			if (lista.array[i].getNome().contains(nome)) {
				i = lista.getSize();
				hasFound = true;
			}
			resultado.incrementarComparacoes();
		}

		return hasFound;
	}

	static final int BD_SIZE = 3922;

	public static void main(String[] args) throws Exception {

		Lib.Timer timer = new Lib.Timer();
		Lib.Log resultado = new Lib.Log();

		Lib.Lista BD = new Lib.Lista("../tmp/players.csv", BD_SIZE);
		Lib.Lista listaJogadores = new Lib.Lista(74); // Tamanho de entradas do pri.in

		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			listaJogadores.Inserir(BD.Get(id));
		}

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean hasFound = PesquisaSequencial(inputPUBIN, listaJogadores, resultado);
			System.out.println(hasFound ? "SIM" : "NAO");
		}
		timer.Stop();

		Lib.Log.RegistroPesquisa("794989_sequencial.txt", timer);		

	}
}
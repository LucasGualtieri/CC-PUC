import TP02.Libs.Lib;

// clear && javac -cp ../.. TP02Q15.java && java -cp ../.. TP02Q15.java < pub.in > result.txt

class TP02Q15 {

	static void SelectionSortParcial(int k, Lib.Lista lista, Lib.Log log) {

		int i, j, menor;
		for (i = 0; i < k; i++) {
			menor = i;
			for (j = i + 1; j < lista.getSize(); j++) {
				if (lista.CompareToStr(menor, j, log)) menor = j;
			}
			lista.swap(i, menor, log);
		}

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
			lista.setAtributoStr(BD.Get(id).getNome());
		}

		int k = 10;

		timer.Start();
		SelectionSortParcial(k, lista, log);
		timer.Stop();

		lista.MostrarParcial(k);

		log.RegistroOrdenacao("794989_selecaoParcial.txt", timer);		

	}

}
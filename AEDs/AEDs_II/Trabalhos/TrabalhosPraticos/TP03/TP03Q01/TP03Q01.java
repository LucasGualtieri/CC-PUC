import TP03.Libs.Lib;

// clear && javac -cp ../.. TP03Q01.java && java -cp ../.. TP03Q01.java < pub.in > result.txt

class TP03Q01 {

	public static void main(String[] args) throws Exception {

		Lib.Lista BD = new Lib.Lista("../tmp/players.csv", BD_SIZE);
		Lib.Lista listaJogadores = new Lib.Lista(200);

		String inputPUBIN = new String();

		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			listaJogadores.Inserir(BD.Get(id));
		}

		listaJogadores.Mostrar();

	}
}
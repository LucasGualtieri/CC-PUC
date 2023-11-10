package TT01.ArquivosEmJava.Ex1;

import TT01.ArquivosEmJava.Arq;

class Ex1 {
	public static void main(String[] args) {
		Arq.openRead("AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex1/arquivoText.txt", "UTF-8");
		String allLinesFromFile;

		allLinesFromFile = Arq.readAll();

		System.out.println(allLinesFromFile);

		Arq.close();
		Arq.openWrite("AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex1/arquivoText_copy.txt", "UTF-8");

		Arq.print(allLinesFromFile);
		Arq.close(); // Opcional
	}
}

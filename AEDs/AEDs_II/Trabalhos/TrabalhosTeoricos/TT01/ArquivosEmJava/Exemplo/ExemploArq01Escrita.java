package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.ArquivosEmJava.Exemplo;

import AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.ArquivosEmJava.Arq;

class ExemploArq01Escrita {
	public static void main(String[] args) {
		Arq.openWrite("AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Exemplo/Exemplo.txt");
		Arq.println(1);
		Arq.println(5.3);
		Arq.println('X');
		Arq.println(true);
		Arq.println("Algoritmos");
		Arq.close();
	}
}
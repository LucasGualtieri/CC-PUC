package AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.ArquivosEmJava.Ex2;

import java.util.*;

import AEDs.AEDs_II.Trabalhos.TrabalhosTeoricos.TT01.ArquivosEmJava.Arq;

class Ex2 {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		System.out.print("Digite uma frase: ");
		String frase = scanner.nextLine();

		String filePath = "AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex2/";
		System.out.print("Digite o nome do arquivo: ");
		String fileName = filePath + scanner.next() + ".txt";

		Arq.openWriteClose(fileName, frase);

		System.out.print("Digite o nome do arquivo: ");
		fileName = filePath + scanner.next() + ".txt";

		System.out.print(Arq.openReadClose(fileName));

		System.out.print("Digite o nome do arquivo: ");
		fileName = filePath + scanner.next() + ".txt";
		System.out.print(Arq.openReadClose(fileName).toUpperCase());

		System.out.print("Digite o nome do arquivo: ");
		fileName = filePath + scanner.next() + ".txt";
		System.out.print("Digite o nome do arquivo: ");
		String newFile = filePath + scanner.next() + ".txt";

		Arq.openWriteClose(newFile, Arq.openReadClose(fileName));

		scanner.close();
	}
}

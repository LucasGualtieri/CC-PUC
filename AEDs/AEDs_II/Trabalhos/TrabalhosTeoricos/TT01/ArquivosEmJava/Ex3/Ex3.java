package TT01.ArquivosEmJava.Ex3;

import TT01.ArquivosEmJava.Arq;
import java.util.*;

class Ex3 {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		String filePath = "AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Ex3/";

		System.out.print("Digite o nome do arquivo: ");
		String firstFile = filePath + scanner.next() + ".txt";
		System.out.print("Digite o nome do arquivo: ");
		String secondFile = filePath + scanner.next() + ".txt";

		Arq.openRead(firstFile, "UTF-8");
		String str = Arq.readAll().toUpperCase();
		Arq.openWriteClose(secondFile, "UTF-8", str);
		Arq.close();

		System.out.print("Digite o nome do arquivo: ");
		firstFile = filePath + scanner.next() + ".txt";
		System.out.print("Digite o nome do arquivo: ");
		secondFile = filePath + scanner.next() + ".txt";

		Arq.openRead(secondFile, "UTF-8");
		str = Arq.readAll();
		StringBuilder reversed = new StringBuilder(str.substring(0, str.length() - 2));
		str = reversed.reverse().toString();
		Arq.openWriteClose(firstFile, "UTF-8", str);

		scanner.close();
	}
}

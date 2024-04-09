package AEDs.AEDs_II.Provas.Prova1.Treino.Espelho;

import java.util.*;

// clear && javac Espelho.java && java Espelho.java < pub.in > result.txt

class Espelho {

	static void MostrarEspelho(int li, int ls) {
		String aux = "";
		for (int i = li; i <= ls; i++) {
			aux += i;
		}
		for (int i = aux.length() - 1; i >= 0; i--) {
			aux += aux.charAt(i);
		}
		System.out.println(aux);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNextLine()) {
			MostrarEspelho(scanner.nextInt(), scanner.nextInt());
			if (scanner.hasNextLine()) scanner.nextLine();
		}

		scanner.close();
	}
}
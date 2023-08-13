import java.util.*;

class Ex18 {

	static Scanner scanner = new Scanner(System.in);

	static void flush() {
		scanner.nextLine();
	}

	static char toUpper(char c) {
		return (char) ('a' <= c && c <= 'z' ? c - 32 : c);
	}

	static boolean isVogal(char c) {
		c = toUpper(c);
		return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}

	static boolean isAlpha(char c) {
		return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
	}

	static boolean isConsonant(char c) {
		return !isVogal(c) && isAlpha(c);
	}

	static void letraC() {

		System.out.println("\nLetra c):\n");

		System.out.print("Digite uma string: ");
		String string = scanner.nextLine();

		int alpha = 0, notAlpha = 0, vowels = 0, consonants = 0;

		for (int i = 0; i < string.length(); i++) {
			char c = string.charAt(i);
			if (isAlpha(c)) {
				alpha++;
			}
			if (!isAlpha(c)) {
				notAlpha++;
			}
			if (isVogal(c)) {
				vowels++;
			}
			if (isConsonant(c)) {
				consonants++;
			}
		}

		System.out.println("Número de letras: " + alpha);
		System.out.println("Número de não letras: " + notAlpha);
		System.out.println("Número de vogais: " + vowels);
		System.out.println("Número de consoantes: " + consonants);

		System.out.println("\n---------------------\n");
	}

	static void letraB() {

		System.out.println("\nLetra b):\n");

		System.out.print("Digite uma string: ");
		String string = scanner.nextLine();

		int indexOfA = string.indexOf("A");
		int indexOfa = string.indexOf("a");

		// = (0 >= indexOfA && indexOfa >= 0) && indexOfA < indexOfa ? indexOfA :
		// indexOfa;
		int index;

		if (indexOfA >= 0 && indexOfa >= 0) {
			index = indexOfA < indexOfa ? indexOfA : indexOfa;
		} else {
			index = indexOfA > 0 ? indexOfA : indexOfa;
		}

		System.out.println("A letra 'A' aparece pela primeira vez no indice: " + index);

		System.out.println("---------------------\n");
	}

	static void letraA() {

		System.out.println("\nLetra a):\n");

		System.out.print("Digite uma palavra: ");
		String string = scanner.next();

		System.out.println("A quantidade de caracteres da string é: " + string.length());

		int qtdMaiusculas = 0;

		for (int i = 0; i < string.length(); i++) {
			if ('A' <= string.charAt(i) && string.charAt(i) <= 'Z') {
				qtdMaiusculas++;
			}
		}

		System.out.println("A quantidade de caracteres maiúsculos da string é: " + qtdMaiusculas);

		System.out.println("---------------------\n");
	}

	public static void main(String[] args) {
		while (optionsMenu()) {
			continue;
		}
	}

	static int ReadingChoice() {
		int choice;
		boolean invalid = false;

		do {
			if (invalid) {
				System.out.println("Valor inválido, tente novamente: ");
			}
			choice = scanner.nextInt();
			flush();
		} while ((invalid = choice < 0 || 3 < choice));

		return choice;
	}

	static boolean optionsMenu() {

		System.out.println("Ex12 letras a) -> c)\n");
		System.out.println("0 - Sair do programa");
		System.out.println("1 - a)");
		System.out.println("2 - b)");
		System.out.println("3 - c)");
		System.out.print("Escolha uma das opções acima: ");

		int escolha = ReadingChoice();

		switch (escolha) {
			case 1:
				letraA();
				break;
			case 2:
				letraB();
				break;
			case 3:
				letraC();
				break;
		}

		return escolha != 0;
	}
}

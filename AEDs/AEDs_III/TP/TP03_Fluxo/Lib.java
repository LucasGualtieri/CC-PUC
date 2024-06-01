package TP03;

import java.util.Scanner;
import java.util.InputMismatchException;

public class Lib {

	// Variáveis usadas para printar mensagens com cores

	public static final String BOLD = "\u001B[1m";
	public static final String RED = "\u001B[31m";
	public static final String GREEN = "\u001B[32m";
	public static final String YELLOW = "\u001B[33m";
	public static final String BLUE = "\u001B[34m";
	public static final String MAGENTA = "\u001B[35m";
	public static final String CYAN = "\u001B[36m";
	public static final String RESET = "\u001B[0m";

	private static Scanner scanner = new Scanner(System.in);

	// Função usada em diversos momentos quando o usuário precisa decidir qual opção do menu escolher
	public static int ReadChoice(int choiceCount) {
		int	 choice;
		boolean invalid = false;
	
		do {
			if (invalid) {
				Lib.cprintf("BOLD RED", "Valor inválido, ");
				System.out.print("tente novamente: ");
			}
			choice = Lib.readInt();
		} while (invalid = choice < 0 || choiceCount < choice);
	
		return choice;
	}

	// Função para ler um inteiro do teclado
	public static int readInt() throws InputMismatchException {
		
		int value = -1;

		boolean invalid = false;

		do {
			if (invalid) {
				cprintf(BOLD + RED, "Valor inválido, ");
				System.out.print("tente novamente: ");
			}

			try {
				String aux = scanner.nextLine();
				if (aux.length() > 0) value = Integer.parseInt(aux);
				invalid = false;
			} catch (NumberFormatException e) {
				invalid = true;
			}

		} while (invalid);

		return value;
	}

	// Função para ler um float do teclado
	public static float readFloat() throws InputMismatchException {
		
		float value = -1;

		boolean invalid = false;

		do {
			if (invalid) {
				cprintf(BOLD + RED, "Valor inválido, ");
				System.out.print("tente novamente: ");
			}

			try {
				String aux = scanner.nextLine();
				if (aux.length() > 0) value = Float.parseFloat(aux);
				invalid = false;
			} catch (NumberFormatException e) {
				invalid = true;
			}

		} while (invalid);

		return value;
	}

	// Função para ler uma string do teclado
	public static String readString() {
		
		String value;

		value = scanner.nextLine();

		return value;
	}

	// Função para limpar a tela
	public static void clearScreen() {
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    }

	// Função para printar mensagens com cores
	public static void cprintf(String color, String format, Object...args) {

		if (color == "BOLD") color = BOLD;
		else if (color == "RED") color = RED;
		else if (color == "BOLD RED") color = BOLD + RED;
		else if (color == "GREEN") color = GREEN;
		else if (color == "BOLD GREEN") color = BOLD + GREEN;
		else if (color == "YELLOW") color = YELLOW;
		else if (color == "BOLD YELLOW") color = BOLD + YELLOW;
		else if (color == "BLUE") color = BLUE;
		else if (color == "BOLD BLUE") color = BOLD + BLUE;
		else if (color == "MAGENTA") color = MAGENTA;
		else if (color == "BOLD MAGENTA") color = BOLD + MAGENTA;
		else if (color == "CYAN") color = CYAN;
		else if (color == "BOLD CYAN") color = BOLD + CYAN;

		System.out.printf(color + format + RESET, args);
	}

	// Função para printar as linhas que formam os cabeçalhos dos menus
	public static void printdiv(int prepend, int append, String text, Object...args) {
		for (int i = 0; i < prepend; i++) System.out.println();
		printdiv(text, args);
		for (int i = 0; i < append; i++) System.out.println();
	}

	public static void printdiv(int lines, String text, Object...args) {
		printdiv(text, args);
		for (int i = 0; i < lines; i++) System.out.println();
	}

	public static void printdiv(String text, Object...args) {
		
		int lineLength = 50;
		
		String div = "";

		int textTotalLength = text.length();
		
		for (Object obj : args) textTotalLength += obj.toString().length() - 2;

		int divSize = (lineLength - textTotalLength) / 2;

		for (int i = 0; i < divSize; i++) div += "-";

		System.out.print(div + " ");
		System.out.printf(text, args);
		System.out.println(" " + div);
	}

}
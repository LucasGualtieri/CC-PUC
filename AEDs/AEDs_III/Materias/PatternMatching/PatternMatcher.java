package AEDs.AEDs_III.Materias.PatternMatching;

import java.io.*;
import java.util.*;

import AEDs.AEDs_III.Materias.PatternMatching.MatchingStrategies.*;

// clear && javac Matcher.java && java Matcher.java

/**
 * The PatternMatcher class provides implementations for pattern matching using
 * various algorithms, including the Boyer-Moore and Knuth-Morris-Pratt (KMP).
 * It supports interchangeable strategies through the MatcherStrategy interface.
 * It also allows matching patterns in both string and byte array formats.
 */
class PatternMatcher {

	static Scanner scanner = new Scanner(System.in);

	static final String filePath = "AEDs/AEDs_III/Materias/PatternMatching/";

	// Aprender doxygen.

	public static void main(String[] args) throws IllegalArgumentException {

		clearScreen();

		String text = readFromFile(filePath + "sampleText.txt");
		System.out.println(text);

		String pattern;

		Matcher matcher = new Matcher(new BoyerMoore());

		do {

			System.out.print("Digite o pattern: ");
			pattern = scanner.nextLine();

			List<Integer> indices = matcher.match(pattern, text);

			// matcher.printInternalStructures();

			printHighlighted(pattern, text, indices);
			System.out.printf("Comparisons: %d\n\n", matcher.getComparisons());

		} while (!pattern.toUpperCase().equals("FIM"));
	}

	/**
	 * Prints the text with occurrences of the pattern highlighted in bold and green.
	 *
	 * @param pattern The pattern to highlight in the text.
	 * @param text The text in which to highlight the pattern.
	 * @param indices The list of starting indices where the pattern is found.
	 */
	static void printHighlighted(String pattern, String text, List<Integer> indices) {

		clearScreen();

		final byte[] textBytes = text.getBytes();
		final int patternLength = pattern.getBytes().length;
		final String GREEN = "\u001B[42m", RESET = "\u001B[0m";

		List<Byte> sequence = new LinkedList<>();

		int state = 0;

		for (int i = 0; i < textBytes.length; i++) {

			if (!indices.isEmpty() && i == indices.get(0)) {
				indices.remove(0);
				if (state == 0) append(GREEN, sequence);
				state = patternLength;
			}

			sequence.add(textBytes[i]);

			if (state > 0 && --state == 0) append(RESET, sequence);
		}

		byte[] highlightedSequence = new byte[sequence.size()];

		for (int i = 0; i < sequence.size(); i++) {
			highlightedSequence[i] = sequence.get(i);
		}

		System.out.println(new String(highlightedSequence));

	}

	static void append(String ANSI, List<Byte> sequence) {
		for (byte b : ANSI.getBytes()) sequence.add(b);
	}

	/**
	 * Clears the console screen by printing the ANSI escape code for clearing the screen.
	 */
	public static void clearScreen() {
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}

	/**
	 * Reads the content of a file from the given file path.
	 *
	 * @param filePath The path to the file to be read.
	 * @return The content of the file as a string.
	 */
	static String readFromFile(String filePath) {

		StringBuilder content = new StringBuilder();

		try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
			String line;
			while ((line = reader.readLine()) != null) {
				content.append(line).append("\n");
			}
		}

		catch (IOException e) {
			// e.printStackTrace();
			System.out.println("Error: File not found.");
			System.exit(-1);
		}

		return content.toString();
	}

	// if (pattern.equals("1")) {
	// 	matcher.setMatcherStrategy(new BruteForce());
	// 	System.out.print("Digite o pattern: ");
	// 	pattern = scanner.nextLine();
	// }
	
	// else if (pattern.equals("2")) {
	// 	matcher.setMatcherStrategy(new KMP());
	// 	System.out.print("Digite o pattern: ");
	// 	pattern = scanner.nextLine();
	// }

	// else if (pattern.equals("3")) {
	// 	matcher.setMatcherStrategy(new BoyerMoore());
	// 	System.out.print("Digite o pattern: ");
	// 	pattern = scanner.nextLine();
	// }
}
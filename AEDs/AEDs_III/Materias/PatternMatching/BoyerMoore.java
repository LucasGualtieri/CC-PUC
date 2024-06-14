package AEDs.AEDs_III.Materias.PatternMatching;

import java.io.*;
import java.util.*;

// clear && javac BoyerMoore.java && java BoyerMoore.java

class BoyerMoore {

	/**
	 * BoyerMooreMatcher class implements the Boyer-Moore pattern search algorithm.
	 */
	static class BoyerMooreMatcher {

		private int[] lastOccurrences, goodSuffixes;

		private byte[] pattern;
		
		/**
		 * Constructor to create a BoyerMooreMatcher with a pattern byte array.
		 *
		 * @param pattern The pattern byte array to be matched.
		 * @throws IllegalArgumentException If the pattern is empty.
		 */
		public BoyerMooreMatcher(String pattern) throws IllegalArgumentException {
			this(pattern.getBytes());
		}

		/**
		 * Constructor to create a BoyerMooreMatcher with a pattern byte array.
		 *
		 * @param pattern The pattern byte array to be matched.
		 * @throws IllegalArgumentException If the pattern is empty.
		 */
		public BoyerMooreMatcher(byte[] pattern) {

			if (pattern.length == 0) {
				throw new IllegalArgumentException("Error: Empty pattern string.");
			}

			this.pattern = pattern;
				
			buildSuffixesArray();
			buildLastOccurrencesTable();
		}

		/**
		 * Builds the Good Suffixes Array for the pattern.
		 * The array stores the number of positions to shift
		 * when a mismatch occurs at each position in the pattern.
		 */
		private void buildSuffixesArray() {

			int suffixShift, patternLen = this.pattern.length;

			goodSuffixes = new int[patternLen];
			goodSuffixes[patternLen - 1] = 1;

			String patternStr = new String(this.pattern);

			for (int i = patternLen - 2; i >= 0; i--) {

				String suffix = patternStr.substring(i + 1, patternStr.length());

				suffixShift = calculateSuffixShift(i, suffix, patternStr);

				if (suffixShift != -1) goodSuffixes[i] = suffixShift;

				else goodSuffixes[i] = calculatePrefixShift(suffix, patternStr);
			}
		}

		/**
		 * Calculates the suffix shift for a given suffix in the pattern.
		 * This method finds the occurrence of the suffix elsewhere in the pattern,
		 * ensuring it is not preceded by the same character.
		 *
		 * @param i The current index in the pattern.
		 * @param suffix The suffix to be checked.
		 * @param pattern The pattern string.
		 * @return The shift value for the suffix if found, otherwise -1.
		 */
		int calculateSuffixShift(int i, String suffix, String pattern) {
			
			char c = pattern.charAt(i);
			
			int shift = -1, len = suffix.length();

			for (int j = i; shift == -1 && j > 0; j--) {

				if (c != pattern.charAt(j - 1)) {
					String str = pattern.substring(j, j + len);
					if (str.equals(suffix)) shift = i - j + 1;
				}
			}

			return shift;
		}

		/**
		 * Calculates the prefix shift for a given suffix in the pattern.
		 * This method determines the shift based on the longest prefix match
		 * when the suffix is not found elsewhere in the pattern.
		 *
		 * @param suffix The suffix to be checked.
		 * @param pattern The pattern string.
		 * @return The shift value for the prefix if found, otherwise the length of the pattern plus one.
		 */
		int calculatePrefixShift(String suffix, String pattern) {

			boolean wasFound = false;

			while (!wasFound && !suffix.isEmpty()) {

				if (pattern.startsWith(suffix)) wasFound = true;

				else suffix = suffix.substring(1, suffix.length());
			}

			return !wasFound ? pattern.length() + 1 : pattern.length() - suffix.length();
		}

		/**
		 * Prints the Good Suffixes Array for debugging purposes.
		 */
		public void printGoodSuffixesArray() {
			
			List<Integer> list = new ArrayList<>(goodSuffixes.length);

			for (int i : goodSuffixes) list.add(i);

			System.out.println(list);
		}

		/**
		 * Builds the last occurrence table for the pattern.
		 * The table stores the last occurrence index of each byte in the pattern.
		 */
		private void buildLastOccurrencesTable() {

			lastOccurrences = new int[256];

			Arrays.fill(lastOccurrences, -1);

			// Adding 128 to pattern[i] ensures that the byte value is treated as unsigned, 
			// preventing negative array indices when accessing the lastOccurrences table.
			for (int i = 0; i < pattern.length - 1; i++) {
				lastOccurrences[pattern[i] + 128] = i;
			}
		}

		/**
		 * Calculates the shift based on the Last Occurrences Table.
		 *
		 * @param i The current index in the search sequence.
		 * @param j The current index in the pattern.
		 * @param sequence The byte array of the search sequence.
		 * @return The calculated shift value.
		 */
		int calcLastOccShift(int i, int j, byte[] sequence) {
			return j - lastOccurrences[sequence[i + j] + 128];
		}

		/**
		 * Prints the Last Occurrence Table for debugging purposes.
		 */
		public void printLastOccurrenceTable() {
			for (int i = 0; i < lastOccurrences.length; i++) {
				if (lastOccurrences[i] != -1) {
					System.out.printf("%c - %d\n", (char)i - 128, lastOccurrences[i]);
				}
			}
		}

		/**
		 * Matches the pattern against the given search text.
		 *
		 * @param searchText The text in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the text.
		 */
		public List<Integer> match(String searchText) {
			return match(searchText.getBytes());
		}

		/**
		 * Matches the pattern against the given byte array.
		 *
		 * @param searchSequence The byte array in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the byte array.
		 */
		public List<Integer> match(byte[] searchSequence) {

			List<Integer> indices = new LinkedList<>();

			int lastOccurrenceShift;
			int maxIndex = searchSequence.length - pattern.length;

			for (int j = pattern.length - 1, i = 0; i <= maxIndex; j--) {

				if (searchSequence[i + j] == pattern[j]) {
					if (j == 0) {
						indices.add(i++);
						j = pattern.length;
					}
				}

				else {
					lastOccurrenceShift = calcLastOccShift(i, j, searchSequence);
					i += Math.max(lastOccurrenceShift, goodSuffixes[j]);
					j = pattern.length;
				}
			}

			return indices;
		}
	}
	
	static Scanner scanner = new Scanner(System.in);

	static final String filePath = "AEDs/AEDs_III/Materias/PatternMatching/";

	public static void main(String[] args) throws IllegalArgumentException {

		clearScreen();

		String text = readFromFile(filePath + "sampleText.txt");
		System.out.println(text);

		String pattern;

		do {

			System.out.print("Digite o pattern: ");

			pattern = scanner.nextLine();

			BoyerMooreMatcher p = new BoyerMooreMatcher(pattern);
			List<Integer> list = p.match(text);

			clearScreen();
			printHighlighted(pattern, text, list);

		} while (!pattern.toUpperCase().equals("FIM"));
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

	/**
	 * Prints the text with occurrences of the pattern highlighted in bold and green.
	 *
	 * @param pattern The pattern to highlight in the text.
	 * @param text The text in which to highlight the pattern.
	 * @param indices The list of starting indices where the pattern is found.
	 */
	static void printHighlighted(String pattern, String text, List<Integer> indices) {

		final byte[] textBytes = text.getBytes();
		final int patternLength = pattern.getBytes().length;
		final String GREEN = "\u001B[42m", RESET = "\u001B[0m";

		List<Byte> sequence = new LinkedList<>();

		int counter = 0;

		for (int i = 0; i < textBytes.length; i++) {

			if (!indices.isEmpty() && i == indices.get(0)) {
				indices.remove(0);
				if (counter == 0) append(GREEN, sequence);
				counter = patternLength;
			}

			sequence.add(textBytes[i]);

			if (counter > 0 && --counter == 0) {
				append(RESET, sequence);
			}
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
}
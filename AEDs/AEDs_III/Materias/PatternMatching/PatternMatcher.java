package AEDs.AEDs_III.Materias.PatternMatching;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

// clear && javac Matcher.java && java Matcher.java

/**
 * The PatternMatcher class provides implementations for pattern matching using
 * various algorithms, including the Boyer-Moore and Knuth-Morris-Pratt (KMP).
 * It supports interchangeable strategies through the MatcherStrategy interface.
 * It also allows matching patterns in both string and byte array formats.
 */
class PatternMatcher {

	/**
	 * MatcherStrategy interface defines the methods for pattern matching strategies.
	 */
	static interface MatcherStrategy {

		/**
		 * Sets the pattern to be matched.
		 *
		 * @param pattern The pattern byte array to be matched.
		 */
		void setPattern(byte[] pattern);

		/**
		 * Gets the pattern to be matched.
		 *
		 * @param pattern The pattern byte array to be matched.
		 */
		byte[] getPattern();

		/**
		 * Gets the number of comparisons made during the last match.
		 *
		 * @return The number of comparisons.
		 */
		int getComparisons();
		
		/**
		 * Prints any internal auxiliary structures used by the algorithm.
		 */
		void printInternalStructures();

		/**
		 * Matches the pattern against the given string.
		 *
		 * @param searchText The string in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the string.
		 */
		List<Integer> match(String searchText);

		/**
		 * Matches the pattern against the given byte array.
		 *
		 * @param searchSequence The byte array in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the byte array.
		 */
		List<Integer> match(byte[] searchSequence);

	}

	/**
	 * BoyerMoore class implements the Boyer-Moore pattern search algorithm.
	 */
	static class BoyerMoore implements MatcherStrategy {

		private int[] lastOccurrences, goodSuffixes;
		private byte[] pattern;
		private int comparisons;
		
		/**
		 * Constructor to create a BoyerMoore Pattern matching strategy.
		 */
		public BoyerMoore() {
			pattern = null;
			comparisons = 0;
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

			/*
			 * This works because ISO-8859-1 is a single-byte character encoding.
			 * making the string the same lenght as the array since no special
			 * characters "merge" into a single char.
			 */
			String patternStr = new String(this.pattern, StandardCharsets.ISO_8859_1);

			for (int i = patternLen - 2; i >= 0; i--) {

				String suffix = patternStr.substring(i + 1, patternLen);

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
		private void printGoodSuffixesArray() {
			
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
		private void printLastOccurrenceTable() {
			for (int i = 0; i < lastOccurrences.length; i++) {
				if (lastOccurrences[i] != -1) {
					System.out.printf("%c - %d\n", (char)i - 128, lastOccurrences[i]);
				}
			}
		}

		@Override
		public void setPattern(byte[] pattern) {
			this.pattern = pattern;
			buildSuffixesArray();
			buildLastOccurrencesTable();
		}

		@Override
		public byte[] getPattern() { return pattern; }

		@Override
		public void printInternalStructures() {
			printGoodSuffixesArray();
			printLastOccurrenceTable();
		}

		@Override
		public int getComparisons() { return comparisons; }

		@Override
		public List<Integer> match(String searchText) {
			return match(searchText.getBytes());
		}

		@Override
		public List<Integer> match(byte[] searchSequence) {

			comparisons = 0;
			
			List<Integer> indices = new LinkedList<>();

			int lastOccurrenceShift, i = 0, j = pattern.length - 1;
			int maxIndex = searchSequence.length - pattern.length;

			while (i <= maxIndex) {

				if (searchSequence[i + j] == pattern[j]) {
					if (j-- == 0) {
						indices.add(i++);
						j = pattern.length - 1;
					}
				}

				else {
					lastOccurrenceShift = calcLastOccShift(i, j, searchSequence);
					i += Math.max(lastOccurrenceShift, goodSuffixes[j]);
					j = pattern.length - 1;
				}

				comparisons++;
			}

			return indices;
		}
	}

	/**
	 * KMP class implements the Knuth-Morris-Pratt (KMP) pattern search algorithm.
	 */
	static class KMP implements MatcherStrategy {

		private int[] partialMatchTable;
		private byte[] pattern;
		private int comparisons;

		/**
		 * Constructor to create a KMP Pattern matching strategy.
		 */
		public KMP() {
			pattern = null;
			comparisons = 0;
		}

		/**
		 * Builds the partial match (or "failure") table for the pattern.
		 * This table stores the length of the longest proper
		 * prefix which is also suffix for each position in the pattern.
		 */
		private void buildPartialMatchTable() {

			partialMatchTable = new int[pattern.length];
			partialMatchTable[0] = 0;

			for (int i = 1, j = 0; i < pattern.length; i++) {

				while (j > 0 && pattern[i] != pattern[j]) {
					j = partialMatchTable[j - 1];
				}

				if (pattern[i] == pattern[j]) j++;

				partialMatchTable[i] = j;
			}
		}

		/**
		 * Prints the Partial Match (or "Failure") Table for debugging purposes.
		 */
		private void printPartialMatchTable() {
			System.out.println(Arrays.toString(partialMatchTable));
		}

		@Override
		public void setPattern(byte[] pattern) {
			this.pattern = pattern;
			buildPartialMatchTable();
		}

		@Override
		public byte[] getPattern() { return pattern; }

		@Override
		public int getComparisons() { return comparisons; }

		@Override
		public void printInternalStructures() {
			printPartialMatchTable();
		}

		@Override
		public List<Integer> match(String searchText) {
			return match(searchText.getBytes());
		}

		@Override
		public List<Integer> match(byte[] searchSequence) {

			comparisons = 0;
			
			List<Integer> indices = new LinkedList<>();

			for (int i = 0, j = 0; i < searchSequence.length; i++) {
				
				while (j > 0 && searchSequence[i] != pattern[j]) {
					j = partialMatchTable[j - 1];
					comparisons++;
				}
				
				if (searchSequence[i] == pattern[j]) j++;
				
				if (j == pattern.length) {
					indices.add(i - j + 1);
					j = partialMatchTable[j - 1];
				}

				comparisons++;
			}

			return indices;
		}
	}

	/**
	 * BruteForce class implements a simple brute-force pattern search algorithm.
	 */
	static class BruteForce implements MatcherStrategy {

		private byte[] pattern;
		private int comparisons;

		/**
		 * Constructor to create a BruteForce Pattern matching strategy.
		 */
		public BruteForce() {
			pattern = null;
			comparisons = 0;
		}

		@Override
		public void setPattern(byte[] pattern) { this.pattern = pattern; }

		@Override
		public byte[] getPattern() { return pattern; }

		@Override
		public int getComparisons() { return comparisons; }
	
		@Override
		public void printInternalStructures() {
			System.out.println("No internal structures for BruteForce.");
		}

		@Override
		public List<Integer> match(String searchText) {
			return match(searchText.getBytes());
		}

		@Override
		public List<Integer> match(byte[] searchSequence) {

			comparisons = 0;
			
			List<Integer> indices = new ArrayList<>();

			int maxIndex = searchSequence.length - pattern.length;
	
			for (int j, i = 0; i <= maxIndex; i++) {

				for (j = 0; j < pattern.length; j++) {
					comparisons++;
					if (searchSequence[i + j] != pattern[j]) break;
				}

				if (j == pattern.length) indices.add(i);
			}
	
			return indices;
		}
	}

	/**
	 * Matcher class that uses a specific MatcherStrategy to perform pattern matching.
	 */
	static class Matcher {

		private MatcherStrategy matcher;

		/**
		 * Default constructor for Matcher.
		 */
		public Matcher() { this(null); }

		/**
		 * Constructor for Matcher with a specific strategy.
		 *
		 * @param matcher The MatcherStrategy to be used.
		 */
		public Matcher(MatcherStrategy matcher) { this.matcher = matcher; }

		/**
		 * Constructor for Matcher with a specific strategy and pattern.
		 *
		 * @param pattern The pattern string to be used.
		 * @param matcher The MatcherStrategy to be used.
		 */
		public Matcher(String pattern, MatcherStrategy matcher) {
			this(pattern.getBytes(), matcher);
		}

		/**
		 * Constructor for Matcher with a specific pattern and strategy.
		 *
		 * @param pattern The pattern byte array to be used.
		 * @param matcher The MatcherStrategy to be used.
		 */
		public Matcher(byte[] pattern, MatcherStrategy matcher) {
			this.matcher = matcher;
			setPattern(pattern);
		}

		/**
		 * Sets the MatcherStrategy to be used for pattern matching.
		 *
		 * @param matcher The MatcherStrategy to be set.
		 */
		public void setMatcherStrategy(MatcherStrategy matcher) {
			this.matcher = matcher;
		}

		/**
		 * Matches the pattern against the given byte array.
		 *
		 * @param searchText The byte array in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the byte array.
		 */
		public List<Integer> match(String searchText) throws IllegalStateException {
			return match(searchText.getBytes());
		}

		/**
		 * Matches the pattern against the given byte array.
		 *
		 * @param searchSequence The byte array in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the byte array.
		 */
		public List<Integer> match(byte[] searchSequence) throws IllegalStateException {

			if (matcher == null) {
				throw new IllegalStateException("MatcherStrategy not set.");
			}

			if (matcher.getPattern() == null) {
				throw new IllegalStateException("Pattern not set.");
			}

			return matcher.match(searchSequence);
		}

		/**
		 * Matches the pattern against the given text.
		 *
		 * @param pattern The pattern to be matched.
		 * @param searchText The text in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the text.
		 */
		public List<Integer> match(String pattern, String searchText) {
			return match(pattern.getBytes(), searchText.getBytes());
		}

		/**
		 * Matches the pattern against the given byte array.
		 *
		 * @param pattern The pattern byte array to be matched.
		 * @param searchSequence The byte array in which to search for the pattern.
		 * @return A list of starting indices where the pattern is found in the byte array.
		 */
		public List<Integer> match(byte[] pattern, byte[] searchSequence) throws IllegalStateException {

			if (matcher == null) {
				throw new IllegalStateException("MatcherStrategy not set.");
			}

			setPattern(pattern);

			return matcher.match(searchSequence);
		}
		
		/**
		 * Sets the pattern string to be matched.
		 *
		 * @param pattern The pattern string to be matched.
		 * @throws IllegalArgumentException If the pattern is empty.
		 */
		public void setPattern(String pattern) throws IllegalArgumentException {
			setPattern(pattern.getBytes());
		}

		/**
		 * Sets the pattern byte array to be matched.
		 *
		 * @param pattern The pattern byte array to be matched.
		 * @throws IllegalArgumentException If the pattern is empty.
		 */
		public void setPattern(byte[] pattern) throws IllegalArgumentException {

			if (pattern.length == 0) {
				throw new IllegalArgumentException("Error: Empty pattern.");
			}

			matcher.setPattern(pattern);
		}
		
		/**
		 * Prints internal structures used by the KMP algorithm for debugging purposes.
		 */
		public void printInternalStructures() {

			if (matcher == null) {
				throw new IllegalStateException("MatcherStrategy not set.");
			}

			matcher.printInternalStructures();
		}

		/**
		 * Retrieves the number of comparisons made during the last match operation.
		 *
		 * @return The number of comparisons.
		 */
		public int getComparisons() {
			return matcher.getComparisons();
		}
	}

	static Scanner scanner = new Scanner(System.in);

	static final String filePath = "AEDs/AEDs_III/Materias/PatternMatching/";

	// Aprender doxygen.
	// Talvez criar um atributo pattern na classe matcher e remover o getPattern da interface?

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

	// --------------------------------------------------------------------------------
	// --------------------------------------------------------------------------------

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

			if (state > 0 && --state == 0) {
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
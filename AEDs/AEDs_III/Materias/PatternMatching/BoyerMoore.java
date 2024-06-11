package AEDs.AEDs_III.Materias.PatternMatching;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

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
         * Builds the good suffix shift table.
         * This method is currently not implemented.
         */
		private void buildSuffixesArray() {
			goodSuffixes = new int[this.pattern.length];
			// Code still to be implemented
		}

		/**
         * Builds the last occurrence table for the pattern.
         * The table stores the last occurrence index of each byte in the pattern.
         */
		private void buildLastOccurrencesTable() {

			lastOccurrences = new int[256];

			Arrays.fill(lastOccurrences, -1);

			for (int i = 0; i < pattern.length - 1; i++) {
				lastOccurrences[pattern[i]] = i;
			}
		}

		/**
         * Prints the last occurrence table for debugging purposes.
         */
		public void printLastOccurrenceTable() {
			for (int i = 0; i < lastOccurrences.length; i++) {
				if (lastOccurrences[i] != -1) {
					System.out.printf("%c - %d\n", (char)i, lastOccurrences[i]);
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

			int lastOccurrenceShift, goodSuffixShift;
			int maxIndex = searchSequence.length - pattern.length;

			for (int i = 0, j = pattern.length - 1; i <= maxIndex; j--) {

				if (searchSequence[i + j] != pattern[j]) {
					lastOccurrenceShift = Math.max(j - searchSequence[i + j], 1);
					goodSuffixShift = goodSuffixes[j];
					i += Math.max(lastOccurrenceShift, goodSuffixShift);
					j = pattern.length;
				}

				else if (j == 0) {
					indices.add(i++);
					j = pattern.length;
				}
			}

			return indices;
		}
	}

	public static void main(String[] args) throws IllegalArgumentException {

		String pattern = "ARARA";
		String text = "A ARARA VIU OUTRA ARARA EM ARARAQUARA";
		//             01234567890123456789012345678901234567

		BoyerMooreMatcher p = new BoyerMooreMatcher(pattern);

		// p.printLastOccurrenceTable();

		List<Integer> list = p.match(text);

		System.out.println(list);
	}
}
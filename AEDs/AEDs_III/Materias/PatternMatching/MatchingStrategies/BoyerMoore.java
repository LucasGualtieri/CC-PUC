package AEDs.AEDs_III.Materias.PatternMatching.MatchingStrategies;

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.LinkedList;
import java.nio.charset.StandardCharsets;

/**
 * BoyerMoore class implements the Boyer-Moore pattern search algorithm.
 */
public class BoyerMoore implements MatcherStrategy {

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

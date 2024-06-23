package AEDs.AEDs_III.Materias.PatternMatching.MatchingStrategies;

import java.util.List;
import java.util.Arrays;
import java.util.LinkedList;

/**
 * KMP class implements the Knuth-Morris-Pratt (KMP) pattern search algorithm.
 */
public class KMP implements MatcherStrategy {

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

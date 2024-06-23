package AEDs.AEDs_III.Materias.PatternMatching.MatchingStrategies;

import java.util.List;
import java.util.ArrayList;

/**
 * BruteForce class implements a simple brute-force pattern search algorithm.
 */
public class BruteForce implements MatcherStrategy {

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

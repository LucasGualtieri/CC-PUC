package AEDs.AEDs_III.Materias.PatternMatching;

import java.util.List;

import AEDs.AEDs_III.Materias.PatternMatching.MatchingStrategies.MatcherStrategy;

/**
 * Matcher class that uses a specific MatcherStrategy to perform pattern matching.
 */
public class Matcher {

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

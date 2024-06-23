package AEDs.AEDs_III.Materias.PatternMatching.MatchingStrategies;

import java.util.List;

/**
 * MatcherStrategy interface defines the methods for pattern matching strategies.
 */
public interface MatcherStrategy {

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

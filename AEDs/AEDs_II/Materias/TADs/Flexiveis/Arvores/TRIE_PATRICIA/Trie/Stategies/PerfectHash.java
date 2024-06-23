package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Node;

public class PerfectHash implements HashingStrategy {

	private final int CHILDREN_SIZE = 256;

	private int length = 0;

	public Node[] children = new Node[CHILDREN_SIZE];

	public PerfectHash() {
		Arrays.fill(children, null);
	}

	@Override
	public int length() { return length; }

	@Override
	public void add(char c, Node node) {
		children[c] = node;
		length++;
	}

	@Override
	public Node get(char c) { return children[c]; }

	@Override
	public boolean isEmpty() { return length == 0; }

	@Override
	public boolean contains(char c) { return children[c] != null; }

	@Override
	public PerfectHash newInstance() { return new PerfectHash(); }

	@Override
	public Iterator<Node> iterator() {

		return new Iterator<Node>() {

			private int currentIndex = 0;

			@Override
			public boolean hasNext() {
				while (currentIndex < children.length && children[currentIndex] == null) {
					currentIndex++;
				}
				return currentIndex < children.length && children[currentIndex] != null;
			}

			@Override
			public Node next() {
				if (!hasNext()) throw new NoSuchElementException();
				return children[currentIndex++];
			}
		};
	}

}

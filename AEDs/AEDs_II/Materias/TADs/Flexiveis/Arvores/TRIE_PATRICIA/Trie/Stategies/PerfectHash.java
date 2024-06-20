package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Node;

public class PerfectHash implements HashingStrategy {

	public Node[] children;

	public PerfectHash() {
		children = new Node[256];
		Arrays.fill(children, null);
	}

	@Override
	public int length() { return children.length; }

	@Override
	public Node get(char c) { return children[c]; }

	@Override
	public void add(char c, Node node) { children[c] = node; }

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

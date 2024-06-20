package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

import java.util.Arrays;

public class PerfectHash implements HashingStrategy {

	Node[] children;

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

}

package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

import java.util.Iterator;

import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies.HashingStrategy;

public class Node implements Iterable<Node> {

	public char value;
	public boolean stringEnd;
	public HashingStrategy children;

	public Node(char value, HashingStrategy children) {
		this.value = value;
		stringEnd = false;
		this.children = children.newInstance();
	}

	int length() { return children.length(); }
	boolean contains(char c) { return children.contains(c); }
	public Node get(char c) { return children.get(c); }
	public void add(char c, Node node) { children.add(c, node); }

	boolean getStringEnd() { return stringEnd; }
	void setStringEnd() { stringEnd = true; }
	void resetStringEnd() { stringEnd = false; }

	@Override
	public Iterator<Node> iterator() { return children.iterator(); }
}

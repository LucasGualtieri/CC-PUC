package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

public class Node {

	public boolean stringEnd;
	public HashingStrategy children;

	public Node(HashingStrategy children) {
		this.children = children;
		stringEnd = false;
	}

	boolean getStringEnd() { return stringEnd; }
	void setStringEnd() { stringEnd = true; }
	void resetStringEnd() { stringEnd = false; }
}

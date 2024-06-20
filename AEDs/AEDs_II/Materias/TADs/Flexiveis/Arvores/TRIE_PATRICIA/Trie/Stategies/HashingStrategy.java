package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies;

import java.util.Iterator;

import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Node;

public interface HashingStrategy {
	int length();
	Node get(char c);
	void add(char c, Node node);
	boolean contains(char c);
	HashingStrategy newInstance();
	public Iterator<Node> iterator();
}

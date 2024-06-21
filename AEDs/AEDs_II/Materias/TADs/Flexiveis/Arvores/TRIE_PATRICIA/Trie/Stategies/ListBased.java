package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies;

import java.util.List;
import java.util.Iterator;
import java.util.LinkedList;

import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Node;

public class ListBased implements HashingStrategy {

	public List<Node> children = new LinkedList<>();

	@Override
	public int length() { return children.size(); }

	@Override
	public void add(char c, Node node) { children.add(node); }

	@Override
	public Node get(char c) {

		for (Node i : children) {
			if (i.value == c) return i;
		}

		return null;
	}

	@Override
	public boolean contains(char c) {

		for (Node i : children) {
			if (i.value == c) return true;
		}

		return false;
	}

	@Override
	public HashingStrategy newInstance() { return new ListBased(); }

	@Override
	public Iterator<Node> iterator() { return children.iterator(); }
}

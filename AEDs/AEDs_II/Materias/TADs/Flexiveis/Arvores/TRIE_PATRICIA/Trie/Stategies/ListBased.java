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
	public Node get(char c) {

		Node node = null;

		for (Node i : children) {
			if (i.value == c) {
				node = i;
				break;
			}
		}

		return node;
	}

	@Override
	public void add(char c, Node node) { children.add(node); }

	@Override
	public boolean contains(char c) {

		boolean contained = false;

		for (Node i : children) {
			if (i.value == c) {
				contained = true;
				break;
			}
		}

		return contained;
	}

	@Override
	public HashingStrategy newInstance() { return new ListBased(); }

	@Override
	public Iterator<Node> iterator() { return children.iterator(); }
}

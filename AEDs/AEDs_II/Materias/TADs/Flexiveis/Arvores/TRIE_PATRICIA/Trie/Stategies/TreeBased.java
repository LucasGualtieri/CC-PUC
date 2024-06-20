package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies;

import java.util.Map;
import java.util.TreeMap;
import java.util.Iterator;
import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Node;

public class TreeBased implements HashingStrategy {

	public Map<Character, Node> children = new TreeMap<>();

	@Override
	public int length() { return children.size(); }

	@Override
	public Node get(char c) { return children.get(c); }

	@Override
	public void add(char c, Node node) { children.put(c, node); }

	@Override
	public boolean contains(char c) { return children.containsKey(c); }

	@Override
	public HashingStrategy newInstance() { return new TreeBased(); }

	@Override
	public Iterator<Node> iterator() { return children.values().iterator(); }
}

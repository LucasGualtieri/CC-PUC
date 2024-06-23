package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies;

import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;
import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Node;

public class MapBased implements HashingStrategy {

	public Map<Character, Node> children = new HashMap<>();

	@Override
	public int length() { return children.size(); }

	@Override
	public void add(char c, Node node) { children.put(c, node); }

	@Override
	public Node get(char c) { return children.get(c); }

	@Override
	public boolean isEmpty() { return children.isEmpty(); }

	@Override
	public boolean contains(char c) { return children.containsKey(c); }

	@Override
	public HashingStrategy newInstance() { return new MapBased(); }

	@Override
	public Iterator<Node> iterator() { return children.values().iterator(); }
}

package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

public interface HashingStrategy {
	int length();
	Node get(char c);
	void add(char c, Node node);
}

package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

import java.util.List;
import java.util.LinkedList;
import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies.HashingStrategy;

public class Trie {

	Node root;
	HashingStrategy strategy;

	Trie(HashingStrategy strategy) {
		this.strategy = strategy;
		this.root = new Node('\0', strategy.newInstance());
	}

	Trie(HashingStrategy children, String... strings) {
		this(children);
		for (String s : strings) this.add(s);
	}

	public boolean add(String string) {

		boolean status = true;

		try { add(0, root, string.toCharArray()); }

		catch (OutOfMemoryError e) { status = false; }

		catch (Exception e) { status = false; }

		return status;
	}

	private void add(int i, Node node, char[] string) throws Exception {

		char c = string[i];

		if (!node.contains(c)) {
			node.add(c, new Node(c, strategy));
		}

		if (i + 1 < string.length) {
			add(i + 1, node.get(c), string);
		}

		else if (node.get(c).stringEnd) {
			throw new Exception("String already inserted.");
		}

		else node.get(c).setStringEnd();
	}

	public void remove(String string) throws Exception {
		throw new Exception("Método ainda não implementado");
	}

	public boolean get(String string) {

		int i = 0, len = string.length();
		Node node = root;

		while (node != null && i < len) {
			char c = string.charAt(i++);
			node = node.get(c);
		}

		return i == len && node != null && node.stringEnd;
	}

	public List<String> startsWith(String string) {

		List<String> list = new LinkedList<>();
		StringBuilder builder = new StringBuilder(string);

		Node node = root;

		for (char c : string.toCharArray()) {
			node = node.get(c);
			if (node == null) break;
		}

		if (node != null) traverse(builder, list, node);

		return list;
	}

	private void traverse(StringBuilder builder, List<String> list, Node node) {

		if (node.stringEnd) list.add(builder.toString());
	
		for (Node child : node) {
			builder.append(child.value);
			traverse(builder, list, child);
			builder.deleteCharAt(builder.length() - 1);
		}
	}

	@Override
	public String toString() {

		List<String> strings = new LinkedList<>();
		StringBuilder builder = new StringBuilder();

		traverse(builder, strings, root);

		for (String s : strings) {
			builder.append(String.format("[%s]\n", s));
		}

		if (!builder.isEmpty()) {
			builder.deleteCharAt(builder.length() - 1);
		}

		else builder.append("The Trie is empty.");

		return builder.toString();
	}
}

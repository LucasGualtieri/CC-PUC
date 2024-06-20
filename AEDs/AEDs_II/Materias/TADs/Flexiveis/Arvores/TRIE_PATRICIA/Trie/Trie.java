package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

import java.util.LinkedList;
import java.util.List;

public class Trie {

	Node root;
	HashingStrategy hashingStrategy;

	Trie(HashingStrategy hashingStrategy) {
		this.hashingStrategy = hashingStrategy;
		this.root = new Node(hashingStrategy);
	}

	Trie(HashingStrategy children, String... strings) {
		this(children);
		for (String s : strings) this.add(s);
	}

	public boolean add(String string) {

		boolean status = true;

		try { add(0, root, string.toCharArray()); }

		catch (OutOfMemoryError e) { status = false; }

		return status;
	}

	private void add(int i, Node node, char[] string) {

		char c = string[i];

		if (node.children.get(c) == null) {
			node.children.add(c, new Node(hashingStrategy));
		}

		if (i + 1 < string.length) {
			add(i + 1, node.children.get(c), string);
		}

		else node.children.get(c).setStringEnd();
	}

	public boolean get(String string) {

		int i = 0, len = string.length();
		Node node = root;

		while (node != null && i < len) {
			char c = string.charAt(i++);
			node = node.children.get(c);
		}

		return i == len && node != null && node.stringEnd;
	}

	private void traverse(int i, StringBuilder builder, List<String> list, Node node) {

		if (node.stringEnd) list.add(builder.toString());

		for (char j = 0; j < node.children.length(); j++) {
			if (node.children.get(j) != null) {
				builder.append(j);
				traverse(i + 1, builder, list, node.children.get(j));
				builder.deleteCharAt(builder.length() - 1);
			}
		}
	}

	@Override
	public String toString() {

		StringBuilder builder = new StringBuilder();
		List<String> strings = new LinkedList<>();

		traverse(0, builder, strings, root);

		for (String s : strings) {
			builder.append(String.format("[%s]\n", s));
		}

		builder.deleteCharAt(builder.length() - 1);

		return builder.toString();
	}
}

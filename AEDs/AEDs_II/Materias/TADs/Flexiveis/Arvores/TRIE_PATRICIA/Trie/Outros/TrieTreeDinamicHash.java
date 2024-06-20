package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Outros;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class TrieTreeDinamicHash {

	static class Node {

		char c;
		HashMap<Character, Node> children;
		boolean stringEnd;

		public Node() { this('\0'); }

		public Node(char c) {

			children = new HashMap<>();

			this.c = c;

			stringEnd = false;

		}

		boolean getStringEnd() { return stringEnd; }
		void setStringEnd() { stringEnd = true; }
		void resetStringEnd() { stringEnd = false; }
	}

	static class Trie {

		Node root;

		Trie() { root = new Node(); }

		Trie(String... strings) {
			this();
			for (String s : strings) this.add(s);
		}

		public boolean add(String string) {

			boolean x = false;

			add(0, root, string.toCharArray());

			return x;
		}

		private void add(int i, Node node, char[] string) {

			Character c = string[i];

			if (node.children.get(c) == null) {
				node.children.put(c, new Node(c));
			}

			if (i + 1 < string.length) {
				add(i + 1, node.children.get(c), string);
			}

			else node.children.get(c).setStringEnd();
		}

		public boolean get(String string) {

			int i = 0;
			Node node = root;

			char[] stringArray = string.toCharArray();

			while (node != null && i < stringArray.length) {
				char c = stringArray[i++];
				node = node.children.get(c);
			}

			return i == stringArray.length && node != null && node.getStringEnd();
		}

		private void traverse(int i, StringBuilder builder, List<String> list, Node node) {

			if (node.getStringEnd()) list.add(builder.toString());

			for (Node j : node.children.values()) {
				if (j != null) {
					builder.append(j.c);
					traverse(i + 1, builder, list, node.children.get(j.c));
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

			return builder.toString();
		}
	}

	public static void main(String[] args) {

		System.out.println("Trie with HashMap");

		Trie trie = new Trie();

		trie.add("BELL");
		trie.add("BEAR");
		trie.add("BID");
		trie.add("BUY");
		trie.add("BULL");
		trie.add("SAPATO");
		trie.add("SAPATOS");
		trie.add("SAPO");
		trie.add("SELL");
		trie.add("STOCK");
		trie.add("STOP");

		System.out.println(trie.get("SAPATO") ? "SIM" : "NÃO");
		System.out.println(trie.get("SAPATOS") ? "SIM" : "NÃO");

		System.out.println(trie);

	}
}

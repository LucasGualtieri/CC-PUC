package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class TrieTreePTBR {

	static class No {

		char valor;
		No[] filhos;
		boolean stringEnd;

		public No() { this('\0'); }

		public No(char valor) {

			filhos = new No[256];
			Arrays.fill(filhos, null);

			this.valor = valor;

			stringEnd = false;

		}

		void setStringEnd() { stringEnd = true; }
		void resetStringEnd() { stringEnd = false; }
	}

	static class Trie {

		No raiz;

		Trie() { raiz = new No(); }

		Trie(String... strings) {
			this();
			for (String s : strings) this.add(s);
		}

		public void add(String string) {
			add(0, raiz, string.toCharArray());
		}

		private void add(int i, No no, char[] string) {

			char c = string[i];

			if (no.filhos[c] == null) {
				no.filhos[c] = new No(c);
			}

			if (i + 1 < string.length) {
				add(i + 1, no.filhos[c], string);
			}

			else no.filhos[c].setStringEnd();
		}

		public boolean get(String string) {

			int i = 0, len = string.length();
			No no = raiz;

			while (no != null && i < len) {
				char c = string.charAt(i++);
				no = no.filhos[c];
			}

			return i == len && no != null && no.stringEnd;
		}

		private void caminhar(int i, StringBuilder str, List<String> list, No no) {

			if (no.stringEnd) list.add(str.toString());

			for (No j : no.filhos) {
				if (j != null) {
					str.append(j.valor);
					caminhar(i + 1, str, list, no.filhos[j.valor]);
					// Sempre que estamos voltando na recursão removemos o último caractere
					str.deleteCharAt(str.length() - 1);
				}
			}
		}

		@Override
		public String toString() {

			StringBuilder builder = new StringBuilder();
			List<String> strings = new LinkedList<>();

			caminhar(0, builder, strings, raiz);

			for (String s : strings) {
				builder.append(String.format("[%s]\n", s));
			}

			return builder.toString();
		}
	}

	public static void main(String[] args) {

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

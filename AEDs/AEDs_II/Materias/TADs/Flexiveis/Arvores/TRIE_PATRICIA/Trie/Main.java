package AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie;

import AEDs.AEDs_II.Materias.TADs.Flexiveis.Arvores.TRIE_PATRICIA.Trie.Stategies.*;

class Main {
	
	public static void main(String[] args) {

		Trie trie = new Trie(new ListBased());

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

		System.out.println(trie);

		System.out.println(trie.get("SAPA") ? "SIM" : "NÃO");
		System.out.println(trie.get("SAPO") ? "SIM" : "NÃO");
		System.out.println(trie.get("SAPATO") ? "SIM" : "NÃO");
		System.out.println(trie.get("SAPATOS") ? "SIM" : "NÃO");

	}
}

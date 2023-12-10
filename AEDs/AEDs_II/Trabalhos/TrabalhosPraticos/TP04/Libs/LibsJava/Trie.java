package TP04.Libs.LibsJava;

import TP04.Libs.LibsJava.Celulas.NoTrie;

public class Trie {

	NoTrie raiz;

	public Trie() {
		raiz = new NoTrie();
	}

	public Trie(Trie t1, Trie t2) {
		this();
		this.juntar(t1);
		this.juntar(t2);
	}

	public NoTrie getRaiz() {
		return raiz;
	}

	public void juntar(Trie t) {
		juntar(t.raiz, "");
	}

	private void juntar(NoTrie no, String s) {
		if (no.ehPalavra) {
			this.Inserir(s);
		}
		for (int i = 0; i < no.filhos.length; i++) {
			if (no.filhos[i] != null) {
				juntar(no.filhos[i], s + (char)(i + 32));
			}
		}
	}

	// INSERIR
	public void Inserir(String nome) {
		NoTrie atual = this.raiz;

		for (int i = 0; i < nome.length(); i++) {
			char c = nome.charAt(i);
			int index = c - 32;

			if (atual.filhos[index] == null) {
				NoTrie node = new NoTrie();
				atual.filhos[index] = node;

				atual = node;// avançando o NoTrie
			}
			else {
				atual = atual.filhos[index];
			}

		}

		atual.ehPalavra = true;
	}


	public void pesquisar(String nome)
	{

		if(pesquisar(nome, raiz))
		{
			System.out.println(nome+" SIM");
		}
		else
		{
			System.out.println(nome+" NAO");
		}
		
	}


	private boolean pesquisar(String nome, NoTrie raiz) {
		NoTrie atual = raiz;
		boolean resp = false;

		for (int i = 0; i < nome.length(); i++) {
			char c = nome.charAt(i);
			int index = c - 32;

			if (atual.filhos[index] == null) {
				resp = false;
			}
			else {
				atual = atual.filhos[index];
			}

		}

		if (atual.ehPalavra) {
			resp = true;
		} else {
			resp = false;
		}

		return resp;
	}

}
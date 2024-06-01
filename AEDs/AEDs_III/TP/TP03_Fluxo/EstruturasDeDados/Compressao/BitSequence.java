package TP03.EstruturasDeDados.Compressao;

import java.util.BitSet;

// Armazena uma sequência de números em um vetor de bits
// Cada número tem "bitsPorNumero" bits
public class BitSequence {
	int bitsPorNumero; // quantidade de bits por número
	private int ultimoBit; // próximo bit a ser usado;
	private BitSet bs; // vetor de bits

	public BitSequence(int bs) {
		bitsPorNumero = bs;
		ultimoBit = 0;
		this.bs = new BitSet();
	}

	// Adiciona um número de "bitsPorNumero" bits
	public void add(int n) {
		int i = bitsPorNumero;
		while (i > 0) {
			if (n % 2 == 0)
				bs.clear(ultimoBit++);
			else
				bs.set(ultimoBit++);
			n >>= 1;
			i--;
		}
	}

	// Recupera um número de "bitsPorNumero" bits na i-ésima posição
	public int get(int i) { // retorna o i-ésimo número
		int pos = i * bitsPorNumero;
		int n = 0;
		for (int j = 0; j < bitsPorNumero; j++) {
			if (bs.get(pos + j))
				n += (int) Math.pow(2, j);
		}
		return n;
	}

	// Retorna a quantidade de números armazenada no BitSet
	public int size() {
		return ultimoBit / bitsPorNumero;
	}

	public byte[] getBytes() {
		return bs.toByteArray();
	}

	public void setBytes(int n, byte[] bytes) {
		ultimoBit = n * bitsPorNumero;
		bs = BitSet.valueOf(bytes);
	}
}

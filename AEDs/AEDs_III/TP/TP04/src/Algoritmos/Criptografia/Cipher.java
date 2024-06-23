package TP04.src.Algoritmos.Criptografia;

import java.util.Arrays;

import TP04.src.Algoritmos.Criptografia.Strategies.*;

public class Cipher {

	CipherStrategy[] strategies;

	public static final byte[] KEY = "AEDsIII".getBytes();

	public Cipher(CipherStrategy... strategies) { this.strategies = strategies; }

	public Cipher() {

		strategies = new CipherStrategy[2];
		strategies[0] = new Viegenere();
		strategies[1] = new Colunas();
	}

	public byte[] cipher(byte[] key, byte[] data) {

		byte[] cipheredData = Arrays.copyOf(data, data.length);

		for (CipherStrategy strategy : strategies) {
			cipheredData = strategy.cipher(key, cipheredData);
		}

		return cipheredData;
	}

	public byte[] decipher(byte[] key, byte[] cipheredData) {

		byte[] decipheredData = Arrays.copyOf(cipheredData, cipheredData.length);

		for (int i = strategies.length - 1; i >= 0; i--) {
			decipheredData = strategies[i].decipher(key, decipheredData);
		}

		return decipheredData;
	}
}

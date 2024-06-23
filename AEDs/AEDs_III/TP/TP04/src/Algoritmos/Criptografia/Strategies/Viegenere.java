package TP04.src.Algoritmos.Criptografia.Strategies;

import TP04.src.Algoritmos.Criptografia.CipherStrategy;

public class Viegenere implements CipherStrategy {

	@Override
	public byte[] cipher(byte[] key, byte[] data) {

		byte[] cipheredData = new byte[data.length];

		for (int i = 0; i < data.length; i++) {
			cipheredData[i] = (byte)(data[i] + key[i % key.length]);
		}
		
		return cipheredData;
	}
	
	@Override
	public byte[] decipher(byte[] key, byte[] data) {
		
		byte[] decipheredData = new byte[data.length];
		
		for (int i = 0; i < data.length; i++) {
			decipheredData[i] = (byte)(data[i] - key[i % key.length]);
		}

		return decipheredData;
	}
}

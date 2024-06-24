package TP04.src.Algoritmos.Criptografia.Strategies;

import TP04.src.Algoritmos.Criptografia.CipherStrategy;

/**
 * Classe que implementa a estratégia de criptografia de Viegenere.
 */
public class Viegenere implements CipherStrategy {

	/**
	 * Método para cifrar os dados utilizando a cifra de Viegenere.
	 * 
	 * @param key  Chave utilizada para cifrar os dados.
	 * @param data Dados a serem cifrados.
	 * @return Dados cifrados.
	 */
	@Override
	public byte[] cipher(byte[] key, byte[] data) {

		byte[] cipheredData = new byte[data.length];

		for (int i = 0; i < data.length; i++) {
			cipheredData[i] = (byte)(data[i] + key[i % key.length]);
		}

		return cipheredData;
	}

	/**
	 * Método para decifrar os dados utilizando a cifra de Viegenere.
	 * 
	 * @param key  Chave utilizada para decifrar os dados.
	 * @param data Dados a serem decifrados.
	 * @return Dados decifrados.
	 */
	@Override
	public byte[] decipher(byte[] key, byte[] data) {

		byte[] decipheredData = new byte[data.length];

		for (int i = 0; i < data.length; i++) {
			decipheredData[i] = (byte)(data[i] - key[i % key.length]);
		}

		return decipheredData;
	}
}

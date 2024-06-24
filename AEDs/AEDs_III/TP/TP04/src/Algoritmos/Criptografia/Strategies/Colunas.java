package TP04.src.Algoritmos.Criptografia.Strategies;

import TP04.src.Algoritmos.Criptografia.CipherStrategy;

/**
 * Classe que implementa a estratégia de criptografia por transposição de colunas.
 */
public class Colunas implements CipherStrategy {

	/**
	 * Método para cifrar os dados utilizando a transposição de colunas.
	 * 
	 * @param key  Chave utilizada para cifrar os dados.
	 * @param data Dados a serem cifrados.
	 * @return Dados cifrados.
	 */
	@Override
	public byte[] cipher(byte[] key, byte[] data) {

		int width = key.length;
		int height = (int)Math.ceil((float)data.length / width);

		char[][] matrix = new char[height][width];
		int counter = 0;

		for (int i = 0; i < height; i++) {

			for (int j = 0; j < width; j++) {

				if (counter < data.length) {
					matrix[i][j] = (char)data[counter++];
				}
				
				else matrix[i][j] = 256;  // Valor que representa espaço vazio na matriz.
			}
		}

		byte[] cipheredData = new byte[data.length];
		counter = 0;

		for (int j = 0; j < key.length; j++) {
			for (int i = 0; i < height; i++) {
				if (matrix[i][j] != 256) {
					cipheredData[counter++] = (byte)matrix[i][j];
				}
			}
		}

		return cipheredData;
	}

	/**
	 * Método para decifrar os dados utilizando a transposição de colunas.
	 * 
	 * @param key  Chave utilizada para decifrar os dados.
	 * @param data Dados cifrados a serem decifrados.
	 * @return Dados decifrados.
	 */
	@Override
	public byte[] decipher(byte[] key, byte[] data) {

		int width = key.length;
		int height = (int)Math.ceil((float)data.length / width);

		char[][] matrix = new char[height][width];
		int counter = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (counter++ >= data.length) {
					matrix[i][j] = 256;  // Valor que representa espaço vazio na matriz.
				}
			}
		}

		counter = 0;

		for (int j = 0; j < key.length; j++) {
			for (int i = 0; i < height; i++) {
				if (counter >= data.length || matrix[i][j] == 256) {
					break;
				}
				matrix[i][j] = (char)data[counter++];
			}
		}

		byte[] decipheredData = new byte[data.length];
		counter = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (matrix[i][j] == 256) break;
				decipheredData[counter++] = (byte)matrix[i][j];
			}
		}

		return decipheredData;
	}
}

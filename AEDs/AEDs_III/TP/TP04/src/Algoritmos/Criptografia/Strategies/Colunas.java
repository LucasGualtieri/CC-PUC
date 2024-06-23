package TP04.src.Algoritmos.Criptografia.Strategies;

import TP04.src.Algoritmos.Criptografia.CipherStrategy;

public class Colunas implements CipherStrategy {

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

				else matrix[i][j] = 256;
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

	@Override
	public byte[] decipher(byte[] key, byte[] data) {

		int width = key.length;
		int height = (int)Math.ceil((float)data.length / width);

		char[][] matrix = new char[height][width];

		int counter = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (counter++ >= data.length) {
					matrix[i][j] = 256;
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

package TP04.src.Algoritmos.Criptografia;

import java.util.Arrays;
import TP04.src.Algoritmos.Criptografia.Strategies.*;

/**
 * Classe que representa um sistema de cifra utilizando diferentes estratégias de criptografia.
 */
public class Cipher {

	/** Array de estratégias de criptografia utilizadas pela classe */
	CipherStrategy[] strategies;

	/** Chave padrão utilizada para cifragem */
	public static final byte[] KEY = "AEDsIII".getBytes();

	/**
	 * Construtor que aceita uma ou mais estratégias de criptografia.
	 * 
	 * @param strategies Estratégias de criptografia a serem utilizadas.
	 */
	public Cipher(CipherStrategy... strategies) { this.strategies = strategies; }

	/**
	 * Construtor padrão que inicializa com as estratégias Viegenere e Colunas.
	 */
	public Cipher() {

		strategies = new CipherStrategy[2];
		strategies[0] = new Viegenere();
		strategies[1] = new Colunas();
	}

	/**
	 * Método para cifrar os dados utilizando a(s) estratégia(s) definida(s).
	 * 
	 * @param key  Chave utilizada para cifrar os dados.
	 * @param data Dados a serem cifrados.
	 * @return Dados cifrados.
	 */
	public byte[] cipher(byte[] key, byte[] data) {

		byte[] cipheredData = Arrays.copyOf(data, data.length);

		for (CipherStrategy strategy : strategies) {
			cipheredData = strategy.cipher(key, cipheredData);
		}

		return cipheredData;
	}

	/**
	 * Método para decifrar os dados utilizando a(s) estratégia(s) definida(s).
	 * 
	 * @param key          Chave utilizada para decifrar os dados.
	 * @param cipheredData Dados cifrados a serem decifrados.
	 * @return Dados decifrados.
	 */
	public byte[] decipher(byte[] key, byte[] cipheredData) {

		byte[] decipheredData = Arrays.copyOf(cipheredData, cipheredData.length);

		for (int i = strategies.length - 1; i >= 0; i--) {
			decipheredData = strategies[i].decipher(key, decipheredData);
		}

		return decipheredData;
	}
}

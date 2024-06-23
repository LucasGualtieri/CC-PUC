package TP04.src.Algoritmos.Criptografia;

public interface CipherStrategy {
	public byte[] cipher(byte[] key, byte[] array);
	public byte[] decipher(byte[] key, byte[] array);
}
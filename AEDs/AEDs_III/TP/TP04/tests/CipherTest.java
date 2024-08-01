package TP04.tests;

import java.io.IOException;

import TP04.src.utils.StreamManager;
import TP04.src.Algoritmos.Criptografia.Cipher;
// import TP04.src.Algoritmos.Criptografia.Strategies.*;

public class CipherTest {
	public static void main(String[] args) throws IOException {

		Cipher c = new Cipher();

		StreamManager sm = new StreamManager();

		sm.write(123);
		sm.writeUTF("Olá mundo!");
		sm.write('M');

		byte[] cipheredMsg = c.cipher(Cipher.KEY, sm.toByteArray());
		System.out.println("Ciphered Data: " + new String(cipheredMsg));

		sm = new StreamManager(c.decipher(Cipher.KEY, cipheredMsg));

		System.out.println("Deciphered Data: " + sm.readInt());
		System.out.println("Deciphered Data: " + sm.readUTF());
		System.out.println("Deciphered Data: " + sm.readChar());

		// byte b = 127;
		// System.out.println("b: " + b);
		// System.out.println("b: " + ++b);
		// System.out.println("b: " + --b);

	}
}

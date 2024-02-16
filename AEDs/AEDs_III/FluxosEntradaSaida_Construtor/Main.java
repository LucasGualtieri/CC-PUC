// clear && javac Main.java && java Main

import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.DataOutputStream;
import java.io.DataInputStream;

class Main {
	public static void main(String[] args) throws Exception {

		Livro livro1 = new Livro(1, "Eu, Robô", "Isaac Asimov", 14.9F);
		Livro livro2 = new Livro(2, "Eu Sou A Lenda", "Richard Matheson", 21.99F);

		System.out.print(livro1);
		System.out.println("--------------------");
		System.out.print(livro2);
		
		String filePath = "dados/livros.db";
		FileOutputStream fileOut = new FileOutputStream(filePath);
		DataOutputStream dos = new DataOutputStream(fileOut);

		byte[] arrayLivro1 = livro1.toByteArray();
		dos.writeInt(arrayLivro1.length);
		fileOut.write(arrayLivro1);
		
		byte[] arrayLivro2 = livro2.toByteArray();
		dos.writeInt(arrayLivro2.length);
		fileOut.write(arrayLivro2);

		fileOut.close();

		System.out.println("=======================");
		
		FileInputStream fileIn = new FileInputStream(filePath);
		DataInputStream dis = new DataInputStream(fileIn);

		int lengthLivro3 = dis.readInt();
		
		byte[] arrayLivro3 = new byte[lengthLivro3];
		dis.read(arrayLivro3);
		
		int lengthLivro4 = dis.readInt();

		byte[] arrayLivro4 = new byte[lengthLivro4];
		dis.read(arrayLivro4);

		Livro livro3 = new Livro(arrayLivro3);
		Livro livro4 = new Livro(arrayLivro4);

		System.out.print(livro3);
		System.out.println("--------------------");
		System.out.print(livro4);
		
		fileIn.close();
	}	
}

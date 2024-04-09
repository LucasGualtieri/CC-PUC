package AEDs.AEDs_III.RandomAccessFile;

// clear && javac Main.java && java Main

import java.io.RandomAccessFile;

class Main {
	public static void main(String[] args) throws Exception {

		Livro livro1 = new Livro(1, "Eu, Robô", "Isaac Asimov", 14.9F);
		Livro livro2 = new Livro(2, "Eu Sou A Lenda", "Richard Matheson", 21.99F);

		System.out.print(livro1);
		System.out.println("--------------------");
		System.out.print(livro2);
		
		String filePath = "dados/livros.db";
		RandomAccessFile file = new RandomAccessFile(filePath, "rw");

		long livro1StartPos = file.getFilePointer();
		byte[] arrayLivro1 = livro1.toByteArray();
		file.writeInt(arrayLivro1.length);
		file.write(arrayLivro1);
		
		long livro2StartPos = file.getFilePointer();
		byte[] arrayLivro2 = livro2.toByteArray();
		file.writeInt(arrayLivro2.length);
		file.write(arrayLivro2);

		System.out.println("=======================");
		
		file.seek(livro2StartPos);
		int lengthLivro3 = file.readInt();
		byte[] arrayLivro3 = new byte[lengthLivro3];
		file.read(arrayLivro3);
		
		file.seek(livro1StartPos);
		int lengthLivro4 = file.readInt();
		byte[] arrayLivro4 = new byte[lengthLivro4];
		file.read(arrayLivro4);

		Livro livro3 = new Livro(arrayLivro3);
		Livro livro4 = new Livro(arrayLivro4);

		System.out.print(livro3);
		System.out.println("--------------------");
		System.out.print(livro4);

		file.close();
	}	
}

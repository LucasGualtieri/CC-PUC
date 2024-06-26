package AEDs.AEDs_III.Materias.BasicosJava.Fluxos.FluxosEntradaSaida;

// clear && javac Main.java && java Main

import java.io.FileOutputStream;
import java.io.DataOutputStream;

import java.io.FileInputStream;
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

		dos.writeInt(livro1.idLivro);
		dos.writeUTF(livro1.titulo);
		dos.writeUTF(livro1.autor);
		dos.writeFloat(livro1.preco);

		dos.writeInt(livro2.idLivro);
		dos.writeUTF(livro2.titulo);
		dos.writeUTF(livro2.autor);
		dos.writeFloat(livro2.preco);

		// dos.flush();
		fileOut.close();
		dos.close();

		System.out.println("================================");

		FileInputStream fileIn = new FileInputStream(filePath);
		DataInputStream dis = new DataInputStream(fileIn);

		Livro livro3 = new Livro();

		livro3.idLivro = dis.readInt();
		livro3.titulo = dis.readUTF();
		livro3.autor = dis.readUTF();
		livro3.preco = dis.readFloat();
		
		Livro livro4 = new Livro();

		livro4.idLivro = dis.readInt();
		livro4.titulo = dis.readUTF();
		livro4.autor = dis.readUTF();
		livro4.preco = dis.readFloat();

		System.out.print(livro3);
		System.out.println("--------------------");
		System.out.print(livro4);

		fileIn.close();
		dis.close();
	}	
}

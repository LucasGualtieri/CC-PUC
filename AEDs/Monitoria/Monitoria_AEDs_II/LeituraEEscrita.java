import java.io.RandomAccessFile;
import java.util.Scanner;

// clear && javac LeituraEEscrita.java && java LeituraEEscrita.java

public class LeituraEEscrita {
	public static void main(String[] args) throws Exception {

		RandomAccessFile arquivo;
		arquivo = new RandomAccessFile("teste.txt", "rw");

		Scanner sc = new Scanner(System.in);
		int qtdNumeros = sc.nextInt();

		float real;
		for (int i = 0; i < qtdNumeros; i++) {
			// Leio do teclado
			real = sc.nextFloat();
			// Escrevo no Arquivo
			arquivo.writeFloat(real);
		}

		long pos = arquivo.getFilePointer();
		arquivo.seek(pos - 4);
		
		float resultado;
		for (int i = 0; i < qtdNumeros; i++) {
			// Salvo a posição inicial
			pos = arquivo.getFilePointer();

			// Leio do arquivo
			resultado = arquivo.readFloat();

			// Printo na tela
			System.out.println(resultado);

			// Voltar 4 bytes.
			if (pos > 0) arquivo.seek(pos - 4);
		}

		sc.close();
		arquivo.close();
	}
}

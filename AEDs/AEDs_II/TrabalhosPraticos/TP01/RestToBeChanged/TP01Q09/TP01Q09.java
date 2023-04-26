import java.io.*;

public class TP01Q09 {
	public static void main(String[] args) throws Exception {

		RandomAccessFile leitor = new RandomAccessFile("file.txt", "rw");
		int numEntradas = 0;
		double aux = 0.0;

		numEntradas = MyIO.readInt();

		for (int i = 0; i < numEntradas; i++) {
			aux = MyIO.readDouble();
			leitor.writeDouble(aux);
		}

		leitor.close();

		RandomAccessFile file = new RandomAccessFile("file.txt", "rw");

		file.seek((numEntradas * 8) - 8);

		for (int i = 0; i < numEntradas; i++) {
			aux = file.readDouble();
			if (aux % 1 == 0) {
				MyIO.println((int) aux);
			} else {
				MyIO.println(aux);
			}
			if (file.getFilePointer() >= 16) {
				file.seek(file.getFilePointer() - 16);
			}

		}
		file.close();

	}
}
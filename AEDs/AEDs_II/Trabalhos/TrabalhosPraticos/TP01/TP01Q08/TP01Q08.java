// clear && javac -cp ../../.. TP01Q08.java && java -cp ../../.. TP01Q08.java < pub.in > result.txt

import TrabalhosPraticos.Lib;
import java.io.File;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.io.*;
import java.util.*;

class TP01Q08 {

	public static void main(String[] args) throws Exception {

		/*
			- Inicialmente abro o arquivo para escrita.
			- Depois leio a quantidade de números a serem lidos.
			- Por último os escrevo em binário no arquivo.
		*/

		String filePath = "TP01Q08_LucasGualtieri.txt";
		RandomAccessFile fileWriter = new RandomAccessFile(filePath, "rw");

		int numberOfRealNumbers = Lib.getInt();

		for (int i = 0; i < numberOfRealNumbers; i++) {
			fileWriter.writeFloat(Lib.getFloat());
		}

		fileWriter.close();

		// --------------------------------------------------------

		/*
			- Agora abro o arquivo para leitura.
			- Levo o curso para o começo do último número.
			- Por último leio os números de trás para frente
			voltando sempre sizeof(float) para ler o número de trás.
		*/

		RandomAccessFile file = new RandomAccessFile(filePath, "r");
		// A ideia de fazer - 1 é posicionar o cursor exatamente
		// aonde ele precisa estar para fazer a primeira leitura.
		int currentPosition = (4 * (numberOfRealNumbers - 1));

		DecimalFormat formatter = new DecimalFormat();
		for (int i = currentPosition; i >= 0; i -= 4) {
			file.seek(i);
			System.out.print(formatter.format(file.readFloat()));
			if (i > 0) System.out.println();
		}
		
        file.close();
	}
}
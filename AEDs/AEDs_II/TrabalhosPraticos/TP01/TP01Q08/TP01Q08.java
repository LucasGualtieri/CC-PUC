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

		String filePath = "TP01Q08_LucasGualtieri.txt";
		RandomAccessFile fileWriter = new RandomAccessFile(filePath, "rw");

		int numberOfRealNumbers = Lib.getInt();

		for (int i = 0; i < numberOfRealNumbers; i++) {
			fileWriter.writeFloat(Lib.getFloat());
		}

		fileWriter.close();

		// --------------------------------------------------------

		RandomAccessFile file = new RandomAccessFile(filePath, "r");
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
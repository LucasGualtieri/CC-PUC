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

		String filePath = "TP01Q09_LucasGualtieri.txt";
		RandomAccessFile fileWriter = new RandomAccessFile(filePath, "rw");

		int numberOfRealNumbers = Lib.getint();

		for (int i = 0; i < numberOfRealNumbers; i++) {
			fileWriter.writeDouble(Lib.getDouble());
		}

		fileWriter.close();

		// --------------------------------------------------------

		RandomAccessFile file = new RandomAccessFile(filePath, "r");
        int currentPosition = (8 * (numberOfRealNumbers - 1));

		DecimalFormat formatter = new DecimalFormat();
		for (int i = currentPosition; i >= 0; i -= 8) {
			file.seek(i);
			System.out.println(formatter.format(file.readDouble()));
		}

        file.close();

	}
}
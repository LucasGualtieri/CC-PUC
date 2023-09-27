import java.util.*;
import java.io.File;

// clear && javac Prototype.java && java Prototype < pub.in

class Prototype {

	public static void main(String[] args) throws Exception {

		String filePath = "players.csv";
		Scanner file = new Scanner(new File(filePath));
		Scanner input = new Scanner(System.in);
		String pubIn;

		while (!(pubIn = input.next()).equals("FIM")) {
			String[] csvFile = file.nextLine().split(",");
			csvFile = file.nextLine().split(",");
			csvFile = file.nextLine().split(",");
			if (pubIn.equals(csvFile[0])) {
				System.out.println("Iguais");
			} else {
				System.out.println("Diferentes");
			}
			// for (int i = 0; i < csvFile.length; i++) {
			// 	System.out.printf("%s, ", csvFile[i]);
			// }
		}
		System.out.println();

		// int id = input.nextInt();
		// System.out.printf("id: %d\n", id);


		input.close();

	}
}
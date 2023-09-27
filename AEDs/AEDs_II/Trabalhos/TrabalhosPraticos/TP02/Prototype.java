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

			// Fazer um input.delimiter(',');
			// Para ler incialmente só o id
			// Se for igual ao do pubin
			// Jogador jogador = newJogador(id, "resto da string");
			// aí sim eu chamo a função Lista.push(jogador);
			// Tenho que passar o resto da string para poder fazer o spit

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
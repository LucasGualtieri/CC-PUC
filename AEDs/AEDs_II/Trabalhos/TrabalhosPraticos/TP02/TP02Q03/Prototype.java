import java.util.*;
import java.io.File;

// clear && javac Prototype.java && java Prototype < pub.in

class Prototype {

	public static void main(String[] args) throws Exception {

		File file = new File("tmp/players.csv");
		Scanner fileScanner = new Scanner(file);
		Scanner input = new Scanner(System.in);
		String pubIn;

		String teste = fileScanner.nextLine();

		while (!(pubIn = input.next()).equals("FIM")) {

			String[] arrayStrings = new String[5];
			arrayStrings[0] = "k\ljdlkfjsdflkjsdfljsdfkldlfsdklfjksdf"

			Class string {
				char array = new char[10000000000000];
			}



			// Fazer um file.delimiter(',');
			// Para ler incialmente só o id
			// Se for igual ao do pubin
			// Jogador jogador = newJogador(id, "resto da string");
			// aí sim eu chamo a função Lista.push(jogador);
			// Tenho que passar o resto da string para poder fazer o spit



			if (pubin == Integer.Parseint(file.delimiter(','))) {
				String linhaDoArquivo = file.nextLine();
				String[] arrayStrings = arrayStringslinhaDoArquivo.split(",");
			}

			jogador.setNome(arrayStrings[1]);

			// String[] csvFile = file.nextLine().split(",");
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
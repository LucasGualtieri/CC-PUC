import java.util.Scanner;

class Duende {
	String nome;
	int idade;
}

public class duendes {

	public static void printTeam(int third, int i, Duende[] duendes) {
		// Third marca o começo do segundo terço do vetor de duendes
		// (Third * 2) marca o começo do terceiro terço do vetor de duendes
		System.out.println("Time " + (i + 1));
		System.out.println(duendes[i].nome + " " + duendes[i].idade);
		System.out.println(duendes[i + third].nome + " " + duendes[i + third].idade);
		System.out.println(duendes[i + third * 2].nome + " " + duendes[i + third * 2].idade);
		System.out.println();
	}

	public static boolean ordemAlfabetica(String nome1, String nome2) {
		nome1.toLowerCase();
		nome2.toLowerCase();

		System.out.println(nome2);
		if (nome1.length() > nome2.length()) {
			return true;
		} else if (nome1.length() < nome2.length()) {
			return false;
		} else {
			for (int i = 0; i < nome1.length(); i++) {
				if (nome1.charAt(i) > nome2.charAt(i)) {
					return true;
				} else if (nome1.charAt(i) < nome2.charAt(i)) {
					return false;
				}
			}
		}
		return false; // Esse código é inalcançável, ele tá aqui pra não bugar
	}

	public static void sort(int arrayLength, Duende[] duendes) {
		for (int i = 0; i < (arrayLength - 1); i++) {
			int maior = i;
			for (int j = (i + 1); j < arrayLength; j++) {
				if (duendes[maior].idade == duendes[j].idade) {
					if (ordemAlfabetica(duendes[maior].nome, duendes[j].nome)) {
						maior = j;
					}
				} else if (duendes[maior].idade < duendes[j].idade) {
					maior = j;
				}
			}
			Duende swap = duendes[maior];
			duendes[maior] = duendes[i];
			duendes[i] = swap;
		}
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		// Quantidade de Duendes na lista
		int N = Integer.parseInt(scanner.nextLine());

		Duende[] duendes = new Duende[N];

		// Atribuindo os nomes e as idades aos Duendes
		for (int i = 0; i < N; i++) {
			/*
			 * Separa a string em um array (nesse caso de tamanho 2)
			 * usando espaço ' ' para separar essa string.
			 * Assim a 1° posição [0] é o nome e a 2° [1] é a idade
			 * Lucas 20 -> array["Lucas", "20"]
			 */
			duendes[i] = new Duende();
			String[] nomeIdade = scanner.nextLine().split(" ");
			duendes[i].nome = nomeIdade[0];
			duendes[i].idade = Integer.parseInt(nomeIdade[1]);
		}

		// Ordenando em ordem de idade
		sort(N, duendes);

		int third = N / 3; // Número de times a serem impressos
		for (int i = 0; i < third; i++) {
			printTeam(third, i, duendes);
		}
		scanner.close();
	}
}
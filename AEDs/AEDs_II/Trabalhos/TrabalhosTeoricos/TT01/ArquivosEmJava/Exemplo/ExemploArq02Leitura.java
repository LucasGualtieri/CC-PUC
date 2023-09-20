import ArquivosEmJava.Arq;

class ExemploArq02Leitura {
	public static void main(String[] args) {
		if (!Arq.openRead(
				"AEDs/AEDs_II/TrabalhosTeoricos/TT01/ArquivosEmJava/Exemplo/Exemplo.txt")) {
			System.out.println("Falha ao abrir o arquivo!");
			return;
		}
		int inteiro = Arq.readInt();
		double real = Arq.readDouble();
		char caractere = Arq.readChar();
		boolean boleano = Arq.readBoolean();
		String str = Arq.readString();
		Arq.close();
		System.out.println("inteiro: " + inteiro);
		System.out.println("real: " + real);
		System.out.println("caractere: " + caractere);
		System.out.println("boleano: " + boleano);
		System.out.println("str: " + str);
	}
}

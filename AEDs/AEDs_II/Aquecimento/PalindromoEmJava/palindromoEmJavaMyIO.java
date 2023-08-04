// clear && javac palindromoEmJavaMyIO.java && java palindromoEmJavaMyIO < pub.in > alun.out

class palindromoEmJavaMyIO {

	public static boolean isPalin(String input) {
		StringBuilder reversed = new StringBuilder(input);
		return input.equals(reversed.reverse().toString());
	}

	public static void main(String[] args) {

		String input;

		while (!(input = MyIO.readLine()).equals("FIM")) {
			// MyIO.println("input: " + input + ".len() = " + input.length());
			MyIO.println(isPalin(input) ? "SIM" : "NAO");
		}
	}
}
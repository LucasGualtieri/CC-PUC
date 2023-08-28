// clear && javac -cp ../../.. TP01Q05.java && java -cp ../../.. TP01Q05.java < pub.in > result.txt

import TrabalhosPraticos.Lib;

class TP01Q05 {

Selection sort
	//static boolean AND() {
	//	boolean val1, boolean val2;
	//	// val1 = searchForVal();
	//	
	//	// Agora buscamos os segundo valor
	//	// val2 = searchForVal();

	//	return val1 && val2;
	//}

	//static boolean OR() {
	//	boolean val1, boolean val2;
	//	// val1 = searchForVal();
	//	
	//	// Agora buscamos os segundo valor
	//	// val2 = searchForVal();

	//	return val1 || val2;
	//}

	//static boolean NOT() {
	//	boolean val1, boolean val2;
	//	// Buscamos saber se temos A ou b ou c, ou and or not or not

	//	if (/* SOMETHING >= A && <= C */) {
	//		val = val1;
	//	}
	//	else if (/* SOMETHING == AND*/) {
	//		val = AND();
	//	} else if (/* SOMETHING == OR*/) {
	//		val = OR();
	//	} else {
	//		val = NOT();
	//	}

	//	return !val1;
	//}

	static boolean searchForVal() {

		// Esse metodo inicia a busca e as chamadas recursivas
		// mas tbm precisa ser capaz de saber a hora de parar de buscar.

		// Talvez if (c == '/n' or c == /r) return something;

		// This method will iterate character by character until it finds
		// A, B, C, AND, OR, NOT.

		while ()

		if (/* SOMETHING >= A && <= C */) {
			return val;
		}
		else if (/* SOMETHING == AND*/) {
			return AND();
		} else if (/* SOMETHING == OR*/) {
			return OR();
		} else {
			return NOT();
		}

	}

	static int algebraBooleana(String input) {
		
		int N = StringNextInt(input);
		
		boolean[] entradas = new boolean[N];

		for (int i = 0; i < N; i++) {
			entradas[i] StringNextIntk() == 1 ? true : false;
		}

		// replace all spaces with nothing
		// if (n == 1) replace all As with value of entradas[0];
		// if (n == 2) replace all As with value of entradas[0] && all Bs with value of entradas[1];
		// if (n == 3) replace all As with value of entradas[0] && all Bs with value of entradas[1], all Cs with value of entradas[2];

		String entradaTratada = 
	
		return searchForVal();
	}

	public static void main(String[] args) {
		String input = new String();
		while(!Lib.isEqual(input = Lib.getstr(), "0")) {
			System.out.println(algebraBooleana(input));
		}
	}
}

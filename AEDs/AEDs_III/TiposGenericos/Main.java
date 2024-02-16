package AEDs.AEDs_III.TiposGenericos;

// clear && javac Main.java && java Main

class Main {
	static class Caixa<tipoGenerico> {
		private tipoGenerico objeto;

		public void armazena(tipoGenerico objeto) {
			this.objeto = objeto;
		}

		public tipoGenerico recupera() {
			return this.objeto;
		}
	}

	static class CaixaRuim {
		private Object objeto;

		public void armazena(Object objeto) {
			this.objeto = objeto;
		}

		public Object recupera() {
			return this.objeto;
		}
	}

	public static void main(String[] args) {
		
		Caixa<String> c = new Caixa<>();
		c.armazena(new String("OLA MUNDO"));
		String str = c.recupera();
		System.out.println(str);
		
		CaixaRuim cr = new CaixaRuim();
		cr.armazena(new String("OLA MUNDO"));
		str = (String)cr.recupera();
		System.out.println(str);
	}
}

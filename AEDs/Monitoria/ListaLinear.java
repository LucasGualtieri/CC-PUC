class ListaLinear {
	static class Lista {
		private int[] array;
		private int n; // Variável que controla a quantidade e elementos presentes 

		Lista() { this(80); }		
		Lista(int arrayMaxSize) {
			array = new int[arrayMaxSize];
			n = 0;
		}

		public void InserirInicio(int numeroInicial) {
			if (n == array.length) {
				System.out.println("Erro ao inserir: Lista cheia.");
				return;
			}
			
			for (int i = n - 1; i > 0; i--) {
				array[i] = array[i-1];
			}

			array[0] = numeroInicial;
			n++;
		}

		public void InserirFim(int numeroFinal)
		{
			if(n==array.length)
			{
				System.out.println("Erro ao inserir: Lista cheia.");
				return;
			}
			array[n++] = numeroFinal;
		}

		public void RemoverFinal() throws Exception {
			if ( n == 0){
				throw new Exception("Erro vacilao!");
			}
			//return array[--n];
			n--;
		}

		public void mostrar() {
			for (int i = 0; i < n; i++) {
				System.out.print(array[i] + " ");
			}
		}

	}

	public static void main(String[] args)  {
		Lista lista = new Lista(4);
		
	//lista.InserirInicio(1);
		//lista.InserirFim(2);
		try{
		lista.RemoverFinal();
		}
		catch(Exception erro)
		{
			System.out.println(erro.getMessage());
		}
		//lista.InserirFim(3);
		//lista.mostrar();
	}
}
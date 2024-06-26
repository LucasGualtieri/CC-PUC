package AEDs.AEDs_III.Materias.BasicosJava.TiposGenericos;

import java.lang.reflect.Constructor;
// import java.lang.reflect.InvocationTargetException;

// clear && javac Interfaces.java && java Interfaces

class Generic {
	
	interface Entidade {
		public int getID();
	}

	class Cliente implements Entidade {
		protected int idCliente;
		
		public Constructor<Cliente> getConstructor() throws NoSuchMethodException, SecurityException {
			return Cliente.class.getConstructor();
		}

		public int getID() {
			return idCliente;
		}
	}	  

	class Produto implements Entidade {
		protected int idCliente;
		
		public int getID() {
			return idCliente;
		}
	}	  

	static class Arquivo<T extends Entidade> {
		Constructor<T> construtor;
		public Arquivo(Constructor<T> construtor) {
			this.construtor = construtor;
		}

		public void Instanciador() throws Exception {
			T objeto = this.construtor.newInstance();
			objeto.getID();
		}
	}

	public static void main(String[] args) throws NoSuchMethodException, SecurityException {

		// Arquivo<Cliente> arquivoDeClientes = new Arquivo<>(Cliente.getConstructor());
		// Arquivo<Produto> arquivoDeProdutos = new Arquivo<>(Produto.class.getConstructor());
	}
}

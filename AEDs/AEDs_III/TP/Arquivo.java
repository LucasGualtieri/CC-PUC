// package AEDs.AEDs_III.TP;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

interface Entidade {
	public int getID();
	public void setID(int id);
}
// testes
class Arquivo<T extends Entidade> {
	Constructor<T> construtor;
	RandomAccessFile arq;

	public Arquivo(Constructor<T> construtor) {
		this.construtor = construtor;
	}

	public Arquivo(Constructor<T> construtor, String filePath) throws FileNotFoundException {
		this.construtor = construtor;
		AbrirArquivo(filePath);
	}

	private void AbrirArquivo(String filePath) throws FileNotFoundException {
		arq = new RandomAccessFile(filePath, "rw");
	}

	public void Instanciador() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.getID();
	}

	public Livro Instanciador(byte[] array) throws Exception {
		return new Livro(array);
	}

	public void Inicializar() throws IOException {
		arq.writeInt(0);
	}

	public void Inicializar(int id) throws IOException {
		arq.writeInt(id);
	}

	public int create(Livro obj) throws Exception {

		arq.seek(0); // Ir para o começo, irrelevante somente na primeira operação
		int ultimoID = arq.readInt(); // Recuperar o último ID
		obj.setID(++ultimoID); // Setta o ID do objeto
		
		arq.seek(0); // Volta pra começo
		arq.writeInt(ultimoID); // Atualiza
	
		arq.seek(arq.length()); // Vai pro fim do arquivo para criar o registro
		
		long endereco = arq.getFilePointer(); // Posição do começo do registro
		byte[] ba = obj.toByteArray();
		short tam = (short)ba.length;
		// arq.write(' '); // lápide
		
		arq.writeShort(tam);
		arq.write(ba);
		
		return obj.getID();
	}
	
	public boolean delete(int id) throws IOException, Exception {
		
		boolean resultado = false;
		
		arq.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		
		long len = arq.length();

		short tamanhoRegistro;

		for (int i = 4; i < len; i += Math.abs(tamanhoRegistro) + 2) {

			long endereco = arq.getFilePointer();
			tamanhoRegistro = arq.readShort();

			if (tamanhoRegistro > 0) {
				byte[] registro = new byte[tamanhoRegistro];
				arq.read(registro);

				Livro obj = Instanciador(registro);

				if (obj.getID() == id) {
					arq.seek(endereco);
					arq.writeShort(-tamanhoRegistro);
					resultado = true;
					i = (int)len;
				}
			}
		}
		
		return resultado;
	}

	public Livro read(int id) {
		Livro l = new Livro();

		// código para busca sequencial do livro

		return l;
	}
	
	public void close() throws Exception {
		arq.close();
	}
}
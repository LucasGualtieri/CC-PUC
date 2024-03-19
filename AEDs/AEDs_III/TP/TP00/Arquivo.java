package TP00;
// package AEDs.AEDs_III.TP;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

class Arquivo<T extends Registro> {
	Constructor<T> construtor;
	RandomAccessFile arq;
	short HEADER_SIZE;

	public Arquivo(Constructor<T> construtor) {
		this.construtor = construtor;
	}

	public Arquivo(Constructor<T> construtor, String filePath) throws FileNotFoundException, IOException {
		this.construtor = construtor;
		AbrirArquivo(filePath);
	}

	private void AbrirArquivo(String filePath) throws FileNotFoundException, IOException {
		arq = new RandomAccessFile(filePath, "rw");

		if (arq.length() < 4) {
			arq.seek(0);
			arq.writeInt(0);
		}
	}

	public void Instanciador() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.getID();
	}

	public T Instanciador(byte[] array) throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.fromByteArray(array);
		return objeto;
	}

	public void Inicializar() throws IOException {
		arq.writeInt(0);
	}

	public int create(T obj) throws Exception {

		arq.seek(0); // Ir para o começo, irrelevante somente na primeira operação
		int ultimoID = arq.readInt() + 1; // Recuperar o último ID
		obj.setID(ultimoID); // Setta o ID do objeto
		
		arq.seek(0); // Volta pra começo
		arq.writeInt(ultimoID); // Atualiza
	
		arq.seek(arq.length()); // Vai pro fim do arquivo para criar o registro
		
		byte[] ba = obj.toByteArray();
		short tam = (short)ba.length;
		
		arq.writeShort(tam);
		arq.write(ba);
		
		return obj.getID();
	}

	public boolean delete(int id) throws IOException, Exception {
		
		boolean resultado = false;
		
		arq.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = arq.length();
		short tamanhoRegistro;
		
		while(arq.getFilePointer() < len) {
			long endereco = arq.getFilePointer();
			tamanhoRegistro = arq.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				arq.read(registro);
				
				T obj = Instanciador(registro);
				
				if (obj.getID() == id) {
					arq.seek(endereco); // Volta para o indicador de tamanho
					arq.writeShort(-tamanhoRegistro);
					resultado = true;
					arq.seek(len);
				}
			} else {
				arq.seek(arq.getFilePointer() + Math.abs(tamanhoRegistro));
			}
		}
		
		return resultado;
	}
	
	public T read(int id) throws IOException, Exception {
		
		T objReturn = null;

		arq.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = arq.length();
		short tamanhoRegistro;

		while(arq.getFilePointer() < len) {

			tamanhoRegistro = arq.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				arq.read(registro);
				
				T obj = Instanciador(registro);
				
				if (obj.getID() == id) {
					objReturn = obj;
					arq.seek(len);
				}
			}

			else {
				arq.skipBytes(Math.abs(tamanhoRegistro));
			}
		}

		return objReturn;
	}
	
	public boolean update(T newObj) throws IOException, Exception {
		boolean resultado = false;
		
		arq.seek(4); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = arq.length();
		short tamanhoRegistro;
		
		while(arq.getFilePointer() < len) {
			long endereco = arq.getFilePointer();
			tamanhoRegistro = arq.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				arq.read(registro);
				
				T obj = Instanciador(registro);
				
				if (obj.getID() == newObj.getID()) {

					byte[] novoRegistro = newObj.toByteArray();

					if (novoRegistro.length <= registro.length) {
						arq.seek(endereco + 2); // Volta para o começo do registro
						arq.write(novoRegistro);
						arq.seek(len); // Encerra o while
					} else {
						arq.seek(endereco);
						arq.writeShort(-tamanhoRegistro);
						arq.seek(len);
						arq.writeShort(novoRegistro.length);
						arq.write(novoRegistro);
					}

					resultado = true;
				}
			} else {
				arq.seek(arq.getFilePointer() + Math.abs(tamanhoRegistro));
			}
		}
		
		return resultado;
	}

	public void close() throws Exception {
		arq.close();
	}
}
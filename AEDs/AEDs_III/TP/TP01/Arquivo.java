package TP01;
// package AEDs.AEDs_III.TP;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;
import java.util.LinkedList;
import java.util.List;

public class Arquivo<T extends Registro> {

	Constructor<T> construtor;
	RandomAccessFile file;
	HashExtensivel<ParIDEndereco> indiceDireto;
	String nome;
	final short HEADER_SIZE = 4;

	public Arquivo() {}

	public Arquivo(Constructor<T> construtor) {
		this.construtor = construtor;
	}

	public Arquivo(Constructor<T> construtor, String nome, String filePath) throws FileNotFoundException, IOException, Exception {
		this.construtor = construtor;
		AbrirArquivo(filePath);

		this.nome = nome;

		indiceDireto = new HashExtensivel<>(
			ParIDEndereco.getConstructor(),
			3,
			"dados/" + nome + ".hash_d.db",
			"dados/" + nome + ".hash_c.db"
		);
	}

	public String getNome() { return nome; }

	private void AbrirArquivo(String filePath) throws FileNotFoundException, IOException {
		file = new RandomAccessFile(filePath, "rw");

		if (file.length() < HEADER_SIZE) {
			file.seek(0);
			file.writeInt(0);
		}
	}

	// public void Instanciador() throws Exception {
	// 	T objeto = this.construtor.newInstance();
	// 	objeto.getID();
	// }

	public T Instanciador(byte[] array) throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.fromByteArray(array);
		return objeto;
	}

	public T Instanciador(long address, short tamanhoRegistro) throws Exception {

		byte[] registro = new byte[tamanhoRegistro];
		file.read(registro);

		T objeto = this.construtor.newInstance();
		objeto.fromByteArray(registro);

		objeto.setAddress(address);

		return objeto;
	}

	public T readNewInstance() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.setAll();
		return objeto;
	}

	public T readNewInstance(int ID) throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.setID(ID);
		objeto.setAll();
		return objeto;
	}

	public int create(T obj) throws Exception {

		file.seek(0); // Ir para o começo, irrelevante somente na primeira operação
		int ID = file.readInt() + 1; // Recuperar o último ID
		obj.setID(ID); // Setta o ID do objeto
		
		file.seek(0); // Volta pra começo
		file.writeInt(ID); // Atualiza
	
		file.seek(file.length()); // Vai pro fim do arquivo para criar o registro
		long endereco = file.getFilePointer();

		byte[] ba = obj.toByteArray();
		short tam = (short)ba.length; 
		
		file.writeShort(tam);
		file.write(ba);

		indiceDireto.create(new ParIDEndereco(ID, endereco));

		return ID;
	}

	public T read(int ID) throws IOException, Exception {
		
		T object = construtor.newInstance();

		ParIDEndereco pie = indiceDireto.read(ID);
		long address = pie != null ? pie.getEndereco() : -1;

		if (address != -1) {

			file.seek(address);

			short tamanhoRegistro = file.readShort();
			byte[] registro = new byte[tamanhoRegistro];

			file.read(registro);

			object.fromByteArray(registro);
		}

		else throw new Exception();

		return object;
	}

	public void update(T oldObj, T newObj) throws IOException, Exception {

		short tamanhoRegistro = (short)oldObj.toByteArray().length;

		byte[] novoRegistro = newObj.toByteArray();

		if (novoRegistro.length <= tamanhoRegistro) {
			file.seek(oldObj.getAddress() + 2); // Começo do registro, após o indicador de tamanho
			file.write(novoRegistro);
		}
		
		else {
			file.seek(oldObj.getAddress());
			file.writeShort(-tamanhoRegistro);
			file.seek(file.length());
			file.writeShort(novoRegistro.length);
			file.write(novoRegistro);
		}
	}

	public void delete(int ID) throws Exception {

		long address = indiceDireto.read(ID).getEndereco();

		file.seek(address);
		short tamanhoRegistro = file.readShort();
		file.seek(address);
		file.writeShort(-tamanhoRegistro);

		indiceDireto.delete(ID);
	}

	// public void delete(T object) throws IOException, Exception {
	// 	file.seek(object.getAddress()); // Volta para o indicador de tamanho
	// 	file.writeShort(-(object.toByteArray().length));
	// }

	// public boolean delete(int id) throws IOException, Exception {
		
	// 	boolean resultado = false;
		
	// 	arq.seek(HEADER_SIZE); // mover o ponteiro para o primeiro registro (após o cabeçalho)
	// 	long len = arq.length();
	// 	short tamanhoRegistro;
		
	// 	while(arq.getFilePointer() < len) {
	// 		long endereco = arq.getFilePointer();
	// 		tamanhoRegistro = arq.readShort();
			
	// 		if (tamanhoRegistro > 0) {
				
	// 			byte[] registro = new byte[tamanhoRegistro];
	// 			arq.read(registro);
				
	// 			T obj = Instanciador(registro);
				
	// 			if (obj.getID() == id) {
	// 				arq.seek(endereco); // Volta para o indicador de tamanho
	// 				arq.writeShort(-tamanhoRegistro);
	// 				resultado = true;
	// 				arq.seek(len);
	// 			}
	// 		} else {
	// 			arq.seek(arq.getFilePointer() + Math.abs(tamanhoRegistro));
	// 		}
	// 	}
		
	// 	return resultado;
	// }

	public List<T> Listar() throws IOException, Exception {

		List<T> list = new LinkedList<>();

		file.seek(HEADER_SIZE); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = file.length();

		while(file.getFilePointer() < len) {

			short tamanhoRegistro = file.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				file.read(registro);

				list.add(Instanciador(registro));
			}

			else {
				file.skipBytes(Math.abs(tamanhoRegistro));
			}
		}

		return list.isEmpty() ? null : list;
	}

	public void printHeader() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.printHeader();
	}

	public void close() throws Exception {
		file.close();
	}
}
package TP01;
// package AEDs.AEDs_III.TP;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;
import java.util.LinkedList;
import java.util.List;

import TP01.Indices.HashExtensivel;
import TP01.Indices.IndiceDeExcluidos;
import TP01.Indices.ParIDEndereco;

public class Arquivo<T extends Registro> {

	final short HEADER_SIZE = 4;
	Constructor<T> construtor;
	RandomAccessFile file;
	HashExtensivel<ParIDEndereco> indiceDireto;
	String nome;
	private final short registerAvgLength = 40; // 2 + 4 + (2 + 14) + (2 + 12) + 4.

	public IndiceDeExcluidos excluidos; // Preciso salvar puxar da memoria

	public Arquivo() {}

	public Arquivo(Constructor<T> construtor) {
		this.construtor = construtor;
	}

	public Arquivo(Constructor<T> construtor, String nome, String filePath) throws FileNotFoundException, IOException, Exception {
		this.construtor = construtor;
		AbrirArquivo(filePath);

		excluidos = new IndiceDeExcluidos(filePath + nome);

		this.nome = nome;

		indiceDireto = new HashExtensivel<>(
			ParIDEndereco.getConstructor(),
			3,
			filePath + nome + ".hash_d.db",
			filePath + nome + ".hash_c.db"
		);
	}

	public int create(T object) throws Exception {

		file.seek(0);
		int ID = file.readInt() + 1; // Recuperar o último ID
		
		try {
			object.setID(ID); // Settar o ID do objeto
		
			// Voltar para o começo para atualizar o último ID.
			file.seek(0);
			file.writeInt(ID);
			
			byte[] registro = object.toByteArray();
			short length = (short)registro.length; 

			Tuple<Short, Long> tuple = excluidos.getBest(length);

			long address = tuple.getValue() == -1 ? file.length() : tuple.getValue();

			file.seek(address == -1 ? file.length() : address);

			short difference = (short)(tuple.getKey() - length);

			if (difference >= registerAvgLength) {
				file.writeShort(length);
				file.write(registro);
				excluidos.create(new Tuple<>(difference, file.getFilePointer()));
				file.writeShort(-(difference - 2));
			}

			// Inserir no fim
			else if (tuple.getKey() == 0) {
				file.seek(file.length());
				file.writeShort(length);
				file.write(registro);
			}
			
			// Atualizar
			else {
				file.writeShort(tuple.getKey());
				file.write(registro);
			}

			indiceDireto.create(new ParIDEndereco(ID, address));
		} catch (Exception e) {
			e.printStackTrace();
		}

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

		System.out.println("OA MUNDO");
		System.exit(-1);

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

		excluidos.create(new Tuple<>(tamanhoRegistro, address));

		indiceDireto.delete(ID);
	}

	// ----------------------------------------------------------------------------------

	private void AbrirArquivo(String filePath) throws FileNotFoundException, IOException {
		file = new RandomAccessFile(filePath + "s.db", "rw");

		if (file.length() < HEADER_SIZE) {
			file.seek(0);
			file.writeInt(0);
			// file.writeLong(-1);
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

	public List<T> Listar() throws IOException, Exception {

		List<T> list = new LinkedList<>();

		file.seek(HEADER_SIZE); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = file.length();

		while(file.getFilePointer() < len) {

			short tamanhoRegistro = file.readShort();
			
			if (tamanhoRegistro > 0) {
				
				byte[] registro = new byte[tamanhoRegistro];
				file.read(registro);

				// Esta linha esta causando problemas
				list.add(Instanciador(registro));
			}

			else file.skipBytes(Math.abs(tamanhoRegistro));
		}

		return list.isEmpty() ? null : list;
	}

	public String getNome() { return nome; }
	public String getNomeLowerCase() { return nome.toLowerCase(); }

	public void printHeader() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.printHeader();
	}

	public void close() throws Exception {
		excluidos.close();
		file.close();
	}

	
	// Talvez implementar uma interface para obrigar as classes filhas como ArquivoLivro a implementarem esse delete
	// private void delete(int shift, short newLength) throws Exception {}

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
}
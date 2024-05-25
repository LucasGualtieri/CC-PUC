package TP03;

import java.util.List;

import TP03.EstruturasDeDados.*;
import TP03.EstruturasDeDados.Tuplas.*;

import java.io.IOException;
import java.util.LinkedList;
import java.io.RandomAccessFile;
import java.io.FileNotFoundException;
import java.lang.reflect.Constructor;

public class Arquivo<T extends Registro> {

	final short HEADER_SIZE = 4;
	protected static RandomAccessFile file;
	protected String nome;
	protected Constructor<T> construtor;
	protected static HashExtensivel<ParIDEndereco> indiceDireto;
	// private final short registerAvgLength = 40; // 2 + 4 + (2 + 14) + (2 + 12) + 4.

	public IndiceDeExcluidos excluidos; // Preciso salvar puxar da memoria

	public Arquivo() {}

	public Arquivo(Constructor<T> construtor) {
		this.construtor = construtor;
	}

	public Arquivo(Constructor<T> construtor, String nome, String filePath) throws FileNotFoundException, IOException, Exception {
		
		this.nome = nome;
		
		this.construtor = construtor;
		AbrirArquivo(filePath + getNomePlural());

		excluidos = new IndiceDeExcluidos(filePath + getNomePlural());

		indiceDireto = new HashExtensivel<>(
			ParIDEndereco.getConstructor(), 3,
			filePath + nome + ".hash_d.db",
			filePath + nome + ".hash_c.db"
		);
	}

	public int create(T object) throws Exception {
		return create(true, 0, object);
	}

	protected int create(boolean createNewID, T object) throws Exception {
		return create(createNewID, 0, object);
	}

	protected int create(boolean createNewID, int registerLength, T object) throws Exception {
		int ID = object.getID();

		if (createNewID) {
			file.seek(0);
			ID = file.readInt() + 1; // Recuperar o último ID
	
			object.setID(ID); // Settar o ID do objeto
	
			// Voltar para o começo para atualizar o último ID.
			file.seek(0);
			file.writeInt(ID);
		}

		byte[] registro = object.toByteArray();
		short length = (short)registro.length;

		Tuple<Short, Long> tuple = excluidos.getBest(length);

		long address = tuple.getValue() == -1 ? file.length() : tuple.getValue();

		file.seek(address);
		// file.seek(address == -1 ? file.length() : address);

		short difference = (short)(tuple.getKey() - (length + 2));

		// Quebrar registro excluido
		if (difference >= registerLength) {
			file.writeShort(length);
			file.write(registro);
			excluidos.create(new Tuple<>(difference, file.getFilePointer()));
			file.writeShort(-difference);
			// System.out.println("IF");
		}
		
		// Inserir no fim
		else if (tuple.getKey() == 0) {
			// Essa linha foi comentada em cima da data de entrega e não houveram testes extensivos depois da modificação
			// excluidos.create(tuple); // Precisa ser recriado já que o getBest deleta // Nesse caso acredito que NUNCA será deletado
			file.seek(file.length());
			file.writeShort(length);
			file.write(registro);
		}
		
		// Manter o Lixo do registro excluído
		else {
			// System.out.println("Else");
			file.writeShort(tuple.getKey());
			file.write(registro);
		}
		
		indiceDireto.create(new ParIDEndereco(ID, address));

		return ID;
	}

	public int read() throws Exception { return -1; }

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

	public void update(int ID, T newObj) throws IOException, Exception {
		ParIDEndereco pie = indiceDireto.read(ID);
		delete(pie.getId());
		create(false, newObj);
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

	// Metodo que será sobrescrito pelas classes filhas
	public int SortList(List<T> list) { return -1; }

	// Métod que percorre o arquivo sequencialmente e adiciona ao final de uma lista encadeada todos os registros não "lapidados"
	public List<T> Listar() throws IOException, Exception {

		List<T> list = new LinkedList<>();

		file.seek(HEADER_SIZE); // mover o ponteiro para o primeiro registro (após o cabeçalho)
		long len = file.length();

		while(file.getFilePointer() < len) {

			short tamanhoRegistro = file.readShort();
			// System.out.println("tamanhoRegsitro: " + tamanhoRegistro);
			// System.out.println("address: " + (file.getFilePointer() - (long)2));
			
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

	// ----------------------------------------------------------------------------------

	private void AbrirArquivo(String filePath) throws FileNotFoundException, IOException {
		file = new RandomAccessFile(filePath + ".db", "rw");

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

	// public T Instanciador(long address, short tamanhoRegistro) throws Exception {

	// 	byte[] registro = new byte[tamanhoRegistro];
	// 	file.read(registro);

	// 	T objeto = this.construtor.newInstance();
	// 	objeto.fromByteArray(registro);

	// 	objeto.setAddress(address);

	// 	return objeto;
	// }

	// Essa função permite que o usuário leia os dados de uma entidade qualquer
	// O método setAll() faz uma interface com o usário e requisita os dados de uma entidade como nome, cpf, ISBN, etc...
	public T readNewInstance() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.setAll(false);
		return objeto;
	}

	public T readNewInstance(T object) throws Exception {
		T objeto = object;
		objeto.setAll(true);
		return objeto;
	}

	public String getNome() { return nome; }
	public String getNomeLowerCase() { return nome.toLowerCase(); }
	public String getNomePlural() { return nome + "s"; }
	public String getNomePluralLowerCase() { return nome.toLowerCase() + "s"; }

	public void printHeader() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.printHeader();
	}

	public void printHeaderCSV() throws Exception {
		T objeto = this.construtor.newInstance();
		objeto.printHeaderCSV();
	}

	public int CRUDMenu() { return -1; }

	public List<T> readInvertida() throws Exception { return null; }

	public void close() throws Exception {
		excluidos.close();
		file.close();
	}

}
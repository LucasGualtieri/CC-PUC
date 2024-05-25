package TP03.EstruturasDeDados;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Iterator;
import java.util.TreeSet;

import TP03.EstruturasDeDados.Tuplas.Tuple;

// Se houverem dois registros excluídos imediatamente um ao lado do outros
// Idealmente os dois deveriam ser fundidos.

public class IndiceDeExcluidos {
	
	private RandomAccessFile file;
	private TreeSet<Tuple<Short, Long>> list;
	private final short REG_LENGTH = 2 + 8;

	public IndiceDeExcluidos(String filePath) throws IOException {
		// Instancia a arvore e passa por parametro o comparator
		list = new TreeSet<>((var1, var2) -> var1.getKey().compareTo(var2.getKey()));
		ImportData(filePath);
	}

	public void close() throws IOException {
		file.close();
	}

	// Monta a arvore a partir dos dados (tuplas) do arquivo
	private void ImportData(String filePath) throws IOException {

		file = new RandomAccessFile(filePath + "Excluidos.db", "rw");
		// file.seek(0);

		long fileLength = file.length();
		Tuple<Short, Long> tuple = new Tuple<>((short)1, (long)1);

		while (file.getFilePointer() < fileLength) {
			byte[] array = new byte[REG_LENGTH];
			file.read(array);
			tuple.fromByteArray(array);
			if (tuple.getKey() > 0) list.add(tuple);
		}
	}

	// Retorna a tupla de menor tamanho da arvore que seja maior que o tamanho do novo registro
	// retorna uma tupla com valores padrão caso não haja como reaproveitar algum espaço vazio
	public Tuple<Short, Long> getBest(short length) throws IOException {
		
		Tuple<Short, Long> result = list.higher(
			new Tuple<>((short)(length - 1), (long)0)
		);

		if (result != null) this.delete(result);
		else result = new Tuple<>((short)0, (long)-1);

		return result;
	}

	// Insere uma tupla na árvore e cria um registro no arquivo
	// Percorre o arquivo sequencialmente para ver se é possível reaproveitar alguma tupla "lapidada"
	public void create(Tuple<Short, Long> tuple) throws IOException {

		list.add(tuple);

		file.seek(0);

		long address, fileLength = file.length();

		while((address = file.getFilePointer()) < fileLength) {
			short lapide = file.readShort();

			if (lapide < 0) {
				file.seek(address);
				fileLength = 0; // Encerrar o while
			}
			else file.skipBytes(8); // Skipando o long;
		}

		// try { Thread.sleep(1000); }
		// catch (InterruptedException e) {}

		file.write(tuple.toByteArray());
	}

	// Remove uma tupla da árvore e marca o respectivo registro com a lápide
	public void delete(Tuple<Short, Long> tuple) throws IOException {
		
		list.remove(tuple);
		
		file.seek(0);

		long address, fileLength = file.length();

		Tuple<Short, Long> compared = new Tuple<>((short)0, (long)-1);

		while((address = file.getFilePointer()) < fileLength) {
			byte[] array = new byte[REG_LENGTH];
			file.read(array);

			compared.fromByteArray(array);

			if (tuple.equals(compared)) {
				file.seek(address);
				file.writeShort(-tuple.getKey());
				fileLength = 0; // Encerrar o while
			}
		}
	}

	// Itera sobre a arvore e printa todas as tuplas
	public void listAll() {
		Iterator<Tuple<Short, Long>> iterator = list.iterator();
		while (iterator.hasNext()) {
			System.out.println(iterator.next());
		}
	}

	// Um método para retornar a posição do anterior ao melhor.

}

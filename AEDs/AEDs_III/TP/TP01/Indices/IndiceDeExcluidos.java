package TP01.Indices;

import java.io.IOException;
import java.io.RandomAccessFile;
// import java.util.Comparator;
// import java.util.Collections;
// import java.util.Comparator;
// import java.util.LinkedList;
// import java.util.List;
import java.util.Iterator;
import java.util.TreeSet;

import TP01.Tuple;

// Se houverem dois registros excluídos imediatamente um ao lado do outros
// Idealmente os dois deveriam ser fundidos.
// Fazer uma árvore de excluidos?

public class IndiceDeExcluidos {
	
	private RandomAccessFile file;
	// Fazer uma árvore de tuplas?
	private TreeSet<Tuple<Short, Long>> list;
	private final short REG_LENGTH = 2 + 8;

	public IndiceDeExcluidos(String filePath) throws IOException {
		list = new TreeSet<>((var1, var2) -> var1.getKey().compareTo(var2.getKey()));
		ImportData(filePath);
	}

	public void close() throws IOException {
		// SaveAllData();
		file.close();
	}

	private void ImportData(String filePath) throws IOException {
		file = new RandomAccessFile(filePath + "Excluidos.db", "rw");

		// file.seek(0);

		long fileLength = file.length();
		Tuple<Short, Long> tuple = new Tuple<Short, Long>((short)1, (long)1);

		while (file.getFilePointer() < fileLength) {
			byte[] array = new byte[REG_LENGTH];
			file.read(array);
			tuple.fromByteArray(array);
			list.add(tuple);
		}
	}

	private void SaveData(Tuple<Short, Long> tuple) throws IOException {
		file.seek(file.length());
		file.write(tuple.toByteArray());
	}

	public Tuple<Short, Long> getBest(short length) throws IOException {
		
		Tuple<Short, Long> elemento, result = null;

		Iterator<Tuple<Short, Long>> iterator = list.iterator();
		while (iterator.hasNext()) {
			elemento = iterator.next();
			// System.out.println(elemento);
			if (length <= elemento.getKey()) {
				result = elemento;
				break;
			}
		}

		if (result != null) this.delete(result);
		else result = new Tuple<>((short)0, (long)-1);

		return result;
	}

	// private void SaveAllData() throws IOException {
	// 	file.seek(0);
	// 	file.setLength(0);

	// 	Iterator<Tuple<Short, Long>> iterator = list.iterator();
	// 	while (iterator.hasNext()) {
	// 		byte[] array = iterator.next().toByteArray();
	// 		file.write(array);
	// 	}
	// }

	// private class TupleCompare implements Comparator<Tuple<Short, Long>> {
	// 	public int compare(Tuple<Short, Long> one, Tuple<Short, Long> two) {
	// 		return Short.compare(one.getKey(), two.getKey());
	// 	}
	// }

	// Ai eu teria que criar um objeto e passar esse objeto pro Collections.sort

	// Preciso criar um método de exclusão que marque os registros com lápides no arquivo
	public void create(Tuple<Short, Long> tuple) throws IOException {
		list.add(tuple);
		SaveData(tuple);
	}

	public void delete(Tuple<Short, Long> result) {
		// list.remove(result);
	}

	// Preciso cuidar do reaproveitamento dos registros excluidos
	// para simplificação e como a lista de excluídos não será longa, vou percorre-la
	// sequencialmente apenas até achar uma lapido ou chegar no fim
	// public void add(...) {}

	public void listAll() {
		Iterator<Tuple<Short, Long>> iterator = list.iterator();
		while (iterator.hasNext()) {
			System.out.println(iterator.next());
		}
	}

	// Um método para retornar a posição do anterior ao melhor.

}

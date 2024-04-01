package TP01;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Comparator;
// import java.util.Collections;
// import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

// Se houverem dois registros excluídos imediatamente um ao lado do outros
// Idealmente os dois deveriam ser fundidos.

public class IndiceDeExcluidos {
	
	private RandomAccessFile file;
	private List<Tuple<Short, Long>> list;
	private final short REG_LENGTH = 2 + 8;

	public IndiceDeExcluidos(String filePath) throws IOException {
		list = new LinkedList<>();
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

		this.sort();
	}

	private void SaveData(Tuple<Short, Long> tuple) throws IOException {
		file.seek(file.length());
		file.write(tuple.toByteArray());
	}

	public Tuple<Short, Long> getBest(short length) throws IOException {
		
		Tuple<Short, Long> result = new Tuple<>((short)0, (long)-1);

		Iterator<Tuple<Short, Long>> iterator = list.iterator();
		int index = 0;
		while (iterator.hasNext() && length <= iterator.next().getKey()) {
			result = list.get(index);
			index++;
		}

		if (index > 0) list.remove(index - 1);

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

	public void sort() {
		// Comparator<Tuple<Short, Long>> comparator = new Comparator<Tuple<Short, Long>>() {
		// 	@Override
		// 	public int compare(Tuple<Short, Long> tuple1, Tuple<Short, Long> tuple2) {
		// 		return Short.compare(tuple1.getKey(), tuple2.getKey());
		// 	}
		// };

		// new Comparator<Tuple<Short, Long>>() { ... }: This part creates an anonymous inner class
		// that implements the Comparator interface for the Tuple<Short, Long> type. It's anonymous
		// because it doesn't have a name, and it's an inner class because it's defined within another class or method.

		// { ... }: Inside the curly braces is the body of the anonymous inner class.
		// It contains the implementation of the compare method required by the Comparator interface.

		// Collections.sort(list, comparator);
		// Collections.sort(list);
	}

	public void add(Tuple<Short, Long> tuple) throws IOException {
		Iterator<Tuple<Short, Long>> iterator = list.iterator();

		short length = tuple.getKey();
		int index = 0;
		while (iterator.hasNext() && iterator.next().getKey() < length) index++;
		list.add(index, tuple);

		SaveData(tuple);
	}

	public void listAll() {
		Iterator<Tuple<Short, Long>> iterator = list.iterator();
		while (iterator.hasNext()) {
			System.out.println(iterator.next());
		}
	}

	// Um método para retornar a posição do anterior ao melhor.

}

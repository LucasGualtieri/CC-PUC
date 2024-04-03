package TP01;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import TP01.Indices.RegistroHashExtensivel;

// Quando eu for trabalhar com os Indices Indiretos precisarei, acredito eu setar uma tamanho máximo para as strings

public class Tuple<Key, Value> implements RegistroHashExtensivel {
// public class Tuple<K extends Comparable<K>, V> implements Comparable<Tuple<K, V>> {
	private Key key;
	private Value value;

	public Tuple(Key key, Value value) {
		this.key = key;
		this.value = value;
	}

	public Tuple() {}

	public Key getKey() { return key; }
	public Value getValue() { return value; }

	@SuppressWarnings("unchecked")
	public void fromByteArray(byte[] array) {
		ByteArrayInputStream ba_in;
		DataInputStream dis;

		try {
			ba_in = new ByteArrayInputStream(array);
			dis = new DataInputStream(ba_in);

			if (key instanceof Integer) {
				this.key = (Key)Integer.valueOf(dis.readInt());
			}
			if (key instanceof Short) {
				this.key = (Key)Short.valueOf(dis.readShort());
			}
			else if (key instanceof Long) {
				this.key = (Key)Long.valueOf(dis.readLong());
			}
			else if (key instanceof String) {
				this.key = (Key)String.valueOf(dis.readUTF());
			}
			
			if (value instanceof Integer) {
				this.value = (Value)Integer.valueOf(dis.readInt());
			}
			if (value instanceof Short) {
				this.value = (Value)Short.valueOf(dis.readShort());
			}
			else if (value instanceof Long) {
				this.value = (Value)Long.valueOf(dis.readLong());
			}
			else if (value instanceof String) {
				this.value = (Value)String.valueOf(dis.readUTF());
			}

			dis.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public byte[] toByteArray() throws IOException {

		ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);

		if (key instanceof Integer) {
			dos.writeInt((Integer)this.key);
		}
		if (key instanceof Short) {
			dos.writeShort((Short)this.key);
		}
		else if (key instanceof Long) {
			dos.writeLong((Long)this.key);
		}
		else if (key instanceof String) {
			dos.writeUTF((String)this.key);
		}

		if (value instanceof Integer) {
			dos.writeInt((Integer)this.value);
		}
		if (value instanceof Short) {
			dos.writeShort((Short)this.value);
		}
		else if (value instanceof Long) {
			dos.writeLong((Long)this.value);
		}
		else if (value instanceof String) {
			dos.writeUTF((String)this.value);
		}

		return ba_out.toByteArray();
	}

	public String toString() {
		String str = "(";
		str += key + ", ";
		str += value + ")";
		return str;
	}

	@Override
	public short size() {
		short size = 0;

		if (key instanceof Integer) {
			size += 4;
		}
		if (key instanceof Short) {
			size += 2;
		}
		else if (key instanceof Long) {
			size += 8;
		}
		else if (key instanceof String) {
			// size += ?;
		}
		
		if (value instanceof Integer) {
			size += 4;
		}
		if (value instanceof Short) {
			size += 2;
		}
		else if (value instanceof Long) {
			size += 8;
		}
		else if (value instanceof String) {
			// size += ?;
		}

		return size;
	}

	// @Override
	// public int compareTo(Tuple<Key, V> tuple) {
	// 	return key.compareTo(tuple.getKey());
	// }
}
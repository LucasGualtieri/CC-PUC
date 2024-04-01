package TP01;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

// public class Tuple<K, V> {
public class Tuple<K extends Comparable<K>, V> implements Comparable<Tuple<K, V>> {
	private K key;
	private V value;

	public Tuple(K key, V value) {
		this.key = key;
		this.value = value;
	}

	public Tuple() {}

	public K getKey() { return key; }
	public V getValue() { return value; }

	@SuppressWarnings("unchecked")
	public void fromByteArray(byte[] array) {
		ByteArrayInputStream ba_in;
		DataInputStream dis;

		try {
			ba_in = new ByteArrayInputStream(array);
			dis = new DataInputStream(ba_in);

			if (key instanceof Short) {
				this.key = (K)Short.valueOf(dis.readShort());
			}
			else if (key instanceof Long) {
				this.key = (K)Long.valueOf(dis.readLong());
			}
			else if (key instanceof String) {
				this.key = (K)String.valueOf(dis.readUTF());
			}
			
			if (value instanceof Short) {
				this.value = (V)Short.valueOf(dis.readShort());
			}
			else if (value instanceof Long) {
				this.value = (V)Long.valueOf(dis.readLong());
			}
			else if (value instanceof String) {
				this.value = (V)String.valueOf(dis.readUTF());
			}

			dis.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public byte[] toByteArray() throws IOException {

		ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(ba_out);

		if (key instanceof Short) {
			dos.writeShort((Short)this.key);
		}
		else if (key instanceof Long) {
			dos.writeLong((Long)this.key);
		}
		else if (key instanceof String) {
			dos.writeUTF((String)this.key);
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
    public int compareTo(Tuple<K, V> tuple) {
        return key.compareTo(tuple.getKey());
    }
}

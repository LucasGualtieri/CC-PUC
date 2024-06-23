package TP04.src.EstruturasDeDados.Tuplas;

import java.io.IOException;

import TP04.src.utils.StreamManager;
import TP04.src.Algoritmos.Criptografia.Cipher;
import TP04.src.EstruturasDeDados.RegistroHashExtensivel;

// Quando eu for trabalhar com os Indices Indiretos precisarei, acredito eu setar uma tamanho máximo para as strings

public class Tuple<Key, Value> implements RegistroHashExtensivel<Tuple<Key, Value>> {
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

	public byte[] toByteArray() throws IOException {

		StreamManager sm = new StreamManager();

		if (key instanceof Integer) {
			sm.write((Integer)this.key);
		}
		if (key instanceof Short) {
			sm.write((Short)this.key);
		}
		else if (key instanceof Long) {
			sm.write((Long)this.key);
		}
		else if (key instanceof String) {
			sm.writeUTF((String)this.key);
		}

		if (value instanceof Integer) {
			sm.write((Integer)this.value);
		}
		if (value instanceof Short) {
			sm.write((Short)this.value);
		}
		else if (value instanceof Long) {
			sm.write((Long)this.value);
		}
		else if (value instanceof String) {
			sm.writeUTF((String)this.value);
		}

		Cipher c = new Cipher();
		return c.cipher(Cipher.KEY, sm.toByteArray());
	}

	@SuppressWarnings("unchecked")
	public void fromByteArray(byte[] array) {

		Cipher c = new Cipher();
		// StreamManager sm = new StreamManager(array);
		StreamManager sm = new StreamManager(c.decipher(Cipher.KEY, array));

		try {

			if (key.getClass() == Integer.class) {
				this.key = (Key)Integer.valueOf(sm.readInt());
			}
			else if (key.getClass() == Short.class) {
				this.key = (Key)Short.valueOf(sm.readShort());
			}
			else if (key.getClass() == Long.class) {
				this.key = (Key)Long.valueOf(sm.readLong());
			}
			else if (key.getClass() == String.class) {
				this.key = (Key)String.valueOf(sm.readUTF());
			}
			
			if (value.getClass() == Integer.class) {
				this.value = (Value)Integer.valueOf(sm.readInt());
			}
			else if (value.getClass() == Short.class) {
				this.value = (Value)Short.valueOf(sm.readShort());
			}
			else if (value.getClass() == Long.class) {
				this.value = (Value)Long.valueOf(sm.readLong());
			}
			else if (value.getClass() == String.class) {
				this.value = (Value)String.valueOf(sm.readUTF());
			}

		} 

		catch (IOException e) { e.printStackTrace(); }
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

	public <K, V> boolean equals(Tuple<K, V> tuple) {
		return !(this.key != tuple.getKey() || this.value != tuple.getValue());
	}

	// @Override
	// public int compareTo(Tuple<Key, V> tuple) {
	// 	return key.compareTo(tuple.getKey());
	// }
}
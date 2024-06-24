package TP04.src.utils;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class StreamManager {
	
	ByteArrayOutputStream baos = new ByteArrayOutputStream();
	DataOutputStream dos = new DataOutputStream(baos);
	DataInputStream dis;

	public StreamManager() {}
	public StreamManager(byte[] byteArray) {
		dis = new DataInputStream(new ByteArrayInputStream(byteArray));
	}

	public void write(int val) throws IOException { dos.writeInt(val); }
	public void write(char c) throws IOException { dos.writeChar(c); }
	public void writeUTF(String str) throws IOException { dos.writeUTF(str); }
	public void write(float val) throws IOException { dos.writeFloat(val); }
	public void write(double val) throws IOException { dos.writeDouble(val); }
	public void write(byte b) throws IOException { dos.writeByte(b); }
	public void write(long val) throws IOException { dos.writeLong(val); }
	public void write(byte[] byteArray) throws IOException { dos.write(byteArray); }

	public byte[] toByteArray() { return baos.toByteArray(); }

	public long readLong() throws IOException { return dis.readLong(); }
	public int readInt() throws IOException { return dis.readInt(); }
	public float readFloat() throws IOException { return dis.readFloat(); }
	public double readDouble() throws IOException { return dis.readDouble(); }
	public char readChar() throws IOException { return dis.readChar(); }
	public byte readByte() throws IOException { return dis.readByte(); }
	public String readUTF() throws IOException { return dis.readUTF(); }
	public short readShort() throws IOException { return dis.readShort(); }
	// public byte[] readBytes() throws IOException { return dis.readAllBytes(); }
	public int read(byte[] byteArray) throws IOException { return dis.read(byteArray); }
	public byte[] read(int size) throws IOException {
		byte[] byteArray = new byte[size];
		dis.read(byteArray);
		return byteArray;
	}

}

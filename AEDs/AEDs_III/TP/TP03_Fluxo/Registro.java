package TP03;

public interface Registro {
	public int getID();
	public String toCSV();
	public String toTable();
	public void printHeader();
	public void setID(int id);
	public void printHeaderCSV();
	public void setAll(boolean update);
	public void fromByteArray(byte[] array);
	public byte[] toByteArray() throws Exception;
}
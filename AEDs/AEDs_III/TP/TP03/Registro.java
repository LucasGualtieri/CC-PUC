package TP03;

public interface Registro {
	public int getID();
	public void setID(int id);
	public byte[] toByteArray() throws Exception;
	public void fromByteArray(byte[] array);
	public void setAll(boolean update);
	public String toTable();
	public String toCSV();
	public void printHeader();
	public void printHeaderCSV();
}
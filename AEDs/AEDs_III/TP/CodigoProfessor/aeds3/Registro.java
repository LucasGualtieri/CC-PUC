package aeds3;

public interface Registro extends Cloneable, Comparable<Object> {
  public void setID(int id);

  public int getID();

  public byte[] toByteArray() throws Exception;

  public void fromByteArray(byte[] ba) throws Exception;

  public Object clone() throws CloneNotSupportedException;

  public int compareTo(Object b);
}

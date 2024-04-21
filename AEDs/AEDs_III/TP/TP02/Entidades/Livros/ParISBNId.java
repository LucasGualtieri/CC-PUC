package TP02.Entidades.Livros;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import TP02.Indices.RegistroHashExtensivel;

public class ParISBNId implements RegistroHashExtensivel<ParISBNId> {

  private String isbn;
  private int id;
  private short TAMANHO = 17;

  public ParISBNId() {
    this.isbn = "0000000000000";
    this.id = -1;
  }

  public ParISBNId(String is, int i) {
    try {
      if (is.getBytes().length != 13)
        throw new Exception("O ISBN deve ter exatamente 13 dígitos");
      this.isbn = is;
      this.id = i;
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public String getISBN() {
    return isbn;
  }

  public int getId() {
    return id;
  }

  public short size() {
    return this.TAMANHO;
  }

  public byte[] toByteArray() throws IOException {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    DataOutputStream dos = new DataOutputStream(baos);
    dos.write(this.isbn.getBytes());
    dos.writeInt(this.id);
    return baos.toByteArray();
  }

  public void fromByteArray(byte[] ba) throws IOException {
    ByteArrayInputStream bais = new ByteArrayInputStream(ba);
    DataInputStream dis = new DataInputStream(bais);
    byte[] b = new byte[13];
    dis.read(b);
    this.isbn = new String(b);
    this.id = dis.readInt();
  }

  @Override
  public int hashCode() {
    return ParISBNId.hashISBN(this.isbn);
  }

  public static int hashISBN(String isbn) {
    return Math.abs(isbn.hashCode());
  }

}

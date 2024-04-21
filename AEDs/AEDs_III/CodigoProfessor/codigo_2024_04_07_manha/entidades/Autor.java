package entidades;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;

import aeds3.Registro;

public class Autor implements Registro {

  private int ID;
  private String nome;

  public Autor() {
    this(-1, "");
  }

  public Autor(String n) {
    this(-1, n);
  }

  public Autor(int id, String n) {
    this.ID = id;
    this.nome = n;
  }

  public int getID() {
    return ID;
  }

  public void setID(int iD) {
    ID = iD;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public byte[] toByteArray() throws Exception {
    ByteArrayOutputStream ba_out = new ByteArrayOutputStream();
    DataOutputStream dos = new DataOutputStream(ba_out);
    dos.writeInt(this.ID);
    dos.writeUTF(this.nome);
    return ba_out.toByteArray();
  }

  public void fromByteArray(byte[] ba) throws Exception {
    ByteArrayInputStream ba_in = new ByteArrayInputStream(ba);
    DataInputStream dis = new DataInputStream(ba_in);
    this.ID = dis.readInt();
    this.nome = dis.readUTF();
  }

  public String toString() {
    return "ID: " + this.ID +
        "\nNome: " + this.nome;
  }

  @Override
  public Object clone() throws CloneNotSupportedException {
    return super.clone();
  }

  @Override
  public int compareTo(Object b) {
    return this.getNome().compareTo(((Autor) b).getNome());
  }
}

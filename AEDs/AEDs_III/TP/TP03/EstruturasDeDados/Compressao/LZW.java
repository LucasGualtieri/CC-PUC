package TP03.EstruturasDeDados.Compressao;


import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import TP03.EstruturasDeDados.Tuplas.Tuple;

public class LZW {

	// Tenho que fazer um menu que permite que o usuário restaure apenas um dos arquivos a partir do header.

	private final int BITS_POR_INDICE = 12;
	private RandomAccessFile file;

	// Estrutura dos registros
	// tamanho + nome + array de bytes

	private int numberOfFiles;
	private long headerAddress;

	private final int HEADER_SIZE = 4 + 8;

	private List<Tuple<String, Long>> list;

	public LZW(String filePath) throws FileNotFoundException, IOException {

		list = new LinkedList<>();

		numberOfFiles = 0;
		headerAddress = -1;

		AbrirArquivo(filePath);
	}

	// Criar um arquivo com a data (e hora?) e salvar no cabeçalho do arquivo
	// Um int com a quantidade de arquivos
	// N endereços diferentes de cada um dos arquivos compactados
	// cada arquivo tem um cabeçalho, uma strign com seu nome e um long com o tamanho (em bytes) do arquivo.

	// Como fazer para realizar esse backup, vou precisar de uma classe? Posso usar a propria do LZW

	private void AbrirArquivo(String filePath) throws FileNotFoundException, IOException {
	
		file = new RandomAccessFile(filePath + "currentDate" +".db", "rw");

		if (file.length() < HEADER_SIZE) {
			file.seek(0);
			file.writeInt(0); // Número de arquivos
			file.writeLong(-1); // Endereço do cabeçalho com os nomes e posições dos arquivos.
		}
	}

	public void add(String fileName, byte[] fileBytes) throws Exception {

		list.add(new Tuple<>(fileName, file.getFilePointer()));

		byte[] compressedFile = comprimir(fileBytes);

		file.writeLong(compressedFile.length);
		file.write(compressedFile);

		numberOfFiles++;
	}

	public Tuple<String, byte[]> next() {
		// Vai retonar uma tupla com o nome do arquivo e o arquivo descomprimido.

		// a ideia é que la no metodo do crud eu decida o que fazer, se crio / substituo um arquivo etc etc.
		return null;
	}

	public void close() throws IOException {

		headerAddress = file.length();

		file.seek(0);
		file.writeInt(numberOfFiles);
		file.writeLong(headerAddress);

		file.seek(headerAddress);

		file.writeInt(list.size());

		for (Tuple<String, Long> tuple : list) {
			file.write(tuple.toByteArray());
		}
	}

	public String toString() {

		StringBuilder sb = new StringBuilder();

		// LocalDateTime currentDateTime = LocalDateTime.now();
		// DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy - HH:mm a");
		// String formattedDateTime = currentDateTime.format(formatter);
		// System.out.println("Formatted current date and time: " + formattedDateTime);

		sb.append("O backup foi realizado no dia tal t tal");

		sb.append("O arquivo orignal possui tatatasjf alsjf asldjf çljs\n");

		return sb.toString();
	}

	public byte[] comprimir(byte[] msgBytes) throws Exception {

		ArrayList<ArrayList<Byte>> dicionario = new ArrayList<>(); // dicionario
		ArrayList<Byte> vetorBytes; // auxiliar para cada elemento do dicionario
		ArrayList<Integer> saida = new ArrayList<>();

		// inicializa o dicionário
		byte b;
		for (int j = -128; j < 128; j++) {
			b = (byte) j;
			vetorBytes = new ArrayList<>();
			vetorBytes.add(b);
			dicionario.add(vetorBytes);
		}

		int i = 0;
		int indice = -1;
		int ultimoIndice;

		while (indice == -1 && i < msgBytes.length) { // testa se o último vetor de bytes não parou no meio caminho
													  // por falta de bytes
			vetorBytes = new ArrayList<>();
			b = msgBytes[i];
			vetorBytes.add(b);
			indice = dicionario.indexOf(vetorBytes);
			ultimoIndice = indice;

			while (indice != -1 && i < msgBytes.length - 1) {
				i++;
				b = msgBytes[i];
				vetorBytes.add(b);
				ultimoIndice = indice;
				indice = dicionario.indexOf(vetorBytes);

			}

			// acrescenta o último índice à saída
			saida.add(ultimoIndice);

			// acrescenta o novo vetor de bytes ao dicionário
			if (dicionario.size() < (Math.pow(2, BITS_POR_INDICE))) {
				dicionario.add(vetorBytes);
			}

		}

		System.out.println("Indices");
		System.out.println(saida);
		System.out.println("Dicionário tem " + dicionario.size() + " elementos");

		BitSequence bs = new BitSequence(BITS_POR_INDICE);
		for (i = 0; i < saida.size(); i++) {
			bs.add(saida.get(i));
		}

		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(baos);
		dos.writeInt(bs.size());
		dos.write(bs.getBytes());

		return baos.toByteArray();
	}

	@SuppressWarnings("unchecked")
	public byte[] descomprimir(byte[] msgCodificada) throws Exception {

		ByteArrayInputStream bais = new ByteArrayInputStream(msgCodificada);
		DataInputStream dis = new DataInputStream(bais);
		int n = dis.readInt();
		byte[] bytes = new byte[msgCodificada.length - 4];
		dis.read(bytes);
		BitSequence bs = new BitSequence(BITS_POR_INDICE);
		bs.setBytes(n, bytes);

		// Recupera os números do bitset
		ArrayList<Integer> entrada = new ArrayList<>();
		int i, j;
		for (i = 0; i < bs.size(); i++) {
			j = bs.get(i);
			entrada.add(j);
		}

		// inicializa o dicionário
		ArrayList<ArrayList<Byte>> dicionario = new ArrayList<>(); // dicionario
		ArrayList<Byte> vetorBytes; // auxiliar para cada elemento do dicionario
		byte b;
		for (j = -128; j < 128; j++) {
			b = (byte) j;
			vetorBytes = new ArrayList<>();
			vetorBytes.add(b);
			dicionario.add(vetorBytes);
		}

		// Decodifica os números
		ArrayList<Byte> proximoVetorBytes;
		ArrayList<Byte> msgDecodificada = new ArrayList<>();
		i = 0;
		while (i < entrada.size()) {

			// decodifica o número
			vetorBytes = (ArrayList<Byte>) (dicionario.get(entrada.get(i)).clone());
			msgDecodificada.addAll(vetorBytes);

			// decodifica o prÃ³ximo número
			i++;
			if (i < entrada.size()) {
				proximoVetorBytes = dicionario.get(entrada.get(i));
				vetorBytes.add(proximoVetorBytes.get(0));

				// adiciona o vetor de bytes (+1 byte do prÃ³ximo vetor) ao fim do dicionário
				if (dicionario.size() < Math.pow(2, BITS_POR_INDICE))
					dicionario.add(vetorBytes);
			}

		}

		byte[] msgDecodificadaBytes = new byte[msgDecodificada.size()];
		for (i = 0; i < msgDecodificada.size(); i++)
			msgDecodificadaBytes[i] = msgDecodificada.get(i);
		return msgDecodificadaBytes;

	}
}
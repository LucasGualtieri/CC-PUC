package TP03.EstruturasDeDados.Compressao;


import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
// import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

import TP02.Lib;
import TP03.EstruturasDeDados.Tuplas.Tuple;

public class LZW {

	// Tenho que fazer um menu que permite que o usuário restaure apenas um dos arquivos a partir do header.

	private int N; // Number of files
	private int BITS_POR_INDICE;
	private RandomAccessFile file;

	// Estrutura dos registros
	// tamanho + nome + array de bytes

	private long totalBytes, totalComprimido;

	//         Name  ,       Size   , Size
	List<Tuple<String, Tuple<Integer, Integer>>> taxasDeCompressao;

	final LocalDateTime currentDateTime;
	DateTimeFormatter formatter;

	String filePath, entidade;

	public LZW(String entidade, String filePath, boolean flag) throws FileNotFoundException, IOException {

		taxasDeCompressao = new LinkedList<>();

		totalBytes = totalComprimido = 0;

		currentDateTime = LocalDateTime.now();
		formatter = DateTimeFormatter.ofPattern("_dd-MM-yy_HH:mm");

		this.filePath = filePath;
		this.entidade = entidade;

		this.N = 0;

		if (flag) AbrirArquivoComprimir();
	}

	// Criar um arquivo com a data (e hora?) e salvar no cabeçalho do arquivo
	// Um int com a quantidade de arquivos
	// N endereços diferentes de cada um dos arquivos compactados
	// cada arquivo tem um cabeçalho, uma strign com seu nome e um long com o tamanho (em bytes) do arquivo.

	// Como fazer para realizar esse backup, vou precisar de uma classe? Posso usar a propria do LZW

	private void AbrirArquivoComprimir() throws FileNotFoundException, IOException {
		// System.out.println("Formatted current date and time: " + formattedDateTime);
		file = new RandomAccessFile(filePath + entidade + currentDateTime.format(formatter) + ".db", "rw");

		file.seek(0);
		file.writeInt(0); // Número de arquivos comprimidos
	}

	private void AbrirArquivoDescomprimir(Path file) throws FileNotFoundException, IOException {
	
		// System.out.println("Formatted current date and time: " + formattedDateTime);
		// System.out.println("file.toString(): " + file.toString());

		this.file = new RandomAccessFile(file.toString(), "r");
	}

	public void add(String fileName, byte[] fileBytes) throws Exception {

		byte[] compressedFile = comprimir(fileBytes);

		Tuple<Integer, Integer> tamanhos = new Tuple<>(fileBytes.length, compressedFile.length);
		taxasDeCompressao.add(new Tuple<>(fileName, tamanhos));

		totalBytes += fileBytes.length;
		totalComprimido += compressedFile.length;

		this.N++;

		file.writeUTF(fileName);
		file.writeInt(compressedFile.length);
		file.writeByte(BITS_POR_INDICE);
		file.write(compressedFile);
	}

	public void recover(Path path) throws Exception {
		String folderName = path.getFileName().toString().substring(0, path.getFileName().toString().length() - 3);
		File folder = new File(filePath + "../Backups/" + folderName);
		folder.mkdir();

		AbrirArquivoDescomprimir(path);

		this.N = file.readInt();

		for (int i = 0 ; i < N; i++) {

			String fileName = file.readUTF();

			System.out.println("file: " + filePath + folderName + "/" + fileName);

			RandomAccessFile backup = new RandomAccessFile(filePath + folderName + "/" + fileName, "rw");

			// System.out.println("Address: " + tuple.getValue());

			int fileSize = file.readInt();
			BITS_POR_INDICE = file.readByte();

			byte[] compressedBytes = new byte[fileSize];

			file.read(compressedBytes);

			backup.write(descomprimir(compressedBytes));
			backup.close();
		}
	}

	public void close() throws IOException {
		file.seek(0);
		file.writeInt(this.N);
	}

	public String toString() {

		StringBuilder sb = new StringBuilder();

		formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm a");

		sb.append("O backup foi realizado na data: " + currentDateTime.format(formatter) + "\n\n");

		String taxaDeCompressaoTotal = String.format("%.2f%%", 100 - (totalComprimido * 100f) / totalBytes);

		sb.append(String.format("Um total de %d bytes foram comprimidos para %d bytes, resultando numa taxa compressão total de %s.\n\n", totalBytes, totalComprimido, taxaDeCompressaoTotal));

		sb.append(Lib.RED + Lib.BOLD + "Índice, ");
		sb.append(Lib.GREEN + "Arquivo, ");
		sb.append(Lib.BLUE + "Tamanho Original, ");
		sb.append(Lib.YELLOW + "Tamanho Comprimido, ");
		sb.append(Lib.CYAN + "Taxa de Compressão\n");

		int[] i = new int[1];

		taxasDeCompressao.forEach((x) -> {
			String taxaDeCompressao = String.format("%.2f%%\n", 100 - (x.getValue().getValue() * 100f) / x.getValue().getKey());

			sb.append(Lib.RED + ++i[0] + " " + Lib.GREEN + x.getKey() + ", ");
			sb.append(Lib.BLUE + x.getValue().getKey() + " bytes, ");
			sb.append(Lib.YELLOW + x.getValue().getValue() + " bytes, ");
			sb.append(Lib.CYAN + taxaDeCompressao);
		});

		sb.append(Lib.RESET);

		return sb.toString();
	}

	public static double log2(double number){
		return (Math.log(number) / (Math.log(2)));
	}

	public byte[] comprimir(byte[] msgBytes) throws Exception {

		HashMap<ArrayList<Byte>, Integer> dicionario = new HashMap<>(256); // dicionario
		ArrayList<Byte> vetorBytes;  // auxiliar para cada elemento do dicionario
		ArrayList<Integer> saida = new ArrayList<>();

		//Inicializando o dicionário
		for (int j = 0; j < 256; j++) {
			vetorBytes = new ArrayList<>();
			vetorBytes.add((byte)j);
			dicionario.put(vetorBytes, j);
		}

		int i = 0;
		int indice = 257;
		int ultimoIndice = 0;

		while (i < msgBytes.length) {

			vetorBytes = new ArrayList<>();
			vetorBytes.add(msgBytes[i++]); 
			ultimoIndice = dicionario.get(vetorBytes);

			while (i < msgBytes.length && dicionario.containsKey(vetorBytes)) {
				ultimoIndice = dicionario.get(vetorBytes);
				vetorBytes.add(msgBytes[i++]);
			}

			dicionario.put(vetorBytes, indice++);

			if(vetorBytes.size() > 1) i--;

			saida.add(ultimoIndice); //O código da instrução inicial é inserida na lista
		}

		BITS_POR_INDICE = (int) Math.ceil(log2((double) dicionario.size())); 

		BitSequence bs = new BitSequence(BITS_POR_INDICE);

		for (i = 0; i < saida.size(); i++) bs.add(saida.get(i));

		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(baos);
		dos.writeInt(bs.size());
		dos.write(bs.getBytes());

		return baos.toByteArray();
	}

	public byte[] descomprimir(byte[] msgCodificada) throws Exception {

		ByteArrayInputStream bais = new ByteArrayInputStream(msgCodificada);
		DataInputStream dis = new DataInputStream(bais);
		int n = dis.readInt();
		byte[] bytes = new byte[msgCodificada.length-4];
		dis.read(bytes);
		BitSequence bs = new BitSequence(BITS_POR_INDICE);
		System.err.println(BITS_POR_INDICE);
		bs.setBytes(n, bytes);

		// Recupera os números do bitset
		ArrayList<Integer> entrada = new ArrayList<>();
		int i, j;
		for (i = 0; i < bs.size(); i++) {
			j = bs.get(i);
			entrada.add(j);
		}

		//MODIFICADO A PARTIR DAQUI

		// inicializa o dicionário
		HashMap<Integer, ArrayList<Byte>> dicionario = new HashMap<>(256); // dicionario
		ArrayList<Byte> vetorBytes;  // auxiliar para cada elemento do dicionario
		for (j = 0; j < 256; j++) {
			vetorBytes = new ArrayList<>();
			vetorBytes.add((byte)j);
			dicionario.put(j, vetorBytes);
		}

		// Decodifica os números
		ArrayList<Byte> proximoVetorBytes;
		ArrayList<Byte> msgDecodificada = new ArrayList<>();
		i = 0;
		int indice = 257;

		while (i < entrada.size()) {
			vetorBytes = dicionario.get(entrada.get(i++));
			msgDecodificada.addAll(vetorBytes); //Adicionando o byte na 'saida'
			
			//Adiciono o vetor antigo + a 1 posição do vetor de bytes
			if (i < entrada.size()) {
				dicionario.put(indice, vetorBytes);

				proximoVetorBytes = new ArrayList<>(vetorBytes);
				byte proximoByte = dicionario.get(entrada.get(i)).get(0);
				proximoVetorBytes.add(proximoByte);
				
				dicionario.replace(indice++, proximoVetorBytes);
			}
		}

		byte[] msgDecodificadaBytes = new byte[msgDecodificada.size()];

		for (i = 0; i < msgDecodificada.size(); i++) {
			msgDecodificadaBytes[i] = msgDecodificada.get(i);
		}

		return msgDecodificadaBytes;
	}
}
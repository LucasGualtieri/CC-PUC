package AEDs.AEDs_III.Materias.Compressao;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.ArrayList;

public class LZW {

	public static final int BITS_POR_INDICE = 12;

	public static void main(String[] args) {

		try {
			String msg = "A ARANHA ARRANHA A JARRA";
			// String msg = """
			// 	Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam eget tortor eu libero molestie lobortis. Maecenas condimentum non nisl venenatis interdum. Praesent vitae aliquet velit. Integer rhoncus sem in ante mattis, nec fringilla orci viverra. Quisque a aliquet urna. Sed luctus condimentum dignissim. Duis feugiat non ante vitae viverra. Duis auctor purus augue, quis hendrerit sem imperdiet id. Sed in sem urna."
			// 	Ut vitae dui a nisl varius interdum. Praesent congue eros ut nibh finibus, non elementum massa commodo. Suspendisse sodales aliquet justo nec laoreet. Cras tempus ornare leo sit amet pharetra. In dictum condimentum ultricies. Praesent blandit vel eros non bibendum. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; In facilisis lorem feugiat turpis auctor, at euismod ipsum condimentum.
			// 	Integer a eros eros. Suspendisse eget aliquet erat, cursus blandit purus. Quisque volutpat mattis mi quis eleifend."
			// 	Proin vitae ipsum non turpis pulvinar condimentum. Sed tortor nisi, dictum id lorem condimentum, mattis aliquet neque. Duis rhoncus tempor felis, a mattis augue feugiat quis. Curabitur ultricies libero quis ex suscipit luctus. Aenean congue, magna ut consectetur ornare, massa lectus condimentum arcu, ac posuere lectus eros id enim. Maecenas eu enim varius, bibendum leo at, finibus quam. Duis eget lobortis lacus.
			// 	Curabitur quis lacus sit amet justo consequat ultrices a id erat. Quisque congue diam a erat fermentum, nec vulputate mi auctor. Etiam hendrerit massa sit amet dui tempus, non dignissim sem dignissim. Aliquam tristique enim laoreet augue bibendum mollis. Ut pulvinar lectus purus, non consequat massa fermentum at. Nulla a enim non nisi lacinia consequat ultricies vel nunc. Fusce interdum orci eget neque pellentesque lacinia.
			// 	Vestibulum id lobortis lectus. Praesent viverra eros ut finibus commodo."
			// 	In hac habitasse platea dictumst. Phasellus interdum elit ut lacinia blandit. Mauris luctus tempor ante ut ultrices. Phasellus vitae magna blandit, ultrices mauris in, ultrices eros. Aliquam erat volutpat. Etiam bibendum pretium elementum. Ut eget elit porttitor, sagittis mi a, suscipit enim. Duis in enim dolor. Nunc vel varius enim."
			// 	Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi ornare varius malesuada. Mauris eu ornare arcu. Cras ultrices efficitur urna, ac porta purus rutrum sit amet. Praesent nisi dui, placerat quis ipsum sodales, tristique gravida est. Donec ex nulla, vestibulum sed eros et, interdum vestibulum lorem. Aenean id laoreet est. Donec sed aliquam neque. Fusce posuere enim porttitor mauris facilisis finibus.
			// 	Aliquam neque ex, imperdiet et diam sit amet, aliquam posuere ante.
			// """;

			byte[] msgBytes = msg.getBytes();
			byte[] msgCodificada = codifica(msgBytes);

			// System.out.println(msg);
			System.out.println("mensagem original tem " + msgBytes.length + " bytes");
			System.out.println("codificado em " + msgCodificada.length + " bytes");

			byte[] msgDecodificada = decodifica(msgCodificada);
			System.out.println(new String(msgDecodificada));

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static byte[] codifica(byte[] msgBytes) throws Exception {

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
	public static byte[] decodifica(byte[] msgCodificada) throws Exception {

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
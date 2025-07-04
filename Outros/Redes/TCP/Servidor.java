import java.io.*;
import java.net.*;

class Servidor {

	private static int portaServidor = 6790;

	public static void main(String argv[]) throws Exception {

		//Efetua as primitivas socket e bind, respectivamente
		ServerSocket socket = new ServerSocket(portaServidor);

		while(true) {

			//Efetua as primitivas de listen e accept, respectivamente
			Socket conexao = socket.accept();

			//Efetua a primitiva receive
			System.out.println("Aguardando datagrama do cliente....");
			BufferedReader entrada =  new BufferedReader(new InputStreamReader(conexao.getInputStream()));

			//Operacao com os dados recebidos e preparacao dos a serem enviados
			String str = entrada.readLine();
			System.out.println("Received: " + str);

			str = str.toUpperCase() + '\n';

			//Efetua a primitiva send
			DataOutputStream saida = new DataOutputStream(conexao.getOutputStream());
			saida.writeBytes(str);

			conexao.close();
		}
	}
}

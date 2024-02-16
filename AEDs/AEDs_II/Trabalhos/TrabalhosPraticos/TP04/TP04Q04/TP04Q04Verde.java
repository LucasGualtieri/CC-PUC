package TP04.TP04Q04;

import java.util.*;
import java.time.Instant;
import java.time.Duration;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

// clear && javac -cp ../.. TP04Q04.java && java -cp ../.. TP04Q04.java < pub.in > result.txt

class TP04Q04Verde {

	static public boolean Pesquisar(Alvinegra arvore, String chave, Lib.Log log) throws Exception {

		if (arvore.getRaiz() == null) {
			throw new Exception("Erro ao remover na árvore: Árvore vazia.");
		}
		System.out.printf("%s raiz ", chave);
		return Pesquisar(arvore.getRaiz(), chave, log);
	}
	
	static private boolean Pesquisar(NoAN raiz, String chave, Lib.Log log) {

		boolean resultado;
		
		if (raiz == null) {
			resultado = false;
		} else if (Alvinegra.CompareTo(chave, raiz, log) < 0) {
			System.out.printf("esq ");
			resultado = Pesquisar(raiz.esq, chave, log);
		} else if (Alvinegra.CompareTo(chave, raiz, log) > 0) {
			System.out.printf("dir ");
			resultado = Pesquisar(raiz.dir, chave, log);
		} else {
			resultado = true;
		}

		return resultado;
	}

	public static void main(String[] args) throws Exception {

		Lib.BD BD = new Lib.BD("/tmp/players.csv");
		Alvinegra arvore = new Alvinegra();
		
		String inputPUBIN = new String();
		
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			int id = Integer.parseInt(inputPUBIN);
			arvore.Inserir(BD.Get(id));
		}

		Lib.Log log = new Lib.Log();
		Lib.Timer timer = new Lib.Timer();

		timer.Start();
		while (!(inputPUBIN = Lib.readStr()).equals("FIM")) {
			boolean resultado = Pesquisar(arvore, inputPUBIN, log);
			System.out.println(resultado ? "SIM" : "NAO");
		}
		timer.Stop();

		log.RegistroPesquisa("794989_alvinegra.txt", timer);
	}
}

class Lib {

	// --------------------------- FUNÇÕES AUXILIARES ---------------------------

	static Scanner scanner = new Scanner(System.in);

	public static String readStr() {
		return scanner.nextLine();
	}

	public static int readInt(boolean flush) {
		int integer = scanner.nextInt();
		if (flush) scanner.nextLine(); // Flushing
		return integer;
	}

	public static int readInt() {
		int integer = scanner.nextInt();
		scanner.nextLine();
		return integer;
	}

	// --------------------------- CLASSE TIMER ---------------------------

	public static class Timer {
	
		private Instant startTime, endTime;

		public Timer() {}
		
		public void Start() { this.startTime = Instant.now(); }

		public void Stop() {
			this.endTime = Instant.now();
		}
		
		public double Time() {
			return Duration.between(startTime, endTime).getNano() / 1000000000.0;
		}

	}

	// --------------------------- CLASSE LOG ---------------------------

	public static class Log {
		private int comparacoes, movimentacoes;

		public Log() {
			this(0, 0);
		}
		
		public Log(int comparacoes, int movimentacoes) {
			this.comparacoes = comparacoes;
			this.movimentacoes = movimentacoes;
		}

		public void RegistroPesquisa(String fileName, Lib.Timer timer) throws Exception {

			PrintWriter printWriter = new PrintWriter(new FileWriter(fileName));

			printWriter.printf("Matrícula: 794989\t");
			printWriter.printf("Tempo de execução: %fs\t", timer.Time());
			printWriter.printf("Número de comparações: %d", comparacoes);

			printWriter.close();
				
		}

		public void RegistroOrdenacao(String fileName, Lib.Timer timer) throws Exception {

			PrintWriter printWriter = new PrintWriter(new FileWriter(fileName));

			printWriter.printf("Matrícula: 794989\t");
			printWriter.printf("Tempo de execução: %fs\t", timer.Time());
			printWriter.printf("Número de comparações: %d\t", comparacoes);
			printWriter.printf("Número de movimentações: %d", movimentacoes);

			printWriter.close();
				
		}

		public void incrementarComparacoes() { this.comparacoes++; }
		public void incrementarComparacoes(int incremento) { this.comparacoes += incremento; }
		public void incrementarMovimentacoes() { this.movimentacoes++; }
		public void incrementarMovimentacoes(int incremento) {
			this.movimentacoes += incremento;
		}
	}

	// --------------------------- CLASSE BD ---------------------------

	public static class BD {
		private Jogador[] array;
		private int size;
		private static final int BD_SIZE = 3922;

		public BD(String filePath) throws Exception {
			this.size = 0;
			this.array = new Jogador[BD_SIZE];
			this.ImportDataBase(filePath);
		}

		public Jogador Get(int id) { return this.array[id]; }
		public Jogador Get(String id) {
			return this.array[Integer.parseInt(id)];
		}


		void ImportDataBase(String filePath) throws Exception {
		
			Scanner fileReader = new Scanner(new File(filePath));

			String inputCSV = new String();
			fileReader.nextLine(); // Despresando o header do .csv

			while (fileReader.hasNextLine()) {
				
				inputCSV = fileReader.nextLine();
				String[] array = inputCSV.split(",", -1);

				for (int i = 1; i < array.length; i++) {
					if (array[i].isEmpty()) {
						array[i] = "nao informado";
					}
				}

				this.InserirFim(new Jogador(array));
			}

			fileReader.close();
		}

		public void InserirFim(Jogador jogador) throws Exception {

			array[size++] = jogador.Clone();

		}
	}

	// --------------------------- CLASSE JOGADOR ---------------------------

	public static class Jogador {
		private int id, altura, peso, anoNascimento;
		private String nome, universidade, cidadeNascimento, estadoNascimento;

		public Jogador() {}

		public Jogador(String[] array) {
			this.setId(array[0]);
			this.setNome(array[1]);
			this.setAltura(array[2]);
			this.setPeso(array[3]);
			this.setUniversidade(array[4]);
			this.setAnoNascimento(array[5]);
			this.setCidadeNascimento(array[6]);
			this.setEstadoNascimento(array[7]);
		}

		// Getter e Setter - Id
		public int getId() { return this.id; }
		public void setId(String id) { this.id = Integer.parseInt(id); }
		public void setId(int id) { this.id = id; }
		
		// Getter e Setter - Nome
		public String getNome() { return this.nome; }
		public void setNome(String nome) { this.nome = nome; }

		// Getter e Setter - Altura
		public int getAltura() { return this.altura; }
		public void setAltura(int altura) { this.altura = altura; }
		public void setAltura(String altura) {
			if (altura.equals("nao informado")) {
				this.altura = -1;
				return;
			}
			this.altura = Integer.parseInt(altura);
		}

		// Getter e Setter - Peso
		public int getPeso() { return this.peso; }
		public void setPeso(int peso) { this.peso = peso; }
		public void setPeso(String peso) {
			if (peso.equals("nao informado")) {
				this.peso = -1;
				return;
			}
			this.peso = Integer.parseInt(peso);
		}

		// Getter e Setter - AnoNascimento
		public int getAnoNascimento() { return this.anoNascimento; }
		public void setAnoNascimento(int anoNascimento) { this.anoNascimento = anoNascimento; }
		public void setAnoNascimento(String anoNascimento) {
			if (anoNascimento.equals("nao informado")) {
				this.anoNascimento = -1;
				return;
			}
			this.anoNascimento = Integer.parseInt(anoNascimento);
		}

		// Getter e Setter - Universidade
		public String getUniversidade() { return this.universidade; }
		public void setUniversidade(String universidade) {
			this.universidade = universidade;
		}

		// Getter e Setter - CidadeNascimento
		public String getCidadeNascimento() { return this.cidadeNascimento; }
		public void setCidadeNascimento(String cidadeNascimento) {
			this.cidadeNascimento = cidadeNascimento;
		}

		// Getter e Setter - EstadoNascimento
		public String getEstadoNascimento() { return this.estadoNascimento; }
		public void setEstadoNascimento(String estadoNascimento) {
			this.estadoNascimento = estadoNascimento;
		}

		public Jogador Clone() {
			Jogador clone = new Jogador();

			clone.setId(this.getId());
			clone.setNome(this.getNome());
			clone.setAltura(this.getAltura());
			clone.setPeso(this.getPeso());
			clone.setUniversidade(this.getUniversidade());
			clone.setAnoNascimento(this.getAnoNascimento());
			clone.setCidadeNascimento(this.getCidadeNascimento());
			clone.setEstadoNascimento(this.getEstadoNascimento());

			return clone;

		}

		public void Mostrar() {
			// System.out.printf("[%d ## ", this.getId());
			System.out.printf("%s ## ", this.getNome());
			System.out.printf("%d ## ", this.getAltura());
			System.out.printf("%d ## ", this.getPeso());
			System.out.printf("%d ## ", this.getAnoNascimento());
			System.out.printf("%s ## ", this.getUniversidade());
			System.out.printf("%s ## ", this.getCidadeNascimento());
			System.out.printf("%s ##\n", this.getEstadoNascimento());
		}

		public void MostrarQuickSort() {
			System.out.printf("[%d ## ", this.getId());
			System.out.printf("%s ## ", this.getNome());
			System.out.printf("%d ## ", this.getAltura());
			System.out.printf("%d ## ", this.getPeso());
			System.out.printf("%d ## ", this.getAnoNascimento());
			System.out.printf("%s ## ", this.getUniversidade());
			System.out.printf("%s ## ", this.getCidadeNascimento());
			System.out.printf("%s]\n", this.getEstadoNascimento());
		}

	}

}

class NoAN {
	public boolean cor;
	public Lib.Jogador jogador;
	public NoAN esq, dir;

	public NoAN() {
		this(null);
	}

	public NoAN(Lib.Jogador jogador) {
	this(jogador, false, null, null);
	}

	public NoAN(Lib.Jogador jogador, boolean cor) {
	this(jogador, cor, null, null);
	}

	public NoAN(Lib.Jogador jogador, boolean cor, NoAN esq, NoAN dir) {
	this.cor = cor;
	this.jogador = jogador;
	this.esq = esq;
	this.dir = dir;
	}
}

class Alvinegra {

   private NoAN raiz;

    public Alvinegra() {
        raiz = null;
    }

	public NoAN getRaiz() { return this.raiz; }

	public static int CompareTo(String chave, NoAN raiz, Lib.Log log) {
		log.incrementarComparacoes();
		return chave.compareTo(raiz.jogador.getNome());
	}

    // INSERIR
    public void Inserir(Lib.Jogador jogador) throws Exception {
        
        /*
         * 1º: Se a arvore estiver vazia, crie a raiz
         * 2º: Se a arvore tiver so raiz, bota na esq ou dir
         * 3º: Se a arvore tiver um filho[dir], julga e bota de acordo
         
         //3.obs: trocaremos o valor da raiz para balancear, deixando altura 1//
         
         * 4º: Definimos a cor dos filhos para VERMELHO
         * 5º: Se a arvore tiver um filho[esq], julga e bota de acordo
         
         //5.obs: trocaremos o valor da raiz para balancear, deixando altura 1//
         
         * 6º: Definimos a cor dos filhos para VERMELHO
         * 7º: Se a arvore tiver mais que 3 nos chama um Inserir "especial"
        */

        //1º
        if(raiz==null)
        {
            raiz= new NoAN(jogador);
        }
        
        //2º
        else if (raiz.dir==null && raiz.esq==null) 
        {

            if(jogador.getNome().compareTo(raiz.jogador.getNome())<0)
            {
                raiz.esq= new NoAN(jogador);//insere esq
            }
            else
            {
                raiz.dir = new NoAN(jogador);//insere dir
            }
            
        }

        //3º
        else if(raiz.esq==null)
        {
            if(jogador.getNome().compareTo(raiz.jogador.getNome())<0)
            {
                raiz.esq= new NoAN(jogador);
            }
            else if (jogador.getNome().compareTo(raiz.dir.jogador.getNome())<0)
            {
                //3.obs
                raiz.esq = new NoAN(raiz.jogador);
                raiz.jogador = jogador;
            }
            else
            {   
                //3.obs
                raiz.esq = new NoAN(raiz.jogador);//raiz desce[nova esq]
                raiz.jogador = raiz.dir.jogador;//direita sobe[nova raiz]
                raiz.dir.jogador = jogador;//nova dir
            }
            
            //4º
            raiz.esq.cor = raiz.dir.cor =false;


        }
        
        //5º
        else if(raiz.dir==null)
        {
            if(jogador.getNome().compareTo(raiz.jogador.getNome())>0)
            {
                raiz.dir= new NoAN(jogador);
            }
            else if (jogador.getNome().compareTo(raiz.esq.jogador.getNome())>0)
            {
                //5.obs
                raiz.dir = new NoAN(raiz.jogador);
                raiz.jogador = jogador;
            }
            else
            {   
                //5.obs
                raiz.dir = new NoAN(raiz.jogador);//raiz desce[novo dir]
                raiz.jogador = raiz.esq.jogador;//esquerda sobe[nova raiz]
                raiz.esq.jogador = jogador;//nova esq
            }
            
            //6º
            raiz.esq.cor = raiz.dir.cor =false;


        }

        else//7º
        {
            Inserir(jogador,null, null, null, raiz);
        }

        raiz.cor=false;

    }

     private void balancear(NoAN bisavo, NoAN avo, NoAN pai, NoAN i) 
    {
        
        /*
         * 1º: Se o Pai for PRETO, reaqulibbramos a arvore rotacionando o Avo
         * 2º: Escolher qual rotação DIREITA fazer;
         * 3º: Escolher qual rotação ESQUERDA fazer;
        */
        //1º
        if(pai.cor==true)
        {

            //2º - ROTAÇÕES DIREITA ou ESQUERDA-DIREITA
            if(pai.jogador.getNome().compareTo(avo.jogador.getNome()) > 0){
                
                if(i.jogador.getNome().compareTo(pai.jogador.getNome()) > 0)
                {
                    avo = rotacaoESQ(avo);// simples
                }
                else
                {
                     avo = rotacaoDirESQ(avo);// dupla
                }
            }

            //3º - ROTAÇÕES ESQUERDA ou DIREITA-ESQUERDA
            else
            {
                
                if(i.jogador.getNome().compareTo(pai.jogador.getNome()) < 0)
                {
                    avo = rotacaoDIR(avo);// simples
                }
                else
                {
                      avo = rotacaoEsqDIR(avo);// dupla
                }
            }
        }

        if (bisavo == null) 
        {
            raiz = avo;
        } 
        else if (avo.jogador.getNome().compareTo(bisavo.jogador.getNome()) < 0) {
            bisavo.esq = avo;
        } 
        else 
        {
            bisavo.dir = avo;
        }
        
        avo.cor = false;
        
        if(avo.esq!=null){avo.esq.cor= true;}
        if(avo.dir!=null){avo.dir.cor= true;}
    } 
        

    
    //ROTAÇÕES
    
private NoAN rotacaoESQ(NoAN no) {
    NoAN noDir = no.dir;
    no.dir = noDir.esq;
    noDir.esq = no;
    return noDir;
}

private NoAN rotacaoDIR(NoAN no) {
    NoAN noEsq = no.esq;
    no.esq = noEsq.dir;
    noEsq.dir = no;
    return noEsq;
}

    private NoAN rotacaoDirESQ(NoAN no) {
        no.dir = rotacaoDIR(no.dir);
        return rotacaoESQ(no);
    }

    private NoAN rotacaoEsqDIR(NoAN no) {
        no.esq = rotacaoESQ(no.esq);
        return rotacaoDIR(no);
    }


    private void Inserir(Lib.Jogador jogador, NoAN bisavo, NoAN avo, NoAN pai, NoAN i) throws Exception {
        /*
         * 1º: Se o No i for nulo, insiro baseado no No PAI;
         
         //1.obs: O No criado vai ser PRETO, e depois vamos balancear//

         * 2º: Caso o No não seja nulo;
         * 3º: Se o No tiver 2 filhos PRETOS, o No fica preto e os filhos VERMELHOS;
         * 4º: Se o No for igual a raiz, o No fica VERMELHO e se não, balanceamos;
        */
        
        // 1º - CASO BASE
         if (i == null)
        {
             if(jogador.getNome().compareTo(pai.jogador.getNome())<0)
             {
                i = pai.esq= new NoAN(jogador, true);
             }
             else
             {
                i = pai.dir= new NoAN(jogador, true);
             }
             
             //1.obs
             if(pai.cor==true)
             {
                balancear(bisavo,avo,pai,i);
             }
        }
        
        //2º - CASO BASE
        else
        {   
            //3º
            if(i.esq!=null && i.dir!=null && i.esq.cor==true && i.dir.cor==true)
            {
                i.cor=true;
                i.esq.cor= i.dir.cor =false;

                //4º
                 if(i==raiz)
                {
                i.cor=false;
                }
                else if (pai.cor==true)
                {
                balancear(bisavo, avo, pai, i);
                }
            }
        
        //CHAMADAS RECURSIVAS PARA CHEGAR NO CASO BASE
        if (jogador.getNome().compareTo(i.jogador.getNome()) < 0) {// 2º
           
            Inserir(jogador,avo,pai,i ,i.esq);

        } else if (jogador.getNome().compareTo(i.jogador.getNome()) > 0) {// 3º
            
            Inserir(jogador,avo,pai,i , i.dir);

        } else {
            throw new Exception("Erro ao Inserir (jogador repetido)");
        }
    }
    }
 
    // PESQUISAR
    public void pesquisar(Lib.Jogador jogador) {
        
        System.out.print(" raiz");
        if( pesquisar(jogador, raiz)){System.out.println(" SIM");}
        else{System.out.println(" NAO");}
       
    }
    

    private boolean pesquisar(Lib.Jogador jogador, NoAN i) {
        /*
         * 1º: Verifica se a arvore não esta vazia;
         * 2º: Se o nome do jogador for o mesmo da Raiz, returna true;
         * 3º: Se o nome do jogador for menor da Raiz, vai pra esquerda da arvore;
         * 4º: Se o nome do jogador for meaior da Raiz, vai pra direita da arvore;
         * OBS: se não achar nada, returna false;
         */
        boolean resp = false;

        if (i == null) {// 1º
            resp = false;
        } else if (jogador.getNome().compareTo(i.jogador.getNome()) == 0)// 2º
        {
            resp = true;
        } else if (jogador.getNome().compareTo(i.jogador.getNome()) < 0) // 3º
        {   System.out.print(" esq");
            resp = pesquisar(jogador, i.esq);
            
        } else// 4º
        {   
            System.out.print(" dir");
            resp = pesquisar(jogador, i.dir);
        }

        return resp;
    }

    

    // MOSTRAR-CAMINHAR
    public void mostrar() {
        mostrar(raiz);
    }

    private void mostrar(NoAN i) {
        /*
         * 1º: printa o nome da celula
         * 2º: vai pra celula mais a esquerda possivel, e recursivamente printa;
         * 3º: vai pra celula mais a direita possivel, e recursivamente printa;
         */

        if (i != null) {
            System.out.println(i.jogador.getNome());// 1º
            mostrar(i.esq);// 2º
            mostrar(i.dir);// 3°
        }
    }



}

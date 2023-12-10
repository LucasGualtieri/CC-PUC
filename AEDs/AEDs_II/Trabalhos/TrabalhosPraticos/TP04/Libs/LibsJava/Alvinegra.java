package TP04.Libs.LibsJava;

import TP04.Libs.LibsJava.Lib.Jogador;
import TP04.Libs.LibsJava.Lib.Log;
import TP04.Libs.LibsJava.Celulas.NoAN;

public class Alvinegra {

   private NoAN raiz;

    public Alvinegra() {
        raiz = null;
    }

	public NoAN getRaiz() { return this.raiz; }

	public static int CompareTo(String chave, NoAN raiz, Log log) {
		log.incrementarComparacoes();
		return chave.compareTo(raiz.jogador.getNome());
	}

    // INSERIR
    public void Inserir(Jogador jogador) throws Exception {
        
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


    private void Inserir(Jogador jogador, NoAN bisavo, NoAN avo, NoAN pai, NoAN i) throws Exception {
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
    public void pesquisar(Jogador jogador) {
        
        System.out.print(" raiz");
        if( pesquisar(jogador, raiz)){System.out.println(" SIM");}
        else{System.out.println(" NAO");}
       
    }
    

    private boolean pesquisar(Jogador jogador, NoAN i) {
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

import java.util.Scanner;
class InsertionSort
{
    public static Scanner leitor = new Scanner(System.in);
    
	static class Insertion
    {
        int []array;
        int DEFAULT;
        int posicao=0;
        
        
        void AlocarArray(int ocupacoes)
        {
            array = new int[DEFAULT];
        } 
        
        
        Insertion()
        {
            DEFAULT=10;
        }
       
        Insertion(int tamanho)
        {
            DEFAULT = tamanho;
        } 
       
       
        void PreencherArray(int numero)
        {
            array[posicao]=numero;
            posicao++;
            if(posicao==DEFAULT)
            {
                ImprimirAntes();
                OrdenarVetor();
            }
        }
        int chave=0;
        int j=0;
        void OrdenarVetor()
        {
            for(int i=1;i<DEFAULT;i++)
            {
                chave = array[i];
                j=i-1;

                while(j>=0 && array[j]>chave) //se eu colocar array[j]>=chave, eu tiro a estabilidade do meu código.
                {
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1]=chave;
            }
            ImprimirOrdenado();
        }
        
        
        void ImprimirAntes()
        {
             System.out.println();
            System.out.println("Vetor antes de ordenar: ");
            for(int i=0;i<DEFAULT;i++)
            {

                System.out.printf("%3d",array[i]);
            }
        }

        void ImprimirOrdenado()
        {
            System.out.println();           
             System.out.println("Vetor depois de de ordenar: ");
            for(int i=0;i<DEFAULT;i++)
            {
            System.out.printf("%3d",array[i]);
            }
        }

    }

    public static void main(String []args) {
        Insertion objeto = new Insertion();
        int ocupacoes = 0;
        
        System.out.println("Digite quantas posicoes serao ocupadas no Vetor-Exemplo, de Insertion-Sort: ");
        ocupacoes = leitor.nextInt();
        objeto.AlocarArray(ocupacoes);
        
        int preencher = 0;
        
        for (int i = 0; i < objeto.array.length; i++) {
            System.out.println("Digite o numero da posicao " + i + " : ");
            preencher = leitor.nextInt();
            objeto.PreencherArray(preencher);
 		}
	}
}
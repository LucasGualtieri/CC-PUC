// clear && gcc gabriel.c && ./a.out < pub.in > result.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

//Struct Log para manter o log das movimentacoes e comparacoes

typedef struct Log
{
	int comp;
	int mov;
}Log;


//Struct que representa a classe Jogador

typedef struct Jogador
{
	// Atributos
	int id;
	char* nome;
	int altura;
	int peso;
	char* universidade;
	int anoNascimento;
	char* cidadeNascimento;
	char* estadoNascimento;

} Jogador;


/*Procedimento que imprime todo conteudo de uma Struct*/

void imprimir(Jogador* jogador){
    if(jogador == NULL){
        printf("Jogador inválido");
    }
    else{
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n",
		jogador->id,
		jogador->nome,
		jogador->altura,
		jogador->peso,
		jogador->anoNascimento,
		jogador->universidade,
		jogador->cidadeNascimento,   
		jogador->estadoNascimento);
    }
}

//Simulando construtores

void constructor(Jogador* jogador, int id, char* nome, int altura, int peso, char* universidade, int anoNascimento, char* cidadeNascimento, char* estadoNascimento){
    
    if(jogador != NULL){
        jogador->id = id;
        jogador->nome = nome;
        jogador->altura = altura;
        jogador->peso = peso;
        jogador->universidade = universidade;
        jogador->anoNascimento = anoNascimento;
        jogador->cidadeNascimento = cidadeNascimento;
        jogador->estadoNascimento = estadoNascimento;
    }
}

void emptyConstructor(Jogador* jogador){
    constructor(jogador,-1,"",0,0,"",0,"","");
}



/*Procedimento que extrai as colunas da linha, substituindo valores vazios por "nao informado"
 * @params: Vetor de apontadores que vai receber as Strings separadas, Apontador para cadeia de caracteres contendo a linha
 */

void tratamentoLinha(char** colunas, char* linha){
    colunas[0] = strtok(linha, ",");
    char* prevTokenEnd = colunas[0] + strlen(colunas[0]);

    for (int i = 1; i < 8; i++){
        if (*(prevTokenEnd + 1) == ',') {
            colunas[i] = "nao informado";
            prevTokenEnd++;
        } else {
            colunas[i] = strtok(NULL, ",");
            if (colunas[i]) {
                prevTokenEnd = colunas[i] + strlen(colunas[i]);
            } else {
                colunas[i] = "nao informado";
            }
        }
    }
}
/*Procedimento que instancia Struct com as informações proveninentes de uma linha (representada por um ID) do arquivo
 @params: Apontador para struct, nome do arquivo a ser lido, id do jogador a ser criado
*/

Jogador** lerParaStruct(char* nomeArquivo, int* lista_ids, int tamanho_lista){
    FILE* file = fopen(nomeArquivo,"r");
    if(file == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(0);
    }
    
    //Apotandor para vetor de strings contendo as linhas
    
    char** linhas = (char**)malloc(sizeof(char*) * 4000);

    //Alocando espaço para cada linha do vetor

    for(int i = 0; i < 4000; i++){
        linhas[i] = (char*)malloc(sizeof(char) * 256);
    }

    //Inicializando cada posicao do vetor com as linhas do arquivo

    int contador = 0;

    while(fscanf(file, " %255[^\n]", linhas[contador]) == 1){
        //printf("Linha lida: %s\n", linhas[contador]);
        contador++;
    }


    //Crinando o vetor das colunas e alocando espaço para cada linha

    char** colunas = (char**)malloc(sizeof(char*) * 8);

    for(int i = 0; i < 8; i++){
        colunas[i] = (char*)malloc(sizeof(char) * 75);
    }
    
    //Vetor para armazenar todos os jogadores

    Jogador** todos_jogadores = (Jogador**)malloc(sizeof(Jogador*) * 4000);

    //Extraindo as colunas 
    
    for(int i = 1; i < contador; i++){
        Jogador* jogador = (Jogador*)malloc(sizeof(Jogador));
        tratamentoLinha(colunas,linhas[i]);
        int id = atoi(colunas[0]);
        int altura = atoi(colunas[2]);
        int peso = atoi(colunas[3]);
        int ano = atoi(colunas[5]);         

        constructor(jogador, id, colunas[1], altura, peso, colunas[4], ano, colunas[6], colunas[7]);
    
        todos_jogadores[i-1] = jogador;
    }

    //Vetor para armazenar os ids corretos

    Jogador** jogadores_corretos = (Jogador**)malloc(sizeof(Jogador*) * tamanho_lista);

    //Criando vetor com os ids corretos

    int k = 0;

    for(int i = 0; i < contador-1; i++){
        for(int j = 0; j < tamanho_lista; j++){
            if(todos_jogadores[i]->id == lista_ids[j]){
                jogadores_corretos[k] = todos_jogadores[i];
                    //imprimir(jogadores_corretos[k]);
                k++;                                            
            }
        }
    }

    fclose(file);
   
    return jogadores_corretos;
}

void swap(Jogador* jogador1, Jogador* jogador2){
    Jogador temp = *(jogador1);
    *(jogador1) = *(jogador2); 
    *(jogador2) = temp;
}

int pesoComp(Jogador* jogador1, Jogador* jogador2, Log* log){
    log->comp += 2;
    if(jogador1->peso != jogador2->peso){
        return jogador1->peso > jogador2->peso;
    }
    else{
        return strcmp(jogador1->nome,jogador2->nome);
    }
}


void insercaoPorCor(Jogador **array, int n, int cor, int h, Log* log){
    for (int i = (h + cor); i < n; i+=h) {
        Jogador *tmp = array[i];
        int j = i - h;
		while ((j >= 0)){
			if (array[j] == NULL) {
				printf("JOGADOR NULL\n");
			} else {
				// printf("JOGADOR NOT NULL\n");
				// if (pesoComp(array[j], tmp, log) > 0) {
				// 	// array[j + h] = array[j];
				// } else {
				// 	break;
				// }
			}
			j-=h;
		}
        array[j + h] = tmp;
    } 
}

void shellsort(Jogador **array, int n, Log* log) {
    int h = 1;  

    do { h = (h * 3) + 1; } while (h < n);

    while(h >= 1){
        h /= 3;
        for(int cor = 0; cor < h; cor++){
            insercaoPorCor(array, n, cor, h, log);
        }
    }   
}

int main(){


    //SEÇÃO QUE CAPUTRA OS IDS

    Jogador* jogador = (Jogador*)malloc(sizeof(Jogador));
    int* lista_ids = (int*)malloc(sizeof(int) * 500);
    char* ids = (char*)malloc(sizeof(char) * 10); 

    scanf("%s",ids);

    int i = 0;

    while(strcmp(ids,"FIM") != 0){
        lista_ids[i] = atoi(ids);
        //  printf("%d",lista_ids[i]);
        i++;
        scanf("%s",ids);
        getchar();
    }
    

    Jogador** jogadores_para_ordenar = lerParaStruct("../tmp/players.csv",lista_ids,i);
    
    Log *log = (Log*)malloc(sizeof(Log));

    log->mov = log->comp = 0;
    
    //Varivaeis para inicio e final da excecucao
    
    // clock_t start, end;
    // double tempo;
    // start = clock();
    shellsort(jogadores_para_ordenar,i,log);
    // end = clock();
    // FILE* file = fopen("725052_shellsort.txt","w");

    // tempo = (end - start)/CLOCKS_PER_SEC;

    // fprintf(file,"725052\t");

    // fprintf(file,"%d\t",log->comp);

    // fprintf(file,"%d\t",log->mov);

    // fprintf(file,"%lf\t",tempo);

    for(int j = 0; j < i; j++){
        // imprimir(jogadores_para_ordenar[j]); 
    }
    
    return 0;
}



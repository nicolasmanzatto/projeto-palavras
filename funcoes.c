#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define MAX_TIMES 100//definido pra fica mas facil, so escrevendo MAX_TIMES
#define ARQUIVO_TIMES "times.txt"//mesma ideia acima

Time times[MAX_TIMES];//definindo o nome time pra usar , puxanndo da struct de funcoes.h
int total_times = 0;

void carregarTimes(){//ele vai ler os arquvios do time.txt, e vai armazenar os arquivos dentro da struct que esta no .h, assim vai fica armazennado os times la
    FILE *arquivo = fopen(ARQUIVO_TIMES,"r");
    if (arquivo == NULL){
        printf("\n---ERRO!!---\n");
        printf("Arquivo de times não encontrado!!");
        return;
    }//if ,//verificando se o arquivo vai abrir ou não
    total_times = 0;
    while (fscanf(arquivo, "%d%d|%49[^|]|%29[^|]|%19[^|]|%d\n",
                            &times[total_times].id,
                            times[total_times].nome,
                            times[total_times].pais,
                            times[total_times].continente,
                            &times[total_times].titulos) == 5){
        total_times++;
         if (total_times >= MAX_TIMES) break;//caso atinja o max de times, ele vai parar
    }//while
    fclose(arquivo);
    printf("Times carregados: %d\n", total_times);
}//carregarTimes

//savlando os times no times.txt
void salvarTimes(){//ele vai pegar todos times que tem na struct times dentro do arquivo .h, e escrever dentro do arquivo time.txt, salvando la
    FILE *arquivo = fopen(ARQUIVO_TIMES,"w");
    if (arquivo == NULL){
        printf("\n---ERRO!!---\n");
        printf("Erro em salvar os times!!");
        return;
    }//if, verificando se o arquivo vai abrir ou não
    
    for (size_t i = 0; i < total_times; i++){
        fprintf(arquivo,"%d|%s|%s|%s|%d\n",
                        times[i].id,
                        times[i].nome,
                        times[i].pais,
                        times[i].continente,
                        times[i].titulos);
    }//for pra pegar os dados da struct time, e colocar no arquivo times.txt
    
    fclose(arquivo);
    printf("Times salvos com sucesso!\n");
}//salvarTimes

void inserirTime(){
      if (total_times >= MAX_TIMES) {
        printf("Limite de times atingido!\n");
        return;
    }//if pra verificar se tem espaço pra por times ainda

    Time novoTime;//nova variável do tipo Time na memória(criada na struct), para receber temporariamente os dados digitados pelo usuario

    printf("\n=== CADASTRAR NOVO TIME ===\n");

    novoTime.id = total_times + 1;// total de times = 60, logo 60+1 = 61, sendo um novo id pra um novo time

    //recebendo do usuario o novo time
    printf("Nome do time: ");
    scanf(" %[^\n]", novoTime.nome);
    
    printf("País: ");
    scanf(" %[^\n]", novoTime.pais);
    
    printf("Continente: ");
    scanf(" %[^\n]", novoTime.continente);
    
    printf("Número de títulos: ");
    scanf("%d", &novoTime.titulos);

    times[total_times] = novoTime;//o time lido(novo time) e copiado pra a proxima  posição vazia do times(array principal)
    total_times++;//O número total de times é incrementado de 1. A partir deste ponto, o novo time existe na memória RAM.

    salvarTimes();
    printf("Time cadastrado com sucesso! ID: %d\n", novoTime.id);
}//inserir time, caso o usuario queira


void listarTime(){
        
    printf("\n=== LISTA DE TIMES ===\n");
    for (size_t i = 0; i < total_times; i++){
        printf("ID: %d | %s | %s | %s | %d títulos\n",
                times[i].id,
                times[i].nome,
                times[i].pais,
                times[i].continente,
                times[i].titulos);
    }//for pra exibir a lista
}//lista de times




void jogar(){//depois vou colocar esse void um arquivo .c pra pode puxar ele

    int dif = 0;

    do{
        if(dif<1 || dif>3){
            printf("\nERRO: Opção inválida!\n");
        }
        printf("\nBEM-VINDO!\n");
        printf("NÍVEIS DE DIFICULDADE:\n");
        printf("1 - Fácil\n");
        printf("2 - Médio\n");
        printf("3 - Dificil\n");
         printf("0. Sair\n");
        printf("Digite o nível de diificuldade: ");
        scanf("%i", &dif);

    }while(dif<0 || dif>3);

    switch (dif){
    case 1 :
        modoFacil();//puxaar do .h
        break;

    case 2 :
        modoMedio();//puxaar do .h
        break;

    case 3 :
        modoDificil();//puxaar do .h
        break;
        
    case 0 :
        printf("Saindo...\n");
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }//swhitch

}//Jogar


void editarTime(){

}

void pesquisarTime(){
    
}

void exclurTime(){

}

void modoFacil(){

}
void modoMedio(){

}
void modoDificil(){

}

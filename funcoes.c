
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
    int id;
    printf("Digite o ID do time a editar: ");
    scanf("%d", &id);
    int idx = -1;
    for(int i=0;i<total_times;i++){
        if(times[i].id == id){idx = i; break;}//procura o id no vetor
    }
    if(idx == -1){
        printf("Time não encontrado.\n");//caso o id não exista
        return;
    }//if  

    printf("Nome atual: %s\n", times[idx].nome);
    printf("Novo nome: ");
    scanf("%[^\n]", times[idx].nome);//muda nome

    printf("País atual: %s\n", times[idx].pais);
    printf("Novo país: ");
    scanf(" %[^\n]", times[idx].pais);//muda país

    printf("Continente atual: %s\n", times[idx].continente);
    printf("Novo continente: ");
    scanf(" %[^\n]", times[idx].continente);//muda continente

    printf("Títulos atuais: %d\n", times[idx].titulos);
    printf("Novos títulos: ");
    scanf("%d", &times[idx].titulos);//muda titulos

    salvarTimes();//salva alteraçoes no arquivo
    printf("Time editado com sucesso.\n");

}//void



void pesquisarTime(){
    
}

void exclurTime(){

}

void modoFacil(){
    
    printf("MODO FACIL\n");//modo
    printf("Times Brasileiros serie A 2025\n");//"tema"
    printf("Você terá 10 tentativas e sem cronometro!\n");//regras

    int tentativas = 10;//quantidade de tentativas
    char chute[50];//variavel para guardar o chute do jogador
    char secreta[50] = "CRUZEIRO";//variavel para guardar palavra correta(o time certo)


     while(tentativas > 0){//repete enquanto ainda tiver tentativas
        printf("Tentativas restantes: %d\n", tentativas);//mostra quantas ainda restam
        printf("Chute o time: ");
        scanf("%[\n]", chute);//le o chute do jogador

        if(strcmp(chute, secreta) == 0){//verifica se o chute é igual à palavra secreta
            printf("Você acertou!\n");//mensagem de acerto caso tenha acertado
            return;

        }else if(chute[0] > secreta[0]){//se o chute estiver acima que a da palavra certa
            printf("Dica: o time correto começa com uma letra abaixo de '%c'\n", chute[0]);//dica

        }else{
            printf("Dica: o time correto começa com uma letra acima de '%c'\n", chute[0]);//dica
        }

        tentativas--;//diminui 1 tentativa a cada erro
        
    }//while

    printf("\nVocê perdeu! O time certo era: %s\n", secreta);//mensagem caso o player perca 

}//void


void modoMedio(){

    printf("MODO MEDIO\n");//titulo do modo
    printf("Times da Premier League 2025\n");//tema do modo
    printf("Você terá 7 tentativas e 3 minutos de tempo\n");//regras do modo

    int tentativas = 7;//menos tentativas que o fácil
    char chute[50];//variavel para guardar o chute do jogador
    char secreta[50] = "CHELSEA";//variavel para guardar palavra correta(o time certo)

    while(tentativas > 0){//repete até acabar as tentativas
        printf("Tentativas restantes: %d\n", tentativas);
        printf("Chute o time: ");
        scanf(" %[^\n]", chute);//le o chute do jogador

        if(strcmp(chute, secreta) == 0){//verifica se o chute é igual à palavra secreta
            printf("Você acertou!\n");//mensagem de acerto caso tenha acertado
            return;

        }else if(chute[0] > secreta[0]){
            printf("Dica: o time correto começa com uma letra abaixo de '%c'\n", chute[0]);//dica

        }else{
            printf("Dica: o time correto começa com uma letra acima de '%c'\n", chute[0]);//dica
        }


        tentativas--;//diminui 1 tentativa a cada erro

    }//while

    printf("\nTempo esgotado ou tentativas acabaram!\n");
    printf("O time correto era: %s\n", secreta);

}//void



void modoDificil(){


    //apresentação e regras
    printf("MODO DIFICIL\n");
    printf("Times da MLS 2025\n");
    printf("Você terá 5 tentativas e 2 minutos de tempo\n");
    printf("a cada erro voce perde 1 tentativa e 10 segundos!\n");
    

    int tentativas = 5;//define as tentativas
    char chute[50];//variavel para guardar o chute do jogador
    char secreta[50] = "LA GALAXY";//palavra correta(primeiro time da lista)
    int tempo = 120;//tempo total (2 minutos em segundos)

    while(tentativas > 0 && tempo > 0){//repete até acabar as tentativas

        printf("Tentativas restantes: %d | Tempo restante: %d segundos\n", tentativas, tempo);
        printf("Chute o time ");
        scanf("%[\n]", chute);

        if(strcmp(chute, secreta) == 0){//verifica se acertou
            printf("Você acertou!\n");//mensagem de acerto caso tenha acertado

            return;


        }else if(chute[0] > secreta[0]){
            printf("Dica: o time correto começa com uma letra abaixo de '%c'\n", chute[0]);//dica

        }else{
            printf("Dica: o time correto começa com uma letra acima de '%c'\n", chute[0]);//dica

        }

        tentativas--;//diminui tentativa
        tempo -= 10;//a cada erro perde 10 segundos

    }//while

    printf("Acabaram as tentativas ou o tempo!\n");
    printf("O time certo era: %s\n", secreta);



}//void



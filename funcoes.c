
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcoes.h"

#define MAX_TENTATIVAS 10
#define MAX_TIMES 100//definido pra fica mas facil, so escrevendo MAX_TIMES
#define ARQUIVO_TIMES "times.txt"//mesma ideia acima

Time times[MAX_TIMES];//definindo o nome time pra usar , puxanndo da struct de funcoes.h
int total_times = 0;


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// Função utilitária para converter uma string para maiúsculas 
void to_upper_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

//savlando os times no times.txt
void salvarTimes(){
    FILE *arquivo = fopen(ARQUIVO_TIMES, "w"); 
    
    if (arquivo == NULL){
        printf("\n--- ERRO: Nao foi possivel abrir/criar o arquivo para salvar! ---\n");
        return;
    }
    
    // Percorre todos os times na memória e os escreve no arquivo
    for (size_t i = 0; i < total_times; i++){
        fprintf(arquivo,"%d|%s|%s|%s|%d\n",
                        times[i].id,
                        times[i].nome,
                        times[i].pais,
                        times[i].continente,
                        times[i].titulos);
    }
    
    fclose(arquivo);
    // Nota: Removi o 'printf("Times salvos com sucesso!\n")' daqui para que a mensagem de sucesso seja dada pela função que a chamou (ex: cadastrarTime).
}//salvar time

void carregarTimes(){
    FILE *arquivo = fopen(ARQUIVO_TIMES, "r"); // MODO DE LEITURA: "r"
    
    if (arquivo == NULL) {
        printf("\n--- Arquivo de times.txt nao encontrado. Criando um novo... ---\n");
        // Tenta criar o arquivo vazio se não existir
        arquivo = fopen(ARQUIVO_TIMES, "w"); 
        if (arquivo != NULL) {
            fclose(arquivo);
        } else {
             printf("ERRO FATAL: Nao foi possivel abrir ou criar o arquivo de times!\n");
        }
        total_times = 0; // Garante que a contagem seja zero.
        return; 
    }
    
    total_times = 0;
    
    // Usando ' %d' com espaço antes do %d para ignorar quebras de linha/espaços iniciais
    // E sem '\n' no final da string de formato para maior robustez de leitura.
    while (fscanf(arquivo, " %d|%49[^|]|%29[^|]|%19[^|]|%d", 
                  &times[total_times].id,
                  times[total_times].nome, 
                  times[total_times].pais, 
                  times[total_times].continente,
                  &times[total_times].titulos) == 5){
        
        total_times++;
        if (total_times >= MAX_TIMES) break;
    }
    
    fclose(arquivo);
    printf("Times carregados: %d\n", total_times);
}//carregar time

void cadastrarTime(){
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


void listarTimes(){
        
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




void jogar(){

    int dif = 0;

    do{
        if(dif < 0 || dif > 3){
            if(dif != 0) {
                printf("\nERRO: Opção inválida!\n");
            }//IF INTERNO
        }//IF EXTERNO
        printf("\nBEM-VINDO!\n");
        printf("NÍVEIS DE DIFICULDADE:\n");
        printf("1 - Fácil\n");
        printf("2 - Médio\n");
        printf("3 - Dificil\n");
         printf("0. Sair\n");
        printf("Digite o nível de diificuldade: ");
        if (scanf("%i", &dif) != 1) { // Verifica a leitura
             // Lógica para lidar com entrada inválida (se o usuário digitar texto)
             while (getchar() != '\n');
             dif = -1; 
             continue;
        }//if
        limpar_buffer();

    }while(dif<0 || dif>3);

    switch (dif){
    case 1 :
        modoFacil();
        break;

    case 2 :
        modoMedio();
        break;

    case 3 :
        modoDificil();
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



void pesquisarTimes(){
    char termo[50];
    printf("Digite parte do nome do time para pesquisar: \n");
    scanf(" %[^\n]", termo);

    printf("\nResultado da pesquisa: \n");
    int encontrou = 0;
    for (int i = 0; i < total_times; i++){
        if (strstr(times[i].nome, termo) != NULL){
            printf("ID: %d | %s | %s | %s | %d | titulos\n",
            times[i].id,
            times[i].nome,
            times[i].pais,
            times[i].continente,
            times[i].titulos);
            
            encontrou = 1;
        }//if
        
    }//for
    
    if (!encontrou){
        printf("Nenhum time encontrado.\n");
    }//if
    
}//void

void excluirTime(){
    int id;
    printf("\nDigite o ID do time para excluir: \n");
    scanf("%d", &id);

    int idx = -1;
   
    for (int i = 0; i < total_times; i++){
        if (times[i].id == id){
            idx = i;
            break;
        }//fif
    }//for
    
    if (idx == -1){
        printf("Time não encontrado.\n");
        return;
    }//if

  

    for (int i = idx; i < total_times - 1; i++){
        times[i] = times[i+1];
       
    }//for

    total_times--;
    
 
    for (int i = 0; i < total_times; i++){
        times[i].id = i + 1;
    }//for
    

    salvarTimes();
    printf("Time '%s' removido e lista reajustada com sucesso!\n", times[idx].nome); 
    

    printf("Time removido com sucesso!\n");
}//exclur times

void modoFacil() {
    if (total_times == 0) {
        printf("🚨 Erro: Nao ha times cadastrados para iniciar o jogo.\n");
        return;
    }

    // Array auxiliar para armazenar os ÍNDICES dos times brasileiros
    int indices_brasil[MAX_TIMES];
    int total_times_brasil = 0;

    // --- 1. FILTRAGEM DE TIMES ---
    for (int i = 0; i < total_times; i++) {
        // Usa strcmp para verificar se o país é "Brasil"
        if (strcmp(times[i].pais, "Brasil") == 0) {
            indices_brasil[total_times_brasil] = i;
            total_times_brasil++;
        }
    }

    if (total_times_brasil == 0) {
        printf("🚨 Erro: Nao ha times brasileiros cadastrados para o Modo Facil.\n");
        return;
    }

    // --- 2. GERAÇÃO DO TIME SECRETO (Apenas entre os brasileiros) ---
    //srand(time(NULL)); 
    // Sorteia um índice dentro da lista filtrada (de 0 até total_times_brasil - 1)
    int indice_sorteado_na_lista = rand() % total_times_brasil;
    
    // Pega o índice real do time na array global 'times'
    int indice_time_global = indices_brasil[indice_sorteado_na_lista];
    Time time_secreto = times[indice_time_global]; 
    
    // Prepara o nome secreto para comparação (MAIÚSCULAS)
    char nome_secreto_upper[50]; 
    strcpy(nome_secreto_upper, time_secreto.nome);
    to_upper_case(nome_secreto_upper); 
    
    int tentativas_restantes = MAX_TENTATIVAS;
    char palpite[50]; 
    char palpite_upper[50];

    printf("\n--- ⚽ MODO FACIL: ADIVINHE O TIME BRASILEIRO ⚽ ---\n");
    printf("O time secreto foi sorteado! Voce tem **%d tentativas**.\n", MAX_TENTATIVAS);
    
    // --- 3. LOOP DE TENTATIVAS ---
    while (tentativas_restantes > 0) {
        printf("\nTentativas restantes: **%d**\n", tentativas_restantes);
        
        // --- LÓGICA DA DICA ---
        if (tentativas_restantes == MAX_TENTATIVAS) {
             // Dica 1: País (Sempre Brasil neste modo)
             printf("💡 DICA 1: O time eh do(a) **%s**.\n", time_secreto.pais);
        } else {
             // Dica 2+: Tamanho do nome
             size_t tamanho_nome = strlen(time_secreto.nome);
             printf("💡 DICA: O nome do time tem **%zu caracteres** (contando espacos/hifens).\n", tamanho_nome);
        }

        // --- ENTRADA DO USUÁRIO ---
        printf("Seu palpite (digite o nome do time): ");
        // Continua usando scanf com espaço para leitura segura de string,
        // mas é altamente recomendado usar fgets com tratamento de \n.
        if (scanf(" %[^\n]", palpite) != 1) { 
            printf("Entrada invalida. Tentativa desperdicada.\n");
            limpar_buffer(); 
            tentativas_restantes--;
            continue;
        }
        limpar_buffer(); // Limpa o buffer após a leitura bem-sucedida

        // Copia e normaliza o palpite para MAIÚSCULAS
        strcpy(palpite_upper, palpite);
        to_upper_case(palpite_upper);

        // --- VERIFICAÇÃO ---
        if (strcmp(palpite_upper, nome_secreto_upper) == 0) {
            printf("\n🎉🎉 PARABENS! Voce adivinhou o time: **%s**! 🎉🎉\n", time_secreto.nome);
            return;
        } else {
            printf("❌ Que pena, '%s' nao eh o time secreto.\n", palpite);
            tentativas_restantes--;
        }
    }

    // --- 4. FIM DO JOGO (PERDEU) ---
    printf("\n--- 💔 FIM DE JOGO 💔 ---\n");
    printf("Suas %d tentativas acabaram.\n", MAX_TENTATIVAS);
    printf("O time secreto era: **%s**\n", time_secreto.nome);
}


void modoMedio(){
    if (total_times == 0) {
        printf("🚨 Erro: Nao ha times cadastrados para iniciar o jogo.\n");
        return;
    }

    // Array auxiliar para armazenar os ÍNDICES dos times ingleses
    int indices_inglaterra[MAX_TIMES];
    int total_times_inglaterra = 0;

    // --- 1. FILTRAGEM DE TIMES ---
    for (int i = 0; i < total_times; i++) {
        // Usa strcmp para verificar se o país é "Brasil"
        if (strcmp(times[i].pais, "Inglaterra") == 0) {
            indices_inglaterra[total_times_inglaterra] = i;
            total_times_inglaterra++;
        }
    }

    // --- 2. GERAÇÃO DO TIME SECRETO (Apenas entre os ingleses) ---
     
    // Sorteia um índice dentro da lista filtrada (de 0 até total_times_inglaterra - 1)
    int indice_sorteado_na_lista = rand() % total_times_inglaterra;
    
    // Pega o índice real do time na array global 'times'
    int indice_time_global = indices_inglaterra[indice_sorteado_na_lista];
    Time time_secreto = times[indice_time_global]; 
    
    // Prepara o nome secreto para comparação (MAIÚSCULAS)
    char nome_secreto_upper[50]; 
    strcpy(nome_secreto_upper, time_secreto.nome);
    to_upper_case(nome_secreto_upper); 
    
    int tentativas = 7;//menos tentativas que o fácil
    char palpite[50];//variavel para guardar o chute do jogador 
    char palpite_upper[50];

    printf("\n--- ⚽ MODO MEDIO: ADIVINHE O TIME DO CAMPEONATO INGLES ⚽ ---\n");
    printf("O time secreto foi sorteado! Voce tem **%d tentativas**.\n", tentativas);

    // --- 3. LOOP DE TENTATIVAS ---
    while (tentativas > 0) {
        printf("\nTentativas restantes: **%d**\n", tentativas);
        
        // --- LÓGICA DA DICA ---
        if (tentativas == 7) {
             // Dica 1: País (Sempre inglaterra neste modo)
             printf("💡 DICA 1: O time eh do(a) **%s**.\n", time_secreto.pais);
        } else {
             // Dica 2+: Tamanho do nome
             size_t tamanho_nome = strlen(time_secreto.nome);
             printf("💡 DICA: O nome do time tem **%zu caracteres** (contando espacos/hifens).\n", tamanho_nome);
        }

        // --- ENTRADA DO USUÁRIO ---
        printf("Seu palpite (digite o nome do time): ");
        // Continua usando scanf com espaço para leitura segura de string,
        // mas é altamente recomendado usar fgets com tratamento de \n.
        if (scanf(" %[^\n]", palpite) != 1) { 
            printf("Entrada invalida. Tentativa desperdicada.\n");
            limpar_buffer(); 
            tentativas--;
            continue;
        }
        limpar_buffer(); // Limpa o buffer após a leitura bem-sucedida

        // Copia e normaliza o palpite para MAIÚSCULAS
        strcpy(palpite_upper, palpite);
        to_upper_case(palpite_upper);

        // --- VERIFICAÇÃO ---
        if (strcmp(palpite_upper, nome_secreto_upper) == 0) {
            printf("\n🎉🎉 PARABENS! Voce adivinhou o time: **%s**! 🎉🎉\n", time_secreto.nome);
            return;
        } else {
            printf("❌ Que pena, '%s' nao eh o time secreto.\n", palpite);
            tentativas--;
        }
    }

        // --- 4. FIM DO JOGO (PERDEU) ---
    printf("\n--- 💔 FIM DE JOGO 💔 ---\n");
    printf("Suas %d tentativas acabaram.\n", tentativas);
    printf("O time secreto era: **%s**\n", time_secreto.nome);
}

    

void modoDificil(){
    if (total_times == 0) {
        printf("🚨 Erro: Nao ha times cadastrados para iniciar o jogo.\n");
        return;
    }

    // Array auxiliar para armazenar os ÍNDICES dos times ingleses
    int indices_eua[MAX_TIMES];
    int total_times_eua = 0;
    int tempo = 120;//tempo total (2 minutos em segundos)

    // --- 1. FILTRAGEM DE TIMES ---
    for (int i = 0; i < total_times; i++) {
        // Usa strcmp para verificar se o país é "Brasil"
        if (strcmp(times[i].pais, "EUA") == 0) {
            indices_eua[total_times_eua] = i;
            total_times_eua++;
        }
    }

    // --- 2. GERAÇÃO DO TIME SECRETO (Apenas entre dos EUA) ---
     
    // Sorteia um índice dentro da lista filtrada (de 0 até total_times_eua - 1)
    int indice_sorteado_na_lista = rand() % total_times_eua;
    
    // Pega o índice real do time na array global 'times'
    int indice_time_global = indices_eua[indice_sorteado_na_lista];
    Time time_secreto = times[indice_time_global]; 
    
    // Prepara o nome secreto para comparação (MAIÚSCULAS)
    char nome_secreto_upper[50]; 
    strcpy(nome_secreto_upper, time_secreto.nome);
    to_upper_case(nome_secreto_upper); 
    
    int tentativas = 5;//menos tentativas que o fácil
    char palpite[50];//variavel para guardar o chute do jogador 
    char palpite_upper[50];

    printf("\n--- ⚽ MODO DIIFICIL: ADIVINHE O TIME DO CAMPEONATO DOS EUA ⚽ ---\n");
    printf("Times da MLS 2025\n");
    //apresentação e regras
    printf("Você terá 5 tentativas e 2 minutos de tempo\n");
    printf("a cada erro voce perde 1 tentativa e 10 segundos!\n");
    printf("O time secreto foi sorteado! Voce tem **%d tentativas**.\n", tentativas);

    // --- 3. LOOP DE TENTATIVAS ---
    while (tentativas > 0) {
        printf("\nTentativas restantes: **%d**\n", tentativas);
        
        // --- LÓGICA DA DICA ---
        if (tentativas == 5) {
             // Dica 1: País (Sempre inglaterra neste modo)
             printf("💡 DICA 1: O time eh do(a) **%s**.\n", time_secreto.pais);
        } else {
             // Dica 2+: Tamanho do nome
             size_t tamanho_nome = strlen(time_secreto.nome);
             printf("💡 DICA: O nome do time tem **%zu caracteres** (contando espacos/hifens).\n", tamanho_nome);
        }

        // --- ENTRADA DO USUÁRIO ---
        printf("Seu palpite (digite o nome do time): ");
        // Continua usando scanf com espaço para leitura segura de string,
        // mas é altamente recomendado usar fgets com tratamento de \n.
        if (scanf(" %[^\n]", palpite) != 1) { 
            printf("Entrada invalida. Tentativa desperdicada.\n");
            limpar_buffer(); 
            tentativas--;
            continue;
        }
        limpar_buffer(); // Limpa o buffer após a leitura bem-sucedida

        // Copia e normaliza o palpite para MAIÚSCULAS
        strcpy(palpite_upper, palpite);
        to_upper_case(palpite_upper);

        // --- VERIFICAÇÃO ---
        if (strcmp(palpite_upper, nome_secreto_upper) == 0) {
            printf("\n🎉🎉 PARABENS! Voce adivinhou o time: **%s**! 🎉🎉\n", time_secreto.nome);
            return;
        } else {
            printf("❌ Que pena, '%s' nao eh o time secreto.\n", palpite);
            tentativas--;
            tempo -= 10;//a cada erro perde 10 segundos
        }
    }

        // --- 4. FIM DO JOGO (PERDEU) ---
    printf("\n--- 💔 FIM DE JOGO 💔 ---\n");
    printf("Suas %d tentativas acabaram.\n", tentativas);
    printf("O time secreto era: **%s**\n", time_secreto.nome);
    
    
}//MODO DIFICIL










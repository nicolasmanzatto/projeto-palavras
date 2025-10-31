#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int id;// id do time
    char nome[50];// nome do time
    char pais[30];// nome do pais do time
    char continente[20];//nome do continente, exem Brasil
    int titulos;//quantos titulos ganhou
} Time;//guardado os times

void cadastrarTime();
void listarTimes();
void editarTime();
void excluirTime();
void carregarTimes();
void salvarTimes();
void pesquisarTimes();

void jogar();
void modoFacil();//timesBrasileiros
void modoMedio();// Premier League
void modoDificil();// Times asiáticos


#endif  
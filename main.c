#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){
    int opc = 0;
    //carrega os times ao iniciar 
    carregarTimes();

    do{//do while caso o usuario escrever um numero menor que 1 e maior que 6
        printf("\n===== MENU ===== \n");
        printf("1. Jogar\n");
        printf("2. Cadastrar Time\n");
        printf("3. Lista dos Times\n");
        printf("4. Editar Time\n");
        printf("5. Excluir Time\n");
        printf("6. Pesquisar os Times\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção(que seja maior que 1 e menor que 6):\n");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
    }while(opc<0 || opc>6);

    switch (opc){
    case 1 :
        jogar();//puxaar do .h
        break;

    case 2 :
        cadastrarTime();//puxaar do .h
        break;

    case 3 :
        listarTimes();//puxaar do .h
        break;

    case 4 :
        editarTime();//puxaar do .h
        break;

    case 5 :
        excluirTime();//puxaar do .h
        break;

    case 6 :
        pesquisarTimes();//puxaar do .h
        break;

     case 0 :
        printf("Saindo...\n");
        break;

    default:
        printf("Opção invalida!!");
        
        break;
    }//switch

    return 0;
}//main
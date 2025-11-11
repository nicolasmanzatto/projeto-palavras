#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    int opc = -1; 

    // Carrega os times 
    carregarTimes();

  
    do { 
        printf("\n===== MENU ===== \n");
        printf("1. Jogar\n");
        printf("2. Cadastrar Time\n");
        printf("3. Lista dos Times\n");
        printf("4. Editar Time\n");
        printf("5. Excluir Time\n");
        printf("6. Pesquisar os Times\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção (0 a 6):\n");
        
      
        if (scanf("%d", &opc) != 1) { 
            while (getchar() != '\n' && getchar() != EOF); 
            opc = -1; 
            continue;
        }
        

        setbuf(stdin, NULL);

        switch (opc){
            case 1 : jogar(); break;
            case 2 : cadastrarTime(); break;
            case 3 : listarTimes(); break;
            case 4 : editarTime(); break;
            case 5 : excluirTime(); break;
            case 6 : pesquisarTimes(); break;
            case 0 : printf("Saindo...\n"); break;
            default: printf("Opção inválida! Digite um número entre 0 e 6.\n");
        }
    } while (opc != 0); // Repete enquanto a opção não for 0

    return 0;
}//main

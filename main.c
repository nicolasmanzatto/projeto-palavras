#include<stdio.h>
#include<stdlib.h>

typedef struct{//struct dos times facil
    char nome[50];
    char dica1[100];
    char dica2[100];
    char dica3[100];
}TimesFacil;

typedef struct{//struct dos time medio
    char nome[50];
    char dica1[100];
    char dica2[100];
    char dica3[100];
}TimesMedio;

typedef struct{//struct dos times dificil
    char nome[50];
    char dica1[100];
    char dica2[100];
    char dica3[100];
}TimesDificil;

void jogar(){//depois vou colocar esse void um arquivo .h pra pode puxar ele

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

    }while(dif<1 || dif>3);

    switch (dif){
    case 1 :
        timesBrasileiros();//puxaar do .h
        break;

    case 2 :
        timesPremierLeague();//puxaar do .h
        break;

    case 3 :
        timesAsiaticos();//puxaar do .h
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }//swhitch

}//Jogar

void timesBrasileiros(){//colocar em .h

}

void timesPremierLeague(){//colocar em .h

}

void timesAsiaticos(){//colocar em .h

}

int main(){
    int opc = 0;

    do{//do while caso o usuario escrever um numero menor que 1 e maior que 6
        printf("\n===== MENU ===== \n");
        printf("1 - Inserir\n");
        printf("2 - Listar\n");
        printf("3 - Pesquisar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("6 - Jogar\n");
        printf("\nEscolha uma opção(que seja maior que 1 e menor que 6):\n");
        scanf("%d", &opc);
        setbuf(stdin, NULL);
    }while(opc<1 || opc>6);

    switch (opc){
    case 1 :
        inserir();//puxaar do .h
        break;

    case 2 :
        listar();//puxaar do .h
        break;

    case 3 :
        pesquisar();//puxaar do .h
        break;

    case 4 :
        alterar();//puxaar do .h
        break;

    case 5 :
        excluir();//puxaar do .h
        break;

    case 6 :
        jogar();//puxaar do .h
        break;

    default:
        break;
    }//switch

    return 0;
}//main
# projeto-palavras
Projeto de Fundamentos de Programação 2 - UTFPR-AP



/*Palavra Secreta 

O jogo começa e da a opção de 3 temas 
pro player escolher: Marca de carro, times do brasileirão 2025 estados do brasil.
Depois que o usuario escolher o seu tema (time por exemplo), ele escolherá a dificuldade do jogo que 
será baseada em regiões. Se ele escolher o modo facil , os times serão apenas times brasileiros do brasileirao
serie A 2025 e ele terá 10 tentativas de acerto (vidas) e não terá temporizador. Se ele escolher o médio, será apenas times da 
premier league 2025, 7 tentativas e 3min de tempo . Agora, se o player escolher o dificil será da MLS e ele terá 5 tentativas e 2min de tempo, e a cada 
erro ele perderá 10sec além de uma tentativa. Depois de escolher a dificuldade o jogo vai abrir uma temática de acordo e dará a opção de usuario começar 
a chutar os times que ele acredita ser o correto. Se ele chutar "SANTOS" mas a opção correta ser "CRUZEIRO" o jogo mostrará uma pontuação positiva, imdicando 
que a opção correta começa com uma letra acima de "S". Agora se a opção correta for "VITÓRIA" ai o jogo mostrará uma pontuação negativa indicando 
que a opção correta está abaixo de "S".


*/

#include<stdio.h>
#include<stdlib.h>

typedef enum{FACIL = 1, MEDIO, DIFICIL}Dificuldade;

typedef struct{

    char nome[30];
    char pais[20];
    int ano;
    Dificuldade dificuldade;

}TIME;




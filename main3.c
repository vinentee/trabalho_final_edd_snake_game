#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

// Vari�veis 
int c[300][2], pontos=1, cx=2, cy=2;
int comida[2], velo=150;

// FUN��ES
void posicaoxy(int x, int y){ // Fun��o 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void desenhaCobra(){ // Desenha a cobrinha
    int i;
    for(i=0; i<pontos; i++){
        posicaoxy(c[i][0],c[i][1]);
        printf("%c",219);
    }
}

void geraComida(){ // Gera comida (aleat�riamente)
    posicaoxy(comida[0],comida[1]);
    printf(" ");
    srand(time(NULL));
    comida[0] = (rand() % 48) +1;
    comida[1] = (rand() % 18) +1;
    posicaoxy(comida[0],comida[1]);
    printf("o");
}

void atualizaCobra(){ // Atualiza a posi��o da cobrinha
    int i;
    posicaoxy(c[pontos][0],c[pontos][1]);
    printf(" ");
    for(i=pontos; i>=0; i--){
        c[i+1][0] = c[i][0];
        c[i+1][1] = c[i][1];
    }
}

int analizaSeBateu(){ // Analiza se a cobrinha encostou em si mesma
    int i, retorno=0;
    for(i=1; i<pontos; i++){
        if(cx==c[i][0] && cy==c[i][1]){
            retorno=1;
        }
    }
    return retorno;
}


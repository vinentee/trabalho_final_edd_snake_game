#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

// Variáveis 
int c[300][2], pontos=1, cx=2, cy=2;
int comida[2], velo=150;

// FUNÇÕES
void posicaoxy(int x, int y){ // Função 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void desenhaCobra(){ // Desenha a cobrinha
    int i;
    for(i=0; i<pontos; i++){
        posicaoxy(c[i][0],c[i][1]);
        printf("%c",219);
    }
}

void geraComida(){ // Gera comida (aleatóriamente)
    posicaoxy(comida[0],comida[1]);
    printf(" ");
    srand(time(NULL));
    comida[0] = (rand() % 48) +1;
    comida[1] = (rand() % 18) +1;
    posicaoxy(comida[0],comida[1]);
    printf("o");
}

void atualizaCobra(){ // Atualiza a posição da cobrinha
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

int main(){
    int i, gameover=0;
    int tecla;

    for(i=0; i<50; i++){ // Parede Superior
        posicaoxy(i,0);
        printf("%c",219);
        Sleep(5); // Pausa execução 
    }
    for(i=0; i<20; i++){ // Parede da direita
        posicaoxy(50,i);
        printf("%c",219);
        Sleep(5); // Pausa execução 
    }
    for(i=50; i>=0; i--){ // Parede inferior
        posicaoxy(i,20);
        printf("%c",219);
        Sleep(05); // Pausa execução
    }
    for(i=20; i>0; i--){ //Parede da esquerda
        posicaoxy(0,i);
        printf("%c",219);
        Sleep(5); // Pausa execução
    }
    geraComida(); 
    desenhaCobra(); 
    
    while(gameover==0){ // Enquanto o usuário não perder
        posicaoxy(52,2); 
        printf("Pontos: %d\t",pontos);
        posicaoxy(52,4); 
        c[0][0]=cx;
        c[0][1]=cy;
        if(kbhit()) // Serve para fazer as teclas de direcionamento funcionarem
            tecla=getch(); 

        if(tecla==72){
            cy--;
            if(cy==0) break; // Se a cobra bater na parede superior o jogo acaba
        }                    
        if(tecla==75){
            cx--;
            if(cx==0) break; // Se a cobra bater na parede da esquerda o jogo acaba
        }                    
        if(tecla==80){
            cy++;
            if(cy==20) break; // Se a cobra bater na parede inferior o jogo acaba
        }                     
        if(tecla==77){
            cx++;
            if(cx>=50) break; //Se a cobra bater na parede da direita o jogo acaba
        }
	}
}

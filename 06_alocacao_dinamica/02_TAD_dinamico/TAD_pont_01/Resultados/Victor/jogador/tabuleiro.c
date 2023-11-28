#include "tabuleiro.h"

#include <stdio.h>
#include <stdlib.h>

tTabuleiro* CriaTabuleiro() {
   // tTabuleiro* tab = (tTabuleiro*)malloc(sizeof(tTabuleiro));
    if (tab == NULL) {
        exit(1);
    }

    tab->peca1 = 'X';
    tab->peca2 = 'O';
    tab->pecaVazio = '-';
    //tab->posicoes = (int *) calloc(TAM_TABULEIRO * TAM_TABULEIRO, sizeof(int));
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }
    return tab;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro) {
    free(*(tabuleiro->posicoes));
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y) {
    if (peca == PECA_1) {
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    } else if (peca == PECA_2) {
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    } else {
        printf("[ERRO] Jogador invalido!\n");
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro) {
    int i, j;
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio)
                return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca) {
    if (peca == PECA_1)
        return tabuleiro->posicoes[y][x] == tabuleiro->peca1;
    else if (peca == PECA_2)
        return tabuleiro->posicoes[y][x] == tabuleiro->peca2;

    printf("[ERRO] Jogador Invalido!\n");
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    return  0 <= y && y < TAM_TABULEIRO &&
            0 <= x && x < TAM_TABULEIRO;
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int i, j;
    char linhaSaida[5] = "\t   ";
    for (i = 0; i < TAM_TABULEIRO; i++){
        for (j = 0; j < TAM_TABULEIRO; j++){
            linhaSaida[j+1] = tabuleiro->posicoes[i][j];
        }
        printf("%s\n", linhaSaida);
    }
}
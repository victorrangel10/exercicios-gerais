#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>

tJogo* CriaJogo() {
    tJogo* jogo = (tJogo*)calloc(1, sizeof(tJogo));
    if (jogo == NULL) {
        exit(1);
    }
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}

void ComecaJogo(tJogo* jogo) {
    int jogador1Venceu = 0, jogador2Venceu = 0;
    while (1) {
        JogaJogador((jogo->jogador1),(jogo->tabuleiro));

        ImprimeTabuleiro((jogo->tabuleiro));

        if (VenceuJogador((jogo->jogador1), (jogo->tabuleiro)) || AcabouJogo(jogo)) {
            break;
        }
        JogaJogador((jogo->jogador2), (jogo->tabuleiro));

        ImprimeTabuleiro((jogo->tabuleiro));

        if (VenceuJogador((jogo->jogador2),(jogo->tabuleiro)) || AcabouJogo(jogo)) {
            break;
        }
    }
    if (VenceuJogador((jogo->jogador1), (jogo->tabuleiro))) {
        printf("JOGADOR 1 Venceu!\n");
    } else if (VenceuJogador(jogo->jogador1, (jogo->tabuleiro))) {
        printf("JOGADOR 2 Venceu!\n");
    } else {
        printf("Sem vencedor!\n");
    }
}

int AcabouJogo(tJogo* jogo){
    return !TemPosicaoLivreTabuleiro((jogo->tabuleiro));
}

int ContinuaJogo(){
    char simounao = '\0';
    while(simounao != 's' && simounao != 'n'){
        printf("Jogar novamente? (s,n)\n");
        
        scanf("%*[^sn]");
        if ( scanf("%c", &simounao) == EOF)
          simounao = 'n';
        scanf("%*[^\n]");
        if ( scanf("%*c") == EOF)
          simounao = 'n';
    }
    if (simounao == 's')
        return 1;
    else
        return 0;
}

void DestroiJogo(tJogo* jogo){
    free(jogo->jogador1);
    free(jogo->jogador2);
    free(jogo->tabuleiro);
    free(jogo);
}
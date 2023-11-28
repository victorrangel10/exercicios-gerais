#include <stdio.h> 
#include "vetor.h"

void LeVetor(Vetor *vetor){
    int i;
    scanf("%d",&vetor->tamanhoUtilizado);
    for ( i = 0; i < vetor->tamanhoUtilizado; i++)
    {
        scanf("%d",&vetor->elementos[i]);
    }
    
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int res=vetor->elementos[0];
    for ( int i = 1; i < vetor->tamanhoUtilizado; i++)
    {
        res=op(vetor->elementos[i],res);
    }
    return res;
}
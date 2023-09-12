#include <stdio.h>
#include "eleitor.h"

tEleitor criaEleitor(int id, int votoP,int votoM){
    tEleitor elector;
    elector.id=id;
    elector.votoM=votoM;
    elector.votoP=votoP;
    return elector;
}

int jaVotou(tEleitor eleitor, int idAnterior){
    if (eleitor.id<idAnterior)
    {
        return 1;
    }
    else return 0;
}

int obtemIdEleitor(tEleitor eleitor){
    return eleitor.id;
}

int obtemVotoPresidente(tEleitor eleitor){
    return eleitor.votoP;
}

int obtemVotoPMinistro(tEleitor eleitor){
    return eleitor.votoM;
}
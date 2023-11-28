#include "pacote.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pacote {
    Type tipo;
    int numElementos;
    void* vet;
    int soma;
    size_t qtdBytes;
};

tPacote* CriaPacote(Type type, int numElem) {
    tPacote* p = calloc(1, sizeof(tPacote));

    p->tipo = type;

    p->numElementos = numElem;

    if (type == CHAR) {
        p->qtdBytes = sizeof(char);
        p->vet = calloc(p->qtdBytes, p->numElementos);
    }

    if (type == INT) {
        p->qtdBytes = sizeof(int);
        p->vet = calloc(p->qtdBytes, p->numElementos);
    }
}

void DestroiPacote(tPacote* pac) {
    free(pac->vet);
    free(pac);
}

void LePacote(tPacote* pac) {


 int * inteiro = (int*) pac->vet;

char * carac = (char*) pac->vet; 

    if (pac->tipo == INT) {
        for (size_t i = 0; i < pac->numElementos; i++) {
            scanf("%d", *(inteiro+i));
           
        }
      //  scanf("%*[^\n]");
        scanf("%*c");
    } else if (pac->tipo == CHAR) {
        for (size_t i = 0; i < pac->numElementos; i++) {
            scanf("%c", *(carac+i));
            
        }
      //  scanf("%*[^\n]");
        scanf("%*c");
    }
}

void ImprimePacote(tPacote* pac) {
    printf("%d ", pac->soma);

int * inteiro = (int*) pac->vet;

  char * carac = (char*) pac->vet; 

    for (size_t i = 0; i < pac->numElementos; i++) {
        if (pac->tipo == CHAR) {
            printf("%c ", *(carac+i));
        }

        if (pac->tipo == INT) {
            printf("%d ",*(inteiro+i) );
        }
    }
    printf("\n");
}
void CalculaSomaVerificacaoPacote(tPacote* pac) {

int * inteiro = (int*) pac->vet;

char * carac = (char*) pac->vet; 

    for (size_t i = 0; i < pac->numElementos; i++)
    {
        if (pac->tipo==INT)
        {
            pac->soma += *(inteiro+i);
        }
        if (pac->tipo==CHAR)
        {
            pac->soma += *(carac+i);
        }
        
    }
    
}
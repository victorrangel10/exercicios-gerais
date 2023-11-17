#include "tadgen.h"

#include <stdio.h>
#include <stdlib.h>

struct generic {
    void* vetor;
    Type tipo;
    int numBytes;
    int nElem;
};

tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric* gen = malloc(sizeof(tGeneric*));

    scanf("%d %d", &gen->tipo, &gen->nElem);

    if (gen->tipo = 1) {
        gen->numBytes = sizeof(int);
    } else
        gen->numBytes = sizeof(float);
    return gen;
}

void DestroiGenerico(tGeneric* gen) {
    /*for (size_t i = 0; i < gen->nElem; i++)
    {
        free(gen->vetor(vetor + i*gen->numBytes));
    }*/

    free(gen->vetor);
    free(gen);
}

void LeGenerico(tGeneric* gen) {
    gen->vetor = malloc(gen->nElem * gen->numBytes);

    if (gen->tipo) {
        for (size_t i = 0; i < gen->nElem; i++) {
            scanf("%d", &gen->vetor[i]);
        }

    } else {
        for (size_t i = 0; i < gen->nElem; i++) {
            scanf("%lf", &gen->vetor[i]);
        }
    }
}


void ImprimeGenerico(tGeneric* gen){
    if (gen->tipo) {
        for (size_t i = 0; i < gen->nElem; i++) {

            printf("%d", gen->vetor[i]);
        }

    } else {
        for (size_t i = 0; i < gen->nElem; i++) {
            printf("%.2lf", gen->vetor[i]);
        }
    }
}
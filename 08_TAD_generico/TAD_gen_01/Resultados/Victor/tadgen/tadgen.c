#include "tadgen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct generic {
    void* vetor;
    Type tipo;
    size_t numBytes;
    int nElem;
};

tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric* gen = malloc(sizeof(tGeneric*));

   gen->tipo=type;

   gen->nElem=numElem;

    if (type == INT) {
        gen->numBytes = sizeof(int);
    } else {
        gen->numBytes = sizeof(float);
    }

    gen->vetor=malloc((gen->numBytes)*gen->nElem);

    return gen;
}

void DestroiGenerico(tGeneric* gen) {
    free(gen->vetor);
    free(gen);
}

void LeGenerico(tGeneric* gen) {
    printf("\nDigite o vetor:\n");

    for (size_t i = 0; i < gen->nElem; i++) {
        if (gen->tipo == FLOAT)
            scanf("%f", (((float*)gen->vetor) + i));

        else if (gen->tipo == INT)
            scanf("%d", (((int*)gen->vetor) + i));
    }
}

void ImprimeGenerico(tGeneric* gen) {
    if (gen->tipo) {
        for (size_t i = 0; i < gen->nElem; i++) {
        printf("%d", (gen->vetor + i));
        }

    } else {
        for (size_t i = 0; i < gen->nElem; i++) {
        printf("%.2f ", (gen->vetor + i));
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

#include "tarefamultiplica.h"

struct mult {
    float n1;
    float n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2) {
    tMult* m = calloc(1, sizeof(tMult));
    if (m == NULL) {
        exit(1);
    }
    m->n1 = n1;
    m->n2 = n2;
    return m;
}

void ExecutaTarefaMultiplicar(void* mult) {
    tMult* a = (tMult*)mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", a->n1, a->n2, a->n1 * a->n2);
}

void DestroiTarefaMultiplicar(void* mult) {
    if (mult) {
        free(mult);
    }
}
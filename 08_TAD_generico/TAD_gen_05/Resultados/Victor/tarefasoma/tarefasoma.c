#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>


struct  soma
{
    float n1;
    float n2;
};

tSoma* CriaTarefaSoma(float n1, float n2){

    tSoma * m = malloc ( sizeof(tSoma));

    m->n1=n1;
    m->n2=n2;
    return m;

}


void ExecutaTarefaSoma(void *sum){
    tSoma* s = (tSoma* )sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f",s->n1,s->n2,s->n1+s->n2);


}

void DestroiTarefaSoma(void *sum){
if (sum)
{
    free(sum);
}

}
#include <stdio.h>
#include "utils.h"

int TrocaInterios(int * n1, int * n2){

    if (*n1<=*n2)
    {
       return 0;
    }

    int aux;
    aux=*n1;
    *n1=*n2;
    *n2=aux;

    return 1;
}
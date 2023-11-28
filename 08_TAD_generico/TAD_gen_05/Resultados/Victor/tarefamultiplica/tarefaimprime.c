#include "tarefaimprime.h"

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct impr
{
   char * msg;
};

tImpr* CriaTarefaImprimir(char *msg){
    tImpr * a = malloc (sizeof(tImpr));

    a->msg=malloc((strlen(msg)+1)*sizeof(char));

    strcpy(a->msg,msg);

    return a;
}

void ExecutaTarefaImprimir(void *imp){

    tImpr* a = (tImpr*)imp;
    printf("\n%s",a->msg);

}

void DestroiTarefaImprimir(void *imp){
      tImpr* a = (tImpr*)imp;
    if (a)
    {
        free(a->msg);
        free(a);
    }
    
}
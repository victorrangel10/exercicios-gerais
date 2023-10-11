#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void OrdenaAprovados(tAluno ** aprovados,int tam){

for (int i = 0; i < tam; i++)
{
   for (int j= i+1; j < tam-1; i++)
   {
        if (ComparaMatricula(aprovados[j],aprovados[i]))
        {
            tAluno* aux=aprovados[j];
            aprovados[j]=aprovados[i];
            aprovados[i] = aux;
        }
  
   }
   for ( i = 0; i < tam; i++)
   {
    ImprimeAluno(aprovados[i]);
   }
   
   
}

}

int main(){
    int nAlunos;
    scanf("%d\n",&nAlunos);
    tAluno** listaAlunos=malloc(nAlunos*sizeof(tAluno *));
    tAluno** aprovados=NULL;
    int tam=0;

    for (int i = 0; i < nAlunos; i++)
    {
        listaAlunos[i]=CriaAluno();
        LeAluno(listaAlunos[i]);
      //     printf("li aluno %s\n",listaAlunos[i]->nome);

        if (VerificaAprovacao(listaAlunos[i]))
        {
            tam++;
            aprovados=realloc(aprovados,tam);
            aprovados[tam-1]=listaAlunos[i];
           
        }
         OrdenaAprovados(aprovados,tam);
    }

    for (int i = 0; i < nAlunos; i++)
    {
        ApagaAluno(listaAlunos[i]);
    }
    free(listaAlunos);
    free(aprovados);

    return 0;
}
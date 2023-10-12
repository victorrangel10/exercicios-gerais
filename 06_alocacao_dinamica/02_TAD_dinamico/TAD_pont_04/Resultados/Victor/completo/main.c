#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void OrdenaAlunos(tAluno** lista,int tam){
    for (int i = 0; i < tam; i++)
    {
        //printf("loop %d\n",i);
        for (int j = i+1; j < tam-1; j++)
        {

        if (ComparaMatricula(lista[i],lista[j])==-1)
        {
            tAluno * aux = lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
            //printf("troquei %d por %d\n",lista[i]->matricula,lista[j]->matricula);
        }
        
        }
        
    }
    
}

int main(){
    int nAlunos;
    scanf("%d\n",&nAlunos);
    tAluno** listaAlunos=malloc(nAlunos*sizeof(tAluno *));
   

    for (int i = 0; i < nAlunos; i++)
    {
        *(listaAlunos+i)=CriaAluno();
        LeAluno(listaAlunos[i]);
    }
    for (int i = 0; i < nAlunos; i++)
    {
       // printf("%s\n",listaAlunos[i]->nome);
       // printf("li assim\n");
    }
    
    OrdenaAlunos(listaAlunos,nAlunos);

    for (int i = nAlunos-1; i >=0; i--)
    {
    
        if (VerificaAprovacao(listaAlunos[i]))
        {
            ImprimeAluno(listaAlunos[i]);
           
        }
        ApagaAluno(listaAlunos[i]);
    }


    
    free(listaAlunos);

    return 0;
}
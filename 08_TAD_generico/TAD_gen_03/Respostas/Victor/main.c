#include "relatorio.h"
#include "aluno.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int nalunos;
    scanf("%d\n",&nalunos);
    Vector * alunos =VectorConstruct();
    
    for (size_t i = 0; i < nalunos; i++)
    {
        tAluno* a =CriaAluno();
        LeAluno(a);
        VectorPushBack(alunos,a);

    }

    ImprimeRelatorio(alunos);

    VectorDestroy(alunos,DestroiAluno);
    
    
    
}

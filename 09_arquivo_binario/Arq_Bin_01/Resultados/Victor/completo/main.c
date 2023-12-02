#include <stdio.h> 
#include <stdlib.h>
#include "aluno.h"


int main(){
    int num;
    printf("Digite o numero de alunos: ");
    scanf("%d",&num);
    Aluno**alunos= CriaVetorAlunos(num);
    LeAlunos(alunos,num);
    SalvaAlunosBinario(alunos,"alunos.bin",num);
    ImprimeAlunos(alunos,num);
    LiberaAlunos(alunos,num);
    return;
}
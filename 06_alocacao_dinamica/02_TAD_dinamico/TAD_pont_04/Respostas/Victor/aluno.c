#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>


char* LeString(){
    int carac;
    int tamanho=0;
    char* nome=NULL;
    scanf("%*[^a-zA-Z]");
while ((carac=getchar())!='\n')
{
    tamanho++;
    nome=realloc(nome,tamanho);
    nome[tamanho-1]=carac;
   // printf("puxei %c\n",carac);
}
    tamanho++;
    nome=realloc(nome,tamanho);
    nome[tamanho-1]='\0';
    //printf("puxei %c\n",carac);
    return nome;
}

tAluno* CriaAluno(){
    tAluno* s= calloc(1,sizeof(tAluno));
    s->nome=NULL;
    s->matricula=-1;
    s->n1=-1;
    s->n2=-1;
    s->n3=-1;
    return s;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    aluno->nome=LeString();
    scanf("%d",&aluno->matricula);
   // printf("li %d\n",aluno->matricula);
    scanf("%d",&aluno->n1);
   // printf("li %d\n",aluno->n1);
     scanf("%d",&aluno->n2);

     // printf("li %d\n",aluno->n2);
      scanf("%d",&aluno->n3);
       //printf("li %d\n",aluno->n3);

    //printf("%s,%d, %d, %d ,%d \n",aluno->nome,aluno->matricula,aluno->n1,aluno->n2,aluno->n3);
}


int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if (aluno1->matricula>aluno2->matricula)
    {
        return 1;
    }else if (aluno1->matricula<aluno2->matricula)
    {
    return -1;
    }else return 0;
}
    

int CalculaMediaAluno(tAluno* aluno){
    int media= (aluno->n1+aluno->n2+aluno->n3)/3;
   // printf("media deu %d\n",media);
    return media;
}

int VerificaAprovacao(tAluno* aluno){
    if (CalculaMediaAluno(aluno)>=7)
    {
        return 1;
    }return 0;
    
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n",aluno->nome);
}
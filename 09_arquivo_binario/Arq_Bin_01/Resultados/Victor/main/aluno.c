#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct aluno {
    char nome[100];
    char dataNasc[20];
    char curso[100];
    char periodo[14];
    int porcetagem_conclusao;
    float CR;
};

Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char *periodoIngresso, int percConclusao, float CRA) {
    Aluno *a = calloc(1, sizeof(Aluno));

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodo, periodoIngresso);
    a->porcetagem_conclusao = percConclusao;
    a->CR = CRA;

    return a;
}

Aluno **CriaVetorAlunos(int numeroAlunos) {
    Aluno **alunos = calloc(numeroAlunos, sizeof(Aluno *));
    return alunos;
}

void LeAlunos(Aluno **vetorAlunos, int numeroAlunos) {
    for (size_t i = 0; i < numeroAlunos; i++) {
        char nome[100];
        char data[15];
        char curso[100];
        char periodo[10];
        int conc;
        float cr;

        scanf("%[^\n]%*c", &nome);
        scanf("%[^\n]%*c", &data);
        scanf("%[^\n]%*c", &curso);
        scanf("%[^\n]%*c", periodo);
        scanf("%d", &conc);
        scanf("%f", &cr);
        
        Aluno *a = CriaAluno(nome, data, curso, periodo, conc, cr);
        a->nome[0]='P';
        printf("indo");
        vetorAlunos[i] = a;
    }
}

void LiberaAlunos(Aluno **alunos, int numeroAlunos) {
    for (size_t i = 0; i < numeroAlunos; i++) {
        if (alunos[i]) free(alunos[i]);
    }
    if (alunos) free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    FILE *arq = fopen(fileName, "wb");
    int total=0;
    total+=fwrite(&numeroAlunos, sizeof(int), 1, arq);

    for (size_t i = 0; i < numeroAlunos; i++) {
        fwrite(alunos[i], sizeof(Aluno), 1, arq);
        if (alunos[i]->curso) {
            total+=fwrite(alunos[i]->curso, sizeof(char), strlen(alunos[i]->curso) + 1, arq);
            total+=fwrite(alunos[i]->nome, sizeof(char), strlen(alunos[i]->nome) + 1, arq);
            total+=fwrite(alunos[i]->dataNasc, sizeof(char), strlen(alunos[i]->dataNasc) + 1, arq);
            total+=fwrite(alunos[i]->periodo, sizeof(char), strlen(alunos[i]->periodo) + 1, arq);
        }
    }
    fclose(arq);
    printf("Numero de bytes salvos:%d\n",total);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE *arq = fopen(fileName, "rb");

    int num;
    fread(&num, sizeof(int), 1, arq);

    alunos = realloc(alunos, num * sizeof(Aluno *));

    for (size_t i = 0; i < num; i++) {
        fread(alunos[i], sizeof(Aluno), 1, arq);
    }
}
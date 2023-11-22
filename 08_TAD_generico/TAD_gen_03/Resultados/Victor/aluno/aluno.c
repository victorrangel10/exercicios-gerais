#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char *nome;
    float nota;
    char sexo
};

tAluno *CriaAluno() {
    tAluno *a = calloc(1, sizeof(tAluno));
    if (a == NULL) exit(1);
    a->nome = NULL;

    return a;
}

void DestroiAluno(data_type aluno) {
    tAluno *a = (tAluno *)aluno;

    free(a->nome);
    free(a);
}

void LeAluno(tAluno *aluno) {
    char nome[100];

    scanf("%[^;];%c;%f", &nome, &aluno->sexo, &aluno->nota);

    aluno->nome = malloc((strlen(nome) + 1) * sizeof(char));

    strcpy(aluno->nome, nome);
}


char GetGeneroAluno(tAluno *aluno) { return aluno->sexo; }

float GetNotaAluno(tAluno *aluno) { return aluno->nota; }
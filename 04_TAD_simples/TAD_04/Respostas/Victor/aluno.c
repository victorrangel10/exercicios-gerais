#include "aluno.h"
#include <string.h>
#include <stdio.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3) {
  tAluno al;
  al.matricula = matricula;
  al.n1 = n1;
  al.n2 = n2;
  al.n3 = n3;
  strcpy(al.nome,nome);
  return al;
}

tAluno LeAluno() {
  tAluno al;
  scanf("%s", &al.nome);
  scanf("%d", &al.matricula);
  scanf("%d %d %d", &al.n1, &al.n2, &al.n3);
  return al;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
  if (aluno1.matricula == aluno2.matricula) {
    return 0;
  }
  if (aluno1.matricula > aluno2.matricula) {
    return 1;
  } else
    return -1;
}

int CalculaMediaAluno(tAluno aluno) {
  return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int VerificaAprovacao(tAluno aluno) {
  if (CalculaMediaAluno(aluno) >= 7) {
    return 1;
  } else
    return 0;
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n",aluno.nome);
}
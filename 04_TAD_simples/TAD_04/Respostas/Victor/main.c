#include <stdio.h>

#include "aluno.h"

void Order(tAluno alunos[], int num) {
  for (int i = 0; i < num; i++) {
    for (int j = i +1 ; j < num; j++) {
      if (ComparaMatricula(alunos[i], alunos[j]) == 1) {
        tAluno aux = alunos[i];

        alunos[i] = alunos[j];

        alunos[j] = aux;
      }
    }
  }
}

void PrintAproved(tAluno alunos[], int num) {
  for (int i = 0; i < num; i++) {
    if (VerificaAprovacao(alunos[i])) {
      ImprimeAluno(alunos[i]);
    }
  }
}

int main() {
  int num;
  scanf("%d", &num);
  tAluno alunos[num];

  for (int i = 0; i < num; i++) {
    alunos[i] = LeAluno();
  }

  Order(alunos, num);

  PrintAproved(alunos, num);

  return 0;
}
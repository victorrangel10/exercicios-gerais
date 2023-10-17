#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int *CriaVetor(int tamanho) {
  int *vet = calloc(tamanho, sizeof(int));

  if (vet == NULL) {
    printf("erro\n");
    exit(1);
  }
  return vet;
}

void LeVetor(int *vetor, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &vetor[i]);
  }
}

float CalculaMedia(int *vetor, int tamanho) {
  int soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma = vetor[i] + soma;
  }

  float media = (float)soma / tamanho;

  return media;
}


void LiberaVetor(int * vetor){
    free(vetor);
}
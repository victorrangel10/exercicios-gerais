#include "vetor.h"

#include <stdio.h>

void LeDadosParaVetor(int *vet, int tam) {
  int value;
  for (int i = 0; i < tam; i++) {
    scanf("%d", &value);
    vet[i] = value;
  }
}

void ImprimeDadosDoVetor(int *n, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", n[i]);
  }
  printf("\n");
}

void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar) {
    
  for (int j = 0; j < tam; j++) {

    if (vet[j] > vet[*paraTrocar]) {
     
      int aux = vet[j];

      vet[j] = vet[*paraTrocar];

      vet[*paraTrocar] = aux;   

    }

  }

}

void OrdeneCrescente(int *vet, int tam) {
  int i = 0;
  int *lowest = &i;

  for ( i = 0; i < tam; i++)
  {
    TrocaSeAcharMenor(vet, tam, lowest);
  }
  
}
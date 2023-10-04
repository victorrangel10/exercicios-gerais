#include <stdio.h>

#include "calculadora.h"

float soma(float n1, float n2) { return n1 + n2; }

float sub(float n1, float n2){ return n1-n2;}

float mult(float n1,float n2){ return n1*n2;}

float div(float n1,float n2){return n1/n2;}

int main() {
  char op;
  float n1, n2;
  do {
    scanf("%c", &op);

    scanf("%f %f", &n1, &n2);

    float resultado = Calcular(n1, n2, );

  } while (!EOF);
}

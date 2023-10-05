#include <stdio.h>

#include "calculadora.h"

float soma(float n1, float n2) { return n1 + n2; }

float sub(float n1, float n2){ return n1-n2;}

float mult(float n1,float n2){ return n1*n2;}

float div(float n1,float n2){return n1/n2;}

int main() {
  char op;
  float n1, n2,res;
  do {
    scanf("%c", &op);

    scanf("%f %f", &n1, &n2);

    switch (op)
    {
    case 'a':
      res=Calcular(n1,n2,soma);
      printf("%.2f + %.2f = %.2f\n",n1,n2,res);
      break;
    
    case 's':
      res=Calcular(n1,n2,sub);
      printf("%.2f - %.2f = %.2f\n",n1,n2,res);
      break;

    case 'm':
      res=Calcular(n1,n2,mult);
      printf("%.2f x %.2f = %.2f\n",n1,n2,res);
      break;

      case 'd':
      res=Calcular(n1,n2,div);
      printf("%.2f / %.2f = %.2f\n",n1,n2,res);
      break;

      case 'f':
      return 0;
    default:
      break;
    }

  } while (1);
}

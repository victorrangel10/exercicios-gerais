#include <stdio.h>
#include "vetor.h"

int soma(int n1,int bank){
   return n1+bank;
}
int mult(int n, int bank){
    if (bank==0)
    {
        bank=1;
        return bank*n;
    }
    return bank*n;
    
}


int main(){
    Vetor vet;
    LeVetor(&vet);
    printf("Soma: %d\n",AplicarOperacaoVetor(&vet,soma));
    printf("Produto: %d\n",AplicarOperacaoVetor(&vet,mult));
    return 0;
}
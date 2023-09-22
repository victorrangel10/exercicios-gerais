#include <stdio.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam){
    int value;
    for (int i = 0; i < tam; i++)
    {
        scanf("%d",&value);
        vet[i]=value;
    }
    
}

void ImprimeDadosDoVetor(int * n, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%d ",n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int lowest=vet[0];
    for (int i = 0; i < tam; i++)
    {
        if (vet[i]<lowest)
        {
            *paraTrocar=vet[i];
            lowest=vet[i];
        }
        
    }
    
}

void OrdeneCrescente(int * vet, int tam){
    for (int i = 0; i < tam; i++)
    {
        for ( int j = i+1; j < tam; j++)
        {
            if (vet[j]<vet[i])
            {
                int aux=vet[j];
                vet[j]=vet[i];
                vet[i]=vet[j];
            }
            
        }
        
    }
    
}
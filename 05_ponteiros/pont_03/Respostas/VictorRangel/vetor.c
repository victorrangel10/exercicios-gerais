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
        for (int j = 0; i < tam; j++)
        {
            if (vet[j]<vet[i])
            {
                int aux= vet[i];
                vet[i]=vet[j];
                vet[j]=vet[i];
            }
            
        }
        
        
    }
    
}

void OrdeneCrescente(int * vet, int tam){
    for (int i = 0; i < tam; i++)
    {
            TrocaSeAcharMenor(vet,tam,vet[i]);
    }
    
}
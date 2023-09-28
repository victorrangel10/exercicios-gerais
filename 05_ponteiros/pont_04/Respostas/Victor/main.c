#include <stdio.h> 
#include "utils.h"

void LeNumeros(int *array, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d",&array[i]);
    }
    
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int low=array[0];
    int big=array[0];
    int soma;
    int idxLow;
    int idxBig;
    
    for ( int i = 0; i < tamanho; i++)
    {
        soma+= array[i];

        if (array[i]<low)
        {
            low=array[i];
        }

        if (array[i]>big)
        {
            big=array[i];  
        }
        
    }
    int avg=soma/tamanho;
    media=&avg;
    menor=&low;
    maior=&big;
}
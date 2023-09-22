#include <stdio.h>

#include "utils.h"

 void LeIntervalo(int * m, int * n){
    int a,b;
    scanf("%d %d",&a,&b);
    *m=a;
    *n=b;
} 

 int EhPrimo(int n){

    int i;
    int divisors = 1;

    for ( i = 2; i <= n; i++)
    {
       
       if (n%i==0)
       {
        divisors++;
       }
       
       
    }

    if (divisors ==2)
    {
        return 1;
    }
    if (n==1 || n==2 )
    {
        return 1;
    }
    
    return 0;
    
}



void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int biggest=-1;
    int lowest=100000;
    //printf(" de %d a %d \n",m,n);
    for (int i = m; i <= n; i++)
    {
        if (EhPrimo(i))
        {
           // printf("eh primo %d\n",i);
            if (i>biggest)
            {
                *maior=i;
                biggest=i;
                //printf("achei %d \n",i);
            }
            
            if (i<lowest)
            {
                *menor=i;
                lowest=1;
                //printf("achei menor %d \n",i);
            }
            
        }
        
    }
    
}
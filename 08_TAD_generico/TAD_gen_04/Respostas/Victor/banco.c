#include "banco.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct Banco
{
    int nAg;
    tAgencia**agencias;
};


tBanco *CriaBanco(){
    tBanco* bank = calloc (1,sizeof(tBanco));
    if (bank==NULL)
    {
        exit(1);
    }
return bank;
    
}


void DestroiBanco(tBanco *banco){
    for (size_t i = 0; i < banco->nAg; i++)
    {
        DestroiAgencia(banco->agencias[i]);
    }
    free(banco->agencias);
    free(banco);   
}

void LeBanco(tBanco *banco){
   
   
}
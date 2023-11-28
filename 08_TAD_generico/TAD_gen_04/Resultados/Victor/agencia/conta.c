#include "conta.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Conta {
    int id;
    char* nomeClient;
    float saldo;
};

tConta* CriaConta() {
    tConta* c = calloc(1, sizeof(tConta));
    if (c == NULL) {
        exit(1);
    }
    c->nomeClient=NULL;
    return c;
}

void DestroiConta(DataType conta) {
    if (conta == NULL) {
       return; 
    }

    tConta* c = (tConta*)conta;

    free(c->nomeClient);
    free(c);
}

void LeConta(tConta *conta){
    char nome[100];

    scanf("%d;%[^;];%f\n",&conta->id,nome,&conta->saldo);

    conta->nomeClient=malloc((strlen(nome)+1)*sizeof(char));

    strcpy(conta->nomeClient,nome);
    
}


float GetSaldoConta(tConta *conta){
    if (conta)
    {
        return conta->saldo;
    }
    
}
#include "agencia.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Agencia {
    char *nome;
    int numero;
    Vector *contas;
    int cadastros;
};

tAgencia *CriaAgencia() {
    tAgencia *t = calloc(1, sizeof(tAgencia));
    if (t == NULL) {
        exit(1);
    }
    t->contas = VectorConstruct();
    return t;
}

void DestroiAgencia(DataType agencia) {
    tAgencia *ag = (tAgencia *)agencia;

    if (ag) {
        free(ag->nome);
        VectorDestroy(ag->contas, DestroiConta);
        free(ag);
    }
}

void LeAgencia(tAgencia *agencia) {
    char nome[100];
    scanf("%d;%[^\n]\n", &agencia->numero, &nome);
    agencia->nome = malloc((strlen(nome) + 1) * sizeof(char));

    strcpy(agencia->nome, nome);
}

void AdicionaConta(tAgencia *agencia, tConta *conta) {
    agencia->cadastros++;
    VectorPushBack(agencia->contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    return numAgencia == agencia2->numero;
}

float GetSaldoMedioAgencia(tAgencia *agencia) {
    float total = 0;
    for (size_t i = 0; i < agencia->cadastros; i++) {
        tConta *a = (tConta *)VectorGet(agencia->contas, i);
        total += GetSaldoConta(a);
    }
    return (float)total / agencia->cadastros;
}

void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("\tNome: %s\n\tNumero: %d\n\tNumero de contas cadastradas: %d\n\tSaldo médio: R$%.2f\n\n", agencia->nome, agencia->numero, agencia->cadastros, GetSaldoMedioAgencia(agencia));
}
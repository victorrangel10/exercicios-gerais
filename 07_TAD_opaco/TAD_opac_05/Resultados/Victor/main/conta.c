#include "conta.h"

#include "stdio.h"
#include "stdlib.h"
#include "usuario.h"

typedef struct Conta {
    int id;
    tUsuario *user;
    float saldo;
};

tConta *CriaConta() {
    tConta *conta = calloc(1, sizeof(conta));
    if (conta == NULL) {
        return NULL;
    }
    return conta;
}

void DestroiConta(tConta *conta) {
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta) {
    LeUsuario(conta->user);
    scanf("%d", &conta->id);
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\nSaldo: R$ %.2f\n",conta->id,conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    return conta->id == numero;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    destino->saldo += valor;
    origem->saldo-=valor;
}

void SaqueConta(tConta *conta, float valor) {
    if (conta->saldo > valor) {
        conta->saldo = conta->saldo - valor;
    }
}

void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}
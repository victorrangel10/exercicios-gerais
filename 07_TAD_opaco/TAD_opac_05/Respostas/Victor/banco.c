#include "banco.h"

#include <stdio.h>
#include <stdlib.h>

#include "conta.h"
typedef struct Banco {
    tConta **contas;
    int nContas;
};

tBanco *CriaBanco() {
    tBanco *bank = calloc(1, sizeof(tBanco));
    return bank;
}

void DestroiBanco(tBanco *banco) {
    for (size_t i = 0; i < banco->nContas; i++) {
        DestroiConta(banco->contas[i]);
    }
    free(banco);
}

void AbreContaBanco(tBanco *banco) {
    banco->nContas++;
    banco->contas = realloc(banco->contas, banco->nContas * sizeof(tConta *));
    banco->contas[banco->nContas - 1] = CriaConta();
}

void SaqueContaBanco(tBanco *banco) {
    int numconta=0;
    float valor=0;
    scanf("%d %f", &numconta, &valor);
    for (size_t i = 0; i < banco->nContas; i++) {
        if (VerificaConta(banco->contas[i], numconta)) {
            SaqueConta(banco->contas[i], valor);
        }
    }
}

void DepositoContaBanco(tBanco *banco) {
    int numconta=0;
    float valor=0;
    scanf("%d %f", &numconta, &valor);
    for (size_t i = 0; i < banco->nContas; i++) {
        if (VerificaConta(banco->contas[i], numconta)) {
            DepositoConta(banco->contas[i], valor);
        }
    }
}

void TransferenciaContaBanco(tBanco *banco) {
    int numconta1=0, numconta2=0;
    int foi = 0;
    float valor=0;
    int conta1 = 0, conta2 = 0;
    scanf("%d %d %f", &numconta1, &numconta2, &valor);
    for (size_t i = 0; i < banco->nContas; i++) {
        if (VerificaConta(banco->contas[i], numconta1)) {
            conta1 = i;
            foi++;
        }

        if (VerificaConta(banco->contas[i], numconta2)) {
            conta2 = i;
            foi++;
        }
        if (foi == 2) {
            TransferenciaConta(banco->contas[conta1], banco->contas[conta2], valor);
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("===| Imprimindo Relatorio |===\n");
    for (size_t i = 0; i < banco->nContas; i++) {
        ImprimeConta(banco->contas[i]);
    }
}
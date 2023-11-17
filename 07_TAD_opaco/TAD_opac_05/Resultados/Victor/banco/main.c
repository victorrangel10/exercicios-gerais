#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

int main() {
    char opt;
    scanf("%c", &opt);

    tBanco* banco = CriaBanco();

    while (opt != 'F') {
        switch (opt) {
            case 'A':
                AbreContaBanco(banco);
                break;

            case 'S':
                SaqueContaBanco(banco);
                break;
            case 'D':
                DepositoContaBanco(banco);
                break;
            case 'T':
                TransferenciaContaBanco(banco);
                break;

            case 'R':
                ImprimeRelatorioBanco(banco);
                break;
        }
        scanf("%c", &opt);
    }
    DestroiBanco(banco);
    return 0;
}
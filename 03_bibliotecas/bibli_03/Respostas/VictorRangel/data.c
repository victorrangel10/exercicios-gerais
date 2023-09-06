#include "data.h"

#include <stdio.h>

int verificaBissexto(int ano) {
    // dois casos, divisivel por 4 mas nao por 100
    // divisivel por 4,100 e 400
    if (ano % 4 == 0) {
        if (ano % 100 == 0) {
            if (ano % 400 == 0) {
                return 1;
            } else
                return 0;

        } else
            return 1;

    } else
        return 0;
}

int numeroDiasMes(int mes, int ano) {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;

    } else if (mes == 2) {
        if (verificaBissexto(ano)) {
            return 29;
        } else
            return 28;
    } else
        return 30;
}

int verificaDataValida(int dia, int mes, int ano){
    if (dia>0 && dia<=numeroDiasMes(mes,ano) && mes>0 && mes<13 && ano>0){
        return 1;
    }else return 0;
}

void imprimeMesExtenso(int mes){
switch (mes)
{
case 1:
    printf("Janeiro");
    break;

case 2:
    printf("Fevereiro");
    break;

case 3:
    printf("Marco");
    break;

case 4:
    printf("Abril");
    break;

case 5:
    printf("Maio");
    break;

case 6:
    printf("Junho");
    break;

case 7:
    printf("Julho");
    break;
case 8:
    printf("Agosto");
    break;

case 9:
    printf("Setembro");
    break;

case 10:
    printf("Outubro");
    break;

case 11:
    printf("Novembro");
    break;

case 12:
    printf("Dezembro");
    break;

default:
printf("mes invalido");
    break;
}    
}

void  imprimeDataExtenso(int dia, int mes, int ano){
    if (verificaDataValida(dia,mes,ano))
    {
        printf("%d de ",dia);
    }
    imprimeMesExtenso(mes);
    printf(" %d\n",ano);
}

int calculaDiasAteMes(int mes, int ano){
    int i,dias=0;
    for ( i = 0; i < mes; i++)
    {
        dias=dias+numeroDiasMes(mes,ano);
    }
    return dias;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if (ano1>ano2)
    {
        return 1;
    }else if (ano2>ano1)
    {
        return -1;
    }else if (mes1>mes2)
    {
        return 1;
    }else if (mes2>mes1)
    {
       return -1;
    }else if (dia1>dia2)
    {
        return 1;
    }else if (dia2>dia1)
    {
        return -1;
    }else return 0;
}
    
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int diff=0;

    
    
    diff=numeroDiasMes(mes1,ano1)-dia1; // inicia o proximo mes zerado
    
    for (int i = mes1; i <=12; i++)
    {
       diff=numeroDiasMes(i,ano1);
    }

    ano1++;

    while (ano1!=ano2)
    {
        diff=diff+calculaDiasAteMes(12,ano1);
        ano1++;
    }
    
    diff=diff+calculaDiasAteMes(mes2,ano2)+dia2;
}
    
    
    
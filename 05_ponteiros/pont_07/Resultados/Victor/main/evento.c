#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
if (*numEventos==MAX_EVENTOS)
{
   printf("Limite de eventos atingido!\n");
   return;
}


char nome[50];
int dia,mes,ano;
scanf("%s\n",eventos[*numEventos].nome);

scanf("%d %d %d\n",&dia,&mes,&ano);

eventos[*numEventos].dia=dia;
eventos[*numEventos].mes=mes;
eventos[*numEventos].ano=ano;

*numEventos+=1;
printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    if (*numEventos==0)
    {
        printf("Nenhum evento cadastrado.\n");
        return;
    }
    
    printf("Eventos cadastrados:\n");
    for (int i = 0; i < *numEventos; i++)
    {
        printf("%d - %s - %02d/%02d/%04d\n",i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
    
    
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int num;
    scanf("%d\n",&num);
    if (num>=*numEventos)
    {
       printf("Indice invalido!\n");
        return;
    }
    
    scanf("%d %d %d\n",&eventos[num].dia,&eventos[num].mes,&eventos[num].ano);
    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento aux;

    if (indiceA>=*numEventos ||indiceB>=*numEventos )
    {
        printf("Indices invalidos!\n");
        return;
    }
    
    eventos[*indiceA]=aux;
    eventos[*indiceA]=eventos[*indiceB];
    eventos[*indiceB]=aux;               
}
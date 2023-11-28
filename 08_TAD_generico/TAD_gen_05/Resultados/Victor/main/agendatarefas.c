#include "agendatarefas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    int prioridade;
    void* dado;
    void (*executa)(void*);
    void (*destroi)(void*);
} tTarefa;

struct agendatarefas {
    int ntarefas;
    tTarefa** tarefas;
    int nfeitas;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas* a = calloc(1, sizeof(tAgendaTarefas));

    if (a == NULL) {
        exit(1);
    }

    a->ntarefas = numElem;
    return a;
}

tTarefa* CriaTarefa(int prio, void* dado, void (*executa)(void*), void (*destroi)(void*)) {
    tTarefa* t = malloc(sizeof(tTarefa));
    if(t==NULL){
        exit(1);
    }

    t->dado = dado;
    t->destroi = destroi;
    t->executa = executa;
    t->prioridade = prio;
    return t;
}

void ExecutaTarefa(tTarefa* t){
    t->executa(t->dado);

}
void DesalocaTarefa(void* t) {
    tTarefa* a = (tTarefa*)t;

    if(a->dado) a->destroi(a->dado);
    if(a) free(a);
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    for (size_t i = 0; i < tar->ntarefas; i++) {
        DesalocaTarefa(tar->tarefas[i]);
    }
    if (tar->tarefas) free(tar->tarefas);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void* tarefa, void (*executa)(void*), void (*destroi)(void*)) {
    if (tar != NULL && tarefa != NULL) {
        tar->tarefas = realloc(tar->tarefas, (tar->nfeitas + 1) * sizeof(tTarefa*));

        tTarefa* a = CriaTarefa(prioridade, tarefa, executa, destroi);

        tar->tarefas[tar->nfeitas] = a;
    }

    tar->nfeitas++;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {
    if (tar != NULL) {

        tTarefa* aux;
        for (size_t i = 0; i < tar->ntarefas; i++)
        {
            for (size_t j = 0; j < tar->ntarefas; j++)
            {
               if (tar->tarefas[i]->prioridade > tar->tarefas[j]->prioridade)
               {
                aux=(tar->tarefas[i]);
                tar->tarefas[i]=tar->tarefas[j];
                tar->tarefas[j]=aux;
               }
               
            }
            
        }
        
        for (size_t i = 0; i < tar->ntarefas; i++) {
            ExecutaTarefa(tar->tarefas[i]);
        }
    }
}
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
    tTarefa** tarefas
};


tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas* a = calloc(1, sizeof(tAgendaTarefas));
    if (a == NULL) {
        exit(1);
    }
    a->ntarefas=numElem;
    return a;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    for (size_t i = 0; i < tar->ntarefas; i++) {
        tar->tarefas[i]->destroi(tar->tarefas[i]);
    }
    free(tar->tarefas);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void* tarefa, void (*executa)(void*), void (*destroi)(void*)) {
    if (tar!=NULL)
    {

    tar->tarefas = realloc(tar->tarefas, (tar->ntarefas + 1) * sizeof(tTarefa*));

    tar->tarefas[tar->ntarefas]= calloc(1, sizeof(tTarefa));

    tar->tarefas[tar->ntarefas]->dado = tarefa;
    tar->tarefas[tar->ntarefas]->destroi = destroi;
    tar->tarefas[tar->ntarefas]->executa = executa;
    tar->tarefas[tar->ntarefas]->prioridade = prioridade;
     }
}

int cmpfunc (const void * a, const void * b) {
   tTarefa* ta = (tTarefa*) a;
   tTarefa* tb = (tTarefa*) b;

    if (!ta)
    {
        
    }
    if (!tb)
    {
       exit(1);
    }
    
   return ta->prioridade-tb->prioridade;

}
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    if (tar!=NULL)
    {
        tTarefa* aux;
    
        for (size_t i = 0; i < tar->ntarefas; i++)
        {
            for (size_t j = i+1; j < tar->ntarefas-1; j++)
            {
                if (tar->tarefas[i]->prioridade<tar->tarefas[j]->prioridade)
                {
                    aux = tar->tarefas[i];
                    tar->tarefas[i]=tar->tarefas[j];
                    tar->tarefas[j]=aux;

                }
                
            }
            
        }
        
    for (size_t i = 0; i < tar->ntarefas; i++)
    {
        tar->tarefas[i]->executa(tar->tarefas[i]);
    }

    }
    
    
}
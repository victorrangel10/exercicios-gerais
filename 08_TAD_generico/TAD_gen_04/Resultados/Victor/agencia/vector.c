#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
  DataType *vet;
  int nElementos;
};

Vector *VectorConstruct() {
  Vector *v = calloc(1, sizeof(Vector));
  if (v == NULL) {
    exit(1);
  }
  v->vet = NULL;
  return v;
}

void VectorPushBack(Vector *v, DataType val) {
  v->nElementos++;

  v->vet = realloc(v->vet, v->nElementos * sizeof(DataType));

  v->vet[v->nElementos - 1] = val;
}

DataType VectorGet(Vector *v, int i) { return v->vet[i]; }

int VectorSize(Vector *v){
    return v->nElementos;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if (v!=NULL)
    {
       for (size_t i = 0; i < v->nElementos; i++)
       {
        destroy(v->vet[i]);
       }
       free(v->vet);
    free(v);
    }
    
}
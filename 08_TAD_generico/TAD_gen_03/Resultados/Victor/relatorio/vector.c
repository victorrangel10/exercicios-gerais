#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
  data_type *vet;
  size_t numBytesElem;
  int nElementos;
};

Vector *VectorConstruct() {
  Vector *v = calloc(1, sizeof(Vector));
  if (v == NULL) {
    exit(1);
  }

  v->numBytesElem = sizeof(data_type);
  v->vet = NULL;
  return v;
}

void VectorPushBack(Vector *v, data_type val) {
  v->nElementos++;

  v->vet = realloc(v->vet, v->nElementos * sizeof(data_type));

  v->vet[v->nElementos - 1] = val;
}

data_type VectorGet(Vector *v, int i) { return v->vet[i]; }



int VectorSize(Vector *v){
    return v->nElementos;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    if (v!=NULL && v->vet!=NULL)
    {
       for (size_t i = 0; i < v->nElementos; i++)
       {
        destroy(v->vet[i]);
       }
       
    }
    free(v->vet);
    free(v);
}
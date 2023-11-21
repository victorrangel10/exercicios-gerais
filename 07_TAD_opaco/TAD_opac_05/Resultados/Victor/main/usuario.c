#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Usuario {
    char *nome;
    int cpf;
};

tUsuario *CriaUsuario() {
    tUsuario *user = malloc(sizeof(tUsuario));
    user->nome=calloc(1,sizeof(char));
    return user;
}

void DestroiUsuario(tUsuario *user) {
    free(user->nome);
    free(user);
}

void LeUsuario(tUsuario *user) {
  
  char  string[100];

  scanf("%s",string);
  
  user->nome=realloc(user->nome,(strlen(string)+1)*sizeof(char));

  strcpy(user->nome,string);
   
scanf("%d",&user->cpf);
}

void ImprimeUsuario(tUsuario *user) {
        printf("Nome: %s\nCPF: %d\n",user->nome,user->cpf);
}


#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(){
    int num;

    scanf("%d",&num);

    int * vet = CriaVetor(num);

    LeVetor(vet,num);

    float media = CalculaMedia(vet,num);
    printf("%.2f",media);

    LiberaVetor(vet);

}
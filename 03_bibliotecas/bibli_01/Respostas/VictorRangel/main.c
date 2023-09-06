
#include "esfera_utils.h"
#include <stdio.h>

int main(){
    float radius;
    scanf("%f",&radius);
    printf("Area: %.2f\n",calcula_area(radius));
    printf("Volume: %.2f",calcula_volume(radius));
    return 0;

}
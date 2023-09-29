#include <stdio.h>
#include "esfera_utils.h"


void CalculaVolume (float R, float *volume){
    float vol;
    vol=(4*PI*R*R*R)/3;
    *volume=vol;
}

void CalculaArea (float R, float *area){
    float vol;
    vol=4*PI*R*R;
    *area=vol;
}



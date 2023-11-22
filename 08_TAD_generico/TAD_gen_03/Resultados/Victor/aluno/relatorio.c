#include "relatorio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "vector.h"


float Porcentagem(float valor, int total){

    return ((float)valor/total)*100;
}

void ImprimeRelatorio(Vector* alunos) {
    int totalAlunos = VectorSize(alunos);

    float soma = 0;
    int mas = 0, fem = 0, outro = 0,passou=0;

    for (size_t i = 0; i < totalAlunos; i++) {
        tAluno* a = VectorGet(alunos, i);

        soma += GetNotaAluno(a);

        if (GetNotaAluno(a)>=6){ passou++;}
        
        
        switch (GetGeneroAluno(a)) {
            case 'M':
                mas++;
                break;
            case 'F':
                fem++;
                break;
            case 'O':
                outro++;
                break;
        }
    }

    float media = (float) soma/totalAlunos;

    printf("Media das notas: %.2f\nPorcentagem de alunos aprovados: %.2f%%\nPorcentagem de cada genero:\nMasculino: %.2f%%\nFeminino: %.2f%%\nOutro: %.2f%%\n",media,Porcentagem(passou,totalAlunos),Porcentagem(mas,totalAlunos),Porcentagem(fem,totalAlunos),Porcentagem(outro,totalAlunos));
}
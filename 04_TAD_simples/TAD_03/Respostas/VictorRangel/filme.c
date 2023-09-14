#include <stdio.h>
#include "filme.h"
#include <string.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme f;
    strcpy(nome,f.nome);
    f.valor=valor;
    f.codigo=codigo;
    f.qtdEstoque=quantidade;
    f.qtdAlugada=0;
    return f;
}

tFilme lerFilme(){
    tFilme filme;   
    scanf("%d,%s,%d,%d",&filme.codigo,&filme.nome,&filme.valor,&filme.qtdEstoque);
    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme){
    printf("%s\n",filme.nome);
}

int obterValorFilme (tFilme filme){
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(codigo==filme.codigo) return 1;
    else return 0;
}

tFilme alugarFilme (tFilme filme){
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme (tFilme filme){
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return strcmp(filme1.nome,filme2.nome);
}
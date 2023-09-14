#include <stdio.h>
#include "locadora.h"


tLocadora criarLocadora (){
    tLocadora loc;
    loc.numFilmes=0;
    loc.lucro=0;
    return loc;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i],codigo))
        {
            return 1;
        }
        
    }
    return 0;
}


tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade){
    locadora.numFilmes++;
    locadora.filme[locadora.numFilmes-1]=criarFilme(nome,codigo,valor,quantidade);
    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora){
     locadora.numFilmes++;
    locadora.filme[locadora.numFilmes-1]=lerFilme();
    return locadora;
}


tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        for ( int j = 0; i < locadora.numFilmes; j++)
        {
            if (ehMesmoCodigoFilme(locadora.filme[j],codigos[i]))
            {
                locadora.filme[j]=alugarFilme(locadora.filme[j]);
            }
            
        }
        
    }
    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora){
    tFilme wantedMovie;
    wantedMovie = lerFilme();
    
}
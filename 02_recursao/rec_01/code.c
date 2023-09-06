/* (REC_01) Problema: Implemente uma função, utilizando o
Cabeçalho: void ImprimeInvertido(char* string);
Utilizando  a  função  anterior,  faça  um  programa  qu conceito de recursão, que
receba uma string como parâmetro e a imprima de trás para frente.e  leia  palavras  de  um  texto
(considere  palavras  como  uma  sequência  de  caracteres  diferentes  de  espaço)  e  as
imprime de trás para frente.

Definição dos formatos de entrada e saída:
• Entrada: um texto contendo palavras com no máximo 1000 caracteres cada.
• Saída: o texto com as palavras impressas de trás para frente.

Ver exemplos de formato de entrada e saída nos arquivos fornecidos com a questão.
 */

#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string) {
    if (strlen(string)==1)
    {
        printf("%s",string);
        return;
    }
    
    int i=0;

    while (string[i]!='\0')
    {
       i++;
    }
  
    printf("%c",string[i-1]);

    string[i-1]='\0';

    ImprimeInvertido(string);
    
    
}

int main() {
    char word[1001];
    while (scanf("%s", word)==1) {
        
        ImprimeInvertido(word);
        printf(" ");
    }
}
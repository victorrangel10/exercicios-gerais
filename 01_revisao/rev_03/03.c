/* (REV_03) Problema: Em uma biblioteca, cada livro possui um identificador único que
é representado por um número inteiro de 1 até N. Porém, se existir cópias deste livro,
elas  possuem  o  mesmo  identificador.  É  sempre  desejável  ter  mais  de  uma  cópia  de
cada  livro  para  que  várias  pessoas  possam  usufruir  do  mesmo.  Sendo  assim,  os
funcionários  da  biblioteca  receberam  uma  lista  de  identificadores  de  livros  para
identificar quais não possuem cópias para solicitar a compra de um novo exemplar.
Sua função é criar um programa que identifique quais livros da lista não tem cópia e
retorne para o funcionário solicitar a compra.

Definição dos formatos de entrada e saída:
• Entrada:  Um  número  N  que  representa  a  quantidade  de  livros  seguido  dos  N
livros em si.
• Saída: O identificador dos livros que não possuem cópia.
''*/

#include <stdio.h>

void ScanBooks(int bookID[], int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        scanf("%d", &bookID[i]);
    }
}

int HasEqual(int bookID[], int book, int numBooks) {
    int numEquals = 0;
    for (int i = 0; i < numBooks; i++) {
        if (bookID[i] == book) {
            numEquals++;
        }
    }
    if (numEquals >= 2) {
        return 1;
    } else
        return 0;
}

void BubbleSort(int bookID[], int numBooks) {
    int i, j;
    int aux;
    for ( i = 0; i < numBooks; i++)
    {
        for(j=i+1;j<numBooks;j++){
            if (bookID[j]<bookID[i])
            {
                aux=bookID[i];
                bookID[i]=bookID[j];
                bookID[j]=aux;
            }
            
        }
    }
    
}

int main() {
    int numBooks;
    scanf("%d", &numBooks);
    int bookID[numBooks];
    ScanBooks(bookID, numBooks);
    BubbleSort(bookID, numBooks);
    int found = 1;
    for (int i = 0; i < numBooks; i++) {
        if (!HasEqual(bookID, bookID[i], numBooks)) {
            found = 0;
            printf("%d", bookID[i]);
            if(i!=numBooks-1){
                printf(" ");
            }
        }
    }
    if (found) {
        printf("NENHUM");
    }
    return 0;
}
#include <stdio.h>

#include "matrix_utils.h"

int main() {
    int rows1, cols1, rows2, cols2;
    scanf("%d%d%d%d", &rows1, &cols1, &rows2, &cols2);
    int matrix1[rows1][cols1], matrix2[rows2][cols2];
    matrix_read(rows1, cols1, matrix1);
    matrix_read(rows2, cols2, matrix2);

    int opt;

    while (1) {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: ");
    printf("\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
            {
                if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                    int result[rows1][cols1];
                    matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result[rows1][cols1]);
                    matrix_print(rows1, cols1, result[rows1][cols1]);

                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            }
            case 2:
            {
                if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                    int result[rows1][cols1];
                    matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result[rows1][cols1]);
                    matrix_print(rows1, cols1, result[rows1][cols1]);

                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }
                break;
            }
            case 3:
            {
                if (possible_matrix_multiply(cols1, rows2)) {

                    int result[rows2][cols1];


                    matrix_multiply(rows1, cols1, matrix1[rows1][cols1],
                                    rows2, cols2, matrix2[rows2][cols2], result[rows2][cols1]);

                    matrix_print(rows2, cols1, result[rows2][cols1]);

                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }

                break;
            }
            case 4:
            {
                int scalar;
                scanf("%d", &scalar);
                scalar_multiply(rows1, cols1, matrix1[rows1][cols1], scalar);
                matrix_print(rows1, cols1, matrix1[rows1][cols1]);
                break;
             }
            case 5:
             {

                int result[cols1][rows1];

                transpose_matrix(rows1, cols1, matrix1[rows1][cols1], result[cols1][rows1]);
                matrix_print(rows1, cols1, result[cols1][rows1]);
                break;
            }
            case 6:
                return 0;
                break;
            default:
                break;
        }
    }
}
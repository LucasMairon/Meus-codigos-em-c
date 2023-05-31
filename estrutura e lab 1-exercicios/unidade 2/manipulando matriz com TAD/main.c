#include <stdio.h>
#include <stdlib.h>
#include "matriz.c"

int main()
{

    Matriz *matriz = mat_cria(2, 3);

    mat_atribui(matriz, 1, 2, 19);
    float acessado = mat_acessa(matriz, 1, 2);
    int linhas = mat_linhas(matriz);
    int colunas = mat_colunas(matriz);

    printf("linhas da matriz:%d\ncolunas da matriz:%d\nelemento acessado da matriz:%.2f", linhas, colunas, acessado);

    mat_libera(matriz);

    return 0;
}

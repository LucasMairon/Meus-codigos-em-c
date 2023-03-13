#include <stdio.h>
#include <stdlib.h>

typedef struct matriz
{
    int lin;
    int col;
    float *v;

} Matriz;

Matriz *mat_cria(int m, int n)
{
    int i;

    Matriz **nova_matriz = (Matriz **)malloc(m * sizeof(Matriz *));
    for (i = 0; i < m; i++)
    {
        nova_matriz[i]->v = (float *)malloc(n * sizeof(float));
        nova_matriz[i]->lin = m;
        nova_matriz[i]->col = n;
    }

    return nova_matriz;
}

void mat_libera(Matriz *mat)
{
    int i, j;
    for (i = 0; i < mat->lin; i++)
    {
        free(mat->v);
    }
    free(mat);
}
float mat_acessa(Matriz *mat, int i, int j)
{

    return mat[i].v[j];
}
void mat_atribui(Matriz *mat, int i, int j, float v)
{

    mat[i].v[j] = v;
}
int mat_linhas(Matriz *mat)
{
    int soma = 0, i;
    for (i = 0; i < mat->lin; i++)
    {
        soma++;
    }

    return soma;
}
int mat_linhas(Matriz *mat)
{
    int soma = 0, j;
    for (j = 0; j < mat->lin; j++)
    {
        soma++;
    }

    return soma;
}

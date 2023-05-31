#include <stdio.h>
#include <stdlib.h>

typedef struct matriz
{
    int lin;
    int col;
    float *v;

}Matriz;

Matriz *mat_cria(int m, int n)
{

    Matriz *nova_matriz = (Matriz *)malloc(m * sizeof(Matriz));
    nova_matriz->lin = m;
    nova_matriz->col = n;
    float *v = (float *)malloc(n * sizeof(float));
    nova_matriz->v=v;

    return nova_matriz;
}

void mat_libera(Matriz *mat)
{
        free(mat->v);
   
    free(mat);
}

float mat_acessa(Matriz *mat, int i, int j)
{
    if(mat->lin>=i && mat->col>=j){
    return mat->v[i+j];
    }else{
        printf("o elemento nao existe na matriz,a funcao retornara -1");
        return (-1);
    }
}

void mat_atribui(Matriz *mat, int i, int j, float v)
{
    if(mat->lin>=i && mat->col>=j){

    mat->v[j+i] = v;

    }
    else{
        printf("o elemento nao existe na matriz");
    }
    
}

int mat_linhas(Matriz *mat)
{
 
    return mat->lin;
}

int mat_colunas(Matriz *mat)
{
 
    return mat->col;
}

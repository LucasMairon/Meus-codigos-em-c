// Questão 1) Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho n e retorne quantos números pares estão armazenados nesse vetor. Essa função deve obedecer ao protótipo: int pares(int n, int* vet); Acesse a resposta

#include <stdio.h>

int pares(int n, int *vet)
{
    
    int i, pares = 0;

    for (i = 0; i < n; i++)

    {

        if (vet[i] % 2 == 0)

        {

            pares++;

        }

    }

    return pares;

}

int main()
{
    int n, i;

    printf("digite a quantidade de numeros que serao armazenados: ");

    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {

        printf("\ndigite o %d valor: ", i + 1);

        scanf("%d", &v[i]);

    }

    printf("a quantidade de numeros pares foi: %d", pares(n, v));

    return 0;

}

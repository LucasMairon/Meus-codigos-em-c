// Escreva um programa em C que preencha um vetor de 10 inteiros com informações
// vindas de um arquivo e escreva em outro arquivo o menor elemento, o maior elemento, bem
// como a média dos elementos do vetor, como ilustrado a seguir
// entrada:
// 10
// 2
// 8
// 1
// 12
// 8
// 10
// 5
// 4
// 19

#include <stdio.h>

int main()
{

    int v[10], i;
    float media, soma = 0;
    char linhas[100];
    FILE *entrada_num = fopen("entrade_nums.txt", "rt");
    FILE *saida_mmm = fopen("saida_mmm.txt", "wt");
    if (entrada_num == NULL)
    {
        printf("o arquivo nao foi aberto");
        return 1;
    }
    if (saida_mmm == NULL)
    {
        printf("o arquivo nao foi aberto");
        return 1;
    }
    while (fgets(linhas, 100, entrada_num) != NULL)
    {
        sscanf(linhas, "%d ", &v[i]);
        soma += v[i];
        i++;
    }
    int menor = v[0];
    int maior = v[0];

    for (i = 0; i < 10; i++)
    {
        if (v[i] > maior)
        {
            maior = v[i];
        }
        if (v[i] < menor)
        {
            menor = v[i];
        }
    }
    media = soma / 10;
    fprintf(saida_mmm, "menor elemento: %d\nmaior elemento: %d\nmedia dos elementos: %f ", menor, maior, media);

    fclose(entrada_num);
    fclose(saida_mmm);

    return 0;
}

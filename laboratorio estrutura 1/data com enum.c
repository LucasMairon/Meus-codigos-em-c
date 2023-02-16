// 3. Escreva um programa que implementa uma struct Data com os campos dia, mês e ano. O mês deve
// ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARÇO, ABRIL, MAIO,
// JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
// deve ler a data e imprimir a data no formato dd/mm/aaaa.
#include <stdio.h>

typedef enum meses
{
    JANEIRO = 01,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Meses;

typedef struct data
{
    char dia[3];

    char ano[5];

    Meses meses;

} Data;

int main()
{

    Data data;

    printf("digite o dia: ");

    scanf(" %[^\n]", data.dia);

    printf("digite o mes: ");

    scanf(" %d", (int *)&data.meses);

    printf("digite o ano: ");

    scanf(" %[^\n]", data.ano);

    if (data.meses < 10)
    {

        printf("data: %s/0%d/%s", data.dia, data.meses, data.ano);
    }

    else
    {

        printf("data: %s/%d/%s", data.dia, data.meses, data.ano);
    }

    return 0;
}

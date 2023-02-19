// Questão 4) Crie um programa para calcular a área e o perímetro de um hexágono. O seu
// programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
// perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
// void calcula_hexagono(float l, float *area, float *perimetro); A área e o perímetro de um
// hexágono regular são dados, respectivamente, por:

// A=(3*l*l*sqrt(3))/2
// P=6*l

// Obs: Para os cálculos, utilize as funções sqrt e pow do módulo math da biblioteca
// padrão de C. Em seguida, crie a função principal do programa e utilize a função
// calcula_hexagono para calcular a área e o perímetro de um hexágono de lado l
// informado pelo usuário.

#include <stdio.h>

#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro); // função que irá ser usada para calcular a área e o perímetro do hexagono;

int main(void)
{

    float A, P, L; // declaração de variaveis que serão necessárias;

    printf("digite o lado do hexagono\n"); // pedindo e preenchendo  o valor do lado;

    scanf("%f", &L);

    calcula_hexagono(L, &A, &P); // chamada da função,passando por parametros o lado e os endereços de A e P,referentes a area e perimetro,para quando modificarmos o valor delas na função já modifique nas variaveis da função main;

    printf("area= %.2f\nperimetro= %.2f", A, P); // imprimindo os resultados armazenados em A e P,referentes a area e perimetro;

    return (0);
}
void calcula_hexagono(float l, float *area, float *perimetro)// inicializando a função,seus parametros são:o valor da variavel L e os ponteiros area e perimetro que irão receber o endereço de A e P;
{ 

    *area = (3 * (pow(2, l)) * (sqrt(3))) / 2; // calculo da área,que será armazenado na variavel A,que é o conteudo do ponteiro area;

    *perimetro = 6 * l; // calculo do perímetro,que será armazenado na variavel P,que é o conteudo do ponteiro perimetro;
}

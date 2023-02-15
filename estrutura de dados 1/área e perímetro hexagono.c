#include<stdio.h>

#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro);

int main(void){

    float A,P,L;

    printf("digite o lado do hexagono\n");

    scanf("%f",&L);

    calcula_hexagono(L,&A,&P);

    printf("area= %f\nperimetro= %f",A,P);

return(0);

}
void calcula_hexagono(float l, float *area, float *perimetro){

    area=(3(pow(2,l))*(sqrt(3)))/2;

    *perimetro=6*l;

}

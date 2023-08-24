// Defina uma fun¸c˜ao para inverter um n´umero. Exemplo:
// f(1234) = 4321
// (a) No formato n˜ao recursivo;
// (b) No formato recursivo.
#include<stdio.h>
int inverteNaoRecursiva(int numero_para_conversao){
    int aux,inverter;

    while(aux != 0){
        aux = numero_para_conversao / 10;
        
        inverter =  aux;

    }
    return inverter;
   
}

int main(){
    int numero_para_inversao;
    printf("digite o numero a ser invertido: ");
    scanf("%d",&numero_para_inversao);
    printf("%d",inverteNaoRecursiva(numero_para_inversao));

    return 0;
}
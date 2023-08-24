//Defina uma fun¸c˜ao recursiva que, dado os valores inteiros de x1 e x2, determine y = x1x2.

#include<stdio.h>
//funcao que representa um somatorio(com limite)
int frecursiva(int x1,int x2){
    if(x2 == 0){
        return 0;
    }if(x2 == 1){
        return x1;
    }
    return x1 + frecursiva(x1,x2-1);
}

int main(){

    int x1,x2;
    printf("digite os valores de x1 e x2: ");
    scanf("%d %d",&x1,&x2);
    printf("resultado da funcao recursiva: %d",frecursiva(x1,x2));

    return 0;
}
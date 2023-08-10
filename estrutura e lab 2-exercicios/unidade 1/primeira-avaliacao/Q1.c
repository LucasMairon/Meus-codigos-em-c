/*Escreva um programa para converter e imprimir os caracteres para os valores ASCII de 0 a 127.
O programa deve imprimir 10 caracteres por linha
*/

#include<stdio.h>
int main(){
    int i,j=0;
    for(i=0 ;i<127; i++){
        printf("%c",i);
        j++;
        if(j == 9){
            j = 0;
            printf("\n");
        }
    }

    return 0;
}

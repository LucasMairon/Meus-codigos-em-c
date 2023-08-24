// Um n´umero inteiro ´e considerado um n´umero perfeito se seus fatores, incluindo 1 (mas n˜ao o
// pr´oprio n´umero), somam o n´umero. Por exemplo, 6 ´e um n´umero perfeito porque 6 = 1 + 2 + 3.
// Escreva uma fun¸c˜ao isPerfect que determina se o n´umero do parˆametro ´e um n´umero perfeito. Use
// esta fun¸c˜ao em um programa que determina e imprime todos os n´umeros perfeitos entre 1 e 1000.
// Imprima os fatores de cada n´umero perfeito para confirmar que o n´umero ´e realmente perfeito.

#include<stdio.h>

void isPerfect(int numero){
    
    int i,verifica_perfeito=0,j,v;
    for(i = 1;i < numero;i++){
        if((numero % i) == 0){
            verifica_perfeito += i;
        }
    } 
    if(verifica_perfeito == numero){
        printf("%d e perfeito\n",numero);
        printf("os fatores que fazem esse numero ser perfeito sao: \n");
         for(i = 1;i < numero;i++){
             if(numero % i == 0){
                 printf("%d\n",i);
                 
             }
         }
    }
    

}
int main(){
    int numero;
    printf("digite o numero que deseja saber se e perfeito: ");
    scanf("%d",&numero);
    isPerfect(numero);

    return 0;
}
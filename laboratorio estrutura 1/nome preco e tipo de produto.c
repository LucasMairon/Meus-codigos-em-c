// 2. Escreva um programa que implementa uma struct Produto com os campos nome, preço e tipo. O
// tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
// ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto. 


#include<stdio.h>

typedef union{

char alimento[10];

char bebida[10];

char eletronico[10];



}Tipo;

typedef struct produto{

char nome[50];

float preco;

Tipo tipo;


}Produto;


int main(){
    Produto produto;

     char resposta[50];

    char resposta[10];

    printf("digite o nome do produto: ");

    scanf(" %[^\n]s",produto.nome);

    printf("digite o preco do produto: ");

    scanf("%f",&produto.preco);

    printf("digite o tipo(alimento, bebida ou eletronico): ");

    scanf(" %[^\n]s",resposta);

    if(resposta=="alimento"){

        printf("digite o alimento");

       scanf(" %[^\n]",produto.tipo.alimento);

    }
     if(resposta=="bebida"){

         printf("digite a bebida");

       scanf(" %[^\n]",produto.tipo.bebida);

    }
     if(resposta=="eletronico"){

         printf("digite o eletronico");

       scanf(" %[^\n]",produto.tipo.eletronico);

    }
    printf("nome do produto: %s\n",produto.nome);

    printf("preco do produto: %.2f\n",produto.preco);

    printf("produto de tipo especifico: %s",produto.tipo.alimento);




    return 0;
}

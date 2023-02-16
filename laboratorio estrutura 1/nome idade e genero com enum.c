// 1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gˆenero. O
// gˆenero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
// deve ler os dados de uma pessoa e imprimir os dados da pessoa.

#include <stdio.h>

typedef enum
{
    MASCULINO,
    
    FEMININO

} Genero;

typedef struct pessoa
{
    char nome[50];

    int idade;

    Genero genero;

} Pessoa;

int main()
{
    Pessoa pessoa;
    printf("digite seu nome: ");

    scanf(" %[^\n]s", pessoa.nome);

    printf("digite a idade: ");

    scanf("%d", &pessoa.idade);

    printf("digite o genero: ");

    scanf("%d", (int *)&pessoa.genero);

    printf("nome: %s\n", pessoa.nome);

    printf("idade: %d \n", pessoa.idade);

    pessoa.genero == 0 ? printf("genero: Masculino") : printf("genero: Feminino");

    return 0;
}

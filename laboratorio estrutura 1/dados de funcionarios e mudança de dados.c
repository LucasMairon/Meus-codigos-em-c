// Crie um tipo estruturado para armazenar dados de um funcionário. Uma estrutura deste tipo possui
// os seguintes campos: nome, salario, identificador e cargo.
// a) Escreva uma funcao que receba como parˆametro o endere ̧co de uma estrutura do tipo Funcionario
// e preencha seus campos com valores fornecidos pelo usu ́ario via teclado.
// b) Escreva uma fun ̧c ̃ao que receba como parˆametro o endere ̧co de uma estrutura do tipo Funcionario
// e imprima os valores dos seus campos.
// c) Implemente uma fun ̧c ̃ao para realizar uma altera ̧c ̃ao no sal ́ario de uma estrutura do tipo Funcionario.
// d) Escreva uma fun ̧c ̃ao que receba como parˆametro um vetor de estruturas do tipo Funcionario e
// imprima o cargo e sal ́ario do Funcionario com maior sal ́ario e o cargo e sal ́ario do funcion ́ario
// com o menor sal ́ario.

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct funcionario // criando a struct funcionario,que contem as variaveis nome,salario,cargo e identificador, e alterando seu nome para Funcionário
{

    char nome[50];

    float salario;

    char cargo[50];

    int identificador;

} Funcionario;

void preenche(Funcionario *dados, int quant) // criando a funcao preenche, que tem como parametros um vetor dados e uma variavel para a quantidade
{

    int i; // declarando i

    for (i = 0; i < quant; i++) // estrutura de repeticao que vai de zero ate a quantidade informada pelo usuario na main
    {

        printf("digite o nome do %d funcionario: ", i + 1); // pedindo e lendo o nome do funcionario, que sera armazenado em uma das posicoes do vetor dados, refrente a uma struct, na variavel nome

        scanf(" %[^\n]", dados[i].nome);

        printf("digite o salario do %d funcionario: ", i + 1); // pedindo e lendo o salario do funcionario, que sera armazenado em uma das posicoes do vetor dados,refrente a uma struct, na variavel salario

        scanf("%f", &dados[i].salario);

        printf("digite o cargo do %d funcionario: ", i + 1); // pedindo e lendo o cargo do funcionario, que sera armazenado em uma das posicoes do vetor dados,refrente a uma struct, na variavel cargo

        scanf(" %[^\n]", dados[i].cargo);

        printf("digite o id do %d funcionario: ", i + 1); // pedindo e lendo o identificador do funcionario, que sera armazenado em uma das posicoes do vetor dados,refrente a uma struct, na variavel identificador

        scanf("%d", &dados[i].identificador);
    }
}
void imprime(Funcionario *impr, int quant) // criando a funcao imprime que tem como parametros o vetor impr e  a variavel que representa a quantidade quant
{
    int i; // declarando a variavel i

    for (i = 0; i < quant; i++) // estrutura de repeticao que vai de zero ate a quantidade de funcionarios informada
    {

        printf("o nome do %d funcionario e: %s\n", i + 1, impr[i].nome); // imprimindo o nome dos funcionarios,sendo acessado em cada posicao do vetor impr que representa uma struct,na variavel nome

        printf("o salario do %d funcionario e: %.2f\n", i + 1, impr[i].salario); // imprimindo o salario dos funcionarios,sendo acessado em cada posicao do vetor impr que representa uma struct,na variavel salario

        printf("o cargo do %d funcionario e: %s\n", i + 1, impr[i].cargo); // imprimindo o cargo dos funcionarios,sendo acessado em cada posicao do vetor impr que representa uma struct,na variavel cargo

        printf("o id do %d funcionario e: %d\n", i + 1, impr[i].identificador); // imprimindo o identificador dos funcionarios,sendo acessado em cada posicao do vetor impr que representa uma struct,na variavel identificador
    }
}
void muda_salario(Funcionario *sal, int quant) // criando a funcao muda_salario, seus parametros sao o vetor sal e a variavel de quantidade quant
{

    int i, alteracao; // criando duas variaveis i e alteraao
    // int num variavel para a hipotese abaixo

    printf("deseja alterar o valor do salario dos funcionarios?(use 1 para sim e 2 para nao)\n"); // perguntando ao usuario se ele deseja mudar o salarios dos funcionarios

    scanf("%d", &alteracao); // lendo a resposta(dada por 1 e 2)

    if (alteracao == 2) // verificando se o usuario digitou 2,se ele digitou entao os salarios nao serao modificados
    {

        printf("o salario nao foi alterado");
    }

    else // verificando se o usuario digitou 1
    {
        // no caso de mudar apenas o salario de uma pessoa:

        // printf("digite o numero do funcionario que ira receber alteracao no salario: ");

        // scanf("%d",&num);
        // if(num<quant && num>0){
        // printf("digite o novo salario do %d funcionario: ",num+1);

        // scanf("%f",&sal[(num+1)].salario);
        // }
        // no caso de mudar o salario de todos os funcionarios(foi o que eu considerei):

        for (i = 0; i < quant; i++) // estrutura de repeticao que vai de 0 ate quant
        {

            printf("digite o novo salario do %d funcionario: ", i + 1); // pedindo o novo salario de cada funcionario

            scanf("%f", &sal[i].salario); // lendo o novo salario e armazenando nas posicoes do vetor sal,que represnta uma struct,na variavel salario
        }
    }
}
void registra_salario(Funcionario *registrasal, int quant) // criando a funcao registra_salario que tem como parametros o vetor registrasal e a quantidade de funcionarios
{
    int i; // criando a variavel i

    float maiors = 0, menors = 9999999; // criando as variaveis maiors e menors,uma sendo inicializada com 0 para que o salario sempre seja maior na primeira vez,e a outra com um valor grande,para que o salario sempre seja menor na primeira vez

    char maiorcargo[50], menorcargo[50]; // criando as variaveis que vao receber o cargo do funcionario com menor e maior salario

    for (i = 0; i < quant; i++) // estrutura de repeticao que vai de 0 ate a quantidade de funcionarios
    {

        if (registrasal[i].salario > maiors) // verificando todos os salarios para guardar o maior
        {

            maiors = registrasal[i].salario; // colocando o valor do maior salario na variavel maiors

            strcpy(maiorcargo, registrasal[i].cargo); // copiando o cargo do funcionario com o maior salario e colando na variavel maiorcargo
        }

        if (registrasal[i].salario < menors) // verificando todos os salarios para guardar o menor
        {

            menors = registrasal[i].salario; // colocando o valor do menor salario na variael menors

            strcpy(menorcargo, registrasal[i].cargo); // copiando o cargo do funcionario com o menor salario e colando na variavel menorcargo
        }
    }

    printf("o cargo da pessoa com o maior salario e: %s e o salario dessa pessoa e: %.2f\n", maiorcargo, maiors); // imprimindo o salario e o cargo da pessoa com o maior salario

    printf("o cargo da pessoa com o menor salario e: %s e o salario dessa pessoa e: %.2f\n", menorcargo, menors); // imprimindo o salario e o cargo da pessoa com o menor salario
}

int main()
{

    int quant_func; // declarando a variavel que representa a quantidade de funcionarios

    printf("digite a quantidade de funcionarios: "); // pedindo e lendo a quantidade de funcionarios que serao entrevistados

    scanf("%d", &quant_func);

    Funcionario *dados_func = (Funcionario *)malloc(quant_func * sizeof(Funcionario)); // alocando dinamicamente o vetor dados_func, com espaco referente a quantidade de funcionarios

    if (dados_func == NULL) // verificando se a alocacao foi bem sucedida,se nao for o progama sera abortado
    {

        printf("memoria insuficiente");

        exit(1);
    }

    preenche(dados_func, quant_func); // passando o vetor dados_func e a quantidade de funcionarios para as funcoes que serao usadas

    imprime(dados_func, quant_func);

    muda_salario(dados_func, quant_func);

    registra_salario(dados_func, quant_func);

    free(dados_func); // liberando o vetor dados_func da memoria

    return 0;
}

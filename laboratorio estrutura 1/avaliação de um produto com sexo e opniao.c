#include <stdio.h>

#include <stdlib.h>

int main()
{

    int pessoas, count, count2, soma_feminino = 0, soma_masculino = 0; // criando as variaveis que serao necessarias;

    printf("digite a quantidade de pessoas que serao entrevistadas:\n"); // pedindo e lendo o numero de pessoas que serao entrevistadas;

    scanf("%d", &pessoas);

    char *sexo = (char *)malloc(pessoas * sizeof(char)); // alocando dinamicamente o vetor sexo,com espaço definido pelo numero de pessoas;

    if (sexo == NULL) // verificando se a alocaçao foi bem sucedida, se nao for o progama sera abortado,e a mensagem memoria insuficiente sera mostrada;
    {

        printf("memoria insuficiente");

        exit(1);
    }

    int *op_produto = (int *)malloc(pessoas * sizeof(int)); // alocando dinamicamente o vetor op_produto,com espaço definido pelo numero de pessoas;

    if (op_produto == NULL) // verificando se a alocaçao foi bem sucedida, se nao for o progama sera abortado,e a mensagem memoria insuficiente sera mostrada;;
    {

        printf("memoria insuficiente");

        exit(1);
    }

    for (count = 0; count < pessoas; count++) // estrutura de repeticao que vai ate o numero de pessoas;
    {

        printf("digite o seu sexo,use M para masculino e F para feminino\n"); // pedindo para o usuario digitar seu sexo;

        scanf(" %c", &sexo[count]); // lendo o caracter e armazenando em um espaço do vetor alocado;

        printf("digite 0 se nao gostou do produto e 1 se gostou\n"); // pedindo para o usuario digitar a opniao sobre o produto;

        scanf("%d", &op_produto[count]); // lendo o numero e armazenando em um espaço do vetor alocado;
    }
    for (count2 = 0; count2 < pessoas; count2++) // estrutura de repeticao que vai ate o numero de pessoas;
    {
        if ((sexo[count2] == 'M') && (op_produto[count2] == 1)) // verificando as pessoas do sexo masuclino que gostaram do produto,usamos o contador para acessar todas as pessoas do vetor e a opcao que escolheu;
        {

            soma_masculino++; // somando a quantidade de pessoas que foram selecionadas no if;
        }
        if ((sexo[count2] == 'F') && (op_produto[count2] == 0)) // verificando as pessoas do sexo feminino que nao gostaram do produto,usamos o contador para acessar todas as pessoas do vetor e a opcao que escolheu;
        {

            soma_feminino++; // somando a quantidade de pessoas que foram selecionadas no if;
        }
    }
    soma_masculino = ((soma_masculino * 100.0f) / pessoas); // fazendo o calculo da porcentagem de pessoas do sexo masculino que gostaram do produto;

    soma_feminino = ((soma_feminino * 100.0f) / pessoas); // fazendo o calculo da porcentagem de pessoas do sexo feminino que nao gostaram do produto;

    printf("a quantidade de pessoas do sexo masculino que gostaram do produto foi: %d%%\n", soma_masculino); // imprimindo essas porcentagens;

    printf("a quantidade de pessoas do sexo feminino que nao gostaram do produto foi: %d%%\n", soma_feminino);

    free(op_produto); // liberando o vetor op_produto da memoria;

    free(sexo); // liberando o vetor sexo da memoria;

    return (0);
}

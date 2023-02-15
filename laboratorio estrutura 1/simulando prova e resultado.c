// Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
// questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
// questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
// 10 alunos matriculados. Calcule e mostre:
// a) a nota obtida para cada aluno;
// b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.

#include <stdio.h>

#include <locale.h>

#include <stdio.h>

#define alunos 5

int main()
{

    setlocale(LC_ALL, "portuguese"); // comando para usar portugues no codigo;

    int n, contador, quant_alunos, soma = 0, media = 0, aprovados = 0; // declaracao e inicializacao das variaveis;

    printf("digite a quantidade de questoes da prova\n"); // pedindo e lendo o numero de questoes;

    scanf("%d", &n);

    int *gabarito = (int *)malloc(n * sizeof(int)); // alocando dinamicamente o vetor gabarito,com espaco referente ao numero de questoes;

    int *resposta = (int *)malloc(n * sizeof(int)); // alocando dinamicamente o vetor resposta,com espaco referente ao numero de questoes;

    if (resposta == NULL) // verificando se a alocacao foi bem sucedida, se nao for o progama ira abortar;
    {

        printf("memória insuficiente para alocação\n");

        exit(1);
    }

    if (gabarito == NULL) // verificando se a alocacao foi bem sucedida, se nao for o progama ira abortar;
    {

        printf("memória insuficiente para alocação\n");

        exit(1);
    }

    printf("digite o gabarito das questoes\n"); // pedindo ao usuario o gabarito;

    for (contador = 0; contador < n; contador++) // estrutura de repeticao indo ate o numero de questoes;
    {

        scanf("%d", &gabarito[contador]); // lendo o gabarito e armazenando em cada posicao do vetor gabarito ;
    }

    for (quant_alunos = 0; quant_alunos < alunos; quant_alunos++) // estrutura de repeticao para preencher os dados do aluno;
    {

        soma = 0; // resetando o valor da variavel soma para que as respostas do novo aluno sejam registradas;

        printf("resposta do %dº aluno\n", quant_alunos + 1);

        for (contador = 0; contador < n; contador++) // estrutura de repeticao para ler as respostas dos alunos em cada questao;
        {

            printf("digite a resposta da questao %d:\n", contador + 1); // pedindo e lendo as questoes,as respostas serao armazenadas em cada posicao do vetor resposta;

            scanf("%d", &resposta[contador]);

            if (gabarito[contador] == resposta[contador]) // verificando se as respostas de cada questao dos alunos esta igual ao do gabarito, se estiver siginifica que a resposta ta certa;
            {

                soma += 10; // somando 10 pontos para cada questao certa;
            }
        }

        media = soma / n; // calculando a media do aluno;

        if (media >= 6) // verificando se o aluno foi aprovado;
        {

            aprovados++; // somando a quantidade de pessoas que foram aprovadas;
        }

        printf("sua nota foi: %d\n\n", media); // mostrando a nota dos alunos;
    }

    printf("porcentagem de alunos aprovados foi:%d %%\n", (aprovados * 100) / alunos); // mostrando a porcentagem de alunos que foram aprovados;

    free(gabarito); // liberando o vetor gabarito da memoria;

    free(resposta); // liberando o vetor resposta da memoria;

    return (0);
}

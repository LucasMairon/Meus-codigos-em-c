#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 2
#define MAX_VAGAS 3
#define q_notas 3

struct aluno
{
    int mat;
    char nome[81];
    float notas[q_notas];
    float media;
};
typedef struct aluno Aluno;

struct turma
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma;
Turma *turmas[MAX_TURMAS];

Turma *cria_turma(char id);
void matricula_aluno(Turma *turma, int mat, char *nome);
void lanca_notas(Turma *turma);
void imprime_alunos(Turma *turma);
void imprime_turmas(Turma **turmas, int n);
Turma *procura_turma(Turma **turmas, int n, char id);

int main()
{
    int opcao, i = 0, aloc, mat;
    char id, nome[81];

    Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
    if (turmas == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    Turma *pturmas = (Turma *)malloc(sizeof(Turma));
    if (pturmas == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas\n Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula,lancamento de notas e listagem de alunos.\nAutor: Lucas Mairon\t Versao: 1.0\n");
    do
    {
        printf("\nMENU:\n");
        printf("1 - Criar turma\n");
        printf("2 - Listar turmas\n");
        printf("3 - Matricular aluno\n");
        printf("4 - Lancar notas\n");
        printf("5 - Listar alunos\n");
        printf("6 - Sair\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            if (i != MAX_TURMAS)
            {
                printf("Criando nova turma...\n");
                printf("digite um id: ");
                scanf(" %c", &id);
                turmas[i] = cria_turma(id);

                i++;
            }
            else
            {
                printf("Maximo de turmas criadas,por favor tente outra opcao\n");
            }
            break;
        case 2:
            printf("Listando turmas...\n");
            imprime_turmas(turmas, i);

            break;
        case 3:
            printf("Matriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf(" %c");
            pturmas = procura_turma(turmas, i, id);
            if (pturmas == NULL)
            {
                printf("Turma nao encontrada\n");
            }
            else
            {
                if (pturmas->vagas > 0)
                {
                    printf("digite a matricula: ");
                    scanf("%d", &mat);
                    printf("digite o nome: ");
                    scanf(" %[^\n]s", nome);
                    matricula_aluno(pturmas, mat, &nome);
                }
                else
                {
                    printf("sem vagas disponiveis\n");
                }
            }

            break;
        case 4:
            printf("Lancando notas...\n");
            printf("digite o id da turma: ");
            scanf(" %c", &id);
            pturmas = procura_turma(turmas, i, id);
            if (pturmas == NULL)
            {
                printf("Turma nao encontrada\n");
            }
            else
            {
                lanca_notas(pturmas);
            }

            break;
        case 5:
            printf("Listando alunos...\n");
            printf("digite o id da turma: ");
            scanf(" %c", &id);
            if (pturmas == NULL)
            {
                printf("Turma nao encontrada\n");
            }
            else
            {
                void imprime_alunos(pturmas);
            }

            break;
        case 6:
            printf("obrigado por usar esse progama!");

            break;
        default:
            printf("opcao invalida,por favor digite um numero de 1 a 6");

            break;
        }

    } while (opcao != 6);
    for (aloc = 0; aloc < MAX_TURMAS; aloc++)
    {
        free(turmas[aloc]->alunos[aloc]);
    }
    free(turmas);
}
Turma *cria_turma(char id)
{
    Turma *n_turmas = (Turma *)malloc(sizeof(Turma));
    int i;
    n_turmas->id = id;
    n_turmas->vagas = MAX_VAGAS;
    for (i = 0; i < MAX_TURMAS; i++)
    {
        n_turmas->alunos[i] = NULL;
    }
    printf("Turma %c criada com sucesso\n", id);
    return (n_turmas);
}

void imprime_turmas(Turma **turmas, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
    }
}
Turma *procura_turma(Turma **turmas, int n, char id)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (turmas[i]->id == id)
        {
            return (turmas[i]);
            break;
        }
        else
        {

            return (NULL);
            break;
        }
    }
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    int i, j;
    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno));
    alunos->mat = mat;
    strcpy(alunos->nome, nome);
    for (i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] == NULL)
        {
            turma->alunos[i] = alunos;
            for (j = 0; j < q_notas; j++)
            {
                turma->alunos[i]->notas[i] = 0;
            }
            printf("Aluno matriculado com sucesso!");
            break;
        }
    }
    turma->vagas = turma->vagas - 1;
}
void lanca_notas(Turma *turma)
{
    int i, n;
    float somanotas;
    for (i = 0; i < MAX_VAGAS; i++)
    {
       

        if (turma->alunos[i] != NULL)
        {
             printf("Matricula: %d\tAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (n = 0; n < q_notas; n++)
            {
                printf("digite a nota %d: ", n + 1);
                scanf("%f", &turma->alunos[i]->notas[n]);
            }
        }
    }
    printf("notas lancadas com sucesso\n");
    for (i = 0; i < MAX_VAGAS; i++)
    {
        somanotas = 0;
        if (turma->alunos[i] != NULL)
        {
            for (n = 0; n < q_notas; n++)
            {
                somanotas = somanotas + turma->alunos[i]->notas[n];
            }
        }
        turma->alunos[i]->media = somanotas;
    }
    
}
void imprime_alunos(Turma *turma)
{
    int i;
    for (i = 0; i < turma->vagas; i++)
    {
        printf("Matricula: %d\nNome: %s\nMedia: %f", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
    }
}

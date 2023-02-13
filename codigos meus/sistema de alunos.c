#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGAS 5

#define MAX_TURMAS 3

struct aluno
{
  int mat;
  char nome[81];
  float notas[3];
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

Turma *cria_turma(char id);

void matricula_aluno(Turma *turma, int mat, char *nome);

void lanca_notas(Turma *turma);

void imprime_alunos(Turma *turma);

void imprime_turmas(Turma **turmas, int n);

Turma *procura_turma(Turma **turmas, int n, char id);

int main()
{
  int decisao, i = 0, cont, vagas;
  char id;
  Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));

  printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
  printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.");
  printf("Autor: Ada Lovelace \t Versao: 1.0");
  do
  {
    printf("MENU:");
    printf("1 – Criar turma");
    printf("2 – Listar turmas");
    printf("3 – Matricular aluno");
    printf("4 – Lancar notas");
    printf("5 – Listar alunos");
    printf("6 – Sair");
    printf("Digite sua opcao:");
    scanf("%d", &decisao);

    switch (decisao)
    {
    case 1:

      if (i < MAX_TURMAS)
      {
        printf("criando nova turma...");
        printf("digite um id:");
        scanf("%c", turmas[i]->id);
        turmas[i] = cria_turma(turma->id);

        printf("turma %c criada com sucesso",
               turmas[i]->id);
      }
      else
      {
        printf("sem espaço para armazenar mais turmas\n");
      }

      break;
    case 2:
      break;
    case 3:
      printf("matriculando aluno...");
      printf("digite o id da turma: ");
      scanf("%c", &id);

      for (cont = 0; cont < MAX_TURMAS; cont++)
      {
        if (turmas[cont]->id == id)
        {
          printf("digite a matricula: ");
          scanf("%d", turmas[i]->alunos[i]->mat);
          printf("digite o nome: ");
          scanf("%[^\n]s", turmas[i]->alunos[i]->nome);

          for (vagas = 0; vagas < MAX_VAGAS; vagas++)
          {
            if (turmas[cont]->alunos[vagas] == NULL)
            {
              printf("aluno matriculado com sucesso");
              matricula_aluno(turmas[i], turmas[i]->alunos[i]->mat, turmas[i]->alunos[i]->nome);
            }
            else
            {
              printf("sem vagas disponiveis na turma");
            }
          }
        }

        else
        {
          printf("turma inexistente");
        }
      }

      ;

      break;
    case 4:
      printf("lancando notas...\n");
      printf("digite o id da turma: ");
      scanf("");
      break;
    case 5:
      break;
    case 6:
      break;
    default:
      break;
    }
    i++;
  } while (decisao != 6);

  return 0;
}

Turma *cria_turma(char id)
{
  Turma *n_turmas;
  int i;
  n_turmas->id = id;
  n_turmas->vagas = NULL;
  for (i = 0; i < MAX_VAGAS; i++)
  {

    n_turmas->alunos[i] = NULL;
  }

  return (n_turmas);
}
void matricula_aluno(Turma *turma, int mat, char *nome)
{
}

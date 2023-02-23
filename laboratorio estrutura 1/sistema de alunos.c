// Escreva um programa em C que manipula dados dos alunos da disciplina de
// Algoritmos e Estruturas de Dados I da UFERSA Pau dos Ferros. Seu programa deverá utilizar os
// tipos estruturados e o vetor definidos a seguir:
// struct aluno {
// int mat;
// char nome[81];
// float notas[3];
// float media;
// };
// typedef struct aluno Aluno;
// struct turma {
// char id; /* caractere que identifica a turma, por exemplo, A ou B */
// int vagas; /* números de vagas disponíveis para fechar a turma */
// Aluno* alunos[MAX_VAGAS];
// };
// typedef struct turma Turma;
// Turma* turmas[MAX_TURMAS];
// Deve-se levar em consideração que é ofertado um número máximo de turmas (definido pela
// constante simbólica MAX_TURMAS) e um número máximo de vagas para cada turma (definido
// pela constante simbólica MAX_VAGAS). Sabendo dessas informações, faça o que se pede nos
// itens a seguir:
// a) Implemente uma função que cria uma turma, fornecendo-lhe um identificador.
// Essa função deve ser responsável por indicar que a turma não tem alunos
// matriculados, atribuindo a constante NULL a cada um dos elementos do vetor de
// ponteiros.
// Protótipo: Turma* cria_turma(char id);
// b) Implemente uma função que recebe os dados de um aluno e o matricula em uma
// das turmas, caso haja vaga disponível. Inicialize suas notas com zero.
// Protótipo: void matricula_aluno(Turma* turma, int mat, char* nome);
// c) Implemente uma função que lança as notas e calcula a média dos alunos de uma
// determinada turma.
// Protótipo: void lanca_notas(Turma* turma);
// d) Implemente uma função que imprime os dados de todos os alunos de uma turma.
// Protótipo: void imprime_alunos(Turma* turma);
// e) Implemente uma função que imprime os dados de todas as turmas.
// Protótipo: void imprime_turmas(Turma** turmas, int n);
// f) Implemente uma função para procurar uma turma.
// Protótipo: Turma* procura_turma(Turma** turmas, int n, char id);

#include <stdio.h>

#include <stdlib.h> //incluindo a biblioteca para fazer alocacao dinamica;

#include <string.h> //incluindo a biblioteca para trabalhar com strings;

#define MAX_VAGAS 3 // definindo a constante de vagas;

#define MAX_TURMAS 2 // definindo a constante de turmas;

#define qnotas 3

struct aluno // criando a struct aluno,com os elementos mat,nome,notas e media;
{
  int mat;
  char nome[81];
  float notas[qnotas];
  float media;
};
typedef struct aluno Aluno; // renomenado a struct para Aluno;

struct turma // criando a struct turma, seus elementos sao id,vagas e um vetor do tipo Aluno;
{
  char id;
  int vagas;
  Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma; // renomeando essa struct para Turma;

Turma *cria_turma(char id); // criando a funcao que sera usada cria_turma que é do tipo Turma;

void matricula_aluno(Turma *turma, int mat, char *nome); // criando a funcao que sera usada matricula_aluno, que é do tipo void;

void lanca_notas(Turma *turma); // criando a funcao que sera usada lanca_notas, que é do tipo void;

void imprime_alunos(Turma *turma); // criando a funcao que sera usada imprime_alunos, que é do tipo void;

void imprime_turmas(Turma **turmas, int n); // criando a funcao que sera usada imprime_turmas, que é do tipo void;

Turma *procura_turma(Turma **turmas, int n, char id); // criando a funcao que sera usada procura_turma, que é do tipo Turma;

int main()
{
  int decisao, i = 0, cont, vagas, aloc, mat, quant, alocaluno; // criando e inicializando as variaveis que serao necessarias;
  char id, nome[81];
  Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *)); // alocando a matriz turmas do tipo Turma com espaco referente a  cosntante MAX_TURMAS;
  Turma *pturma;                                                   // criando um ponteiro do tipo Turma;

  if (turmas == NULL) // verificando se a alocacao foi bem sucedida,se nao for o progama sera abortado;
  {

    printf("memoria insuficiente");
    exit(1);
  }

  printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n"); // apresentando o progama(segui o modelo que esta na questao);
  printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
  printf("Autor: Ada Lovelace \t Versao: 1.0\n");
  do // inicio da estrutura de repeticao;
  {
    printf("MENU:\n"); // mostrando o menu e as opcoes ao usuario para que ele escolha qual deseja relizar;
    printf("1 - Criar turma\n");
    printf("2 - Listar turmas\n");
    printf("3 - Matricular aluno\n");
    printf("4 - Lancar notas\n");
    printf("5 - Listar alunos\n");
    printf("6 - Sair\n");
    printf("Digite sua opcao:\n"); // pedindo para o usuario escolher;
    scanf("%d", &decisao);         // lendo o que o usuario informou e armazenando em decisao;

    switch (decisao) // verificando a variavel  decisao para utilizar case;
    {
    case 1: // verificando se o usuario digitou 1;

      if (i < MAX_TURMAS) // verificando se ainda ha espaco para criar novas turmas;
      {
        printf("criando nova turma...\n");
        printf("digite um id: "); // pedindo e lendo o id a turma ao usuario;
        scanf(" %c", &id);
        turmas[i] = cria_turma(id); // aramazenando no elemento i de turma o retorno da funcao cria_turma e passando como parametro nessa funcao o id que o usuario informou;
        i++;                        // somando +1 a variavel i cada vez que o laco de repeticao repetir;
      }
      else // se nao houver espaco para mais turmas a mensagem abaixo sera exibida;
      {
        printf("\nsem espaço para armazenar mais turmas\n\n");
      }

      break; // comando para finalizar o case;

    case 2: // verificando se o usuario digitou 1;

      printf("listando turmas...\n");
      imprime_turmas(turmas, i); // passando a matriz turmas e a variavel i como parametro para a funcao imprime_turmas;

      break; // comando para finalizar o case;
    case 3:  // verificando se o usuario digitou 3;

      for (cont = 0; cont < i; cont++) // estrutura de repeticao que vai de 0 ate i;
      {

        if (turmas[cont]->vagas != 0) // verificando se ainda ha vagas disponiveis para preencher;
        {

          printf("matriculando aluno...\n");
          printf("digite o id da turma: ");      // pedindo o id da turma;
          scanf(" %c", &id);                     // lendo o id e armazenando na variavel id;
          pturma = procura_turma(turmas, i, id); // armazenando o resultado da funcao procura_turma com os parametros sendo turma,i e id,que vai ser a turma que o usuario deseja modificar;

          if (pturma == NULL) // verificando se a funcao procura_turma retornou um null;
          {
            printf("id nao encontrado"); // dizendo ao usuario que se pturma for null entao o id nao foi encontrado;
            break;                       // comando para finalizar o laco de repeticao for,a intencao e fazer com que a mensagem nao seja mostrada ao usuario varias vezes,no caso de 2 ou mais alunos;
          }
          else // verificando se a funcao procura_turma retornou outro numero;
          {
            printf("digite a matricula: "); // pedindo e lendo a matricula do usuario,que esta sendo armazenada na variavel mat;
            scanf("%d", &mat);
            printf("digite o nome: "); // pedindo e lendo o nome do usuario,que esta sendo armazenado na variavel nome;
            scanf(" %[^\n]s", nome);
            matricula_aluno(pturma, mat, nome); // chamando a funcao matricula e passando os parametros pturma,mat e nome,pturma sendo a turma que o usuario deseja modificar;
            break;                              // comando para finalizar o laco de repeticao for,a intencao e fazer com que os dados nao sejam pedidos todos de uma vez,no caso de 2 ou mais alunos;
          }
        }
        else // verificando se as vagas foram totalmente preenchidas;
        {
          printf("turma cheia"); // imprimindo a mensagem para o usuario saber que nao ha mais vagas;
          break;                 // comando para finalizar o laco de repeticao for,a intencao e fazer com que a mensagem nao seja mostrada ao usuario varias vezes,no caso de 2 ou mais alunos;
        }
      }
      if (i == 0) // verificando se o progama esta na primeira execucao,ou seja,i sendo igual a 0;
      {
        printf("nenhuma turma cadastrada ainda\n"); // mostrando ao usuario que ainda nao ha turmas cadastradas;
      }

      break; // comando para finalizar o case;

    case 4: // verificando se o usuario digitou 4;
      printf("lancando notas...\n");
      printf("digite o id da turma: ");      // pedindo o id da turma;
      scanf(" %c", &id);                     // lendo o id e armazenando na variavel id;
      pturma = procura_turma(turmas, i, id); // armazenando o resultado da funcao procura_turma com os parametros sendo turma,i e id,que vai ser a turma que o usuario deseja modificar;

      if (pturma == NULL) // verificando se a funcao procura_turma retornou um null;
      {
        printf("turma inexistente\n"); // dizendo ao usuario que se pturma for null entao a turma nao foi encontrada;
      }
      else // verificando se a funcao procura_turma retornou outro numero;
      {
        lanca_notas(pturma); // chamando a funcao lanca_notas e passando pturma como parametro,pturma sendo a turma que o usuario deseja modificar;
      }

      break; // comando para finalizar o case;

    case 5: // verificando se o usuario digitou 5;

      printf("listando alunos...\n");
      printf("digite o id da turma: ");      // pedindo o id da turma;
      scanf(" %c", &id);                     // lendo o id e armazenando na variavel id;
      pturma = procura_turma(turmas, i, id); // armazenando o resultado da funcao procura_turma com os parametros sendo turma,i e id,que vai ser a turma que o usuario deseja modificar;

      if (pturma == NULL) // verificando se a funcao procura_turma retornou um null;
      {
        printf("id nao encontrado"); // dizendo ao usuario que se pturma for null entao o id nao foi encontrado;
      }
      else // verificando se a funcao procura_turma retornou outro numero;
      {
        imprime_alunos(pturma); // chamando a funcao imprime_alunos e passando pturma como parametro,pturma sendo a turma que o usuario deseja modificar;
      }

      break; // comando para finalizar o case;

    case 6: // verificando se o usuario digitou 6;

      printf("Obrigado por usar este programa"); // finalizando o progama com uma mensagem

      break; // comando para finalizar o case;

    default: // verificando se o usuario digitou qualquer outro numero;

      printf("opção invalida\n"); // mostrando ao usuario opcao ivalida;

      break; // comando para finalizar o default;
    }

  } while (decisao != 6); // finalizando a estrutura de repeticao, sera finalizada quando a decisao do usuario for 6;

  for (aloc = 0; aloc < MAX_TURMAS; aloc++) // estrutura de repeticao que vai de 0 ate o maximo de turmas;
  {

    for (alocaluno = 0; alocaluno < MAX_TURMAS; alocaluno++) // estrutura de repeticao que vai de 0 ate o maximo de turmas;
    {

      free(turmas[aloc]->alunos[alocaluno]); // liberando cada elemento da matriz turmas e do vetor alunos;
    }
  }

  free(turmas); // liberando da memoria a matriz turmas em si;

  return 0;
}

Turma *cria_turma(char id)
{ // inicializando a funcao cria_turma,tendo o id como parametro;

  Turma *n_turmas = (Turma *)malloc(MAX_VAGAS * sizeof(Turma)); // alocando dinamicamente n_turmas do tipo Turma, com espaco referente ao maximo de vagas;
  int i;                                                        // declarando a variavel i;
  n_turmas->id = id;                                            // preenchendo o id da nova turma com o id informado pelo usuario;
  n_turmas->vagas = MAX_VAGAS;                                  // preenchendo as vagas da nova turma com a cosntante MAX_VAGAS;

  for (i = 0; i < MAX_VAGAS; i++) // estrutura de repeticao que vai de zero ate a quantidade de vagas;
  {
    n_turmas->alunos[i] = NULL; // preenchendo os alunos da nova turma com NULL;
  }
  printf("turma %c criada com sucesso\n", n_turmas->id); // informando ao usuario que a nova turma foi criada;

  return (n_turmas); // retornando a variavel n_turmas;
}
void matricula_aluno(Turma *turma, int mat, char *nome) // inicializando a funcao matricula_aluno,seus parametros sao a o ponteiro turma,a matricula e o nome;
{

  Aluno *alunos = (Aluno *)malloc(sizeof(Aluno));
  if (alunos == NULL)
  {
    printf("memoria insuficente ");
    exit(1);
  }

  int c;
  strcpy(alunos->nome, nome);
  alunos->mat = mat;

  for (c = 0; c < qnotas; c++)
  {
    alunos->notas[c] = 0;
  }

  for (c = 0; c < MAX_VAGAS; c++)
  {
    if (turma->alunos[c] == NULL)
    {
      turma->alunos[c] = alunos;
      break;
    }

    turma->vagas -= 1;
  }
  printf("Aluno matriculado com sucesso!\n");
}
void lanca_notas(Turma *turma)
{

  int i, n, somamedia;
  for (i = 0; i < MAX_VAGAS; i++)
  {

    if (turma->alunos[i] != NULL)
    {
      printf("matricula: %d\t aluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
      for (n = 0; n < qnotas; n++)
      {
        printf("digite a nota %d: ", n + 1);
        scanf("%f", &turma->alunos[i]->notas[n]);
      }

      printf("notas lancandas com sucesso\n");
    }
  }

  for (i = 0; i < MAX_VAGAS; i++)
  {
    somamedia = 0;
    if (turma->alunos[i] != NULL)
    {
      for (n = 0; n < qnotas; n++)
      {
        somamedia += turma->alunos[i]->notas[n];
      }

      turma->alunos[i]->media = (somamedia / qnotas);
    }
  }
}

void imprime_alunos(Turma *turma)
{
  int i, n;
  for (i = 0; i < MAX_VAGAS; i++)
  {

    if (turma->alunos[i] != NULL)
    {
      printf("matricula: %d\nnome: %s\nmedia: %.2f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
    }
  }
}
void imprime_turmas(Turma **turmas, int n) // inicializando a funcao imprime_turmas,seus parametros sao um ponteiro para ponteiro do tipo Turma e um numero n;
{
  int i, vd, index; // criando as variaveis que serao usadas;

  for (i = 0; i < n; i++) // estrutura de repeticao que vai de 0 ate n;
  {
    vd = 0;                                     // inicializando vd com 0;
    for (index = 0; index < MAX_VAGAS; index++) // estrutura de repeticao que vai de 0 ate o maximo de vagas;
    {
      if (turmas[i]->alunos[index] == NULL) // verificando se há alunos em cada turma;
      {
        vd++; // somando a quantidade de vagas disponiveis;
      }
    }
    turmas[i]->vagas = vd;// guardando a quantidade de vagas em cada elemento de turmas na variavel vagas;
    printf("Turma %c - vagas disponiveis: %d\n", turmas[i]->id, turmas[i]->vagas); // imprimindo o id de cada turma e a quantidade de vagas disponiveis;
  }
}

Turma *procura_turma(Turma **turmas, int n, char id)
{
  int cont, vagas;
  for (cont = 0; cont < n; cont++)
  {

    if (turmas[cont]->id == id)
    {
      return (turmas[cont]);
    }
  }
  return (NULL);
}

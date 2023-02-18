#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_VAGAS 3

#define MAX_TURMAS 2

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
  int decisao, i = 0, cont, vagas,aloc;
  char id;
  Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
  
  if(turmas==NULL){

      printf("memoria insuficiente");
      exit(1);
  }

  printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
  printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
  printf("Autor: Ada Lovelace \t Versao: 1.0\n");
  do
  {
    printf("MENU:\n");
    printf("1 - Criar turma\n");
    printf("2 - Listar turmas\n");
    printf("3 - Matricular aluno\n");
    printf("4 - Lancar notas\n");
    printf("5 - Listar alunos\n");
    printf("6 - Sair\n");
    printf("Digite sua opcao:\n");
    scanf("%d", &decisao);

    switch (decisao)
    {
    case 1:

      if (i < MAX_TURMAS)
      {
        printf("criando nova turma...\n");
        printf("digite um id:");
        scanf(" %c", &id);
        turmas[i]= cria_turma(id);
        
      }
      else
      {
        printf("\nsem espaço para armazenar mais turmas\n\n");
      }

      break;
    case 2:
    printf("listando turmas...\n");
        imprime_turmas(turmas,i);








      break;
    case 3:
      printf("matriculando aluno...\n");
      printf("digite o id da turma: ");
      scanf(" %c", &id);

      for (cont = 0; cont < MAX_TURMAS; cont++)
      {
        if (turmas[cont]->id == id)
        {
          printf("digite a matricula: ");
          scanf("%d", &turmas[i]->alunos[cont]->mat);
          printf("digite o nome: ");
          scanf(" %[^\n]s", turmas[i]->alunos[cont]->nome);
          matricula_aluno(turmas,turmas[i]->alunos[cont]->mat,turmas[i]->alunos[cont]->nome);

          for (vagas = 0; vagas < MAX_VAGAS; vagas++)
          {
            if (turmas[i]->alunos[vagas] == NULL)
            {
              printf("aluno matriculado com sucesso");
              // matricula_aluno(turmas[i], turmas[i]->alunos[i]->mat, turmas[i]->alunos[i]->nome);
            }
            else
            {
              printf("sem vagas disponiveis na turma");
            }
          }
        }

        else
        {
          printf("turma inexistente\n");
        }
      }
      
        

      ;

      break;
    case 4:
      lanca_notas(turmas);
      break;
    case 5:
     imprime_alunos(turmas);
      break;
    case 6:
      break;
    default:
      break;
    }
    i++;
  } while (decisao != 6);



for(aloc=0;aloc<MAX_TURMAS;aloc++){
       free(turmas[aloc]);
  }
  free(turmas);





    

  return 0;
}

Turma *cria_turma(char id)
{
  Turma *n_turmas=(Turma*) malloc(MAX_VAGAS*sizeof(Turma));
  int i;
  n_turmas->id = id;
  n_turmas->vagas = MAX_VAGAS;
  
  for (i = 0; i < MAX_VAGAS; i++)
  {
      n_turmas->alunos[i]= NULL;
  }
  printf("turma %c criada com sucesso\n",n_turmas->id);


  return (n_turmas);
}
void matricula_aluno(Turma *turma, int mat, char *nome)
{
  
    int c = 0,i=0;
    for(i=0;i<MAX_TURMAS;i++){
      // if(turma->alunos[i]=NULL){
      //   turma->alunos[i]->notas[i]=0;
      //   turma->alunos[i]->mat=mat;
      //    turma->alunos[i]->nome = nome;
      // }
      for(c=0;c<MAX_VAGAS;c++){
       if(turma[i].alunos[c]=NULL){
        turma[i].alunos[c]->notas[i]=0;
        turma[i].alunos[c]->mat=mat;
         turma[i].alunos[c]->nome = nome;
      }
      }
    }





}

void lanca_notas(Turma *turma){
int i;
char id;
printf("lancando notas...");
printf("digite o id da turma");
scanf(" %c",&id);
for(i=0;i<MAX_TURMAS;i++){
if (turma[i].id == id){
    printf("matricula: %d\t Aluno: %s",i+1,turma[i].alunos[i]->nome);
    printf("digite a nota %d",i+1);
    scanf("%f",&turma[i].alunos[i]->notas[i]);


}



}



}

void imprime_alunos(Turma *turma){
int i,soma[MAX_TURMAS];
char id;

printf("Listando alunos...");
printf("digite o id da turma: ");
scanf(" %c",&id);
for(i=0;i<MAX_TURMAS;i++){
if (turma[i].id == id){
    printf("matricula: %d\n nome: %s",i+1,turma[i].alunos[i]->nome);
    printf("digite a nota %d",i+1);
    scanf("%f",&turma[i].alunos[i]->notas[i]);
    soma[i]+=(*turma[i].alunos[i]->notas);

}


}
}
void imprime_turmas(Turma **turmas, int n){
int i,vd,index;

  for(i=0;i<n;i++){
    vd = 0;
    for(index=0;index<=MAX_VAGAS;index++){
    if(turmas[i]->alunos[index] == NULL){
        vd++;
    }
  }
  turmas[i]->vagas=vd;
  printf("Turma %c vagas disponiveis: %d\n",turmas[i]->id,turmas[i]->vagas);
}



}

Turma *procura_turma(Turma **turmas, int n, char id){





}
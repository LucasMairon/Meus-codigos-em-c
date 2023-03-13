#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct aluno{

    char nome[50];
    float nota;

}Aluno;

Aluno* aluno_cria(char* nome, float nota){
    Aluno *novo_aluno=(Aluno*) malloc(sizeof(Aluno));
    strcpy(novo_aluno->nome,nome);
    novo_aluno->nota=nota;


}

void aluno_libera(Aluno* a){
    free(a);


}
void aluno_imprime(Aluno* a){
    printf("aluno: %s, nota: %f",a->nome,a->nota);

}
void aluno_ordena(int n, Aluno** v){
int i;



}

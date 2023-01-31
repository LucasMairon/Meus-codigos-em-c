#include<stdio.h>

#include<locale.h>

#include<stdio.h>

#define alunos 5

int main(){

 setlocale(LC_ALL,"portuguese");

 int n,contador,quant_alunos,soma=0,media=0,aprovados=0;

 printf("digite a quantidade de questoes da prova\n");

 scanf("%d",&n);

 int *gabarito=(int*)malloc(n*sizeof(int));

 int *resposta=(int*)malloc(n*sizeof(int));

 if(resposta == NULL){

     printf("memória insuficiente para alocação\n");

     exit(1);
 }

 if(gabarito == NULL){

     printf("memória insuficiente para alocação\n");

     exit(1);
 }

 printf("digite o gabarito das questoes\n");

 for(contador=0;contador<n;contador++){

     scanf("%d",&gabarito[contador]);

 }

 for(quant_alunos=0;quant_alunos<alunos ; quant_alunos++){
     soma=0;

     printf("resposta do %dº aluno\n",quant_alunos+1);

for(contador=0;contador<n;contador++){

    printf("digite a resposta da questao %d:\n",contador+1);

     scanf("%d",&resposta[contador]);

if(gabarito[contador] == resposta[contador]){

    soma+=10;
}

 }
media=soma/n;

if(media>=6){

    aprovados++;
}

printf("sua nota foi: %d\n\n",media);

 }
 
printf("porcentagem de alunos aprovados foi:%d %%\n",(aprovados*100)/alunos);


    free(gabarito);

    free(resposta);

    return(0);
}
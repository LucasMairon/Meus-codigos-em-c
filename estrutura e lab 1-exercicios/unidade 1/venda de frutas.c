#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(){

int quant_frutas,i;

printf("digite a quantidade de frutas que pretende comprar:\n");

scanf("%d",&quant_frutas);

char **nome= (char**) malloc(quant_frutas * sizeof(char*));

if (nome==NULL){
    printf("memoria insuficiente");
    exit(1);
}

 for(i=0;i<quant_frutas;i++){
     nome[i]=(char*) malloc(100*sizeof(char));
 }

 float *preco = (float*) malloc(quant_frutas * sizeof(float));

 if(preco==NULL){
     printf("memoria insuficiente");
     exit(1);
 }

 printf("digite o nome das frutas e o preco:\n");

 for (i = 0; i < quant_frutas; i++) {
   scanf(" %[^\n]s", nome[i]);
    scanf("%f",&preco[i]);
 }

for (i = 0; i < quant_frutas; i++) {
   nome[i]=(char*)realloc(nome[i],(strlen(nome[i]+1)*sizeof(char)));
 }

 for (i = 0; i < quant_frutas; i++) {
   printf("nome das frutas: %s\t",nome[i]);
    printf("preco das frutas: %.1f\n",preco[i]);
 }

 for (i = 0; i < quant_frutas; i++) {
   free(nome[i]);
 }

 free(nome);

 free(preco);

    return 0;
}

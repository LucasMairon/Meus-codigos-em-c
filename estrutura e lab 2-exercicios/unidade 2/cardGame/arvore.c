#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"

typedef struct no No;
struct no{
    Card* valor;
    int altura;
    No *esq;
    No *dir;
};


No* insere_card(No* raiz,Card* dados){

    if(raiz == NULL){

        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->valor = dados;
        novoNo->dir = novoNo->esq = NULL;
        novoNo->altura = 1;
        return novoNo;

    }
    else if(hash_card(dados) < hash_card(raiz->valor)){
        raiz->esq = insere_card(raiz->esq,dados);
    }else if(hash_card(dados) > hash_card(raiz->valor)){
        raiz->dir = insere_card(raiz->dir,dados);
    }else{
        printf("este valor ja esta na arvore");
      
    }
  return raiz;

}



void imprimeArvore(No* raiz){
  
    if(raiz != NULL){

        imprimeArvore(raiz->esq);
        imprime_cards(raiz->valor);
        imprimeArvore(raiz->dir);

    }

}


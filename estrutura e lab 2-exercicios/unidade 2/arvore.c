#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"

typedef struct no No;
struct no{
    int valor;
    int altura;
    No *esq;
    No *dir;
};

No* insere_elemento(No* raiz,int dados){
    if(raiz == NULL){
        No *novoNo = (No*)malloc(sizeof(No));
        novoNo->valor = dados;
        novoNo->dir = novoNo->esq = NULL;
        //novoNo->altura = 1;
        return novoNo;
    }
    else if(dados < raiz->valor){
        raiz->esq = insere_elemento(raiz->esq,dados);
    }else if(dados > raiz->valor){
        raiz->dir = insere_elemento(raiz->dir,dados);
    }else{
        printf("este valor ja esta na arvore");
    }
    raiz->altura = altura(raiz) + 1;
}

int altura(No* raiz){
    int alturaEsq,alturaDir;
    if(raiz == NULL){
        return -1;
    }
    alturaEsq = altura(raiz->esq);
    alturaDir = altura(raiz->dir);
    return (alturaEsq > alturaDir)? alturaEsq + 1: alturaDir + 1;
    
}

No* remove_elemento(No* raiz, int dados){
    if(raiz == NULL){
        printf("nao ha valores na arvore para remover");
    }
    else if(dados < raiz->valor){
        raiz->esq = remove_elemento(raiz->esq,dados);
    }else if(dados > raiz->valor){
        raiz->dir = remove_elemento(raiz->dir,dados);
    }else{

        if(raiz->esq == 0){
            return raiz->dir;
        }else if(raiz->dir == 0){
            return raiz->esq;
        }

    }

}
void imprimeArvore(No* raiz){
    //imprimindo os elementos da arvore em in order
    if(raiz != NULL){
        imprimeArvore(raiz->esq);
        printf(" %d ",raiz->valor);
        imprimeArvore(raiz->dir);
    }
}
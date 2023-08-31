#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"

// typedef struct no No;
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
        novoNo->altura = 1;
        return novoNo;
    }
    else if(dados < raiz->valor){
        raiz->esq = insere_elemento(raiz->esq,dados);
    }else if(dados > raiz->valor){
        raiz->dir = insere_elemento(raiz->dir,dados);
    }else{
        printf("este valor ja esta na arvore");
    }
    raiz->altura = alturaDaArvore(raiz) + 1;
}

int alturaDaArvore(No* raiz){
    int alturaEsq,alturaDir;
    if(raiz == NULL){
        return -1;
    }
    alturaEsq = alturaDaArvore(raiz->esq);
    alturaDir = alturaDaArvore(raiz->dir);
    return max(alturaDir,alturaEsq) + 1;
    
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

        if(raiz->esq == NULL){
            return raiz->dir;
        }else if(raiz->dir == NULL){
            return raiz->esq;
        }
        raiz->valor = sucessor(raiz->dir);
        raiz->dir = remove_elemento(raiz->dir,raiz->valor);

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

int alturaDoNo(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    return raiz->altura;
}

int sucessor(No* raiz){
    int s = raiz->valor;
    while(raiz->esq != NULL){
        s = raiz->esq->valor;
        raiz = raiz->esq;
    }
    raiz->esq = NULL;
    return s;
    
   
}
int max(int a,int b){
    return (a > b) ? a : b;
}

int balanceamento(No* raiz){
    if(raiz == NULL){
        return 0;
    }

    return alturaDaArvore(raiz->esq) - alturaDaArvore(raiz->dir);
}

int verificaBalanceamento(No* raiz){
    if(raiz == NULL){
        return 1;
    }

    int alturaEsq,alturaDir;
    alturaEsq = alturaDaArvore(raiz->esq);
    alturaDir = alturaDaArvore(raiz->dir);

    int balanceamento = (alturaEsq > alturaDir) ? alturaEsq - alturaDir : alturaDir - alturaEsq;

    if(balanceamento > 1){
        return 0;
    }
}

No* rotacaoDir(No* raiz){
    No* novoNo = raiz->esq;
    raiz->esq = novoNo->dir;
    novoNo->dir = raiz;

    raiz->altura = max(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
    novoNo->altura = max(alturaDoNo(novoNo->esq), alturaDoNo(novoNo->dir)) + 1;
    return novoNo;
}

No* rotacaoEsq(No* raiz){
    No* novoNo = raiz->dir;
    raiz->esq = novoNo->esq;
    novoNo->dir = raiz;

    raiz->altura = max(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
    novoNo->altura = max(alturaDoNo(novoNo->esq), alturaDoNo(novoNo->dir)) + 1;
    return novoNo;
}

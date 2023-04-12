#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

typedef struct lista Lista;
struct lista{
    int info;
    struct lista *prox;
};

Lista *lst_cria(void){
    return NULL;
}

Lista *lst_insere(Lista *l, int v){
    Lista *novo=(Lista*) malloc(sizeof(Lista));
    novo->info=v;
    novo->prox=l;
    return novo;
}

int lst_vazia(Lista *l){
    return(l==NULL);
}

void lst_imprime(Lista *l){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox){
        printf("info = %d\n",p->info);
    }

}

Lista *lst_busca(int elemento,Lista *l){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->info == elemento){
            return p;
        }
    }
    return NULL;
}

Lista *lst_retira(Lista *l,int v){
    Lista *ant = NULL;
    Lista *p=l;
    while(p->info!=v){

        if(p==NULL){
            return l;
        }

        ant=p;
        p=p->prox;
    }

    if(ant==NULL){
        l=p->prox;
    }
    else{
        ant->prox=p->prox;
    }
    free(p);
    return l;
}

void lst_libera(Lista *l){
    Lista *p=l;
    Lista *t;

    while(p!=NULL){
        t=p->prox;
        free(p);
        p=t;
    }

}

Lista *lst_insere_ordenada(Lista *l,int v){
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    while(p!=NULL && p->info<v){
        ant=p;
        p=p->prox;
    }

    novo=(Lista*) malloc(sizeof(Lista));
    novo->info=v;

    if(ant == NULL){
        novo->prox=l;
        l=novo;
    }
    else{
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    
    return l;
}

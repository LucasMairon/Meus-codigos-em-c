#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;
struct lista{
    ListaNo *prim;
};

struct listano{
    int info;
    ListaNo *prox;
};

Lista *cria_lst(void){
    Lista *l=(Lista*) malloc(sizeof(Lista));
    l->prim=NULL;
    return l;
}

void insere_lst(Lista *l, int v){
    ListaNo *novo=(ListaNo*) malloc(sizeof(ListaNo));
    novo->info=v;
    novo->prox=l->prim;
    l->prim=novo;
}
void lst_imprime(Lista *l){
    ListaNo *p;
    for(p=l->prim;p!=NULL;p=p->prox){
        printf("info = %d\n",p->info);

    }
}
int pertence(Lista *l,int v){
    ListaNo *p;
    for(p=l->prim;p!=NULL;p=p->prox){
        if(p->info==v){
            return 1;
        }

    }
    return 0;
}
void lst_insere_ordenado(Lista *l,int v){
    ListaNo *ant=NULL;
    ListaNo *p=l->prim;

    while(p!=NULL && p->info <v){
        ant=p;
        p=p->prox;
    }
    ListaNo *novo=(ListaNo*) malloc(sizeof(ListaNo));
    novo->info=v;
    if(ant==NULL){
        novo->prox=l->prim;
        l->prim=novo;
    }else{
        novo->prox=ant->prox;
        ant->prox=novo;
    }

}
int main(){
    Lista *l=cria_lst();
    lst_insere_ordenado(l,50);
    lst_insere_ordenado(l,45);
    lst_insere_ordenado(l,100);
    lst_insere_ordenado(l,2);
    lst_imprime(l);
    return 0;
}

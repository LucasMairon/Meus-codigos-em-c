#include<stdio.h>
#include"arvore.c"

int main(){
    No* raiz = NULL;
    raiz = insere_elemento(raiz,30);
    raiz = insere_elemento(raiz,5);
    raiz = insere_elemento(raiz,7);
    raiz = insere_elemento(raiz,4);
    raiz = insere_elemento(raiz,35);
    raiz = insere_elemento(raiz,40);
    raiz = insere_elemento(raiz,34);
    printf("sucessor da arvore: %d\n",sucessor(raiz->dir));

    
    imprimeArvore(raiz);

}
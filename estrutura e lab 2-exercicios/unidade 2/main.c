#include<stdio.h>
#include"arvore.c"

int main(){
    No* raiz = NULL;
    raiz = insere_elemento(raiz,4);
    raiz = insere_elemento(raiz,5);
    
    imprimeArvore(raiz);

}
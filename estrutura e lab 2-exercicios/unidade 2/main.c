#include<stdio.h>
#include"arvore.c"

int main(){
    No* raiz = NULL;
    raiz = insere_elemento(raiz,30);
    imprimeArvore(raiz);
    printf("\n\n");
    raiz = insere_elemento(raiz,5);
    imprimeArvore(raiz);
    printf("\n\n");
    raiz = insere_elemento(raiz,7);
    imprimeArvore(raiz);
    printf("\n\n");
    raiz = insere_elemento(raiz,4);
    imprimeArvore(raiz);
    printf("\n\n");
    raiz = insere_elemento(raiz,35);
    imprimeArvore(raiz);
    printf("\n\n");
    raiz = insere_elemento(raiz,40);
    imprimeArvore(raiz);
    printf("\n\n");
    raiz = insere_elemento(raiz,34);
    imprimeArvore(raiz);
    printf("\n\n");
    int altura = alturaDaArvore(raiz);
    if(verificaBalanceamento(raiz)){
        printf("\na arvore esta balanceada");
    }else{
        printf("\na arvore nao esta balanceada\n");
    }
    printf("\nsucessor da arvore: %d\n",sucessor(raiz->dir));
    

    
    imprimeArvore(raiz);

}

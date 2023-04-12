#include<stdio.h>
#include<stdlib.h>
#include"lista.c"

int main(){
    Lista *l=lst_cria();
    Lista *busca;
    l=lst_insere_ordenada(l,19);
    l=lst_insere_ordenada(l,90);
    l=lst_insere_ordenada(l,15);
    l=lst_insere_ordenada(l,70);
    l=lst_insere_ordenada(l,40);
    busca= lst_busca(19,l);
    lst_imprime(l);
    printf("resultado da busca: %d",busca->info);
    lst_libera(l);
    

    return 0;
}


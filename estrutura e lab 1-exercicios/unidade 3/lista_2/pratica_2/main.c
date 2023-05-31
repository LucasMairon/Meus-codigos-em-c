#include<stdio.h>
#include"lista.c"


int main(){

    Lista2 *l=lst2_cria();
    Lista2 *buscada;

    l=lst2_insere(l,5);
    l=lst2_insere(l,6);
    l=lst2_insere(l,7);
    l=lst2_insere(l,8);
    printf("lista l original:\n");
    lst2_imprime(l);
    

    buscada=lst2_busca(l,7);
    printf("lista com elemento buscado:\n");
    lst2_imprime(buscada);


    l=lst2_retira(l,5);
    printf("lista com elemento 5 retirado:\n");
    lst2_imprime(l);

    

    lst2_libera(l);
    lst2_libera(buscada);
    

    return 0;
}

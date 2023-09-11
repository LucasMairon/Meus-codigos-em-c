#include<stdio.h>
#include "arvore.h"

int main(){
    
    No* raiz = NULL;
    int p1,p2,p3,p4,cont = 0;
    for(p1 = 0; p1 <= 2;p1++){
      p2 = 0;
      for(p2 = 0; p2 <= 2;p2++){
        p3 = 0;
        for(p3 = 0; p3 <= 2;p3++){
          p4 = 0;
          for(p4 = 0; p4 <= 2;p4++){
             cont++;
             raiz = insere_card(raiz,cria_carta(p1,p2,p3,p4));
          }
        }
      }
    }
    
    imprimeArvore(raiz);
    printf("%d\n",cont);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include "card.h"

typedef struct card{

    short p1;
    short p2;
    short p3;
    short p4;

}Card;

int hash_card(Card* carta){
    return carta->p1 + 3 * carta->p2 + 3 * 3 * carta->p3 + 3 * 3 * 3 * carta->p4;
}

Card* cria_carta(short p1, short p2, short p3, short p4){

    Card *carta = (Card*) malloc(sizeof(Card));
    carta->p1 = p1;
    carta->p2 = p2;
    carta->p3 = p3;
    carta->p4 = p4;
    return carta;


}

void imprime_cards(Card* carta){
  printf("carta{%d  %d  %d  %d}\n",carta->p1,carta->p2,carta->p3,carta->p4);
}

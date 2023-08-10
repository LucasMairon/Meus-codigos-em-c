//Defina uma fun ̧c ̃ao chamada diasDeAula que calcula quantas aulas de laborat ́orio temos dado
//como entrada: Dia de hoje(dia,mˆes,ano) e  ́Ultimo dia do Semestre(dia,mˆes,an


#include<stdio.h>

int totalDeAulas(int diaH,int mesH,int anoH,int diaF,int mesF,int anoF){

    anoH *= 365;
    anoF *= 365;
    mesH *= 30;
    mesF *= 30;
    diaH += mesH + anoH;
    diaF += mesF +anoF;
    return 2*((diaF - diaH)/7);


}
int main(){
    
    int diaH,mesH,anoH,anoF,diaF,mesF,resultado;
    printf("digite o dia,mes e ano de hoje:\n");
    scanf("%d %d %d",&diaH,&mesH,&anoH);
    printf("digite o dia,mes e ano do final do semestre:\n");
    scanf("%d %d %d",&diaF,&mesF,&anoF);
    resultado = totalDeAulas(diaH,mesH,anoH,diaF,mesF,anoF);
    printf("%d",resultado);

    return;
}

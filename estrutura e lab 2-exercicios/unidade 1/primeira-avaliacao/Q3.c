// Um triˆangulo retˆangulo pode ter lados inteiros. O conjunto do comprimento de trˆes valores
// inteiros para os lados de um triˆangulo retˆangulo  ́e chamado de triplo pitag ́orico. Esses trˆes lados
// devem satisfazer a rela ̧c ̃ao de que a soma dos quadrados de dois dos lados  ́e igual ao quadrado da
// hipotenusa. Encontre todos os triplos pitag ́oricos para cateto1, cateto2 e a hipotenusa, todos com
// at ́e o valor de, indicado como parˆametro.
#include<stdio.h>
#include<math.h>

int verifica_dupla_pitagorica(int c1,int c2,int h){
    if((pow(c1,2) + pow(c2,2)) == pow(h,2)){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    int cateto1,cateto2,hipotenusa;
    printf("digite os valores dos catetos e da hipotenusa\n");
    scanf("%d %d %d",&cateto1,&cateto2,&hipotenusa);
    
    if(verifica_dupla_pitagorica(cateto1,cateto2,hipotenusa)){
        printf("é um triango que tem tripla pitagorica");
    }else{
        printf("nao e um triangulo com tripla pitagorica");
    }
    return 0;
}

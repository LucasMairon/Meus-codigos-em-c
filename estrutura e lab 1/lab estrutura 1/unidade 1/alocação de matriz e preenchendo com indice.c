#include<stdio.h>

#include<stdlib.h>

int main(void){
 
 int linhas=3,colunas=3,linha,coluna;
 
 int **mindice= (int**) malloc(linhas * sizeof(int*));
 
 for(linha=0;linha<linhas;linha++){
     mindice[linha]=(int*) malloc(colunas*sizeof(int));
 }
 
 for (linha = 0; linha < linhas; linha++) {
  
     for(coluna=0;coluna<colunas;coluna++){
         mindice[linha][coluna] = linha*3 + coluna;
     }
 }
 
 for (linha = 0; linha < linhas; linha++) {
  
     for(coluna=0;coluna<colunas;coluna++){
         printf("%d\t",mindice[linha][coluna]);
     }
 }
 
 for(linha=0;linha<linhas;linha++){
         free(mindice[linha]);
     }
 
 free(mindice);
    return 0;
}

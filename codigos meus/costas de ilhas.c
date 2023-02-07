#include<stdio.h>

#include<stdlib.h>

int main(){

int m,n,linha,coluna,soma=0;

printf("digite o numero de linhas e de colunas:\n");

scanf("%d %d",&m,&n);

char **mapa=(char**) malloc(m*sizeof(char*));

    for ( linha = 0; linha < m; linha++){

        mapa[linha]=(char*) malloc(n*sizeof(char));

        if(mapa[linha]==NULL){

            printf("memoria insuficiente");

            exit(1);

        }
    }
    printf("digite o mapa(use '#' para area com terra e '.' para area com mar)\n");

for ( linha = 0; linha < m; linha++){

        scanf(" %[^\n]s",mapa[linha]);
    
}

for ( linha = 0; linha < m; linha++){

    for ( coluna = 0; coluna < n; coluna++){

        if(mapa[linha][coluna]=='#'){

               if(linha != (m-1) && linha !=0 && coluna !=0 && coluna != (n-1)){

                if(mapa[linha+1][coluna]=='.'|| mapa[linha-1][coluna]=='.'|| mapa[linha][coluna+1]=='.'|| mapa[linha][coluna-1]=='.'){

                    soma++;

                   }
                }
                else if(linha==(m-1) ){
                    
                       // if (mapa[linha-1][coluna+1]=='.'|| mapa[linha-1][coluna]=='.'||mapa[linha][coluna]=='.'|| mapa[linha][coluna+1]=='.'){

                    soma++;

               //}
                }
                else if(linha==0){

                       // if(mapa[linha-1][coluna-1]=='.'|| mapa[linha][coluna]=='.'|| mapa[linha][coluna-1]=='.'|| mapa[linha-1][coluna]=='.'){

                            soma++;

                       // }

                }
                else if(coluna==(n-1)){

                  // if(mapa[linha+1][coluna]=='.'||mapa[linha][coluna-1]=='.'|| mapa[linha][coluna]=='.'|| mapa[linha+1][coluna-1]){

                        soma++;

                   // }

                }
                else if(coluna==0){

                 //   if(mapa[linha][coluna]=='.'|| mapa[linha+1][coluna]=='.'|| mapa[linha][coluna+1]=='.'||mapa[linha+1][coluna+1]=='.'){

                        soma++;

                 //   }
                }
        }
       
    }
}
       
printf("a quantidade de costas presentes na imagem foi: %d",soma);
       
for ( linha = 0; linha < m; linha++){

        free(mapa[linha]);
}
free(mapa);

    return 0;
}

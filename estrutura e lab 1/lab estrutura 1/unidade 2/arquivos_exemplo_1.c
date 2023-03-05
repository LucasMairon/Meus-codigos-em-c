#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c,nlinhas=0;
FILE *fp = fopen("entrada.txt", "rt");
    if (fp == NULL){
        printf("erro na abertura do arquivo\n");
        exit(1);
    }

    while((c = fgetc(fp)) != EOF){
        if(c == '\n'){
        nlinhas++;
        }
    }
    
    printf("Numero de linhas = %d\n",nlinhas+1);

int valor = fclose(fp);
    if (valor != 0){
        printf("nao foi possivel fechar o arquivo\n");
    }
    else{
        printf("arquivo criado com sucesso");
    }

    return 0;
}

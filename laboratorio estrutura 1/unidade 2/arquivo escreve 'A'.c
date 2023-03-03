#include<stdio.h>

int main(){
    int c;
    FILE *fp=fopen("arquivo.txt","r");
    if(fp==NULL){
        printf("o arquivo nao foi aberto corretamente");
    }
    fputc('A',fp);
    c=fgetc(fp);
    printf("%c\n",c);
    
    fclose(fp);



    return 0;
}

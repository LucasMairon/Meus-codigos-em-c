#include<regex.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


const short int FLAG = 1;
const char NUMERO_PADRAO[] = "[0-9]"; 
const char EMAIL_PADRAO[] = "([a-z0-9\.\-]{2,})@([a-z 0-9]{2,})(\.[a-z]{2,})(\.[a-z]{2,})?";
const char TELEFONE_PADRAO[] = "([\(0-9\)]{2})([\s0-9\-]{4,5})([0-9]{4})";
const char NOME_PADRAO[] = "[a-zA-Z]+";


int isvalidPadrao(char* string,const char* PADRAO,const int FLAG){
    regex_t regex;
    int valor_regex = regcomp(&regex,PADRAO,FLAG);
    
    if(valor_regex == 0){
        //valor_regex = regexec(&regex,string,0,NULL,FLAG);
        valor_regex = regexec(&regex,string,0,(regmatch_t *)NULL,0);
        regfree(&regex);
        if(valor_regex == 0){
            return 1;
        }else{
            return 0;
        }
    }else{
        printf("erro na verificacao,tente novamente\n");
        return 0;
    }
    
}

char* capturastring(char* string,const char* PADRAO,const int FLAG){

   
   int valor = isvalidPadrao(string,PADRAO,FLAG);
   if(valor != 1){
    do{
    
            printf("padrao invalido, tente novamente: ");
            scanf(" %[^\n]",string);
            valor = isvalidPadrao(string,PADRAO,FLAG);
    
    }while(valor != 1);

   }
   
   return string;
}


int capturaNumero(char* numero,const char* PADRAO,const int FLAG){
    int valor = isvalidPadrao(numero,PADRAO,FLAG);
    
    if(valor != 1){
    do{
   
        printf("padrao invalido, tente novamente: ");
        scanf(" %[^\n]",numero);
        valor = isvalidPadrao(numero,PADRAO,FLAG);
   
   }while(valor != 1);

   
   }
   return atoi(numero);
   
}


int main(){
    char* verifica_nome = capturastring("(84) 998976167",TELEFONE_PADRAO,FLAG);
    printf("%s\n",verifica_nome);
    // int valor = capturaNumero("c",NUMERO_PADRAO,FLAG);
    // printf("%d\n",valor);

}

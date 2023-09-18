#include<regex.h>
#include<stdio.h>

int main(){
    // o /g é para dizer q é global, é mais para quando tem muita informações então acho que não precisa
    //regex para telefone: /[0-9]{5}[-][0-9]{4}/g
    //regex para telefone sem barra: /[0-9]{9}/g
    //regex para telefone com ddd e barra: /[(][0-9]{2}[)][0-9]{5}[-][0-9]{4}/g
    //regex para telefone com ddd e sem barra: /[(][0-9]{2}[)][0-9]{9}/g
    //regex para nome: /[a-z && A-Z]+/g


    regex_t regex;
  int valor;

valor = regcomp(&regex,"([a-z 0-9\.\-]{2,})@([a-z 0-9]{2,})(\.[a-z]{2,})?", "/g");
  if (valor == 0) {
        printf("RegEx compiled successfully.\n");
    }
    else {
        printf("Compilation error.\n");
    }

  char email[] = "lucas@gmail.com";
   
  valor = regexec(&regex,email, 0, NULL, /g);

  
if (valor == 0) {
        printf("Pattern found.\n");
    }
    else if (valor == REG_NOMATCH) {
        printf("Pattern not found.\n");
    }
    else {
        printf("An error occured.\n");
    }
    return 0;
}
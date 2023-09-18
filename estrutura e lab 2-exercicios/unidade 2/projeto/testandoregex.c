#include<regex.h>
#include<stdio.h>

int main(){
    
    regex_t regex;
    //int valor;
    int valor2;

    //valor = regcomp(&regex,"([a-z0-9\.\-]{2,})@([a-z 0-9]{2,})(\.[a-z]{2,})(\.[a-z]{2,})?", 1);
    //não ta funcionando :
    //valor2 = regcomp(&regex,"([0-9]{2})\s([0-9]{4,5})\-([0-9]{4})",1);
    valor2 = regcomp(&regex,"([0-9]{2})([0-9]{4,5})([0-9]{4})",1);
  if (valor2 == 0) {
        printf("RegEx compiled successfully.\n");
    }
    else {
        printf("Compilation error.\n");
    }

  //char email[] = "lucAs@gmail.com";
  char tel[] = "8499896167";
   
  valor2 = regexec(&regex,tel, 0, NULL, 1);

  
if (valor2 == 0) {
        printf("Pattern found.\n");
    }
    else if (valor2 == REG_NOMATCH) {
        printf("Pattern not found.\n");
    }
    else {
        printf("An error occured.\n");
    }
    return 0;
}
#include<regex.h>

int main(){
    // o /g é para dizer q é global, é mais para quando tem muita informações então acho que não precisa
    //regex para telefone: /[0-9]{5}[-][0-9]{4}/g
    //regex para telefone sem barra: /[0-9]{9}/g
    //regex para telefone com ddd e barra: /[(][0-9]{2}[)][0-9]{5}[-][0-9]{4}/g
    //regex para telefone com ddd e sem barra: /[(][0-9]{2}[)][0-9]{9}/g
    //regex para nome: /[a-z && A-Z]+/g



    
    // regex_t regex;
    // int valor;
    // valor = regcomp(&regex,"[a-z && A-Z && 0-9]");
    return 0;
}
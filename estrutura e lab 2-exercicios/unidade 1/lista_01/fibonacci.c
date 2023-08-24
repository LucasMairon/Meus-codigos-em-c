#include <stdio.h>
int fibonacci(int n){
    if (n <= 1){
        return n;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){

    fibonacci(15);

}


//a) Depure o c´odigo para descobrir quantas vezes o fibonacci(5) ´e calculado (requisitado).
// 88 vezes: para saber isso basta crear um breakpoint com condição(b fibonacci if(n==5))
//b) Descubra atrav´es da depura¸c˜ao, qual a maior quantidade de n´ıveis (frames) esse c´odigo alcan¸ca.
// 14 vezes: usa b fibonacci if n==1,da um finish e da um bt/where
//Depure o c´odigo at´e o momento que o primeiro fibonacci(14) ´e calculado e o execut´avel ir´a come¸car
//a calcular o fibonacci(13).
// usar step para entrar nas funções, n para passar os comandos e display para acompanhar a variavel n
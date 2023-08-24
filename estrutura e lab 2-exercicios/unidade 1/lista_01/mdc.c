#include<stdio.h>

// Funcao para calcular algo
int operacaoMatematica(int a, int b){
    int r;

    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(){
    int num1, num2;

    printf(" Digite o primeiro numero : ");
    scanf("%d", &num1);

    printf(" Digite o segundo numero : ");
    scanf("%d", &num2);

    int res = operacaoMatematica(num1, num2);

    printf("A operacao de %d e %d e: %d\n", num1, num2, res);

    return 0;
}

//a) Execute o algoritmo em modo de depura¸c˜ao.
// usar breakpoint step e next
//b) Descubra atrav´es da depura¸c˜ao, qual a maior profundidade de (frames) esse c´odigo alcan¸ca.
//depende dos numeros que a pessoa colocar
//c) Descubra o que ocorre quando um parˆametro ´e 0.
// se um dos numeros for zero a função vai retornar o outro parametro, contanto que o outro seja diferente de 0
//d) Descubra o que ocorre quando os dois parˆametros apresentados s˜ao iguais e maiores que 1.
//o procedimento só acontece uma vez,e o resultado vai ser o proprio numero
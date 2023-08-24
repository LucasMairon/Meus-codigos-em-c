// Implemente a seguinte fun¸c˜ao matem´atica f(m, n) definida por partes:
// (a) f(m, n) = m + 1, se n = 1.
// (b) f(m, n) = n + 1, se m = 1.
// (c) f(m, n) = f(m, n − 1) + f(m − 1, n), se m > 1, n > 1.
#include<stdio.h>
//
int funcaoRecursiva(int m,int n){
    if(n == 1){
        return m + 1;
    }
    if(m == 1){
        return n + 1;
    }
    if(m > 1 && n > 1){
        return funcaoRecursiva(m,n-1) + funcaoRecursiva(m-1,n);
    }
    
}
int main(){
    int x1,x2;
    printf("digite dois valores: ");
    scanf("%d %d",&x1,&x2);
    printf("%d",funcaoRecursiva(x1,x2));
    return;
}
//1 +1 = 2
//2 + 2 = 4
//3 + 1 = 4
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int *vindice=(int*) malloc(10*sizeof(int));
    for ( i = 0; i < 10; i++){
        vindice[i] = i;
    }
    for ( i = 0; i < 10; i++){
       printf("o indice do %d elemento foi %d\n",i+1,vindice[i]);
    }

    free(vindice);
    return(0);
}
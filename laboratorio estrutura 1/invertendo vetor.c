#include<stdio.h>

void inverte(int vetor[],int n){
  int aux[n],idx;
  
    for(idx=0;idx<n;idx++){
        aux[idx]=vetor[idx];
    }
    for(idx=0;idx<n;idx++){
        vetor[idx]=aux[n-1-idx];
    }
}

int main(){
    
    int vetor[5]={1,2,3,4,5},count;
  
    inverte(vetor,5);

    for(count=0;count<5;count++){
        printf("%d\t",vetor[count]);
    }
  
    return(0);
}

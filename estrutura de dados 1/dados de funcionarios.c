#include<stdio.h>

#include<stdlib.h>

typedef struct Funcionario{
    char nome[50];
    
    float salario;
    
    char cargo[50];
    
}funcionario; 

int main(){
    
    int n,i;
    
    printf("digite a quantidade de funcionarios que irao fornecer os dados: ");
    
    scanf("%d",&n);
    
    funcionario *quant=(funcionario*) malloc(n*sizeof(funcionario));
    
        if(quant==NULL){
            
            printf("memoria insuficiente");
            
            exit(1);
            
        }
        for(i=0;i<n;i++){
            printf("digite o nome do %d funcionario: ",i+1);
            
            scanf(" %[^\n]s",quant[i].nome);
            
            printf("digite o salario do %d funcionario: ",i+1);
            
            scanf("%f",&quant[i].salario);
            
            printf("digite o cargo do %d funcionario: ",i+1);
            
            scanf(" %[^\n]s",quant[i].cargo);
            
        }
        
    printf("==================================================================================\n");
    
        for(i=0;i<n;i++){
            
            printf("nome do %d° funcionario: %s\n",i+1,quant[i].nome);
   
            printf("salario do %d° funcionario: %.2f\n",i+1,quant[i].salario);
   
            printf("cargo do %d° funcionario: %s\n",i+1,quant[i].cargo);
            
            printf("==================================================================================\n");
            
        }

free(quant);
    
    return 0;
}

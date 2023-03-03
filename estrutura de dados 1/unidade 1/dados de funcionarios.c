#include<stdio.h>

#include<locale.h>

#include<stdlib.h>

typedef struct Funcionario{
    char nome[50];
    
    float salario;
    
    char cargo[50];
    
}funcionario; 

int main(){

    setlocale(LC_ALL,"Portuguese");
    
    int n,i;
    
    printf("digite a quantidade de funcionarios que irao fornecer os dados: ");
    
    scanf("%d",&n);
    
    funcionario *quant=(funcionario*) malloc(n*sizeof(funcionario));
    
        if(quant==NULL){
            
            printf("memoria insuficiente");
            
            exit(1);
            
        }

    

        for(i=0;i<n;i++){

            printf("==================================================================================\n");
            
            printf("vez do %d° funcionário:\n",i+1);

            printf("==================================================================================\n");

            printf("digite seu nome: ");
            
            scanf(" %[^\n]s",quant[i].nome);
            
            printf("digite seu salário: ");
            
            scanf("%f",&quant[i].salario);
            
            printf("digite seu cargo: ");
            
            scanf(" %[^\n]s",quant[i].cargo);

            
            
        }
        
    printf("==================================================================================\n");
    
        for(i=0;i<n;i++){
            printf("dados do %d° funcionário:\n",i+1);

            printf("nome: %s\n",quant[i].nome);
   
            printf("salário: %.2f\n",quant[i].salario);
   
            printf("cargo: %s\n",quant[i].cargo);
            
            printf("==================================================================================\n");
            
        }

free(quant);
    
    return 0;
}

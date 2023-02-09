#include<stdio.h>

#include<stdlib.h>

#include<string.h>

typedef struct funcionario{
    char nome[50];
    float salario;
    char cargo[50];
    int identificador;
}Funcionario;

void preenche(Funcionario * dados, int quant){
    int i;
  
    for(i=0;i<quant;i++){
      
        printf("digite o nome do %d funcionario: ",i+1);
      
        scanf(" %[^\n]",dados[i].nome);
      
        printf("digite o salario do %d funcionario: ",i+1);
      
        scanf("%f",&dados[i].salario);
      
        printf("digite o cargo do %d funcionario: ",i+1);
      
        scanf(" %[^\n]",dados[i].cargo);
      
        printf("digite o id do %d funcionario: ",i+1);
      
        scanf("%d",&dados[i].identificador);
      
    }
}
void imprime( Funcionario *impr,int quant){
    int i;
  
    for(i=0;i<quant;i++){
      
    printf("o nome do %d funcionario e: %s\n",i+1,impr[i].nome);

    printf("o salario do %d funcionario e: %f\n",i+1,impr[i].salario);
     
    printf("o cargo do %d funcionario e: %s\n",i+1,impr[i].cargo);
     
    printf("o id do %d funcionario e: %d\n",i+1,impr[i].identificador);
   
}
}
void muda_salario(Funcionario * sal,int quant){
    int i,alteracao;
    
    printf("deseja alterar o valor do salario dos funcionarios?(use 1 para sim e 2 para nao)\n");
  
    scanf("%d",&alteracao);
  
    if(alteracao==2){
      
        printf("o salario nao foi alterado");
      
    }
  
    else{
      
for(i=0;i<quant;i++){
  
    printf("digite o novo salario do %d funcionario: ",i+1);
  
        scanf("%f",&sal[i].salario);

}
    }

}
void maior_salario(Funcionario *maiorsal,int quant){
    int i;
  
    float maiors=0;
  
    char mcargo[50];
  
    for(i=0;i<quant;i++){
      
    if(maiorsal[i].salario>maiors){
      
        maiors=maiorsal[i].salario;
      
        strcpy(mcargo,maiorsal[i].cargo);
      
    }
      
    }
  
    printf("o cargo da pessoa com o maior salario e: %s e o salario dessa pessoa e: %f\n",mcargo,maiors);
    
}

int main(){
  
 int quant_func;
  
printf("digite a quantidade de funcionarios: ");
  
scanf("%d",&quant_func);
  
 Funcionario *dados_func=(Funcionario*) malloc(quant_func*sizeof(Funcionario));
  
preenche(dados_func,quant_func);
  
imprime(dados_func,quant_func);
  
muda_salario(dados_func,quant_func);
  
maior_salario(dados_func,quant_func);


    return 0;
}

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<locale.h>

typedef struct pessoa{
    
    char nome[50];
    
    int documento;
    
    int idade;
    
}Pessoa;

void preenche(Pessoa * dados, int quant){
    
    int i;
  
    for(i=0;i<quant;i++){
      
        printf("digite o nome da %dª pessoa: ",i+1);
      
        scanf(" %[^\n]s",dados[i].nome);
      
        printf("digite o numero do documento da %dª pessoa(desconsidere '.' e '-'): ",i+1);
      
        scanf("%d",&dados[i].documento);
      
        printf("digite a idade da %dª pessoa: ",i+1);
      
        scanf(" %d",&dados[i].idade);
      
    }
    
}

void imprime( Pessoa *impr,int quant){
    
    int i;
  
    for(i=0;i<quant;i++){
      
    printf("o nome da %dª pessoa é: %s\n",i+1,impr[i].nome);

    printf("o numero do documento da %dª pessoa é: %d\n",i+1,impr[i].documento);
     
    printf("a idade da %dª pessoa é: %d\n",i+1,impr[i].idade);
     
    }

}

void muda_idade(Pessoa * midade,int quant){
    
    int i,alteracao;
    
    //int indice,o indice para caso so fosse uma pessoa
    
    printf("deseja alterar o valor da idade das pessoas?(use 1 para sim e 2 para nao)\n");
  
    scanf("%d",&alteracao);
  
    if(alteracao==2){
      
        printf("nenhuma idade foi alterada nao foi alterado");
      
    }
  
    else{
        
    //caso a mudança de idade seja so para uma pessoa:
    //printf("de quem deseja mudar a idade?");
    //scanf("%d",&indice);
    //printf("qual vai ser a nova idade dessa pessoa?");
    //scanf("%d",&midade[indidce+1].idade);
    //printf("a nova idade da pessoa %d é: %d",indice+1,midade[indice+1].idade);
    //caso seja para todas(foi o que eu assumi)
    
        for(i=0;i<quant;i++){
  
            printf("digite a nova idade da %dª pessoa: ",i+1);
  
            scanf("%d",&midade[i].idade);
    
        }
        for(i=0;i<quant;i++){
    
            printf("nova idade da %dª pessoa é:%d\n",i+1,midade[i].idade);
    
        }

    }

}

void verifica_idade(Pessoa *vidade,int quant){
    
    int i;
  
    int maisvelha=0,maisnova=99999;
  
    char maisnome[50],menosnome[50];
  
 for(i=0;i<quant;i++){
      
    if(vidade[i].idade>maisvelha){
      
        maisvelha=vidade[i].idade;
      
        strcpy(maisnome,vidade[i].nome);
      
    }
    if(vidade[i].idade<maisnova){
      
        maisnova=vidade[i].idade;
      
        strcpy(menosnome,vidade[i].nome);
      
    }
      
 }
  
printf("o nome da pessoa mais velha é:%s, e o nome da pessoa mais nova é:%s",maisnome,menosnome);
    
}

int main(){
    
setlocale(LC_ALL,"Portuguese");
  
int quant_pessoa;
  
printf("digite a quantidade de pessoas que serão entrevistadas: ");
  
scanf("%d",&quant_pessoa);
  
Pessoa *dados_pessoa=(Pessoa*) malloc(quant_pessoa*sizeof(Pessoa));
    
if(dados_pessoa==NULL){
    
    printf("memoria insuficiente");
    
    exit(1);
    
}
  
preenche(dados_pessoa,quant_pessoa);
  
imprime(dados_pessoa,quant_pessoa);
  
muda_idade(dados_pessoa,quant_pessoa);
  
verifica_idade(dados_pessoa,quant_pessoa);
    
free(dados_pessoa);

return 0;
    
}

// Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
// seguintes campos: nome da pessoa, numero do documento e idade.
// a) Escreva uma fun ̧c ̃ao que receba como parˆametro o endere ̧co de uma estrutura do tipo Pessoa e
// preencha seus campos com valores fornecidos pelo usu ́ario via teclado.
// b) Escreva uma fun ̧c ̃ao que receba como parˆametro o endere ̧co de uma estrutura do tipo Pessoa e
// imprima os valores dos seus campos.
// c) Implemente uma fun ̧c ̃ao para realizar uma atualiza ̧c ̃ao da idade de uma estrutura do tipo Pessoa.
// d) Escreva uma fun ̧c ̃ao que receba como parˆametro um vetor de estruturas do tipo Pessoa e imprima
// o nome da Pessoa mais velha e mais nova.


#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<locale.h>

typedef struct pessoa//criando a struct pessoa com os parametros nome,documento e idade e renomeando para Pessoa;
{
    
    char nome[50];
    
    int documento;
    
    int idade;
    
}Pessoa;

void preenche(Pessoa * dados, int quant)//criando a funcao preenche, que tem como parametro o vetor dados e a variavel quant;
{
    
    int i;//criando a variavel i;
  
    for(i=0;i<quant;i++)//estrutura de repeticao que vai de 0 ate a quantidade de pessoas;
    {
      
        printf("digite o nome da %dª pessoa: ",i+1);//pedindo ao usuario o nome das pessoas;
      
        scanf(" %[^\n]s",dados[i].nome);//armazenando a resposta em um elemento do vetor dados,referente a uma struct,na variavel nome;
      
        printf("digite o numero do documento da %dª pessoa(desconsidere '.' e '-'): ",i+1);//pedindo ao usuario o documento das pessoas;
      
        scanf("%d",&dados[i].documento);//armazenando a resposta em um elemento do vetor dados,referente a uma struct,na variavel documento;
      
        printf("digite a idade da %dª pessoa: ",i+1);//pedindo ao usuario a idade das pessoas;
      
        scanf(" %d",&dados[i].idade);//armazenando a resposta em um elemento do vetor dados,referente a uma struct,na variavel idade;
      
    }
    
}

void imprime( Pessoa *impr,int quant)//criando uma funcao imprime que tem como parametros o vetor impr e a quantidade de pessoas;
{
    
    int i;//declarando a variavel i;
  
    for(i=0;i<quant;i++)//estrutura de repeticao que vai de 0 ate a quantidade de pessoas;
    {
      
    printf("o nome da %dª pessoa é: %s\n",i+1,impr[i].nome);//imprimindo o nome das pessoas,que foram armazenados nas structs anteriormente;

    printf("o numero do documento da %dª pessoa é: %d\n",i+1,impr[i].documento);//imprimindo o numero do documento das pessoas,que foram armazenados nas structs anteriormente;
     
    printf("a idade da %dª pessoa é: %d\n",i+1,impr[i].idade);//imprimindo a idade das pessoas,que foram armazenados nas structs anteriormente;
     
    }

}

void muda_idade(Pessoa * midade,int quant)//criando a funcao muda_idade,que tem como parametros o vetor midade e a quantidade de pessoas;
{
    
    int i,alteracao;//criando as variaveis que serao utilizadas;
    
    //int indice,o indice para caso so fosse uma pessoa;
    
    printf("deseja alterar o valor da idade das pessoas?(use 1 para sim e 2 para nao)\n");//perguntando ao usuario se ele deseja alterar o valor das idade das pessoas;
  
    scanf("%d",&alteracao);//armazenando essa resposta na variavel alteracao;
  
    if(alteracao==2)//verificando se a resposta foi nao,se for entao as idades nao serao alteradas;
    {
      
        printf("nenhuma idade foi alterada nao foi alterado");
      
    }
  
    else//verificando se a resposta foi sim;
    {
        
    //caso a mudança de idade seja so para uma pessoa:
    //printf("de quem deseja mudar a idade?");
    //scanf("%d",&indice);
    // if(indice<quant && indice>0){
    //printf("qual vai ser a nova idade dessa pessoa?");
    //scanf("%d",&midade[indidce+1].idade);
    //printf("a nova idade da pessoa %d é: %d",indice+1,midade[indice+1].idade);
    // }
    //caso seja para todas(foi o que eu assumi):
    
        for(i=0;i<quant;i++)//estrutura de repeticao que vai de 0 ate a quantidade de pessoas;
        {
  
            printf("digite a nova idade da %dª pessoa: ",i+1);//pedindo a nova idade de cada pessoa;
  
            scanf("%d",&midade[i].idade);//lendo essa nova idade e armazenando em cada elemento do vetor midade na variavel idade;
    
        }
        for(i=0;i<quant;i++)//estrutura de repeticao que vai de 0 ate a quantidade de pessoas;
        {
    
            printf("nova idade da %dª pessoa é:%d\n",i+1,midade[i].idade);//imprimindo a nova idade de cada pessoa;
    
        }

    }

}

void verifica_idade(Pessoa *vidade,int quant)//criando a funcao verifica_idade,que tem como parametros o vetor vidade e a quantidade de pessoas;
{
    
    int i;//criando a variavel i;
  
    int maisvelha=0,maisnova=99999;//criando as ariaveis maisvelha e mais nova,e inicializando maisvelha com 0 para que na primeira vez a idade seja sempre maior e mais nova com um numero muito grande para que a idade seja sempre menor;
  
    char maisnome[50],menosnome[50];//criando as variaveis que vao receber o nome da pessoa com a maior idade e a que tem a menor idade; 
  
 for(i=0;i<quant;i++)//estrutura de repeticao que vai de zero a quantidade de pessoas;
 {
      
    if(vidade[i].idade>maisvelha)//verificando se a idade da pessoa é a maior idade;
    {
      
        maisvelha=vidade[i].idade;//se essa idade for a maior idade vai ser armazenada em maisvelha, para ser verificado ate o laco de repeticao acabar;
      
        strcpy(maisnome,vidade[i].nome);//copiando o nome da pessoa mais velha e colando na variavel maisnome;
      
    }
    if(vidade[i].idade<maisnova)//verificando se a idade da pessoa é a menor idade;
    {
      
        maisnova=vidade[i].idade;//se essa idade for a menor idade vai ser armazenada em maisnova, para ser verificado ate o laco de repeticao acabar;
      
        strcpy(menosnome,vidade[i].nome);//copiando o nome da pessoa mais nova e colando na variavel menosnome;
      
    }
      
 }
  
printf("o nome da pessoa mais velha é:%s, e o nome da pessoa mais nova é:%s",maisnome,menosnome);//imprimindo o nome da pessoa mais velha e da mais nova;
    
}

int main(){
    
setlocale(LC_ALL,"Portuguese");//comando para trabalhar com portugues no codigo;
  
int quant_pessoa;//declarando a variavel para a quantidade de pessoas;
  
printf("digite a quantidade de pessoas que serão entrevistadas: ");//pedindo e lendo a quantidade de pessoas que serao entrevistadas;
  
scanf("%d",&quant_pessoa);
  
Pessoa *dados_pessoa=(Pessoa*) malloc(quant_pessoa*sizeof(Pessoa));//alocando dinamicamente o vetor dados_pessoa com o tamanho referente a quantidade de pessoas ;
    
if(dados_pessoa==NULL)//verificando se a alocacao foi bem sucedida, se nao for o progama sera abortado;
{
    
    printf("memoria insuficiente");
    
    exit(1);
    
}
  
preenche(dados_pessoa,quant_pessoa);//chamando todas as funcoes,os parametros serao preenchidos com o vetor de struct dados_pessoa e a quantidade de pessoas;
  
imprime(dados_pessoa,quant_pessoa);
  
muda_idade(dados_pessoa,quant_pessoa);
  
verifica_idade(dados_pessoa,quant_pessoa);
    
free(dados_pessoa);//liberando o vtor dados_pessoa da memoria;

return 0;
    
}

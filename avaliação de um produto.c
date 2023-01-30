#include<stdio.h>
#include<stdlib.h>

int main(){
   
    int pessoas,count,count2,soma_feminino=0,soma_masculino=0;
    
    printf("digite a quantidade de pessoas que serao entrevistadas:\n");
    
    scanf("%d",&pessoas);
    
    char *sexo=(char*) malloc(pessoas*sizeof(char));
    
    int *op_produto=(int*) malloc(pessoas* sizeof(int));

     for (count = 0; count < pessoas; count++){
        
        printf("digite o seu sexo,use M para masculino e F para feminino\n");
        
        scanf(" %c",&sexo[count]);
        
        printf("digite 0 se nao gostou do produto e 1 se gostou\n");
        
        scanf("%d",&op_produto[count]);
     }
     for (count2 = 0; count2 < pessoas; count2++){
        if((sexo[count2]== 'M') && (op_produto[count2]==1)){
            soma_masculino++;

        }
        if((sexo[count2]== 'F') && (op_produto[count2]==0)){
            soma_feminino++;
        }
     }
     soma_masculino=((soma_masculino*100.0f)/pessoas);
     soma_feminino=((soma_feminino*100.0f)/pessoas);
     printf("a quantidade de pessoas do sexo masculino que gostaram do produto foi:%d %%\n",soma_masculino);
     printf("a quantidade de pessoas do sexo feminino que nao gostaram do produto foi:%d %%\n",soma_feminino);

    free(op_produto);
    free(sexo);

    return(0);
}
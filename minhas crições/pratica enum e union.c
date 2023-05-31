#include<stdio.h>

typedef union indices_academicos{
    float ig;
    float ira;
    float irt;

}Indices_academicos;

typedef enum situacao{ativo,inativo,trancado}Situacao;

typedef struct aluno{
    char nome[50];
    int matricula;
    char curso[50];
    Indices_academicos escolha;
    Situacao op;


}Aluno;






int main(){

    Aluno aluno;
    int op;

   
    printf("digite o seu nome: ");
    scanf(" %[^\n]s",aluno.nome);
    printf("digite o numero da matricula: ");
    scanf("%d",&aluno.matricula);
    printf("digite o curso: ");
    scanf(" %[^\n]s",aluno.curso);
    printf("digite qual indice academico deseja preencher use:\n 1 para indice geral\n 2 para indice de rendimento academico\n 3 para indice de rendimento tecnico\n ");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        printf("digite seu indice geral: ");
        scanf("%f",&aluno.escolha.ig);
        printf("digite sua situacao(ativo,inativo e trancado): ");
        scanf(" %d",(int*)&aluno.op);
     if(aluno.op=="ativo"||aluno.op==0){
         printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: ativo\n indice geral: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.ig);
    }
    if(aluno.op=="inativo"||aluno.op==1){
        printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: inativo\n indice geral: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.ig);

    }
    if(aluno.op=="trancado"||aluno.op==2){
        printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: trancado\n indice geral: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.ig);

    }




        break;
    case 2:
        printf("digite seu indice de rendimento academico: ");
        scanf("%f",&aluno.escolha.ira);
        printf("digite sua situacao(ativo,inativo e trancado): ");
        scanf(" %d",(int*)&aluno.op);
     if(aluno.op=="ativo"|| aluno.op==0){
         printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: ativo\n indice de rendimento academico: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.ira);
    }
    if(aluno.op=="inativo"|| aluno.op==1){
        printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: inativo\n indice de rendimento academico: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.ira);

    }
    if(aluno.op=="trancado"|| aluno.op==2){
        printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: trancado\n indice de rendimento academico: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.ira);

    }

break;


    case 3:
        printf("digite seu indice de rendimento tecnico: ");
        scanf("%f",&aluno.escolha.irt);
        printf("digite sua situacao(ativo,inativo e trancado): ");
        scanf(" %d",(int*)&aluno.op);

        if(aluno.op=="ativo"|| aluno.op==0){
         printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: ativo\n indice de rendimento tecnico: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.irt);
    }
    if(aluno.op=="inativo"|| aluno.op==1){
        printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: inativo\n indice de rendimento tecnico: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.irt);

    }
    if(aluno.op=="trancado"|| aluno.op==2){
        printf("nome: %s\n matricula: %d\n curso: %s\nsituacao: trancado\n indice de rendimento tecnico: %.2f",aluno.nome,aluno.matricula,aluno.curso,aluno.escolha.irt);

    }

        break;
    }
   




    return 0;
}

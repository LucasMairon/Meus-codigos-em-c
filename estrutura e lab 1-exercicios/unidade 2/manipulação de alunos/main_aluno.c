#include"aluno.c"

int main(){
    Aluno *aluno1=aluno_cria("lucas",9.0);
    Aluno *aluno2=aluno_cria("aluno 2",8.0);
    Aluno *aluno3=aluno_cria("aluno 3",6.0);
    Aluno *aluno4=aluno_cria("aluno 4",10.0);
    Aluno *aluno5=aluno_cria("aluno 5",5.0);


    aluno_imprime(aluno1);
    aluno_imprime(aluno2);
    aluno_imprime(aluno3);
    aluno_imprime(aluno4);
    aluno_imprime(aluno5);



    return 0;
}
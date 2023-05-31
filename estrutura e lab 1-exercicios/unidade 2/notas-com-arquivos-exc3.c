// Escreva um programa em C que leia de um arquivo as notas dos alunos de uma
// turma e escreva em outro arquivo o nome e a média de cada aluno, bem como a sua situação
// (aprovado (média >= 7.0) ou reprovado). Tanto no arquivo de entrada quanto no de saída,
// considere que os dados em cada linha estão separados por um caractere de tabulação ‘\t’. Para a
// execução do programa com o arquivo de entrada “entrada_q3.txt”, deverá ser criado o arquivo
// de saída “saída_q3.txt”, como ilustrado a seguir.

#include <stdio.h>
#include <string.h>

int main(void)
{
    float nota1, nota2, nota3, media = 0;
    char nome[100], linha[100];
    FILE *arquivo_entrada = fopen("entrada_q3.txt", "r");
    FILE *arquivo_saida = fopen("saida_q3.txt", "w");
    if (arquivo_entrada == NULL)
    {
        printf("nao foi possivel abrir o arquivo de entrada");
        return 1;
    }
    if (arquivo_saida == NULL)
    {
        printf("nao foi possivel abrir o arquivo de saida");
        return 1;
    }
    while (fgets(linha, 100, arquivo_entrada))
    {
        sscanf(linha, "%20[^\t]\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3) / 3;
        fprintf(arquivo_saida, "%s\t%.1f\t%s\n", nome, media, (media >= 7.0) ? "aprovado" : "reprovado");
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}
// entrada:
// Amanda	7.0	6.5	9.0
// Alberto	5.0	7.0	3.5
// Jane	8.0	6.8	4.5
// Igor	9.0	9.0	8.5
// Samara	10.0	10.0	7.0
// Maria Luiza	10.0	10.0	10.0
// Cesar 	10.0	9.0	8.0
// Pedro Felipe	7.0	7.0	7.0

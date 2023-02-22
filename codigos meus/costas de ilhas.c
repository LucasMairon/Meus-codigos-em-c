// A Nlogônia é um país tropical, com muitas belezas naturais internacionalmente
// famosas; dentre elas, encontram-se as belas praias que compõem o arquipélago do país, que
// todo verão recebem milhões de turistas estrangeiros.
// O Ministério do Turismo da Nlogônia está preparando o país para a chegada dos turistas, mas,
// para fazer seu planejamento, precisa saber a extensão da costa nlogônica. Para isso, ele gerou
// um mapa que divide o território nacional em vários quadrados, que podem ser ocupados por
// água ou por terra; considera-se que um quadrado é parte da costa nlogônica se ele é um
// quadrado ocupado por terra que tem um lado em comum com um quadrado ocupado por
// água.
// Como a Nlogônia é um país muito grande, o ministro do turismo pediu que você escrevesse um
// programa que, dado o mapa da Nlogônia, determina a extensão da costa nlogônica.
// Entrada
// A primeira linha da entrada contém dois inteiros M e N indicando, respectivamente, o número
// de linhas e o número de colunas do mapa. Cada uma das M linhas seguintes contém N
// caracteres: um caractere ‘.’ indica que aquele quadrado do território é ocupado por água; um
// caractere ‘#’ indica que aquele quadrado do território é ocupado por terra.
// Considere que todo o espaço fora da área do mapa é ocupado por água.
// Saída
// Seu programa deve imprimir uma única linha contendo um único inteiro, indicando quantos
// quadrados do território fazem parte da costa da Nlogônia.

#include <stdio.h>

#include <stdlib.h> //incluindo a biblioteca para fazer alocacao;

int main()
{

    int m, n, linha, coluna, soma = 0; // declarando as variaveis e inicializando as que precisam com 0;

    printf("digite o numero de linhas e de colunas:\n"); // pedindo o numero de linhas e colunas do mapa;

    scanf("%d %d", &m, &n); // lendo os valores das linhas e colunas

    char **mapa = (char **)malloc(m * sizeof(char *)); // alocando dinamicamente a matriz mapa com quantidade referente ao numero de linhas;

    for (linha = 0; linha < m; linha++) // estrutura de repeticao para percorrer as linhas;
    {

        mapa[linha] = (char *)malloc(n * sizeof(char)); // alocando dinamicamente cada coluna da matriz mapa com espaco referente a n;

        if (mapa[linha] == NULL) // verificando se a alocacao foi bem sucedida,se nao for o progama sera abortado;
        {

            printf("memoria insuficiente");

            exit(1);
        }
    }
    printf("digite o mapa(use '#' para area com terra e '.' para area com mar)\n"); // pedindo ao usuario que informe o terreno do mapa;

    for (linha = 0; linha < m; linha++) // estrutura de repeticao que vai de 0 ate a quantidade de linhas;
    {

        scanf(" %[^\n]s", mapa[linha]); // lendo cada linha do mapa;
    }

    for (linha = 0; linha < m; linha++) // estrutura de repeticao que vai de 0 ate a quantidade de linhas;
    {

        for (coluna = 0; coluna < n; coluna++) // estrutura de repeticao que vai de 0 ate a quantidade de colunas;
        {

            if (mapa[linha][coluna] == '#') // verificando se o usuario digitou #,ou seja,pedaco de terra;
            {

                if (linha != (m - 1) && linha != 0 && coluna != 0 && coluna != (n - 1)) // verificando se o pedaco de terra esta nas bordas do mapa;
                {

                    if (mapa[linha + 1][coluna] == '.' || mapa[linha - 1][coluna] == '.' || mapa[linha][coluna + 1] == '.' || mapa[linha][coluna - 1] == '.') // verificando se ao redor desses pedacos de terra existe agua;
                    {

                        soma++; // somando a quantidade de costas;
                    }
                }
                else if (linha == (m - 1)) // verificando se o pedaco de terra esta na ultima linha;
                {

                    // if (mapa[linha-1][coluna+1]=='.'|| mapa[linha-1][coluna]=='.'||mapa[linha][coluna]=='.'|| mapa[linha][coluna+1]=='.'){//considerando as bordas como agua verificamos se ao redor do pedaco de terra tem agua;

                    soma++; // somando a quantidade de costas;

                    //}
                }
                else if (linha == 0) // verificando se o pedaco de terra esta na primeira linha;
                {

                    // if(mapa[linha-1][coluna-1]=='.'|| mapa[linha][coluna]=='.'|| mapa[linha][coluna-1]=='.'|| mapa[linha-1][coluna]=='.'){//considerando as bordas como agua verificamos se ao redor do pedaco de terra tem agua;

                    soma++; // somando a quantidade de costas;

                    // }
                }
                else if (coluna == (n - 1)) // verificando se o pedaco de terra esta na ultima coluna;
                {

                    // if(mapa[linha+1][coluna]=='.'||mapa[linha][coluna-1]=='.'|| mapa[linha][coluna]=='.'|| mapa[linha+1][coluna-1]){//considerando as bordas como agua verificamos se ao redor do pedaco de terra tem agua;

                    soma++; // somando a quantidade de costas;

                    // }
                }
                else if (coluna == 0) // verificando se o pedaco de terra esta na primeira coluna;
                {

                    //   if(mapa[linha][coluna]=='.'|| mapa[linha+1][coluna]=='.'|| mapa[linha][coluna+1]=='.'||mapa[linha+1][coluna+1]=='.'){//considerando as bordas como agua verificamos se ao redor do pedaco de terra tem agua;

                    soma++; // somando a quantidade de costas;

                    //   }
                }
            }
        }
    }

    printf("a quantidade de costas presentes na imagem foi: %d", soma); // imprimindo a quantidade de costas registradas;

    for (linha = 0; linha < m; linha++) // estrutura de repeticao para percorrer as linhas;
    {

        free(mapa[linha]); // liberando as colunas da matriz;
    }
    free(mapa); // liberando a matriz como um todo;

    return 0;
}

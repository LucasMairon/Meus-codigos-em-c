#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contabancaria
{
    char titular[50];
    int numero;
    float saldo;

} ContaBancaria;

ContaBancaria *cria_conta(char *titular, int numero, float saldo)
{

    ContaBancaria *nova_conta = (ContaBancaria *)malloc(sizeof(ContaBancaria));

    strcpy(nova_conta->titular, titular);
    nova_conta->numero = numero;
    nova_conta->saldo = saldo;

    return (nova_conta);
}

void Deposita_valor(ContaBancaria *conta, float valor)
{

    conta->saldo = conta->saldo + valor;
}

void saca_valor(ContaBancaria *conta, float valor)
{

    if (conta->saldo > 0)
    {
        conta->saldo = conta->saldo - valor;
    }
    else
    {
        printf("saldo insuficiente para saque");
    }
}
void transfere_valor(ContaBancaria *conta_destino, ContaBancaria *conta_origem, float valor)
{
    if (conta_origem->saldo > 0)
    {
        conta_destino->saldo = conta_destino->saldo + valor;
        conta_origem->saldo = conta_origem->saldo - valor;
    }
    else
    {

        printf("saldo insuficiente para transferencia");
    }
}
float retorna_saldo(ContaBancaria *conta)
{
    return (conta->saldo);
}
void exclui_conta(ContaBancaria *conta)
{
    free(conta);
}

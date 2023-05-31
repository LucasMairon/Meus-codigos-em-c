#include "manipula_cbancaria_modulo.c"

int main()
{
    float saldo_conta1, saldo_conta2;
    // char nome_1[10]="lucas",nome_2[10]="lidiana";
    ContaBancaria *conta_1 = cria_conta("lucas", 1, 00);
    ContaBancaria *conta_2 = cria_conta("lidiana", 2, 00);
    Deposita_valor(conta_1, 10000);
    Deposita_valor(conta_2, 5000);
    saca_valor(conta_1, 10);
    transfere_valor(conta_2, conta_1, 1000);
    saldo_conta1 = retorna_saldo(conta_1);
    saldo_conta2 = retorna_saldo(conta_2);

    printf("saldo da conta 1: %f\nsaldo da conta 2: %f", saldo_conta1, saldo_conta2);

    exclui_conta(conta_1);
    exclui_conta(conta_2);
}

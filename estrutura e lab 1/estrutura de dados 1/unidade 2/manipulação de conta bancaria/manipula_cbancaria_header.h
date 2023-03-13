typedef struct contabancaria ContaBancaria;

ContaBancaria *cria_conta(char *titular,int numero, float saldo);

void Deposita_valor(ContaBancaria *conta,float valor);

void saca_valor(ContaBancaria *conta,float valor);

void transfere_valor(ContaBancaria *conta_destino,ContaBancaria *conta_origem,float valor);

float retorna_saldo(ContaBancaria *conta);

void exclui_conta(ContaBancaria *conta);

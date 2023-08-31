typedef struct no No;

No* insere_elemento(No* raiz,int dados);

int alturaDaArvore(No* raiz);

No* remove_elemento(No* raiz, int dados);

void imprimeArvore(No* raiz);

int alturaDoNo(No* raiz);

int sucessor(No* raiz);

int max(int a,int b);

int balanceamento(No* raiz);

int verificaBalanceamento(No* raiz);

No* rotacaoDir(No* raiz);

No* rotacaoEsq(No* raiz);

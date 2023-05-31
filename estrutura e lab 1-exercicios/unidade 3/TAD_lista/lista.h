typedef struct lista Lista;

typedef struct listano ListaNo;

Lista *lst_cria(void);

Lista *lst_insere(Lista *l, int v);

int lst_vazia(Lista *l);

void lst_imprime(Lista *l);

Lista *lst_busca(int elemento,Lista *l);

Lista *lst_retira(Lista *l,int v);

void lst_libera(Lista *l);

Lista *lst_insere_ordenada(Lista *l,int v);

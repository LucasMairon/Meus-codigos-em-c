

typedef struct lista2 Lista2;

void lst2_imprime(Lista2* l);

int lst2_vazia(Lista2* l);

void lst2_libera(Lista2* l);

Lista2* lst2_busca(Lista2* l, int v);

Lista2* lst2_retira(Lista2* l, int v);

void lst2_libera(Lista2 *l);

Lista2* lst2_cria(void);

Lista2* lst2_insere(Lista2* l, int v);

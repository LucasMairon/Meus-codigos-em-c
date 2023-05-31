 #include<stdio.h>
 #include<stdlib.h>
typedef struct lista2 Lista2;

struct lista2{
    int info;
    Lista2 *prox; 
    Lista2 *ant;
};

Lista2* lst2_cria(void){
    return NULL;
}

Lista2* lst2_insere(Lista2* l, int v){
    Lista2 *p=(Lista2*) malloc(sizeof(Lista2));
    if(p==NULL){
        exit(1);
    }
    p->prox=l;
    p->ant=NULL;
    p->info=v;
    if(l!=NULL){
        l->ant=p;
    }
    return p;
}
void lst2_imprime(Lista2 *l){
    Lista2 *p;
    for(p=l;p!=NULL;p=p->prox){
       printf("info = %d\n",p->info);
    }

}
Lista2* lst2_busca(Lista2* l, int v){
    Lista2 *p;
    
    for(p=l;p!=NULL;p=p->prox){
        
        if(p->info==v){
            
            return p;
        }
    }
    return NULL;

}
Lista2* lst2_retira(Lista2* l, int v){
    Lista2 *p=lst2_busca(l,v);
    
    if(l==NULL){
        return l;
    }
    if(p==l){
        l=p->prox;
    }
    if(p->prox!=NULL){
       p->prox->ant= p->ant;  
    }
    else{
        p->ant->prox = p->prox;
       
    }

    free(p);
    return l;
}
void lst2_libera(Lista2 *l){
    free(l);
}
int lst2_vazia(Lista2* l){
     Lista2 *p=l;
    if(p==NULL){
        return 0;
    }else{
        return 1;
    }
}

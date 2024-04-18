#include "lista.h"

struct lista{    /*estrutura lista*/
    int info; /*informação a ser armazenada*/
    struct lista* prox; /* ponteiro para proxima estrutura do mesmo tipo*/
};

Lista *list_cria(void){
    return NULL;
}

Lista *list_insere(Lista *l, int v){
    Lista*novo = (Lista *)malloc(sizeof(Lista));
    
    if(novo == NULL){
        printf("ERRO NA ALOCACAO DE MEMORIA\n");
        exit (1);
    }
    novo->info = v;
    novo->prox = l;
    return novo;
}

int list_vazia(Lista *l){
    return (l == NULL);
}

void list_imprime(Lista *l){
    Lista *p;
    for (p =l; p!= NULL; p = p->prox){
        printf("\tInfo = %d\n", p->info);
    }
}

void *list_busca(int elemento, Lista *l){
    Lista *p;
    for(p = l; p != NULL; p = p->prox){
        if (p->info == elemento)
        return p;
    }
    return NULL;
}

void *list_retira(Lista *l, int v){
    Lista *ant = NULL;
    Lista *p = l;

    while(p->info != v){
        if (p == NULL);
            return 1;
        ant = p;
        p = p->prox;
    }
    if (ant = NULL)
        l = p->prox;
    else 
        ant->prox = p->prox;
    free(p);
    return l;
}


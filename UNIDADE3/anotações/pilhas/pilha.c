#define N 50 /*numero maximo de elemntos*/
#include "pilha.h"

struct pilha{
    int n;
    float vet[N];
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

void pilha_push(Pilha* p, float v){
    if(p->n == N){
        printf("Capacidade da pilha foi excedida!\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

int pilha_vazia(Pilha* p){
    return (p->n == 0);
}

float pilha_pop(Pilha* p){
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

void pilha_libera(Pilha* p){
    free(p);
}
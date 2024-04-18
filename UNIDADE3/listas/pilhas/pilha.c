#define N 50
#include "pilha.h"

struct pilha{
    int n;
    float *vet;
};

typedef struct pilha Pilha;

Pilha* pilha_cria(void){
    Pilha *stack = (Pilha*) malloc(sizeof(Pilha));
    if(stack == NULL){
        exit(1);
    }
    stack->vet = (float*) malloc(N* sizeof(float));
    if(stack->vet == NULL){
        exit(1);
    }
}

void pilha_push(Pilha* p, float v){
    if(p->n == NULL){
        exit(1);
    }
    p->vet = (float*)realloc(p->vet, N* sizeof(float));
    if(p->vet == NULL){
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

int pilha_vazia(Pilha* p){
    return(p->n == 0);
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

